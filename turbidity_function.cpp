#include <Arduino.h>
int Turbidity_Sensor_Pin = A0;
float Turbidity_Sensor_Voltage;
int samples = 600;
float ntu; // Nephelometric Turbidity Units

float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}

int square(int x) {  // function declared and implemented
    return x*x;
}

void setup_turbidity(){
  pinMode(Turbidity_Sensor_Pin, INPUT);
}

void read_turbidity()
{
  Turbidity_Sensor_Voltage = 0;
  for(int i=0; i<samples; i++)
  {
    Turbidity_Sensor_Voltage += ((float)analogRead(Turbidity_Sensor_Pin)/1023)*5;
  }
    
  Turbidity_Sensor_Voltage = Turbidity_Sensor_Voltage/samples;

  Turbidity_Sensor_Voltage = round_to_dp(Turbidity_Sensor_Voltage,2);
    if(Turbidity_Sensor_Voltage < 2.5){
      ntu = 0;
    } else{
      ntu = -1120.4*square(Turbidity_Sensor_Voltage)+ 5742.3*Turbidity_Sensor_Voltage - 4352.9; 
  }
  Serial.print(Turbidity_Sensor_Voltage,2);
  Serial.print(" | ");
  Serial.print(ntu,2);
  Serial.println(" NTU");
}

float read_turbidity_value()
{
  Turbidity_Sensor_Voltage = 0;
  for(int i=0; i<samples; i++)
  {
    Turbidity_Sensor_Voltage += ((float)analogRead(Turbidity_Sensor_Pin)/1023)*5;
  }
    
  Turbidity_Sensor_Voltage = Turbidity_Sensor_Voltage/samples;

  Turbidity_Sensor_Voltage = round_to_dp(Turbidity_Sensor_Voltage,2);
    if(Turbidity_Sensor_Voltage < 2.5){
      ntu = 0;
    } else{
      ntu = -1120.4*square(Turbidity_Sensor_Voltage)+ 5742.3*Turbidity_Sensor_Voltage - 4352.9; 
  }
  return ntu;
}