/*
 * main.c
 *
 * Created: 8/16/2022 5:13:27 PM
 * Author: DELL
 */

#include "LCD_20x4_4b.h"



void main(void)
{
    char data[20];
    int count = 0; 
    
    setup_port();
     
    LCD_init(); 
    
    LCD_printStr("TT HTN", 0, 0);
    LCD_printStr("NewBie: Danh", 1, 1);
    LCD_printStr("See you soon!", 2, 2); 
    
    while (1)
    {
        sprintf(data, "Count up: %d", count++);
        LCD_printStr(data, 3, 3);
        delay_ms(100);
    }
}
