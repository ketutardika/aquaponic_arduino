#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "helper_function.h"
#include "sr01_dht11_function.h"
#include "sr02_tds_function.h"
#include "sr03_turbidity_function.h"
#include "sr04_water_temp_function.h"
#include "sr05_ph_function.h"
#include "sr06_sending_data.h"
#include "sr07_add_ultrasonic.h"


const int ledPin = 3;
const int buzzerPin = 4;
const int intervalSendEsp = 10;
unsigned long previousMillis = 0;
float temps, hums, tdss, trbds, wtemps, wlevels, phs;
float inputVoltage1, inputVoltage2, inputVoltage3, inputVoltage4, inputVoltage5, inputVoltage6;

void setup() {
  Serial.begin(9600);
  setup_sending_data();
  setupHelper(ledPin,buzzerPin);
  buzzerSingleBeep(buzzerPin, 1);
  powerOnLED(ledPin);  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("AQUAMONIA  OS");
  lcd.setCursor(2, 1);
  lcd.print("Version 1.0");
  delay(3000);
  lcd.clear();
  lcd.print("Preparing Data...");
  delay(3000);
  lcd.clear();  
}

void loop() {  
  int analogValue1 = analogRead(A0);
  inputVoltage1 = (analogValue1 * 5.0) / 1024.0;

  int analogValue2 = analogRead(A1);
  inputVoltage2 = (analogValue2 * 5.0) / 1024.0;

  int analogValue3 = analogRead(A2);
  inputVoltage3 = (analogValue3 * 5.0) / 1024.0;

  int analogValue4 = analogRead(A3);
  inputVoltage4 = (analogValue4 * 5.0) / 1024.0;

  int analogValue5 = analogRead(A4);
  inputVoltage5 = (analogValue5 * 5.0) / 1024.0;

  int analogValue6 = analogRead(A5);
  inputVoltage6 = (analogValue6 * 5.0) / 1024.0;

  //Serial.print("Read 1 : ");
  //Serial.print(analogValue1);
  //Serial.print(" || ");
  //Serial.println(inputVoltage1);

  //Serial.print("Read 2 : ");
  //Serial.print(analogValue2);
  //Serial.print(" || ");
  //Serial.println(inputVoltage2);

  //Serial.print("Read 3 : ");
  //Serial.print(analogValue3);
  //Serial.print(" || ");
  //Serial.println(inputVoltage3);

  //Serial.print("Read  4 : ");
  //Serial.print(analogValue4);
  //Serial.print(" || ");
  //Serial.println(inputVoltage4);

  //Serial.print("Read 5 : ");
  //Serial.print(analogValue5);
  //Serial.print(" || ");
  //Serial.println(inputVoltage5);

  //Serial.print("Read 6 : ");
  //Serial.print(analogValue6);
  //Serial.print(" || ");
  //Serial.println(inputVoltage6);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= intervalSendEsp) {
    loop_sending_data();
    powerOffLED(ledPin);
    delay(100);
    powerOnLED(ledPin);
  }  
  printLCD();
}

void printLCD(){
  temps = readTemperature();
  hums = readHumidity();
  tdss = read_tds_value();
  trbds = read_turbidity_value();
  wtemps = read_water_temp_value();
  phs = read_ph_return();
  wlevels = read_w_level();
  String water_level = String(wlevels);
  String ipAdd = recieveIP();

  lcd.setCursor(0, 0);
  lcd.print("TEMP");
  lcd.setCursor(0, 1);
  lcd.print(temps);
  lcd.setCursor(8, 0);
  lcd.print("HUM");
  lcd.setCursor(8, 1);
  lcd.print(hums);
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TDS");
  lcd.setCursor(0, 1);
  lcd.print(tdss);
  lcd.setCursor(8, 0);
  lcd.print("TURB");
  lcd.setCursor(8, 1);
  lcd.print(trbds);
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WTEMP");
  lcd.setCursor(0, 1);
  lcd.print(wtemps);
  lcd.setCursor(8, 0);
  lcd.print("PH");
  lcd.setCursor(8, 1);
  lcd.print(phs);
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("W LEVEL");
  lcd.setCursor(0, 1);
  lcd.print(water_level + " CM");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP Address");
  lcd.setCursor(0, 1);
  lcd.print(ipAdd);
  delay(2000);
  lcd.clear(); 
}