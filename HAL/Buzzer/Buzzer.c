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


//PinkPanther
const unsigned char    Melody001[54] = {40,8,164,8,165,2,160,8,167,8,168,2,160,8,164,8,165,16,160,8,167,8,168,16,160,8,193,8,172,16,160,8,164,8,165,16,160,8,172,2,171,2,160,16,170,16,168,16,165,16,163,2,165,0};
//AxelF
const unsigned char    Melody002[48] = {40,4,167,136,170,8,167,16,167,8,172,8,167,8,165,4,167,136,194,8,167,16,167,8,195,8,194,8,170,8,167,8,194,8,199,16,167,8,165,16,165,8,162,8,169,132,167,0};
//Dallas
const unsigned char    Melody003[70] = {31,8,165,132,170,8,165,132,197,8,170,4,194,8,172,8,194,4,170,4,165,4,170,4,199,4,197,8,194,8,195,130,197,8,160,8,165,4,170,4,199,4,197,8,194,8,195,4,197,8,172,8,194,4,170,4,165,4,170,8,194,8,195,132,172,8,170,2,170,0};
//Szimszonék :)
const unsigned char    Melody004[48] = {40,132,193,4,197,4,199,8,202,132,200,4,197,4,193,8,170,8,167,8,167,8,167,2,168,8,160,8,160,8,167,8,167,8,167,8,168,132,171,8,193,8,193,8,193,4,193,0};
//Agadoo
const unsigned char    Melody005[54] = {31,8,172,8,169,4,165,8,165,8,165,4,165,8,165,8,165,8,165,8,165,8,164,8,165,4,167,8,170,8,167,4,164,8,164,8,164,4,164,8,164,8,164,8,164,8,164,8,162,8,164,8,165,0};
//Adams
const unsigned char    Melody006[56] = {40,8,161,4,166,8,170,4,166,8,161,4,140,2,168,8,166,4,165,8,168,4,165,8,133,4,138,2,166,8,161,4,166,8,170,4,166,8,161,4,140,2,168,8,166,4,165,8,161,4,163,8,165,1,166,0};
//PacMan
const unsigned char    Melody007[106] = {28,32,140,32,128,32,172,32,128,32,167,32,128,32,164,32,128,32,172,32,167,16,128,16,164,16,128,32,161,32,128,32,193,32,128,32,168,32,128,32,165,32,128,32,193,32,168,16,128,16,165,16,128,32,140,32,128,32,172,32,128,32,167,32,128,32,164,32,128,32,172,32,167,16,128,16,164,16,128,32,164,32,165,32,166,32,128,32,166,32,167,32,168,32,128,32,168,32,169,32,170,32,128,160,172,0};
//FunkyTown
const unsigned char    Melody008[52] = {31,8,193,8,193,8,171,8,193,8,128,8,168,8,128,8,168,8,193,8,198,8,197,8,193,2,128,8,193,8,193,8,171,8,193,8,128,8,168,8,128,8,168,8,193,8,198,8,197,8,193,0};
//Indiana
const unsigned char    Melody009[112] = {62,4,165,8,160,8,166,8,168,8,160,1,193,136,160,4,163,8,160,8,165,1,166,132,160,4,168,8,160,8,170,8,172,8,160,1,198,4,160,4,170,8,160,8,172,2,193,2,195,2,197,4,165,8,160,8,166,8,168,8,160,1,193,4,160,4,195,8,160,8,197,129,198,4,168,8,160,8,168,132,197,8,160,4,195,8,160,8,168,132,197,8,160,4,195,8,160,8,168,132,198,8,160,4,197,8,160,8,195,2,193,0};
//Looney
const unsigned char    Melody010[54] = {35,4,193,8,198,8,197,8,195,8,193,132,170,8,193,8,198,8,197,8,195,8,196,132,197,8,197,8,197,8,193,8,195,8,193,8,197,8,193,8,195,8,170,8,193,8,168,8,171,8,170,8,166,0};
//Monty Pyton
const unsigned char    Melody011[118] = {50,4,198,8,197,4,195,8,194,4,193,8,172,4,171,8,170,8,168,8,170,8,171,4,170,8,168,2,193,8,160,8,193,8,170,8,160,8,170,8,170,8,169,8,170,8,198,8,160,8,193,8,193,8,160,8,170,8,171,8,160,8,171,8,171,8,160,8,193,2,195,8,160,8,171,8,168,8,160,8,168,8,168,8,167,8,168,8,197,8,160,8,195,8,195,8,160,8,171,8,170,8,160,8,170,8,170,8,160,8,171,2,193,8,160,0};
//Popey
const unsigned char    Melody012[72] = {40,8,170,8,193,8,193,8,193,4,171,8,170,4,193,2,192,8,193,8,195,8,171,8,195,4,198,8,195,2,193,8,192,8,193,8,195,8,171,8,195,8,198,8,197,8,195,8,193,8,195,8,193,8,170,8,166,8,170,8,193,8,195,8,193,4,171,8,168,2,166,0};
//Popcorn
const unsigned char    Melody013[64] = {40,8,193,8,171,8,193,8,168,8,164,8,168,4,161,8,193,8,171,8,193,8,168,8,164,8,168,4,161,8,193,8,195,8,196,16,193,8,196,16,193,8,196,8,195,16,171,8,195,16,171,8,195,8,193,8,171,8,168,8,171,4,193,0};
//Star trek
const unsigned char    Melody014[18] = {16,136,166,16,171,132,196,8,195,144,171,144,168,144,193,4,198,0};
//Piccolo
const unsigned char    Melody015[68] = {80,4,195,4,200,4,168,4,200,8,195,8,197,8,195,8,172,4,168,4,163,8,168,8,170,8,172,8,193,4,195,4,200,1,195,4,195,4,200,4,168,4,200,8,195,8,197,8,172,4,168,4,163,8,166,8,168,8,170,8,172,4,193,4,198,1,193,0};
//A team (Szuper csapat)
const unsigned char    Melody016[42] = {40,4,196,8,171,2,196,16,160,8,169,4,171,132,164,8,160,16,168,16,171,8,196,8,171,8,198,2,196,16,160,136,194,16,193,16,171,136,169,2,171,0};
//Bond
const unsigned char    Melody017[76] = {80,4,161,8,163,8,163,4,163,2,163,4,161,4,161,4,161,4,161,8,164,8,164,4,164,2,164,4,163,4,163,4,163,4,161,8,163,8,163,4,163,2,163,4,161,4,161,4,161,4,161,8,164,8,164,4,164,2,164,4,163,4,162,4,161,4,193,129,172,4,168,4,166,129,168,0};
//Knight Rider
const unsigned char    Melody018[62] = {15,16,165,32,166,32,165,8,172,16,197,32,198,32,197,8,172,16,165,32,166,32,165,16,172,16,197,4,195,8,160,4,160,16,165,32,166,32,165,8,172,16,197,32,198,32,197,8,172,16,165,32,166,32,165,16,172,16,197,4,198,0};
//Smurfs (Hupikék törpikék)
const unsigned char    Melody019[64] = {25,4,193,4,198,16,193,8,195,8,171,4,168,32,160,4,193,16,170,8,166,8,170,4,168,16,160,32,168,32,169,32,170,32,171,32,172,4,193,32,160,4,198,16,193,8,195,8,171,4,168,32,160,4,193,16,170,8,171,8,165,4,166,0};
//Benny Hill
const unsigned char    Melody020[96] = {31,136,195,16,197,8,200,8,200,16,197,16,195,16,170,16,172,16,195,16,172,8,197,16,195,16,172,16,170,16,172,8,170,16,170,16,171,16,172,16,195,16,197,16,195,4,200,8,192,16,195,16,197,16,195,8,200,8,200,16,197,16,195,16,170,16,172,16,195,16,172,8,197,16,195,16,172,16,170,16,172,8,195,16,195,16,195,16,199,16,202,8,198,4,195,0};


