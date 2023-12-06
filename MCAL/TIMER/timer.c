#include "timer.h"


void ConfigureTimer()
{
	// sets the Timer/Counter Control Register A to 0
	// indicating no special modes or configurations for the output compare pins
	TCCR1A = 0x00;

	// configuring the prescaler to divide the clock by 64
	TMR1_SET_PRESCALER(TMR1_64_PRESCALER);

	// configuring the timer mode CTC OCR1A
	TMR1_SET_MOOD(TMR1_CTC_OCR1A_MODE);

	//initializes the Timer/Counter 1 register to 0
	TMR1_SET_TCNT1_VALUE(0);
}
