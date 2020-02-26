//
//Design Assignment 2B C
//Tanner Tindall
//

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;	//sets all to output
	PORTB = 0xFF;	//sets all to output
	DDRC = 0x00;	//sets all to input
	
	while (1)
	{
		PORTB |= (1<<3);	//turns on led 3
		_delay_ms(337.5);	//delay for 337.5ms
		PORTB &= ~(1<<3);	//turns off led 3
		_delay_ms(412.5);	//delay for 412.5ms
		
		if(!(PINC & (1<<3)))	//enters loop if button is pressed
		{
			PORTB |= (1<<3);
			PORTB &= ~(1<<2);
			_delay_ms(2000);
			PORTB |= (1<<2);
		}
	}
	return 0;
}