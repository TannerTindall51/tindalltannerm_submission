//
//Design Assignment 2C - Task 1
//Tanner Tindall
//

#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	DDRB = 0xFF;							//sets DDRB to OUTPUT
	DDRC = 0x00;							//sets DDRC to INPUT
	PORTB = 0xFF;							//sets all of PORTB logic level HIGH
	TCNT0 = 0x00;							//initializes the 8 bit timer0 register to begin at 0
	TCCR0A = 0x00;							//sets the timer to "Normal" Mode by WGM00
	TCCR0B |= (1 << CS02) | (1 << CS00);	//sets prescaler value to 1024, refer to TCCROB truthTable
	int overFlow = 0;						//initializes variable to be used as counter for overflow occurrences
	
	while (1)								//primary (infinite) loop for the program
	{
		TCNT0 = 0x00;						//resetting the timer to 0 when the code loops back up
		overFlow = 0;						//resetting the counter to 0 when the code loops back up
		
		while(overFlow < 25)				//55% DutyCycle Loop (.75s = 45 therefore 55% * 45 = 25)
		{
			if(TCNT0 ==0xFF)				//once the timer reaches the max value...
			{
				TCNT0 = 0x00;				//...reset it and...
				overFlow++;					//...add to the overflow counter and begin again
			}
			
			else if(!(PINC & (1 << 3)))		//checks to see if SW3 is pressed
			{
				PORTB |= (1<<3);			//turns off LED at PB3
				PORTB &= ~(1<<2);			//turns on LED PB2
				overFlow = 0;				//reset overflow counter
				TCNT0 = 0x00;				//reset timer
				
				while(overFlow < 120)		//2s Delay Loop (1 sec = 60 therefore 2 * 60 = 120)
				{
					if(TCNT0 ==0xFF)		//once the timer reaches the max value...
					{
						TCNT0 = 0x00;		//...reset it and...
						overFlow++;			//...add to the overflow counter and begin again
					}
				}
				PORTB |= (1<<2);			//turns off LED at PB2
			}
		}
		
		while (overFlow < 20)				//55% DutyCycle Loop (.75s = 45 therefore 45% * 45 = 20)
		{
			if(TCNT0 ==0xFF)				//once the timer reaches the max value...
			{
				TCNT0 = 0x00;				//...reset it and...
				overFlow++;					//...add to the overflow counter and begin again
			}
			
			else if(!(PINC & (1 << 3)))
			{
				PORTB |= (1 << 3);			//turn off LED at PB3
				PORTB &= ~(1 << 2);			//turn on LED at PB2
				overFlow = 0;				//reset overflow counter
				TCNT0 = 0x00;				//reset timer
				
				while(overFlow < 120)		//2s Delay Loop (1 sec = 60 therefore 2 * 60 = 120)
				{
					if(TCNT0 == 0xFF)		//once the timer reaches the max value...
					{
						TCNT0 = 0x00;		//...reset it and...
						overFlow++;			//...add to the overflow counter and begin again
					}
				}
				PORTB |= (1<<2);			//turn off LED at PB2
			}
		}
		PORTB ^= (1<<3);					//inverts LED for each execution of the loop to produce strobe
	}
	return 0;
}

