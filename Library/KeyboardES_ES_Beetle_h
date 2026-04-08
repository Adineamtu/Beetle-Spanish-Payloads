#pragma once
#include <Arduino.h>
#include <Keyboard.h>

class KeyboardES_ES_Beetle {
public:
  static void begin();
  static void end();

  static void tap(uint8_t hidKey, uint8_t modifier = 0);

  static bool typeChar(const char* utf8Char);
  static void printES(const char* text);
  static void printlnES(const char* text);

private:
  static bool typeAscii(char c);
  static bool typeUtf8TwoByte(const char* s, uint8_t &consumed);
};
