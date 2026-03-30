#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "esp_camera.h"

// ===========================
// Wi-Fi & API Credentials
// ===========================
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* ocr_api_key = "YOUR_API_KEY"; // OCR.space API Key

// ===========================
// Camera Configuration 
// (AI Thinker ESP32-CAM)
// ===========================
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

// ===========================
// UART Setup (To Speech Controller)
// ===========================
#define RXD2 15 // Not used by us, but required to init Serial
#define TXD2 14 // Connect to RX (GPIO 16) on ESP32 Dev Module
HardwareSerial SerialTalkie(2); 

// Global variables
unsigned long lastCaptureTime = 0;
const unsigned long captureInterval = 10000; // 10 seconds

void setupCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  
  // Frame parameters
  config.frame_size = FRAMESIZE_VGA; // Higher res for better OCR, but more memory
  config.jpeg_quality = 12; // 10-63, lower is better quality
  config.fb_count = 1;

  if (psramFound()) {
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x. Restarting...\n", err);
    delay(3000);
    ESP.restart();
  }
}

void setup() {
  Serial.begin(115200);
  SerialTalkie.begin(115200, SERIAL_8N1, RXD2, TXD2);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi Connected!");

  setupCamera();
  Serial.println("System Ready. Beginning OCR Loop.");
}

void captureAndSendImage() {
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed!");
    return;
  }
  
  Serial.println("Image Captured!");

  WiFiClient client;
  if (!client.connect("api.ocr.space", 80)) {
    Serial.println("Connection to OCR.space failed");
    esp_camera_fb_return(fb);
    return;
  }

  String boundary = "Esp32CamBoundary";
  String head = "--" + boundary + "\r\n" +
                "Content-Disposition: form-data; name=\"apikey\"\r\n\r\n" +
                String(ocr_api_key) + "\r\n" +
                "--" + boundary + "\r\n" +
                "Content-Disposition: form-data; name=\"language\"\r\n\r\n" +
                "eng\r\n" +
                "--" + boundary + "\r\n" +
                "Content-Disposition: form-data; name=\"isOverlayRequired\"\r\n\r\n" +
                "false\r\n" +
                "--" + boundary + "\r\n" +
                "Content-Disposition: form-data; name=\"file\"; filename=\"image.jpg\"\r\n" +
                "Content-Type: image/jpeg\r\n\r\n";
  String tail = "\r\n--" + boundary + "--\r\n";

  uint32_t contentLength = head.length() + fb->len + tail.length();

  String request = "POST /parse/image HTTP/1.1\r\n";
  request += "Host: api.ocr.space\r\n";
  request += "Content-Length: " + String(contentLength) + "\r\n";
  request += "Content-Type: multipart/form-data; boundary=" + boundary + "\r\n";
  request += "Connection: close\r\n\r\n";

  // Send request header
  client.print(request);
  // Send multipart head
  client.print(head);
  
  // Send image data (chunked to avoid watchdog resets and huge memory allocation)
  uint8_t *fb_buf = fb->buf;
  size_t fb_len = fb->len;
  size_t chunk_size = 1024;
  for (size_t i = 0; i < fb_len; i += chunk_size) {
    size_t send_size = (fb_len - i < chunk_size) ? (fb_len - i) : chunk_size;
    client.write(fb_buf + i, send_size);
  }
  
  // Send multipart tail
  client.print(tail);

  // Read response
  unsigned long timeout = millis();
  while (client.connected() && !client.available()) {
    if (millis() - timeout > 20000) {
      Serial.println("Timeout waiting for response.");
      client.stop();
      esp_camera_fb_return(fb);
      return;
    }
    delay(10);
  }

  // Parse Body
  bool isBody = false;
  String jsonResponse = "";
  while (client.available()) {
    String line = client.readStringUntil('\n');
    if (!isBody && line == "\r") {
      isBody = true;
      continue;
    }
    if (isBody) {
      jsonResponse += line;
    }
  }
  client.stop();
  esp_camera_fb_return(fb); // CRITICAL: Free the buffer to prevent memory leaks!

  // Process JSON
  if (jsonResponse.length() > 0) {
    DynamicJsonDocument doc(2048);
    DeserializationError error = deserializeJson(doc, jsonResponse);

    if (error) {
      Serial.print("JSON parsing failed: ");
      Serial.println(error.c_str());
      return;
    }

    // OCR.space response structure
    JsonArray parsedResults = doc["ParsedResults"];
    if (!parsedResults.isNull() && parsedResults.size() > 0) {
      String parsedText = parsedResults[0]["ParsedText"].as<String>();
      
      // Clean text (remove newlines and excess spaces)
      parsedText.replace("\r", " ");
      parsedText.replace("\n", " ");
      parsedText.trim();

      if (parsedText.length() > 0) {
        Serial.print("OCR Result: ");
        Serial.println(parsedText);
        
        // Transmit over UART to the ESP32 Dev module
        SerialTalkie.println(parsedText);
      } else {
        Serial.println("No text found in image.");
      }
    } else {
       Serial.println("Error or no results from OCR API.");
    }
  }
}

void loop() {
  if (millis() - lastCaptureTime >= captureInterval) {
    lastCaptureTime = millis();

    // Ensure Wi-Fi is still connected
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Wi-Fi disconnected. Reconnecting...");
      WiFi.disconnect();
      WiFi.begin(ssid, password);
      return;
    }

    captureAndSendImage();
    
    // Check free heap to prevent fragmentation issues over time
    if (ESP.getFreeHeap() < 20000) {
      Serial.println("Low memory, restarting to prevent crash...");
      delay(1000);
      ESP.restart();
    }
  }
}
