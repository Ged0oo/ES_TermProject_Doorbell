#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "HAL/Buzzer/Buzzer.h"
#define F_CPU	8000000UL

volatile uint8 gOctave = 0;
volatile uint8 gTempo;
volatile uint8 gActMelody = 0;

// set the intial button state as LOW
volatile uint8_t ButtonState = 0;

ISR(INT0_vect)
{
	gActMelody++;
}

void ConfigureExternalInterrupt()
{
    // Set INT0/PD2 as input
    DDRD &= ~(1 << DDD2);

    // Enable INT0
    GICR |= (1 << INT0);

    // Trigger INT0 on falling edge
    MCUCR |= (1 << ISC01);
}

void ConfigureTimer()
{
	//sets the Timer/Counter Control Register A to 0
	//indicating no special modes or configurations for the output compare pins
	TCCR1A = 0x00;

	//sets Control Register B with the following configurations
	TCCR1B = (0 << WGM13) | (1 << WGM12) | //configures Timer/Counter 1 for CTC Mode
			 (0 << CS12)  | (1 << CS11)  | (1 << CS10); //configuring the prescaler to divide the clock by 1024

	//initializes the Timer/Counter 1 register to 0
	TCNT1 = 0x00;
}


void main(void)
{
	sei();
	ConfigureExternalInterrupt();
	ConfigureTimer();

	// set PIND5 as output for the buzzer
	DDRD |= (1<<PIND5);

	// set PINB2 as input for the push button
	DDRB &= ~(1<<PIND2);

	uint8_t retMelody = 0;

    while (1)
    {
    	// first read the button state
    	ButtonState = READ_BIT(PIND, PIND2);

    	if(ButtonState == 1)
    	{
    		retMelody = PlayMelody(gActMelody);
    	}
    	else if(ButtonState == 0)
    	{
    		// turn of the buzzer
    		TCCR1A = 0x00;
			OCR1A = 0x00;
    	}
    }
}
