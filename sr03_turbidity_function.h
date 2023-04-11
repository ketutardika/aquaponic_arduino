#ifndef SR03_TURBIDITY_FUNCTION_H
#define SR03_TURBIDITY_FUNCTION_H
#include <Arduino.h>

void setup_turbidity();
void round_to_dp();
void read_turbidity();
float read_turbidity_value(byte type);

#endif