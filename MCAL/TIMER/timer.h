#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../StdTypes.h"
#include "../MemoryMap.h"

#define TMR1_CTC_OCR1A_MODE		1

#define TMR1_NO_CLOCK_SOURCE   0X00
#define TMR1_1_PRESCALER       0X01
#define TMR1_8_PRESCALER       0X02
#define TMR1_64_PRESCALER      0X03
#define TMR1_256_PRESCALER     0X04
#define TMR1_1024_PRESCALER    0X05

#define TMR1_SET_TCNT1_VALUE(_VAL)              	(TCNT1 = _VAL)
#define TMR1_SET_OCR1A_VALUE(_VAL)              	(OCR1A = _VAL)
#define TMR1_SET_MOOD(_MOOD)               			(TCCR1B |= (_MOOD<<3))
#define TMR1_SET_PRESCALER(_PRESCALER)              (TCCR1B |= _PRESCALER)
#define TMR1_SET_COMPARE_MATCH(_COM)              	(TCCR1A |= (_COM<<6))

void ConfigureTimer();

#endif /* MCAL_TIMER_TIMER_H_ */
