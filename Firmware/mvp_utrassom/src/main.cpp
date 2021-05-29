#include <Arduino.h>
#include "check_temp.h"

// DEFININDO PINOS

#define LED 2
#define RELE_Chapa 26
#define RELE_Ultra 27

// DEFININDO CONSTANTES

#define Tmax_Ultra 70
#define Tmax_Chapa 60
#define time_check 500

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(RELE_Chapa, OUTPUT);
  pinMode(RELE_Ultra, OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:

  float LM35_TempC_Sensor1 = read_temp();

  if (LM35_TempC_Sensor1>Tmax_Ultra){
    digitalWrite(RELE_Chapa, HIGH);
    digitalWrite(RELE_Ultra, HIGH);
  } else {
    if (LM35_TempC_Sensor1>Tmax_Chapa){
      digitalWrite(RELE_Chapa, HIGH);
    } else {
      digitalWrite(RELE_Chapa, LOW);
    }
    digitalWrite(RELE_Ultra, LOW);
  }

  delay(time_check);
}