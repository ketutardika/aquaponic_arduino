#include <Arduino.h>
#include "GravityTDS.h"
#include "sr04_water_temp_function.h"
 
#define TdsSensorPin A0
GravityTDS gravityTds;


float tdsValue = 0;



void setup_tds(){
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
}

void read_tds(){
}

float read_tds_value(){
    float temperature = read_water_temp_value() > 0 ? read_water_temp_value() : 0; 
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    if (isnan(temperature) || temperature == -1 || temperature == 0)  {
      tdsValue=-1;
    }
    else {
      tdsValue = gravityTds.getTdsValue();
    }
    return tdsValue; // return the humidity value
}