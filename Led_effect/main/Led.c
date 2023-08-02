/*
 * Led.c
 *
 * Created: 2/1/2023 8:17:12 PM
 * Author: DANH
 */

#include <io.h>
#include "Led.h"



void main(void)
{      
    while (1)
    {     
        blink(&PORTD, &DDRD, 0xAA, 3, 500);   
        
        run(&PORTE, &DDRE, 'L', 2, 200);  
    }
}
