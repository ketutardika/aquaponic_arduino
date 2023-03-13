#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "led_function.h"
#include "sr01_dht11_function.h"
#include "sr02_tds_function.h"
#include "sr03_turbidity_function.h"
#include "sr04_water_temp_function.h"
#include "sr05_ph_function.h"
#include "sr06_sending_data.h"


const int ledPin = 53;
const int buzzerPin = 3;
const int intervalSendEsp = 100;
unsigned long previousMillis = 0;
float temps, hums, tdss, trbds, wtemps, phs;

void setup() {
  Serial.begin(9600);
  setup_sending_data();
  pinMode(buzzerPin, OUTPUT);
  setupLED(ledPin);
  powerOnLED(ledPin);
  lcd.init();
  lcd.backlight();
  delay(5000);
  lcd.clear();
}

void loop() {  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= intervalSendEsp) {
    loop_sending_data();
  }
  printLCD();
}

//fungsi untuk membuat dering pendek dengan duty cycle 50%,selama 0,8 s
void dering_pendek(){
digitalWrite(buzzerPin, HIGH);
delay(400);
digitalWrite(buzzerPin, LOW);
delay(400);
}
 
//fungsi untuk membuat dering pendek dengan duty cycle 50% ,selama 1,4 s
void dering_panjang(){
digitalWrite(buzzerPin, HIGH);
delay(700); //memberikan nilai tunda 0.7 second
digitalWrite(buzzerPin, LOW);
delay(700);
}

void printLCD(){
  temps = readTemperature();
  hums = readHumidity();
  tdss = read_tds_value();
  trbds = read_turbidity_value();
  wtemps = read_water_temp_value();
  phs = read_ph_return();

  lcd.setCursor(0, 0);
  lcd.print("TEMP");
  lcd.setCursor(0, 1);
  lcd.print(temps);
  lcd.setCursor(8, 0);
  lcd.print("HUM");
  lcd.setCursor(8, 1);
  lcd.print(hums);
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TDS");
  lcd.setCursor(0, 1);
  lcd.print(tdss);
  lcd.setCursor(8, 0);
  lcd.print("TURB");
  lcd.setCursor(8, 1);
  lcd.print(trbds);
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WTEMP");
  lcd.setCursor(0, 1);
  lcd.print(wtemps);
  lcd.setCursor(8, 0);
  lcd.print("PH");
  lcd.setCursor(8, 1);
  lcd.print(phs);
  delay(5000);
  lcd.clear();
}