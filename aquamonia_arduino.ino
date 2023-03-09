#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include "sr01_dht11_function.h"
#include "sr02_tds_function.h"
#include "sr03_turbidity_function.h"
#include "sr04_water_temp_function.h"
#include "sr05_ph_function.h"

//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial nodemcu(5, 6);

void setup() {
  Serial.begin(115200);
  nodemcu.begin(9600);
  setup_dht();
  setup_tds();
  setup_turbidity();
  setup_water_temp();
  setup_ph();
  delay(5000);
}

void loop() {
  sendingDatatoNode();
}

void sendingDatatoNode(){
  float new_temperature_sensor = readTemperature();
  float new_humidity_sensor = readHumidity();
  float new_tds_sensor = read_tds_value();
  float new_turbidity_sensor = read_turbidity_value();
  float new_water_temp_sensor = read_water_temp_value();
  float new_ph_sensor = read_ph_return();

  float temperature_sensor = new_temperature_sensor > 0 ? new_temperature_sensor : 0;
  float humidity_sensor = new_humidity_sensor  > 0 ? new_humidity_sensor : 0;
  float tds_sensor = new_tds_sensor  > 0 ? new_tds_sensor : 0;
  float turbidity_sensor = new_turbidity_sensor > 0 ? new_turbidity_sensor : 0;
  float water_temp_sensor = new_water_temp_sensor  > 0 ? new_water_temp_sensor : 0;
  float ph_sensor = new_ph_sensor  > 0 ? new_ph_sensor : 0;

  Serial.print("Temperature Reading: ");
  Serial.println(temperature_sensor);
  Serial.print("Humidity Sensor: ");
  Serial.println(humidity_sensor);
  Serial.print("TDS Sensor: ");
  Serial.println(tds_sensor);
  Serial.print("Turbidity Sensor: ");
  Serial.println(turbidity_sensor);
  Serial.print("Water Temperature Sensor: ");
  Serial.println(water_temp_sensor);
  Serial.print("PH: ");
  Serial.println(ph_sensor);
  

  StaticJsonDocument<200> doc;
  doc["temperature_sensor"] = temperature_sensor;
  doc["humidity_sensor"] = humidity_sensor;
  doc["tds_sensor"] = tds_sensor;
  doc["turbidity_sensor"] = turbidity_sensor; 
  doc["water_temp_sensor"] = water_temp_sensor;
  doc["ph_sensor"] = ph_sensor;

  serializeJson(doc, nodemcu);
  Serial.println("send data to nodemcu ");

  delay(1000);
}
