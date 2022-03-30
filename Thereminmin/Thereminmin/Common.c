
/*
 * Common.c
 *
 * Created: 30/03/2022 14:43:17
 *  Author: stijn
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>

void COMMON_wait( int ms ) {
	for (int i=0; i<ms; i++) {
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}