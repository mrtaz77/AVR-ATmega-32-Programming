/*
 * Display V.c
 */ 

#define F_CPU 1000000
#define SIZE 8
#define DELAY 1

#include <avr/io.h>
#include <util/delay.h>
unsigned char params= 0b10000000;

unsigned char pattern_V[SIZE] = { 
	0b10000010, 
	0b10000010, 
	0b10000010, 
	0b10000010, 
	0b10000010, 
	0b01000100, 
	0b00101000, 
	0b00010000
};

void drawPattern_V(){
	for(int i=0; i<50; i++){
		PORTA = params;
		for (int i=0; i<SIZE; i++){
			PORTD = (~pattern_V[i]);
			_delay_ms(DELAY);
			PORTA = PORTA>>1;
			if (!PORTA)
			{
				PORTA = 0b10000000;
			}
		}
	}
}

void slidingRight() {
	for(int i=0; i<SIZE; i++)pattern_V[i] = ((pattern_V[i] & 0x80) >> 7) | (pattern_V[i] << 1);
}

void slidingLeft() {
	for(int i=0; i<SIZE; i++)pattern_V[i] = ((pattern_V[i] & 0x1) << 7) | (pattern_V[i] >> 1);
}

void flash(){
	PORTA = 0;
	for(int i=0; i<50; i++){
		for (int i=0; i<SIZE; i++){
			PORTD = (~pattern_V[i]);
			_delay_ms(DELAY);
		}
	}
}

void slidingDown(){
	params = params >> 1;
	if(!params){
		params = 0b10000000;
	}
}

void slidingUp(){
	params = params << 1;
	if(!(params & 0xff)){
		params = 0b00000001;
	}
}

void rotatePatternClockwise() {
	unsigned char temp[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = pattern_V[i];
	}

	for (int i = 0; i < SIZE; i++) {
		pattern_V[i] = 0;
		for (int j = 0; j < SIZE; j++) {
			pattern_V[i] |= ((temp[j] >> (SIZE - 1 - i)) & 1) << j;
		}
	}
}

void rotatePatternAntiClockwise() {
	unsigned char temp[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = pattern_V[i];
	}

	for (int i = 0; i < SIZE; i++) {
		pattern_V[i] = 0;
		for (int j = 0; j < SIZE; j++) {
			pattern_V[i] |= ((temp[SIZE - 1 - j] >> i) & 1) << j;
		}
	}
}


int main(void)
{
	DDRA = 0xFF;
	DDRD = 0xFF;
	
	while (1) {
		drawPattern_V(); // needed for all functions
		//slidingDown();
		//slidingUp();
		//flash();
		//slidingRight();
		//slidingLeft();
		//rotatePatternClockwise();
		//rotatePatternAntiClockwise();
	}
}

