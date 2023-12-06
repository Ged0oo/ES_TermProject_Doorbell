#include "Application/app.h"

volatile uint8 gActMelody = 0;

void main(void)
{
	System_Initialize();
	uint8_t ButtonState = 0;

    while (1)
    {
    	ButtonState = READ_BIT(PIND, PIND2);

    	if(ButtonState == 1)
    		PlayMelody(gActMelody);

    	else if(ButtonState == 0)
    		TMR1_SET_OCR1A_VALUE(0);
    }
}
