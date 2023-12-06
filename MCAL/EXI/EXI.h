#ifndef MCAL_EXI_EXI_H_
#define MCAL_EXI_EXI_H_

#include "../StdTypes.h"
#include "../MemoryMap.h"

#define EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL			0x00
#define EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL			0x01
#define EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x02
#define EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE			0x03

#define EXI_INT1_GENERATE_INTERRUPT_AT_LOW_LEVEL			0x00
#define EXI_INT1_GENERATE_INTERRUPT_AT_HIGH_LEVEL			0x01
#define EXI_INT1_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x02
#define EXI_INT1_GENERATE_INTERRUPT_AT_RISING_EDGE			0x03

#define EXI_INT2_GENERATE_INTERRUPT_AT_RISING_EDGE			0x01
#define EXI_INT2_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x00


#define EXI_INT0_SET_EDGE(EDGE)								(MCUCR  |= EDGE)
#define EXI_INT1_SET_EDGE(EDGE)								(MCUCR  |= (EDGE<<2))
#define EXI_INT2_SET_EDGE(EDGE)								(MCUCSR |= (EDGE<<6))


typedef enum
{
	EXI_INT0,
	EXI_INT1,
	EXI_INT2
}EN_externalInterruptSource_t;


typedef struct
{
	EN_externalInterruptSource_t source;
	uint8 edge;
	void (*INT0_fpt) (void);
	void (*INT1_fpt) (void);
	void (*INT2_fpt) (void);

}ST_externalInterrupt_t;


void EXI_interrupt_init(const ST_externalInterrupt_t* interrupt);
void EXI_CallBack(const ST_externalInterrupt_t* interrupt);
void ConfigureExternalInterrupt();

#endif /* MCAL_EXI_EXI_H_ */
