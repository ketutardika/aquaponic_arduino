#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 53
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;


void setup_water_temp(){
}
void read_water_temp(){
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  if (isnan(Celcius))  {
    Celcius=0;
  } 
  Serial.print(Celcius);
  Serial.println(" C");
}
float read_water_temp_value() {
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  if (isnan(Celcius))  {
    Celcius=0;
  } 
  return (Celcius);
}