
/*
 * Buzzer.c
 *
 * Created: 30/03/2022 11:33:32
 *  Author: stijn
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>

// Initialize timer 1: fast PWM at pin PORTB.5
void BUZZER_init( void )
{
	DDRB = 0xFF;					// set PORTB for compare output
	OCR1A = 140;					// sets the top value of Timer 1 to 140
	TCCR1A = 0b01101011;		// sets timer 1 to: compare output OC1A,OC1B,OC1C
	TCCR1B = 0b00011011;		// sets timer 1 to:fast PWM 8 bit, prescaler=64, RUN
}

void BUZZER_change_frequency(char frequency) {
	OCR1A = frequency; //changes the top value of the timer which causes a shift in pwm value
}