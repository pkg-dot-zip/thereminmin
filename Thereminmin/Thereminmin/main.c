#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#define INTERVAL  		2273

#define BIT(x)			(1 << (x))

double distance;


void display_distance_on_lcd() {
	char string[10];
	dtostrf(distance, 2, 2, string);/* distance to string */
	strcat(string, " cm");	/* Concat unit i.e.cm */
	lcd_clear();
	lcd_display_text(string);
}



int main(void)
{
	US_init();
	BUZZER_init();
	
	while(1)
	{
		
		US_trigger();
		wait(250);
		display_distance_on_lcd();
			// toggle bit 7 PORTA
		
		
	}
}