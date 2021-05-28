#include <Arduino.h>
#include "check_temp.h"

#define LED 2
#define RELE 32

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(RELE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 // if (!read_temp()){
    digitalWrite(RELE, HIGH);
    delay(1500);
//  } else {
    digitalWrite(RELE, LOW);
    delay(1500);
//  }
}