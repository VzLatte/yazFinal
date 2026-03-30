#ifndef TALKIEDICT_H
#define TALKIEDICT_H

#include "Vocab_US_Large.h"
#include <Arduino.h>
#include <Talkie.h>

// Structure to map String to voice data
struct TalkieWord {
  const char *word;
  const uint8_t *voiceData;
};

// Common mapping array.
// Note: Expand this dictionary based on your specific application needs.
// All voice data constants are sourced from Vocab_US_Large.h
const TalkieWord talkieDict[] = {{"hello", spc_HELLO},
                                 {"ready", spc_READY},
                                 {"danger", spc_DANGER},
                                 {"system", spc_SYSTEM},
                                 {"error", spc_ERROR},
                                 {"alert", spc_ALERT},
                                 {"time", spc_TIME},
                                 {"fire", spc_FIRE},
                                 {"one", spc_ONE},
                                 {"two", spc_TWO},
                                 {"three", spc_THREE},
                                 {"four", spc_FOUR},
                                 {"five", spc_FIVE},
                                 {"six", spc_SIX},
                                 {"seven", spc_SEVEN},
                                 {"eight", spc_EIGHT},
                                 {"nine", spc_NINE},
                                 {"ten", spc_TEN},
                                 {"stop", spc_STOP},
                                 {"go", spc_GO},
                                 {"left", spc_LEFT_1},
                                 {"right", spc_RIGHT_1},
                                 {"up", spc_UP},
                                 {"down", spc_DOWN},
                                 {"a", spA},
                                 {"i", spI},
                                 // Adding logic words
                                 {"and", spc_AND},
                                 {"the", spc_THE},
                                 {"is", spc_IS},
                                 {"are", spc_ARE},
                                 {"to", spc_TO},
                                 {"for", spc_FOR}};

const int talkieDictSize = sizeof(talkieDict) / sizeof(talkieDict[0]);

// Helper to convert char to alphabet Talkie sound
const uint8_t *getLetterSound(char c) {
  switch (tolower(c)) {
  case 'a':
    return spA;
  case 'b':
    return spB;
  case 'c':
    return spC;
  case 'd':
    return spD;
  case 'e':
    return spE;
  case 'f':
    return spF;
  case 'g':
    return spG;
  case 'h':
    return spH;
  case 'i':
    return spI;
  case 'j':
    return spJ;
  case 'k':
    return spK;
  case 'l':
    return spL;
  case 'm':
    return spM;
  case 'n':
    return spN;
  case 'o':
    return spO;
  case 'p':
    return spP;
  case 'q':
    return spQ;
  case 'r':
    return spR;
  case 's':
    return spS;
  case 't':
    return spT;
  case 'u':
    return spU;
  case 'v':
    return spV;
  case 'w':
    return spW;
  case 'x':
    return spX;
  case 'y':
    return spY;
  case 'z':
    return spZ;
  // Basic number fallback as individual digits
  case '0':
    return spc_ZERO;
  case '1':
    return spc_ONE;
  case '2':
    return spc_TWO;
  case '3':
    return spc_THREE;
  case '4':
    return spc_FOUR;
  case '5':
    return spc_FIVE;
  case '6':
    return spc_SIX;
  case '7':
    return spc_SEVEN;
  case '8':
    return spc_EIGHT;
  case '9':
    return spc_NINE;
  default:
    return nullptr;
  }
}

// Function to speak the word or fallback to spelling it out
void speakWord(Talkie &voice, const String &word) {
  String lowerWord = word;
  lowerWord.toLowerCase();

  // 1. Array Lookup
  for (int i = 0; i < talkieDictSize; i++) {
    if (lowerWord.equalsIgnoreCase(talkieDict[i].word)) {
      voice.say(talkieDict[i].voiceData);
      return;
    }
  }

  // 2. Fallback: spell it out letter by letter
  Serial.print("  -> Word not in dictionary. Spelling it out: ");
  for (int i = 0; i < lowerWord.length(); i++) {
    const uint8_t *ptr = getLetterSound(lowerWord[i]);
    if (ptr != nullptr) {
      Serial.print(lowerWord[i]);
      voice.say(ptr);
      delay(20); // Small pause between letters
    }
  }
  Serial.println();
}

#endif
