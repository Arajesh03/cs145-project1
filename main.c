/*
 * GccApplication1.c
 *
 * Created: 4/20/2025 4:06:14 PM
 * Author : Phil & Ami
 */ 

#include <avr/io.h>
#include "avr.h"

#define LED_PIN PB0
#define BUTTON_PIN PB1


void
avr_wait(unsigned short msec) 
{
	TCCR0 = 3;
	while (msec--) {
		TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
		SET_BIT(TIFR, TOV0);
		while(!GET_BIT(TIFR, TOV0));
	}
	TCCR0 = 0;
}


int main(void)
{
    /* Replace with your application code */
	DDRB |= (1 << LED_PIN);
	DDRB &=~ (1 << BUTTON_PIN);
	PORTB |= (1 << BUTTON_PIN);
    while (1) 
    {
		if (!(PINB & (1 << BUTTON_PIN))) {
			SET_BIT(PORTB, LED_PIN);
			avr_wait(500);
			CLR_BIT(PORTB, LED_PIN);
			avr_wait(500);
		} 
		else {
				CLR_BIT(PORTB, LED_PIN);
		}
	}
	return 0;
		
}

