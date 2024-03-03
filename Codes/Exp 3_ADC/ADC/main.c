#define F_CPU 1000000UL
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7


#define OUTPUT_SIZE 5 // output_size is precision+3

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

char output[OUTPUT_SIZE];

void setoutput(float f)
{
	output[0] = (((int) f)%10) + '0';
	output[1] = '.';
	for(int i=2;i<OUTPUT_SIZE-1;i++)
	{
		f *= 10.0;
		output[i] = (((int) f)%10) + '0';
	}
	f *= 10.0;
	output[OUTPUT_SIZE-1] = '\0';
}


int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	Lcd4_Init();
	
	unsigned char result_L;
	unsigned char result_H;
	DDRB = 0xFF;
	
	ADMUX = 0b00100011;   //REF 00 -> AREF (4V)  //1 -> Left Adjusted  //00011 -> ADC3 is set as (single ended) input analog signal
	ADCSRA = 0b10000100;  //1 -> ADC enable  //0 -> (Start conversion when is set 1)
	//0 -> auto trigger enable  //0 -> interrupt flag  //0 -> interrupt enable
	//100 -> ADC Prescaler bits (100 means division factor 16)
	
	Lcd4_Set_Cursor(1,0);
	Lcd4_Write_String("Voltage :");
	//float voltage=2.5;
	while(1)
	{
		
		ADCSRA |= (1 << ADSC); //Start conversion when ADSC is set to 1
		
		while (ADCSRA & (1<<ADSC)){} //Wait until conversion is completed
		
		result_L = ADCL; //data register is locked after ADCL is read
		result_H = ADCH; //data register is unlocked after ADCH is read
		
		float voltage = ((result_H<<2)|(result_L>>6))*(4.00/1024); //ADC 10 Bits //multiplying with step size
		
		setoutput(voltage);
		
		Lcd4_Set_Cursor(1,10);
		Lcd4_Write_String(output);
		_delay_ms(50);
		//voltage=voltage+0.1;
		
	}
	return 0;
}
