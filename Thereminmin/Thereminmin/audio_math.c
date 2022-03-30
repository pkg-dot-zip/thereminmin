/*
 * audio_math.c
 *
 * Created: 29/03/2022 12:34:37
 *  Author: ZimonIsHim
 */ 

static double get_pow(double value);
int get_note(int note, int octave);

char get_musical_value(double distance) {
	if (distance > 50) { // If distance greater than 50 we return silence.
		return (char)0;
	}
	
	int notes_to_increment = distance / (50 / 12);
	return (char)(140 - 10 * notes_to_increment);
}

/*
Frequencies are calculated using the following formula: 2^N/12 * 440.
Where:
* N: The amount of halfsteps/semitones compared to the note A4.
* 12: The amount of halfsteps in an octave (12 halfsteps/semitones).
* 440: The frequency in Hertz of the note A4.
*/
int get_note(int note, int octave) {
	double noteFrequency;
	int halfStepDifference = 0; // A is 0, C is -9, A# is 1, B is 2 etc..
	
	 //Formulas used to calculate the frequency.
	 halfStepDifference += (octave - 4) * 12;
	 noteFrequency = get_pow(halfStepDifference / 12.0) * 440.0;
	 return noteFrequency;
}

static double get_pow(double value) {
	return value * value;
}