#include "esp_adc_cal.h"

#define LM35_Sensor1    35

uint32_t readADC_Cal(int ADC_Raw);
float read_temp();
void print_temp(float LM35_TempC_Sensor1);