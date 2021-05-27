#include <Arduino.h>
#include "check_temp.h"
#include "esp_adc_cal.h"


bool read_temp(){

    int LM35_Raw_Sensor1 = 0;
    float LM35_TempC_Sensor1 = 0.0;
    float LM35_TempF_Sensor1 = 0.0;
    float Voltage = 0.0;

    // Read LM35_Sensor1 ADC Pin
    LM35_Raw_Sensor1 = analogRead(LM35_Sensor1);  
    // Calibrate ADC & Get Voltage (in mV)
    Voltage = readADC_Cal(LM35_Raw_Sensor1); 
    // TempC = Voltage(mV) / 10
    LM35_TempC_Sensor1 = Voltage / 10;
    LM35_TempF_Sensor1 = (LM35_TempC_Sensor1 * 1.8) + 32;
    // Print The Readings
    Serial.print("Temperature = ");
    Serial.print(LM35_TempC_Sensor1);
    Serial.print(" °C , ");
    Serial.print("Temperature = ");
    Serial.print(LM35_TempF_Sensor1);
    Serial.println(" °F");
    
    delay(100);

    return true;
}

uint32_t readADC_Cal(int ADC_Raw)
{
  esp_adc_cal_characteristics_t adc_chars;
  
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
  return(esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars));
}