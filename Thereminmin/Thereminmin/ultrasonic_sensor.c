/*
 * ultrasonic_sensor.c
 *
 * Created: 29/03/2022 14:43:49
 *  Author: stijn
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#define  TRIGGER_PIN	0	// Trigger pin 
#define  ECHO_PIN	7	// Echo pin 
#define TICK_CM 58.0

char ticksOnTrigger = 0;
double distance = 0; //extern



//This intterupt triggers after an overflow
ISR(TIMER2_OVF_vect) {
	TCNT2 = 0; // reset the timer after an overflow
}

ISR ( INT7_vect ) {
	// 
	if(PINE & (1 << ECHO_PIN)) {
		ticksOnTrigger = TCNT2; //get the amount of ticks at the start of the echo
	} else {
		unsigned char diff = TCNT2 - ticksOnTrigger;        // Getting the difference from timer and start
		distance = ( diff * ( 32.0 / TICK_CM ) );    // distance calculation
		ticksOnTrigger = 0; // resetting the ticks since calculation echo was detected
	}
}

void US_init_pins() {
	EICRB |= 0x40;			// any logical change on INT7 generates an interrupt request
	EIMSK |= 0x80;			// Enable INT7
	
	DDRE |= (1 << TRIGGER_PIN); // PORTE TRIGGER_PIN to output
	DDRE &= ~(1 << ECHO_PIN); // PORTE ECHO_PIN to input
}

void timer_init() {
	TCNT2 = 0;	// Clear Timer counter 
	TIMSK |= 0b01000000; // Enables overflow interrupt for timer 2.
	TCCR2 = 0b00001100; // Timer mode of operation: pwm phase correct, prescaler: 256
	sei();			// Enable global interrupt 
}


void US_trigger() {
	/* Give 10us trigger pulse on trig. pin to HC-SR04 */
	PORTE |= (1 << TRIGGER_PIN);
	_delay_us(10);
	PORTE &= ~(1 << TRIGGER_PIN);
}

//initialize the ultrasonic sensor
void US_init() {
	timer_init();
	US_init_pins();
}