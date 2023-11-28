#include <avr/io.h>
#include <util/delay.h>
#include "HAL/Buzzer/Buzzer.h"
#define F_CPU	8000000UL

volatile uint8_t gActMelody = 0;

void main(void)
{
	DDRD |= (1<<PIND5);
	DDRB &= ~(1<<PINB2);
	uint8_t ButtonState = 0;

	//timer1InitCompare()
	TCCR1A = 0x00;
	TCCR1B = (0 << WGM13) | (1 << WGM12) | (0 << CS12) | (1 << CS11) | (1 << CS10);
	TCNT1 = 0x00;

    while (1)
    {
    	ButtonState = PINB & (1<<PINB2);
    	if(ButtonState)
    		PlayMelody(0);
    	else
    		TCCR1A = 0x00;
    }
}
