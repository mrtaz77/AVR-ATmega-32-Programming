#include <avr/io.h>
#define F_CPU 1000000 // Clock Frequency
#include <util/delay.h>



int main(void)
{
	unsigned char c=0,inc=0,dec=0;
	DDRA=0xFF;
	DDRB=0x00;
	DDRD=0x00;
	
	PORTA=c;
	/* Replace with your application code */
	while (1)
	{
		inc=PINB;
		dec=PIND;
		
		if(inc & 0x01){
			if(c < 15)c =  c + 1;
			else c = 0;
			PORTA = c;
			_delay_ms(500); // DEBOUNCE_DELAY needed for hardware implementation
			while(PINB & 0x01); // polling
		}
		else if(dec & 0x01){
			if(c > 0)c = c - 1;
			else c = 15;
			PORTA=c;
			_delay_ms(500); // DEBOUNCE_DELAY needed for hardware implementation
			while(PIND & 0x01); // polling
		}
	}
}