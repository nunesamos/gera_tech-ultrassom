#include <Arduino.h>
#include "check_temp.h"

#define LED 2

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (read_temp()){
    digitalWrite(LED, HIGH);
    delay(900);
  }
  digitalWrite(LED, LOW);
  delay(1000);
}