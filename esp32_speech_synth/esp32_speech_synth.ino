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

  // Test voice output locally on start up.
  voice.say(sp2_READY);
  voice.say(sp2_ALERT);
}

void processAndSpeakSentence(const String &sentence) {
  if (sentence.length() >= 256) {
    Serial.println("Error: Sentence too long to process (max 255 chars).");
    return;
  }

  // strtok requires a mutable char array.
  char sentenceArray[256];
  sentence.toCharArray(sentenceArray, sizeof(sentenceArray));

  // Collect tokens first so we can match two-word phrases from the vocabulary.
  String tokens[128];
  int tokenCount = 0;

  char *wordToken = strtok(sentenceArray, " \t.,!;?\"'");
  while (wordToken != NULL && tokenCount < 128) {
    tokens[tokenCount++] = String(wordToken);
    wordToken = strtok(NULL, " \t.,!;?\"'");
  }

  int i = 0;
  while (i < tokenCount) {
    String current = tokens[i];
    current.toLowerCase();

    bool spokePhrase = false;
    if (i + 1 < tokenCount) {
      String next = tokens[i + 1];
      next.toLowerCase();
      String twoWord = current + " " + next;
      const uint8_t *phraseSound = findPhraseSound(twoWord);
      if (phraseSound != nullptr) {
        Serial.print("Speaking phrase: ");
        Serial.println(twoWord);
        voice.say(phraseSound);
        delay(50);
        i += 2;
        spokePhrase = true;
      }
    }

    if (!spokePhrase) {
      Serial.print("Speaking word: ");
      Serial.println(current);
      speakWord(voice, current);
      delay(50);
      i += 1;
    }
  }
}



void handleIncomingSentence(const String &source, const String &sentence) {
  if (sentence.length() == 0) {
    return;
  }

  Serial.println("=========================================");
  Serial.print("Received sentence from ");
  Serial.print(source);
  Serial.print(": ");
  Serial.println(sentence);

  processAndSpeakSentence(sentence);
  Serial.println("=========================================");
}

void loop() {
  // Allow direct typing in the Arduino Serial Monitor.
  if (Serial.available()) {
    String sentence = Serial.readStringUntil('\n');
    sentence.trim();
    handleIncomingSentence("Serial Monitor", sentence);
  }

  // Buffer incoming sentence from ESP32-CAM until \n.
  if (SerialCam.available()) {
    String sentence = SerialCam.readStringUntil('\n');
    sentence.trim();
    handleIncomingSentence("ESP32-CAM", sentence);
  }
}
