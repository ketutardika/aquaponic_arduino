#ifndef SR01_DHT11_FUNCTION_H
#define SR01_DHT11_FUNCTION_H
#include <Arduino.h>

void setup_dht();
void read_dht_11();
float readTemperature();
float readHumidity();

#endif