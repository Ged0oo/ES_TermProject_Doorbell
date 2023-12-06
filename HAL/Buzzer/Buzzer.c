#include "Buzzer.h"


/*
 * Each element in the array represents a specific pitch or frequency associated with a musical note
 * used in conjunction with the note information extracted from the melody data
 * determine the pitch or frequency of the notes to be played during the melody
 */
const unsigned short Notes[] =
{
	NOTE_P,
	NOTE_C,NOTE_C_SHARP,
	NOTE_D,NOTE_D_SHARP,
	NOTE_E,
	NOTE_F,NOTE_F_SHARP,
	NOTE_G,NOTE_G_SHARP,
	NOTE_A,NOTE_A_SHARP,
	NOTE_B
};


volatile uint8 gTempo;
volatile uint8 gOctave;
extern uint8 gActMelody;


/*
 * This function is responsible for playing melody identified by Melody_ID
 * end of the melody has been reached if returned 1
 * it returns 0 if the melody doesn't end
 */
uint8 PlayMelody(uint8 Melody_ID)
{
	uint8 ChrIndex = 0x00;

	// This holds the duration of the current note
	volatile uint16 duration = 0;

	/*
	 * Represents the octave of the current note
	 * octave is the interval between one musical pitch and another with half or double its frequency
	 * It is set based on the information extracted from the melody data
	 */
	volatile uint8 octave = 0;

	/*
	 * Represents the frequency of the current note
	 * It is set based on the information extracted from the melody data
	 * The frequency is used to configure Timer1 for sound generation
	 */
	volatile uint16 note = 0;

	/*
	 * temp variable to store a byte of data retrieved from the melody
	 * It holds information about the note, including its duration,
	 * whether it's a rest, the note value, and the octave.
	 */
	volatile uint8 ch;

	// hold current melody id
	gActMelody = Melody_ID;

	// Checks if the given Melody_ID is greater than or equal to LAST_MELODY
	if (Melody_ID >= LAST_MELODY)
	{
		// if true it resets the melody, should wrap around to the beginning.
		Melody_ID = 0;

		//Resets the index to the starting position for the melody data.
		ChrIndex = 0x00;
		gActMelody = 0;
	}

	// initializing the gTempo when the melody is just starting
	if(ChrIndex == 0)
	{
		// ChrIndex is incremented to move on to the next piece of data in the melody.
		gTempo = GetByteFromData(ChrIndex++);
	}

	// ch is to store byte of data which retrieved from the melody
	ch = GetByteFromData(ChrIndex++);

	// extracting the duration of a musical note
	duration = ch & 0b00111111;

	// extracting another byte of data from the melody
	ch = GetByteFromData(ChrIndex++);

	// extracts information about the pitch then,
	// access an element from Notes which corresponds to it
	note = pgm_read_byte(Notes+(ch & 0b00001111));

	// extracts the octave information from the byte of data from melody
	octave = (ch & 0b11100000)>>5 ;

	PlayNote(note, octave, duration);

	// checks if the next byte of data in the melody sequence is 0
	if (GetByteFromData(ChrIndex) == 0)
	{
		// Resets the ChrIndex like indicating that
		// end of the melody has been reached
		ChrIndex = 0x00;
		return 1;
	}
	return 0;
}


/*
 * This function plays the musical note.
 * It adjusts the note frequency based on the octave.
 * align with the range of octaves in a musical context.
 * Octave numbering in music often starts at 1,
 * and each increase in octave number represents a doubling of frequency
 */
void PlayNote(uint8 note, uint8 octave, uint16 duration)
{
	// Changing the octave involves doubling or halving the frequency of the note
	// Shifting to a higher octave means doubling the frequency
	// Shifting to a lower octave means halving the frequency.
	switch (octave)
	{
		case 4 : break;
		case 5 : note = note>>1; break;
		case 6 : note = note>>2; break;
		case 7 : note = note>>3; break;
	}


	/*
	 * 60000 used to convert the tempo from beats per minute (BPM) to milliseconds per beat
	 * gTempo holds the tempo information.
	 * 60000 / gTempo calculates the duration of one beat in milliseconds based on the tempo
	 * The duration is typically expressed as a fraction of a whole note (e.g., quarter note, eighth note)
	 */
	uint16 adur = (60000/gTempo/duration);

	// playing a musical note based on the calculated duration (adur) and frequency (note).
	if (note == 0)
	{
		/*
		 * If note is 0, it means the musical note is a rest (no sound),
		 * and the program introduces a delay using _delay_ms(adur)
		 * This delay represents the duration of the rest.
		 */
		_delay_ms(adur);
	}
	// If note is not 0, it means there's an actual musical note to be played
	else
	{
		// resets Timer1's counter to 0.
		TMR1_SET_TCNT1_VALUE(0);

		// sets the Output Compare Register (OCR1A) to the value of note
		// OCR1A value determines the frequency of the waveform generated by Timer1.
		TMR1_SET_OCR1A_VALUE(note);

		// sets timer1 Control Register A (TCCR1A)
		// to enable the Toggle Compare Match (COM1A0) bit.
		TMR1_SET_COMPARE_MATCH(1);

		// introduces a delay of adur milliseconds, representing
		// the duration for which the musical note should be played.
		_delay_ms(adur);

		// After the delay, turn off the PWM signal
		TCCR1A = 0;
	}
}


uint8 GetByteFromData(uint8 index)
{
	switch (gActMelody)
	{
		case 1 : return  pgm_read_byte(Melody001+index); break;
		case 2 : return  pgm_read_byte(Melody002+index); break;
		case 3 : return  pgm_read_byte(Melody003+index); break;
		case 4 : return  pgm_read_byte(Melody004+index); break;
		case 5 : return  pgm_read_byte(Melody005+index); break;
		case 6 : return  pgm_read_byte(Melody006+index); break;
		case 7 : return  pgm_read_byte(Melody007+index); break;
		case 8 : return  pgm_read_byte(Melody008+index); break;
		case 9 : return  pgm_read_byte(Melody009+index); break;
		case 10: return  pgm_read_byte(Melody010+index); break;
		case 11: return  pgm_read_byte(Melody011+index); break;
		case 12: return  pgm_read_byte(Melody012+index); break;
		case 13: return  pgm_read_byte(Melody013+index); break;
		case 14: return  pgm_read_byte(Melody014+index); break;
		case 15: return  pgm_read_byte(Melody015+index); break;
		case 16: return  pgm_read_byte(Melody016+index); break;
		case 17: return  pgm_read_byte(Melody017+index); break;
		case 18: return  pgm_read_byte(Melody018+index); break;
		case 19: return  pgm_read_byte(Melody019+index); break;
		case 20: return  pgm_read_byte(Melody020+index); break;
		default: break;
	}
	return 0;
}
