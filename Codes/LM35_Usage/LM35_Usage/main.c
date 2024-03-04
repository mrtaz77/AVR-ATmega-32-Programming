/*
 * LM35_Usage.c
 *
 */ 

#include <avr/io.h>

int main(void)
{
	DDRB = 0xff;
	
	/* 
		Reference voltage = 2.56
		ADLAR = 0 so right adjusted
		single channel input from ADC.0
	*/
	
	ADMUX = 0b11000000;
	
	/*
		Enable ADC
		enable ADC interrupt
		use prescaler = 2
	*/
	ADCSRA = 0b10000001;
	
	// sei();
    /* Replace with your application code */
    while (1) 
    {
		ADCSRA |= 1 << ADSC ;
		
		while(ADCSRA & (1<<ADSC));
		
		float temp = ADC / 4.0;
		
		if(temp > 20.0) PORTB = 0xff;
		else PORTB = 0x0;
		
    }
}

