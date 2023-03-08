#include "DHT.h"
#include "dht11_function.h"

#define DHTPIN 52
#define DHTTYPE DHT11

DHT dht11(DHTPIN, DHTTYPE);

void setup_dht(){
  dht11.begin();
}

void read_dht_11(){
  float h1 = dht11.readHumidity();
  float t1 = dht11.readTemperature();

  if (isnan(h1) || isnan(t1)) {
      float h1 = 0;
      float t1 = 0;
      Serial.print(t1);
      Serial.print(" | ");
      Serial.println(h1);
  } else {
      Serial.print(t1);
      Serial.print(" | ");
      Serial.println(h1);
  }  
}

float readTemperature() {
  float temperature = dht11.readTemperature(); // read temperature value
  if (isnan(temperature)){
     temperature = 0;
  }
  return temperature; // return the temperature value
}

float readHumidity() {
  float humidity = dht11.readHumidity(); // read humidity value
  if (isnan(humidity)){
     humidity = 0;
  }
  return humidity; // return the humidity value
}