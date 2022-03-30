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

// Initialize timer 1: fast PWM at pin PORTB.6 (hundredth ms)
inline void timer1Init( void )
{
	OCR1A = 0x003F;					// 
	OCR1B = 0x03FF;					// 
	TCCR1A = 0b01101011;		// compare output OC1A,OC1B,OC1C
	TCCR1B = 0b00011011;		// fast PWM 8 bit, prescaler=64, RUN
}

int main(void)
{
	US_init();
		DDRB = 0xFF;					// set PORTB for compare output 
	DDRA = 0xFF;					// set PORTA for output in main program
	timer1Init();
	
	
	while(1)
	{

		/*Calculate width of Echo by Input Capture (ICP) */
		/* 8MHz Timer freq, sound speed =343 m/s */
		
		wait(10000);
		
		PORTB ^= BIT(5);
			// toggle bit 7 PORTA
		
		
	}
}