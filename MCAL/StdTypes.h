#ifndef STDTYPES_H_
#define STDTYPES_H_
#include <stdlib.h>

/************************************************************************/
/*                   section: data type declaration                     */
/************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


typedef		unsigned char			uint8;
typedef		unsigned short			uint16;
typedef		unsigned int			uint32;

typedef		signed char				sint8;
typedef		signed short			sint16;
typedef		signed int				sint32;

typedef		uint8				Std_ReturnType;


#define		ZERO_INIT				0

#define		E_OK					1
#define		E_NOT_OK				0

/*					section: macro declaration					*/
#define			MASK_PIN			1

/*					section: macro function declaration					*/
#define			SET_BIT(_REG,PIN)			(_REG = _REG | (MASK_PIN<<PIN))
#define			CLEAR_BIT(_REG,PIN)			(_REG = _REG & (~(MASK_PIN<<PIN)))
#define			TOGGLE_BIT(_REG,PIN)		(_REG = _REG ^ (MASK_PIN<<PIN))
#define			READ_BIT(_REG,PIN)			((_REG>>PIN)  & MASK_PIN)


#endif /* STDTYPES_H_ */
