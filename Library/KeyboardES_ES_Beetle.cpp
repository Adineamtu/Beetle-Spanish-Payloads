#include "KeyboardES_ES_Beetle.h"
#include <string.h>

static constexpr uint8_t RAW_OFFSET = 136;

void KeyboardES_ES_Beetle::begin() {
  Keyboard.begin();
  delay(100);
  Keyboard.releaseAll();
}

void KeyboardES_ES_Beetle::end() {
  Keyboard.releaseAll();
  delay(20);
  Keyboard.end();
}

void KeyboardES_ES_Beetle::tap(uint8_t hidKey, uint8_t modifier) {
  Keyboard.releaseAll();
  delay(10);

  if (modifier) {
    Keyboard.press(modifier);
    delay(10);
  }

  Keyboard.press(hidKey + RAW_OFFSET);
  delay(20);

  Keyboard.release(hidKey + RAW_OFFSET);
  delay(10);

  if (modifier) {
    Keyboard.release(modifier);
  }

  Keyboard.releaseAll();
  delay(20);
}

bool KeyboardES_ES_Beetle::typeAscii(char c) {
  switch (c) {
    // litere mici
    case 'a': tap(4); return true;
    case 'b': tap(5); return true;
    case 'c': tap(6); return true;
    case 'd': tap(7); return true;
    case 'e': tap(8); return true;
    case 'f': tap(9); return true;
    case 'g': tap(10); return true;
    case 'h': tap(11); return true;
    case 'i': tap(12); return true;
    case 'j': tap(13); return true;
    case 'k': tap(14); return true;
    case 'l': tap(15); return true;
    case 'm': tap(16); return true;
    case 'n': tap(17); return true;
    case 'o': tap(18); return true;
    case 'p': tap(19); return true;
    case 'q': tap(20); return true;
    case 'r': tap(21); return true;
    case 's': tap(22); return true;
    case 't': tap(23); return true;
    case 'u': tap(24); return true;
    case 'v': tap(25); return true;
    case 'w': tap(26); return true;
    case 'x': tap(27); return true;
    case 'y': tap(28); return true;
    case 'z': tap(29); return true;

    // litere mari
    case 'A': tap(4, KEY_LEFT_SHIFT); return true;
    case 'B': tap(5, KEY_LEFT_SHIFT); return true;
    case 'C': tap(6, KEY_LEFT_SHIFT); return true;
    case 'D': tap(7, KEY_LEFT_SHIFT); return true;
    case 'E': tap(8, KEY_LEFT_SHIFT); return true;
    case 'F': tap(9, KEY_LEFT_SHIFT); return true;
    case 'G': tap(10, KEY_LEFT_SHIFT); return true;
    case 'H': tap(11, KEY_LEFT_SHIFT); return true;
    case 'I': tap(12, KEY_LEFT_SHIFT); return true;
    case 'J': tap(13, KEY_LEFT_SHIFT); return true;
    case 'K': tap(14, KEY_LEFT_SHIFT); return true;
    case 'L': tap(15, KEY_LEFT_SHIFT); return true;
    case 'M': tap(16, KEY_LEFT_SHIFT); return true;
    case 'N': tap(17, KEY_LEFT_SHIFT); return true;
    case 'O': tap(18, KEY_LEFT_SHIFT); return true;
    case 'P': tap(19, KEY_LEFT_SHIFT); return true;
    case 'Q': tap(20, KEY_LEFT_SHIFT); return true;
    case 'R': tap(21, KEY_LEFT_SHIFT); return true;
    case 'S': tap(22, KEY_LEFT_SHIFT); return true;
    case 'T': tap(23, KEY_LEFT_SHIFT); return true;
    case 'U': tap(24, KEY_LEFT_SHIFT); return true;
    case 'V': tap(25, KEY_LEFT_SHIFT); return true;
    case 'W': tap(26, KEY_LEFT_SHIFT); return true;
    case 'X': tap(27, KEY_LEFT_SHIFT); return true;
    case 'Y': tap(28, KEY_LEFT_SHIFT); return true;
    case 'Z': tap(29, KEY_LEFT_SHIFT); return true;

    // cifre
    case '1': tap(30); return true;
    case '2': tap(31); return true;
    case '3': tap(32); return true;
    case '4': tap(33); return true;
    case '5': tap(34); return true;
    case '6': tap(35); return true;
    case '7': tap(36); return true;
    case '8': tap(37); return true;
    case '9': tap(38); return true;
    case '0': tap(39); return true;

    // whitespace
    case ' ':  tap(44); return true;
    case '\n': tap(40); return true;
    case '\t': tap(43); return true;

    // basic punctuation
    case '\'': tap(45); return true;
    case '+': tap(48); return true;
    case '*': tap(48, KEY_LEFT_SHIFT); return true;
    case ',': tap(54); return true;
    case '.': tap(55); return true;
    case '-': tap(56); return true;

    // Spanish specific
    case '¡': tap(46); return true;
    case '¿': tap(46, KEY_LEFT_SHIFT); return true;

    // SHIFT symbols
    case '!': tap(30, KEY_LEFT_SHIFT); return true;
    case '"': tap(31, KEY_LEFT_SHIFT); return true;
    case '$': tap(33, KEY_LEFT_SHIFT); return true;
    case '%': tap(34, KEY_LEFT_SHIFT); return true;
    case '&': tap(35, KEY_LEFT_SHIFT); return true;
    case '/': tap(36, KEY_LEFT_SHIFT); return true;   // Shift + 7
    case '(': tap(37, KEY_LEFT_SHIFT); return true;   // Shift + 8
    case ')': tap(38, KEY_LEFT_SHIFT); return true;   // Shift + 9
    case '=': tap(39, KEY_LEFT_SHIFT); return true;   // Shift + 0
    case '?': tap(45, KEY_LEFT_SHIFT); return true;
    case ':': tap(55, KEY_LEFT_SHIFT); return true;
    case ';': tap(54, KEY_LEFT_SHIFT); return true;

    // ALTGR
    case '@': tap(31, KEY_RIGHT_ALT); return true;    // AltGr + 2
    case '#': tap(32, KEY_RIGHT_ALT); return true;    // AltGr + 3
    case '€': tap(8, KEY_RIGHT_ALT); return true;     // AltGr + E
    case '|': tap(30, KEY_RIGHT_ALT); return true;    // AltGr + 1
    case '\\': tap(53, KEY_RIGHT_ALT); return true;

    // brackets
    case '[': tap(47, KEY_RIGHT_ALT); return true;
    case ']': tap(48, KEY_RIGHT_ALT); return true;

    // underscore _
    case '_': tap(56, KEY_LEFT_SHIFT); return true;

    // curly braces
    case '{': tap(52, KEY_RIGHT_ALT); return true;
    case '}': tap(49, KEY_RIGHT_ALT); return true;

    // backtick `
    case '`':
      return false;

    default:
      return false;
  }
}

