/*
 * 4 bit button counter.c
 *
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x0;
	DDRB = 0xf;
	
	unsigned char counter = 0;
	
    while (1) 
    {
		unsigned char input = PINA;
		
		if(input & 0x1){
			counter++;
			if(counter > 15)counter = 0;
			PORTB = counter ;
			
			input = PINA;
			
			while(input & 0x1){
				input = PINA;
			}
		}
    }
}

