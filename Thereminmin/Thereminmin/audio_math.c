/*
 * audio_math.c
 *
 * Created: 29/03/2022 12:34:37
 *  Author: ZimonIsHim
 */ 

char get_musical_value(double distance) {
	int notes_to_increment;
	
	if (distance > 50) { // If distance greater than 50 we return silence.
		return (char)0;
	} else {
		notes_to_increment = distance / (50 / 12);
		
		switch(notes_to_increment) {
			case 0:
			noteToPlay = "A";
			break;
			case 1:
			noteToPlay = "A#";
			break;
			case 2:
			noteToPlay = "B";
			break;
			case 3:
			noteToPlay = "C";
			break;
			case 4:
			noteToPlay = "C#";
			break;
			case 5:
			noteToPlay = "D";
			break;
			case 6:
			noteToPlay = "D#";
			break;
			case 7:
			noteToPlay = "E";
			break;
			case 8:
			noteToPlay = "F";
			break;
			case 9:
			noteToPlay = "F#";
			break;
			case 10:
			noteToPlay = "G";
			break;
			case 11:
			noteToPlay = "G#";
			break;
			case 12:
			noteToPlay = "A";
			break;
		}
	}
	
	return (char)(140 - 10 * notes_to_increment);
}