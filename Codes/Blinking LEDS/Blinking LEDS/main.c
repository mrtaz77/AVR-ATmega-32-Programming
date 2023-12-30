/*
 * Blinking LEDS.c
 *
 */ 
#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	unsigned char blinker = 1;
	DDRB = 0xff;
    /* Replace with your application code */
    while (1) 
    {
		PORTB = blinker;
		if(blinker == 0b10000000)blinker = 1;
		else blinker = blinker << 1;
		_delay_ms(250);
    }
}

