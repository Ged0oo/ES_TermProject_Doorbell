#include "EXI.h"

extern uint8 gActMelody;

void ConfigureExternalInterrupt()
{
    // Set INT0/PD2 as input
    DDRD &= ~(1 << DDD2);

    // Enable INT0
    GICR |= (1 << INT0);

    // Trigger INT0 on falling edge
    MCUCR |= (1 << ISC01);
}

ISR(INT0_vect)
{
	gActMelody++;
}
