/*
 * Btn_Led.c
 *
 * Created: 2/2/2023 12:31:38 PM
 * Author: DELL
 */

#include <io.h>
#include "Button.h"



void main(void)
{
    // PIND: Input Pins    
    while (1)
    {        
        ctrlLed(&PORTD, &DDRD, &PIND);
        ctrlLed(&PORTF, &DDRF, &PINF);    
    }
}
