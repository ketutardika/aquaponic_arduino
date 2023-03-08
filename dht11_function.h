#ifndef DHT11_FUNCTION_H
#define DHT11_FUNCTION_H
#include <Arduino.h>

void setup_dht();
void read_dht_11();
float readTemperature();
float readHumidity();

#endif