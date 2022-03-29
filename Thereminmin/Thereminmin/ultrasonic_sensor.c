/*
 * ultrasonic_sensor.c
 *
 * Created: 29/03/2022 14:43:49
 *  Author: stijn
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#define  TRIGGER_PIN	0	/* Trigger pin */
#define  ECHO_PIN	7	/* Echo pin */
#define TICK_CM 58.0

char ticksOnTrigger = 0;
double distance = 0;

void wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

ISR(TIMER2_OVF_vect)
{
	TCNT2 = 0;
}

ISR ( INT7_vect )
{
	// Setting the time from the timer on PE7 going high
	if(PINE & (1 << ECHO_PIN)) {
		ticksOnTrigger = TCNT2;
	}
	else
	{
		unsigned char diff = TCNT2 - ticksOnTrigger;        // Getting the difference from timer and start

		distance = ( diff * ( 32.0 / TICK_CM ) );    // Calculating cm


		ticksOnTrigger = 0;                                    // resetting ticksOnTrigger
	}
}

void US_init_pins() {
	DDRD = 0xFF;
	
	EICRB |= 0x40;			//
	EIMSK |= 0x80;			// Enable INT7
	
	DDRE |= (1 << TRIGGER_PIN);
	DDRE &= ~(1 << ECHO_PIN);
}

void Timer_init() {
	TCNT2 = 0;	/* Clear Timer counter */
	TIMSK |= 0b01000000; /* Enables overflow interrupt for timer 2, TOV2 bit is set in the Timer/Counter Interrupt Flag Register – TIFR. */
	TCCR2 = 0b00001100;
	sei();			/* Enable global interrupt */
}

void US_trigger() {
	/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	PORTE |= (1 << TRIGGER_PIN);
	_delay_us(10);
	PORTE &= ~(1 << TRIGGER_PIN);
}

void US_init() {
	Timer_init();
	lcd_init();
	lcd_clear();
	US_init_pins();
}