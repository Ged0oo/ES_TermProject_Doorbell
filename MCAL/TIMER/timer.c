#include "timer.h"


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
