#include "helper_function.h"
int j;

void setupHelper(byte pin, byte buzzerPin){
  pinMode(pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void powerOnLED(byte pin){
  digitalWrite(pin, HIGH);
}

void powerOffLED(byte pin){
  digitalWrite(pin, LOW);
}

void buzzerSingleBeep(byte buzzerPin, byte first){
for (j=1;j<=100;j=j+1){
  digitalWrite(buzzerPin, HIGH);
  delay(first);
  digitalWrite(buzzerPin, LOW);
  delay(first);
}
}

void buzzerDoubleBeep(byte buzzerPin, byte first, byte second){
for (j=1;j<=100;j=j+1){
  digitalWrite(buzzerPin, HIGH);
  delay(first);
  digitalWrite(buzzerPin, LOW);
  delay(first);
}
for (j=1; j<=100;j=j+1){
  digitalWrite(buzzerPin, HIGH);
  delay(second);
  digitalWrite(buzzerPin, LOW);
  delay(second);
}
}

void buzzerTones(byte buzzerPin){
  tone(buzzerPin, 262); delay(500);
  tone(buzzerPin, 294); delay(500);
  tone(buzzerPin, 330); delay(500);
  tone(buzzerPin, 349); delay(500);
  tone(buzzerPin, 395); delay(500);
  tone(buzzerPin, 440); delay(500);
  tone(buzzerPin, 494); delay(500);
  tone(buzzerPin, 523); delay(500);
}