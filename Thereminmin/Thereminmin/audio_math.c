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
	
	int value_to_return = 0;
	
	switch(notes_to_increment) {
		case 0:
		value_to_return = 140;
		break;
		case 1:
		value_to_return = 130;
		break;
		case 2:
		value_to_return = 120;
		break;
		case 3:
		value_to_return = 110;
		break;
		case 4:
		value_to_return = 100;
		break;
		case 5:
		value_to_return = 90;
		break;
		case 6:
		value_to_return = 80;
		break;
		case 7:
		value_to_return = 70;
		break;
		case 8:
		value_to_return = 60;
		break;
		case 9:
		value_to_return = 50;
		break;
		case 10:
		value_to_return = 40;
		break;
		case 11:
		value_to_return = 30;
		break;
		case 12:
		value_to_return = 20;
		break;
	}
	
	return value_to_return;
	
	// return (char)(140 - 10 * notes_to_increment); // Old calculation (inaccurate).
}