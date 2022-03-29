#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

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
		
	while(1)
	{

		/*Calculate width of Echo by Input Capture (ICP) */
		/* 8MHz Timer freq, sound speed =343 m/s */
		US_trigger();
		wait(250);
		display_distance_on_lcd();
		
	}
}