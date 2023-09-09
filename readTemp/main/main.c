/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 8/17/2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega128
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 1024
*******************************************************/
#include <mega128.h>
#include <1wire.h>      // 1 Wire Bus interface functions
#include <ds18b20.h>    // DS1820 Temperature Sensor functions
#include "LCD_20x4_4b.h"



void main(void)
{
    char data[20];
    float temp;
    
    w1_init();
    
    // F1 -> Library Funcs Ref -> Peripheral Chips Funcs -> DS18B20
    ds18b20_init(NULL, 0, 0, DS18B20_10BIT_RES); 
    // 1 device -> null
    // No need threshold of temperature -> 0, 0
    // error 0.25 degree C
       
    setup_port();
     
    LCD_init(); 
    
    while (1)
    {
        temp = ds18b20_temperature(NULL);   // 1 device -> null
        sprintf(data, "Temperature: %.1f", temp); 
        
        LCD_printStr(data, 1, 1); 
        delay_ms(200);
    }
}