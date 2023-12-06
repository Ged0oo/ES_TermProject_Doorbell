#include "app.h"

ST_externalInterrupt_t exi_0 =
{
		.source = EXI_INT0,
		.edge = EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE
};


void ConfugureIOPins()
{
	// set PIND5 as output for the buzzer
	DDRD |= (1<<PIND5);

	// set PINB2 as input for the push button
	DDRB &= ~(1<<PIND2);
}

void System_Initialize()
{
	sei();
	ConfigureTimer();
	ConfugureIOPins();
	EXI_interrupt_init(&exi_0);
}
