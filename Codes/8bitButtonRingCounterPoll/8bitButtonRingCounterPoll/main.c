/*
 * 8bitButtonRingCounterPoll.c
 *
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char counter = 0x1;
	unsigned char input;
	DDRA = 0xff;
	DDRD = 0x0;
	PORTA = counter;
    /* Replace with your application code */
    while (1) 
    {
		input = PIND;
		if(!(input & (0x1<<2))){
			if(counter == 0x80) counter = 1;
			else counter = counter << 1;
			PORTA = counter;
			while(!(input & (0x1<<2))){
				input = PIND;
			}
		}
    }
}

