#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#define BIT(x)			(1 << (x))
#define  TRIGGER_PIN	0	/* Trigger pin */
#define  ECHO_PIN	7	/* Echo pin */
#define TICK_CM 58.0

int TimerOverflow = 0;
char ticksOnTrigger = 0;
int distance;

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

ISR(TIMER2_OVF_vect)
{
	TCNT2 = 0;	/* Increment Timer Overflow count */
}

ISR ( INT7_vect )
{
	// Setting the time from the timer on PE7 going high
	if( PINE & (1 << ECHO_PIN) ) {
	ticksOnTrigger = TCNT2;
	}
	else
	{
		unsigned char diff = TCNT2 - ticksOnTrigger;        // Getting the difference from timer and start

		distance = ( diff * ( 32.0 / TICK_CM ) );    // Calculating cm


		ticksOnTrigger = 0;                                    // resetting ticksOnTrigger
	}

}

void Timer_init() {
	TCNT2 = 0;	/* Clear Timer counter */
	TIMSK |= 0b01000000;	
	TCCR2 = 0b00001100;
	sei();			/* Enable global interrupt */
}

void Ultrasonic_trigger() {
		/* Give 10us trigger pulse on trig. pin to HC-SR04 */
		PORTE |= (1 << TRIGGER_PIN);
		_delay_us(10);
		PORTE &= ~(1 << TRIGGER_PIN);
}

void display_distance_on_lcd() {
	char string[10];
	dtostrf(distance, 2, 2, string);/* distance to string */
	strcat(string, " cm");	/* Concat unit i.e.cm */
	lcd_clear();
	lcd_display_text(string);
}

int main(void)
{
	
	DDRD = 0xFF;	
	
	EICRB |= 0x40;			// INT1 falling edge, INT0 rising edge
	EIMSK |= 0x80;			// Enable INT7
	
	DDRE &= ~(1 << TRIGGER_PIN);
	DDRE &= ~(1 << TRIGGER_PIN);
	
	lcd_init();
	lcd_clear();
	
	Timer_init();
		
	while(1)
	{

		/*Calculate width of Echo by Input Capture (ICP) */
		/* 8MHz Timer freq, sound speed =343 m/s */
		Ultrasonic_trigger();
		wait(250);
		display_distance_on_lcd();
		
	}
}