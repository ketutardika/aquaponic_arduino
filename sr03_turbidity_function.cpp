#include <Arduino.h>
int Turbidity_Sensor_Pin = A2;
float Turbidity_Sensor_Voltage;
int samples = 800;
float ntu; // Nephelometric Turbidity Units
float ntuValue;

void setup_turbidity(){
  pinMode(Turbidity_Sensor_Pin, INPUT);
}

float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}

float read_turbidity_value(byte type)
{
  Turbidity_Sensor_Voltage = 0;
  for(int i=0; i<samples; i++)
    {
        Turbidity_Sensor_Voltage += ((float)analogRead(Turbidity_Sensor_Pin)/1023)*5;
    }    
  Turbidity_Sensor_Voltage = Turbidity_Sensor_Voltage/samples;
  Turbidity_Sensor_Voltage = round_to_dp(Turbidity_Sensor_Voltage,2);
  if(Turbidity_Sensor_Voltage < 2.5){
      ntu = -1;                                                                                                                                                                                                                                                                                                                                                                                                                         
    }else{
      ntu = -1120.4*square(Turbidity_Sensor_Voltage)+ 5742.3*Turbidity_Sensor_Voltage - 4352.9; 
  } 

  if (type == 1){
    ntuValue = ntu;
  } else {
    ntuValue = Turbidity_Sensor_Voltage;
  }
  
  return ntuValue;
}