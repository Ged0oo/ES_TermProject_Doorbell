#include <avr/io.h>
#include <util/delay.h>
#include "HAL/Buzzer/Buzzer.h"
#define F_CPU	8000000UL

void main(void)
{
	// the current melody to be played upon press
	uint8_t currentMelody = 2;

	// stored the return value from the playMelody API
	uint8_t melodyRET = 1;

	// set PIND5 as output for the buzzer
	DDRD |= (1<<PIND5);

	// set PINB2 as input for the push button
	DDRB &= ~(1<<PINB2);

	// set the intial button state as LOW
	uint8_t ButtonState = 1;

	//timer1InitCompare()

	//sets the Timer/Counter Control Register A to 0
	//indicating no special modes or configurations for the output compare pins
	TCCR1A = 0x00;

	//sets Control Register B with the following configurations
	TCCR1B = (0 << WGM13) | (1 << WGM12) | //configures Timer/Counter 1 for CTC Mode
			 (0 << CS12)  | (1 << CS11)  | (1 << CS10); //configuring the prescaler to divide the clock by 1024

	//initializes the Timer/Counter 1 register to 0
	TCNT1 = 0x00;

    while (1)
    {
    	// first read the button state
    	ButtonState = READ_BIT(PINB, PINB2);

    	// check the button state
    	if(ButtonState == 1)
    	{
    		// Play the melody and wait for it to finish
    		melodyRET = 0;
    		do
    		{
    			// read the button state
    			ButtonState = READ_BIT(PINB, PINB2);
    			// breaks the loop if the button is not pressed
    			if(ButtonState  == 0)
    				break;

    			// Play the current melody until finished
    			melodyRET = PlayMelody(currentMelody);

    			if (melodyRET == 1)
    			{
    				_delay_ms(200);
    				currentMelody += 1;
    				if (currentMelody >= LAST_MELODY)
    				     currentMelody = 0;
    			}
    		}
    		while(melodyRET == 0);
    	}
    	else if(ButtonState == 0)
    	{
    		// turn of the buzzer
    		TCCR1A = 0x00;
			OCR1A = 0x00;
    	}
    }
}
