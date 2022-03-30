#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "audio_math.h"
#include "buzzer.h"
#include "lcd.h"
#include "common.h"
#define INTERVAL  		2273

#define BIT(x)			(1 << (x))

double distance;
const char *noteToPlay;

void display_distance_on_lcd() {
	char string[10];
	dtostrf(distance, 2, 2, string);/* distance to string */
	
	strcat(string, " cm ");	/* Concat unit i.e.cm */
	LCD_clear();
	LCD_display_text(string);
	strcpy(string, "note: ");
	strcat(string, noteToPlay);
	LCD_set_cursor(40);
	LCD_display_text(string);
}

int main(void)
{
	LCD_init();
	US_init();
	BUZZER_init();

	while(1)
	{
		
		US_trigger();
		COMMON_wait(250);
		display_distance_on_lcd();
		BUZZER_change_frequency(AUDIO_MATH_get_musical_value(distance));
		
	}
}