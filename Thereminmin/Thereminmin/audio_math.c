/*
 * audio_math.c
 *
 * Created: 29/03/2022 12:34:37
 *  Author: ZimonIsHim
 */ 

char get_musical_value(double distance) {
	if (distance > 50) { // If distance greater than 50 we return silence.
		return (char)0;
	}
	
	int notes_to_increment = distance / (50 / 12);
	
	return (char)(140 - 10 * notes_to_increment);
}