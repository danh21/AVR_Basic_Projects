#include <io.h>
#include <delay.h>
#include <stdio.h>



/* ------------------------- CONFIG ------------------------- */
#define LCD_Data    PORTD
#define LCD_Ctrl    PORTG
#define LCD_RS      2
#define LCD_EN      3

void setup_port(void)
{
    DDRG |= (1 << LCD_RS) | (1 << LCD_EN);  
    DDRD = 0xFF; 
}



/* ------------------------- FUNCTION ------------------------- */
#define RS_High (LCD_Ctrl |=  (1 << LCD_RS))  
#define RS_Low  (LCD_Ctrl &= ~(1 << LCD_RS))  
#define E_High  (LCD_Ctrl |=  (1 << LCD_EN))
#define E_Low   (LCD_Ctrl &= ~(1 << LCD_EN))



void LCD_sendCmd(unsigned char cmd) 
{
    RS_Low;
    LCD_Data = cmd; 
    E_High;
    E_Low; 
    delay_ms(1); 
}



void LCD_init() 
{       
    LCD_sendCmd(0x38);  // 8-bit mode, 2 lines, 5x8 pixel   
    delay_ms(1);
    LCD_sendCmd(0x0C);  // turn on screen, turn off cursor 
    delay_ms(1);
    LCD_sendCmd(0x06);  // increase cursor
    delay_ms(1);    
    LCD_sendCmd(0x01);  // clear display
    delay_ms(1);          
}



void LCD_sendData(char data) {
    RS_High;
    LCD_Data = data; 
    E_High;
    E_Low;
    delay_ms(1); 
}



void LCD_printStr(char *str, int row, int column) 
{
    switch (row)
    {
        case 0: 
            LCD_sendCmd((0x00 | 0x80) + column);   
            break;
        case 1: 
            LCD_sendCmd((0x40 | 0x80) + column);    
            break;
        case 2: 
            LCD_sendCmd((0x14 | 0x80) + column);    
            break;  
        case 3: 
            LCD_sendCmd((0x54 | 0x80) + column);    
            break;
        default: 
            break;
    } 
    
    while (*str != '\0')                            
        LCD_sendData(*str++);        
}