#include <Arduino.h>
int Turbidity_Sensor_Pin = A2;

void setup_turbidity(){
  pinMode(Turbidity_Sensor_Pin, INPUT);
}

float read_turbidity_value()
{
  int sensorValue = Turbidity_Sensor_Pin;// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0);
  if (sensorValue == 15.00 || sensorValue == 16.00 )  {
    voltage=-1;
  }
  return voltage;
}