bool KeyboardES_ES_Beetle::typeUtf8TwoByte(const char* s, uint8_t &consumed) {
  consumed = 0;

  const uint8_t b0 = (uint8_t)s[0];
  const uint8_t b1 = (uint8_t)s[1];

  if (b0 == 0xC3) {
    switch (b1) {
      case 0xB1: tap(51); consumed = 2; return true;                 // ñ
      case 0x91: tap(51, KEY_LEFT_SHIFT); consumed = 2; return true; // Ñ
      case 0xA7: tap(50); consumed = 2; return true;                 // ç
      case 0x87: tap(50, KEY_LEFT_SHIFT); consumed = 2; return true; // Ç
      default: return false;
    }
  }

  if (b0 == 0xC2) {
    switch (b1) {
      case 0xA1: tap(46); consumed = 2; return true;                 // ¡
      case 0xBF: tap(46, KEY_LEFT_SHIFT); consumed = 2; return true; // ¿
      default: return false;
    }
  }

  return false;
}

bool KeyboardES_ES_Beetle::typeChar(const char* utf8Char) {
  if (!utf8Char || !*utf8Char) return false;

  if (((uint8_t)utf8Char[0]) < 0x80) {
    return typeAscii(utf8Char[0]);
  }

  uint8_t consumed = 0;
  return typeUtf8TwoByte(utf8Char, consumed);
}

void KeyboardES_ES_Beetle::printES(const char* text) {
  if (!text) return;

  size_t i = 0;
  while (text[i] != '\0') {
    uint8_t c = (uint8_t)text[i];

    if (c < 0x80) {
      typeAscii((char)c);
      i += 1;
      continue;
    }

    uint8_t consumed = 0;
    if (typeUtf8TwoByte(&text[i], consumed) && consumed > 0) {
      i += consumed;
      continue;
    }

    // fallback: spațiu pentru caracter necunoscut
    tap(44);
    i += 1;
    continue;
  }
}

void KeyboardES_ES_Beetle::printlnES(const char* text) {
  printES(text);
  tap(40);
}
