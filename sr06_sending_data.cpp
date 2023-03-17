#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include "sr01_dht11_function.h"
#include "sr02_tds_function.h"
#include "sr03_turbidity_function.h"
#include "sr04_water_temp_function.h"
#include "sr05_ph_function.h"

//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial SerialMega(5, 6);

void setup_sending_data(){
  SerialMega.begin(9600);
  setup_dht();
  setup_tds();
  setup_turbidity();
  setup_water_temp();
  setup_ph();
}

String recieveIP() {
  String ipaddress = "Reading IP..";
  if (SerialMega.available() > 0) {
    String jsonString = "";
    while (SerialMega.available()) {
      jsonString += (char)SerialMega.read();
    }
    StaticJsonDocument<300> doc;
    DeserializationError err = deserializeJson(doc, jsonString);
    int ip1 = doc["ip1"].as<int>();
    int ip2 = doc["ip2"].as<int>();
    int ip3 = doc["ip3"].as<int>();
    int ip4 = doc["ip4"].as<int>();
    String ipaddress = String(ip1)+"."+String(ip2)+"."+String(ip3)+"."+String(ip4);
    Serial.print("ip = ");
    Serial.println(ipaddress);
    return (ipaddress);
  }
  return (ipaddress);
  delay(3000);
}

void loop_sending_data(){
  float temperature_sensor = readTemperature() > 0 ? readTemperature() : 0;
  float humidity_sensor = readHumidity() > 0 ? readHumidity() : 0;
  float tds_sensor = read_tds_value() > 0 ? read_tds_value() : 0;
  float turbidity_sensor = read_turbidity_value() > 0 ? read_turbidity_value() : 0;
  float water_temp_sensor = read_water_temp_value() > 0 ? read_water_temp_value() : 0;
  float ph_sensor = read_ph_return() > 0 ? read_ph_return() : 0;

  delay(2000);
  SerialMega.print(temperature_sensor);
  SerialMega.print(",");
  SerialMega.print(humidity_sensor);
  SerialMega.print(",");
  SerialMega.print(tds_sensor);
  SerialMega.print(",");
  SerialMega.print(turbidity_sensor);
  SerialMega.print(",");
  SerialMega.print(water_temp_sensor);
  SerialMega.print(",");
  SerialMega.print(ph_sensor);
  SerialMega.println();

  Serial.print(temperature_sensor);
  Serial.print(",");
  Serial.print(humidity_sensor);
  Serial.print(",");
  Serial.print(tds_sensor);
  Serial.print(",");
  Serial.print(turbidity_sensor);
  Serial.print(",");
  Serial.print(water_temp_sensor);
  Serial.print(",");
  Serial.print(ph_sensor);
  Serial.println();

  StaticJsonDocument<200> doc;
  doc["temperature_sensor"] = temperature_sensor;
  doc["humidity_sensor"] = humidity_sensor;
  doc["tds_sensor"] = tds_sensor;
  doc["turbidity_sensor"] = turbidity_sensor; 
  doc["water_temp_sensor"] = water_temp_sensor;
  doc["ph_sensor"] = ph_sensor;

  // Mengonversi objek JSON ke string
 // String jsonString;
  //serializeJson(doc, jsonString);
  // Mengirim data ke SerialNode
  //SerialMega.println(jsonString);
}