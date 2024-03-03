# 8 x 8 bicolor LED matrix Simulation
This project displays the pattern V. Also some variations are also available.
- [Pin Connections](#pin-connections)
- [How to display your own pattern](#how-to-display-your-own-pattern)
- [How to display your desired animation](#how-to-display-your-desired-animation)

## Pin Connections
The row and column pin conventions are according to this [spec](/Codes/Exp%202_DisplayV/MC%20Experiment%202.pdf)
### Rows 
|Row|Port-Pin|
|-|-|
| Row1 | A7 |
| Row2 | A6 |
| Row3 | A5 |
| Row4 | A4 |
| Row5 | A3 |
| Row6 | A2 |
| Row7 | A1 |
| Row8 | A0 |

<hr>

### Columns 
|<span style="color:#00ff00">Green Color</span>|Port-Pin|
|-|-|
| G1 | D7 |
| G2 | D6 |
| G3 | D5 |
| G4 | D4 |
| G5 | D3 |
| G6 | D2 |
| G7 | D1 |
| G8 | D0 |

|<span style="color:#ff0000">Red Color</span>|Port-Pin|
|-|-|
| R1 | D7 |
| R2 | D6 |
| R3 | D5 |
| R4 | D4 |
| R5 | D3 |
| R6 | D2 |
| R7 | D1 |
| R8 | D0 |

## How to display your own pattern
1. Open the [main](/Codes/Exp%202_DisplayV/Display%20V/Display%20V/main.c) using Atmel Studio 7.
2. Navigate to the **pattern_V** array 
```cpp
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
```
3. Modify the pattern to display your desired pattern !!!. \
For instance, to display 'A' use the following array
```cpp
unsigned char pattern_A[SIZE] = { 
	0b00010000, 
	0b00101000, 
	0b01000100, 
	0b11111110, 
	0b10000010, 
	0b10000010, 
	0b10000010, 
	0b10000010
};
```
where SIZE is the macro for array dimension

## How to display your desired animation
1. Open the [main](/Codes/Exp%202_DisplayV/Display%20V/Display%20V/main.c) using Atmel Studio 7.

2. Navigate to the **main** function
```cpp
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
``` 

3. The drawPattern function is needed for all animations. To only display the pattern, keep the **drawPattern** function uncommented and comment the other functions.
4. For any other animation, uncomment that function only . Also make sure that the **drawPattern** function is active.
For instance, for sliding up animation, 
```cpp
int main(void)
{
	DDRA = 0xFF;
	DDRD = 0xFF;
	
	while (1) {
		drawPattern_V(); // needed for all functions
		//slidingDown();
		slidingUp();
		//flash();
		//slidingRight();
		//slidingLeft();
		//rotatePatternClockwise();
		//rotatePatternAntiClockwise();
	}
}
```