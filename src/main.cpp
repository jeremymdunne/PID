#include <Arduino.h>
#include "PID.h"


PID pid(.6,.4,0);

int readLight(){
  long light = 0;
  for(int i = 0; i < 20; i ++){
    light += analogRead(A0);
  }

  return (int)(light / 20.0 + .5);
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(3,OUTPUT);
    digitalWrite(3,HIGH);
    pid.setSP(300);
}
float value = 256/2.0;
void loop() {
  int read = readLight();
  value = 80;
  value += (int)pid.calculate(read,100);
  if(value < 0) value = 0;
  analogWrite(3, value);
  Serial.println("Value: " + String(read) + " Writing: " + String(value));
  delay(100);
}
