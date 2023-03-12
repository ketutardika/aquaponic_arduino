#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include "sr01_dht11_function.h"
#include "sr02_tds_function.h"
#include "sr03_turbidity_function.h"
#include "sr04_water_temp_function.h"
#include "sr05_ph_function.h"
#include "sr06_sending_data.h"

const int intervalSendEsp = 100;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  setup_sending_data();
  delay(5000);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= intervalSendEsp) {
    loop_sending_data();
  }
}