volatile uint8 gOctave = 0;
volatile uint8 gTempo;
volatile uint8 gActMelody;
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

	// might suggest to be a rest ?!
	volatile uint8 van_nyujt = 0;

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
	van_nyujt = ch & 0b10000000;

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
		TCNT1 = 0;

		// sets the Output Compare Register (OCR1A) to the value of note
		// OCR1A value determines the frequency of the waveform generated by Timer1.
		OCR1A = note;

		// This sets the Timer/Counter1 Control Register A (TCCR1A)
		// to enable the Toggle Compare Match (COM1A0) bit.
		TCCR1A = (0 << COM1A1) | (1 << COM1A0);

		// introduces a delay of adur milliseconds, representing
		// the duration for which the musical note should be played.
		_delay_ms(adur);

		// After the delay, this turns off the PWM signal
		// generation by clearing the TCCR1A register.
		TCCR1A = 0x00;
	}
}


uint8 GetByteFromData(uint8 index)
{
	switch (gActMelody)
	{
		case 0: return  pgm_read_byte(Melody001+index); break;
		case 1: return  pgm_read_byte(Melody002+index); break;
		case 2: return  pgm_read_byte(Melody003+index); break;
		case 3: return  pgm_read_byte(Melody004+index); break;
		case 4: return  pgm_read_byte(Melody005+index); break;
		case 5: return  pgm_read_byte(Melody006+index); break;
		case 6: return  pgm_read_byte(Melody007+index); break;
		case 7: return  pgm_read_byte(Melody008+index); break;
		case 8: return  pgm_read_byte(Melody009+index); break;
		case 9: return  pgm_read_byte(Melody010+index); break;
		case 10: return pgm_read_byte(Melody011+index); break;
		case 11: return pgm_read_byte(Melody012+index); break;
		case 12: return pgm_read_byte(Melody013+index); break;
		case 13: return pgm_read_byte(Melody014+index); break;
		case 14: return pgm_read_byte(Melody015+index); break;
		case 15: return pgm_read_byte(Melody016+index); break;
		case 16: return pgm_read_byte(Melody017+index); break;
		case 17: return pgm_read_byte(Melody018+index); break;
		case 18: return pgm_read_byte(Melody019+index); break;
		case 19: return pgm_read_byte(Melody020+index); break;
		default: break;
	}
	return 0;

}




