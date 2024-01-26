/*
 * GccApplication1.c
 *
 * Created: 1/21/2024 2:23:51 AM
 * Author : LENOVO
 */ 

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
      c =  c + 1;
      if(c>16){c=0;}
      PORTA=c;
	  
      _delay_ms(500);
    }
    else if(dec & 0x01){
      c = c-1;
      if(c<0){c=0;}
      PORTA=c;
      _delay_ms(500);
    }
    
    }
}