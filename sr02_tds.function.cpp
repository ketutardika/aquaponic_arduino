#include <Arduino.h>
#include "GravityTDS.h"
 
#define TdsSensorPin A0
GravityTDS gravityTds;
 
float temperature = 25,tdsValue = -1;


void setup_tds(){
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
}

void read_tds(){
}

float read_tds_value(){
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();
    return tdsValue; // return the humidity value

}