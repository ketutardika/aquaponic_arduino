#include <Arduino.h>
#include <NewPing.h>

#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define MAX_DISTANCE 400 // Maximum distance we want to measure (in centimeters).
float max_level = 60.00;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup_w_level(){

}
void loop_w_level(){
  delay(50);
  int distance = sonar.ping_cm();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}
float read_w_level(){
  delay(50);
  float distance = sonar.ping_cm();  
  float distance_total = max_level - distance;
  return (distance_total);
}
