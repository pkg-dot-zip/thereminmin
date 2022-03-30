/*
 * audio_math.c
 *
 * Created: 29/03/2022 12:34:37
 *  Author: ZimonIsHim
 */ 

const char *noteToPlay; // extern from headerfile

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
	
	int value_to_return = 0;
	
	switch(notes_to_increment) {
		case 0: // A
		value_to_return = 140;
		break;
		case 1: // A#
		value_to_return = 133;
		break;
		case 2: // B
		value_to_return = 125;
		break;
		case 3: // C
		value_to_return = 118;
		break;
		case 4: // C#
		value_to_return = 111;
		break;
		case 5: // D
		value_to_return = 103;
		break;
		case 6: // D#
		value_to_return = 99;
		break;
		case 7: // E
		value_to_return = 93;
		break;
		case 8: // F
		value_to_return = 89;
		break;
		case 9: // F#
		value_to_return = 84;
		break;
		case 10: // G
		value_to_return = 78;
		break;
		case 11: // G#
		value_to_return = 74;
		break;
		case 12: // A
		value_to_return = 70;
		break;
	}
	
	return value_to_return;
	
	// return (char)(140 - 10 * notes_to_increment); // Old calculation (inaccurate).
}