#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H
#include <Arduino.h>

void setupHelper(byte pin, byte buzzerPin);

void powerOnLED(byte pin);
void powerOffLED(byte pin);

void buzzerSingleBeep(byte pin, byte first);
void buzzerDoubleBeep(byte pin, byte first, byte second);
void buzzerTones();

#endif