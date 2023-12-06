#include "MCAL/EXI/EXI.h"
#include "MCAL/TIMER/timer.h"
#include "HAL/Buzzer/Buzzer.h"

volatile uint8 gActMelody = 0;

void ConfugureIOPins()
{
	// set PIND5 as output for the buzzer
	DDRD |= (1<<PIND5);

	// set PINB2 as input for the push button
	DDRB &= ~(1<<PIND2);
}

ST_externalInterrupt_t exi_0 = {.source = EXI_INT0, .edge = EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE};

void main(void)
{
	sei();
	ConfigureTimer();
	ConfugureIOPins();
	EXI_interrupt_init(&exi_0);

	uint8_t retMelody = 0;
	uint8_t ButtonState = 0;

    while (1)
    {
    	ButtonState = READ_BIT(PIND, PIND2);
    	if(ButtonState == 1)
    		retMelody = PlayMelody(gActMelody);
    	else if(ButtonState == 0)
    		TMR1_SET_OCR1A_VALUE(0);
    }
}
