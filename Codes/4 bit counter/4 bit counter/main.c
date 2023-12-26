/*
 * 4 bit counter.c
 *
 */ 

#define F_CPU 1000000 // Clock Frequency

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xF ;
	unsigned char counter = 0 ;
    /* Replace with your application code */
    while (1) {
		counter++;
		if(counter > 15) counter = 0;
		PORTB = counter ;
		_delay_ms(1000) ;
    }
}

