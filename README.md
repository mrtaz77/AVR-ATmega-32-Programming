# AVR-ATmega-32-Programming
Codes for ATmega32
- [Tools](#tools)
- [Experiments](#experiments)
- [Practices](#practice)

## Tools
1. Atmel Studio 7.0 . Download [link](https://www.microchip.com/en-us/tools-resources/archives/avr-sam-mcus)
2. Proteus Version 8.15. Download [link](https://engineeringsoftware.net/electronics/proteus-8-15-full-crack/).

## Experiments 
- **Experiment 1**
	- [Spec](/Codes/Exp1_UnitCounter/MC%20Experiment%201.pdf)
	- [Code](/Codes/Exp1_UnitCounter/Exp1_UnitCounter/main.cpp)

- **Experiment 2**
	- [Spec](/Codes/Exp%202_DisplayV/MC%20Experiment%202.pdf)
	- [Code](/Codes/Exp%202_DisplayV/Display%20V/Display%20V/main.c)
	- [README of implementation details](/Codes/Exp%202_DisplayV/README.md)

- **Experiment 3**
	- [Spec](/Codes/Exp%203_ADC/MC%20Experiment%203.pdf)
	- [Code](/Codes/Exp%203_ADC/ADC/main.c)
	- [Header file used for 16 * 2 LCD](/Codes/Exp%203_ADC/ADC/lcd.h)

## Practice
|#|Code|Description|
|-----|----|-----------|
|1| [4-bit Delay Counter](/Codes/4%20bit%20counter/4%20bit%20counter/main.c)     | A 4 bit counter which increments every 1 second |
|2| [4-bit Button Counter](/Codes/4%20bit%20button%20counter/4%20bit%20button%20counter/main.c)   |A 4 bit counter which increments every time the switch is turned on|
|3| [Blinking LEDS](/Codes/Blinking%20LEDS/Blinking%20LEDS/main.c)| LEDS connected to port B blink sequentially  |
|4| [8bitButtonRingCounterINT](/Codes/8bitButtonRingCounterINT/8bitButtonRingCounterINT/main.c) |An 8 bit ring counter; switch using interrupt|
|5| [8bitButtonRingCounterPoll](/Codes/8bitButtonRingCounterPoll/8bitButtonRingCounterPoll/main.c) |An 8 bit ring counter; switch using polling|