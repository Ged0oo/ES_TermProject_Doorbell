#ifndef __BUZZER_H__
#define __BUZZER_H__


#include "Melody.h"
#include "../../MCAL/StdTypes.h"
#include "../../MCAL/MemoryMap.h"
#include "../../MCAL/TIMER/timer.h"


#define F_CPU	8000000UL
#define TMR1_PRESCALE  (64*2)


#define LAST_MELODY	  20


#define NOTE_C_SHARP   ((F_CPU/277.18)/TMR1_PRESCALE)            // 277.18Hz
#define NOTE_D_SHARP   ((F_CPU/311.13)/TMR1_PRESCALE)            // 311.13 Hz
#define NOTE_F_SHARP   ((F_CPU/369.99)/TMR1_PRESCALE)            // 369.99 Hz
#define NOTE_G_SHARP   ((F_CPU/415.30)/TMR1_PRESCALE)            // 415.30 Hz
#define NOTE_A_SHARP   ((F_CPU/466.16)/TMR1_PRESCALE)            // 466.16 Hz


#define NOTE_C         ((F_CPU/261.63)/TMR1_PRESCALE)            // 261.63 Hz
#define NOTE_D         ((F_CPU/293.66)/TMR1_PRESCALE)            // 293.66 Hz
#define NOTE_E         ((F_CPU/329.63)/TMR1_PRESCALE)            // 329.63 Hz
#define NOTE_F         ((F_CPU/349.23)/TMR1_PRESCALE)            // 349.23 Hz
#define NOTE_G         ((F_CPU/392.00)/TMR1_PRESCALE)            // 392.00 Hz
#define NOTE_A         ((F_CPU/440.00)/TMR1_PRESCALE)            // 440.00 Hz
#define NOTE_B         ((F_CPU/493.88)/TMR1_PRESCALE)            // 493.88 Hz
#define NOTE_P   	   0


uint8 PlayMelody(uint8 Melody_ID);
void PlayNote(uint8 note, uint8 octave, uint16 duration);
uint8 GetByteFromData(uint8 index);


#endif //__BUZZER_H__
