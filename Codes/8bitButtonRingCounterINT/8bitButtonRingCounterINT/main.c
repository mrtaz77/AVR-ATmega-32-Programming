/*
 * 8bitButtonRingCounterPoll.c
 *
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned volatile char counter = 0x1;
unsigned volatile char input;


ISR(INT0_vect){
	input = PIND;
	if(!(input & 0x4)){
		if(counter == 0x80)counter = 1;
		else counter = counter << 1;
		PORTA = counter;
	}
}


int main(void)
{
	DDRA = 0xff;
	DDRD = 0x0;
	PORTA = counter;
	MCUCR = 1<<ISC00;
	GICR = 1<<INT0;
	sei();
    /* Replace with your application code */
    while (1);
}

