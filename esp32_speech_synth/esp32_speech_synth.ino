#include "TalkieDict.h"
#include <Arduino.h>
#include <Talkie.h>

// ===========================
// UART Setup (From ESP32-CAM)
// ===========================
#define RXD2 16 // Connect to TX (GPIO 14) on ESP32-CAM

HardwareSerial SerialCam(2);
Talkie voice; // Uses DAC1 (GPIO 25) by default on ESP32 for analog output

void setup() {
  Serial.begin(115200);
  SerialCam.begin(115200, SERIAL_8N1, RXD2, -1);

  Serial.println("Speech Synthesizer Ready.");
  Serial.println("Waiting for UART input from ESP32-CAM...");

  // Test voice output locally on start up
  voice.say(spc_SYSTEM);
  voice.say(spc_READY);
}

void processAndSpeakSentence(const String &sentence) {
  if (sentence.length() >= 256) {
    Serial.println("Error: Sentence too long to process (max 255 chars).");
    return;
  }
  // Convert to lowercase or uppercase if necessary.
  // We'll leave it as is and handle matching dynamically in TalkieDict.

  // strtok requires a mutable char array
  char sentenceArray[256];
  sentence.toCharArray(sentenceArray, sizeof(sentenceArray));

  // Tokenize using space and common punctuation as delimiters
  char *wordToken = strtok(sentenceArray, " \t.,!;?\"'");

  while (wordToken != NULL) {
    String wordStr = String(wordToken);

    if (wordStr.length() > 0) {
      Serial.print("Speaking word: ");
      Serial.println(wordStr);
      speakWord(voice, wordStr);
    }

    // Tiny pause between words for clarity
    delay(50);

    wordToken = strtok(NULL, " \t.,!;?\"'");
  }
}

void loop() {
  // Buffer the incoming sentence until \n
  if (SerialCam.available()) {
    String sentence = SerialCam.readStringUntil('\n');
    sentence.trim(); // Remove trailing \r or spaces

    if (sentence.length() > 0) {
      Serial.println("=========================================");
      Serial.print("Received sentence from CAM: ");
      Serial.println(sentence);

      processAndSpeakSentence(sentence);
      Serial.println("=========================================");
    }
  }
}
