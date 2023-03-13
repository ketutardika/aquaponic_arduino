#ifndef SR05_PH_FUNCTIONS_H
#define SR05_PH_FUNCTIONS_H
#include <Arduino.h>

void setup_ph();
void read_ph();
float read_ph_return();
double avergearray(int* arr, int number);

#endif