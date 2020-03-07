//
//Design Assignment 2C - Task 3
//Tanner Tindall
// 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int overFlow_Count = 0;		//initializes variable to be used as counter for overflow occurrences
volatile int overFlow_Max = 21;			//45% Duty Cycle @337.5ms (((16MHz/1024) * .3375)/256) = 21

int main(void)
{
	DDRB = 0xFF;						//sets DDRB to OUTPUT
	DDRC = 0x00;						//sets DDRC to INPUT
	PORTB = 0xFF;						//sets all of PORTB logic level HIGH
	TCNT0 = 0;							//initializes the 8 bit timer0 register to begin at 0
	TCCR0A = 0x02;						//sets the timer to "CTC" Mode by setting WGM01 high
	TCCR0B = (1 << CS02) | (1 << CS00);//sets prescaler value to 1024, refer to TCCROB truthTable
	TIMSK0 = (1<<OCIE1A);				//enable timer0 overflow interrupt
	OCR0A = 255;
	sei();								//turn on interrupts 
	
	while (1)							//infinite loop which is interrupted by the function below
	{
		
	}
}
	ISR (TIMER0_COMPA_vect)
	{
		overFlow_Count++;				//increments the counter upon interrupt
		
		if (overFlow_Count == overFlow_Max) //comparison between counter and counterMax values
		{
			PORTB ^= (1<<3);			//toggle LED at PB3
			PORTB |=(1<<2);				//turn off LED at PB2
			
			if(overFlow_Max == 21)		//if 45% DutyCycle, then begin this statement 
			{
				overFlow_Max = 25;		//change max counter to 55% Duty Cycle @412.5ms (((16MHz/1024) * .4125)/256) = 25
				if(!(PINC & (1<<3)))	//checks to see if SW3 is pressed
				{
				PORTB &= ~(1<<2);		//turns on LED at PB2
				overFlow_Max = 120;		//2s Delay Loop (1 sec = 60 therefore 2 * 60 = 120)
				PORTB |= (1<<3);		//turns off LED at PB3
				}
			} 
			
			else						//if 55% DutyCycle, then begin this statement
			{
				overFlow_Max = 21;		//reset back to 45% DutyCycle for next iteration
				if(!(PINC & (1<<3)))	//checks to see if SW3 is pressed
				{
					PORTB &= ~(1<<2);	//turns on LED at PB2
					overFlow_Max = 120;	//2s Delay Loop (1 sec = 60 therefore 2 * 60 = 120)
					PORTB |= (1<<3);	//turns off LED at PB3
				}
			}
			overFlow_Count = 0;			//resetting counter
		}
		TCNT0 = 0;						//resetting timer
	}


