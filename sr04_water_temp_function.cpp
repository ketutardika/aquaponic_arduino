#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;


void setup_water_temp(){
  sensors.begin();
}

float read_water_temp_value() {
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  if (isnan(Celcius) || Celcius == -127 || Celcius == 0.07)  {
    Celcius=-1;
  } 
  return (Celcius);
}