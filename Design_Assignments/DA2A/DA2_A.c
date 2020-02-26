//
//Design Assignment 2A C
//Tanner Tindall
//

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;			//sets all ports to output
	PORTB = 0b00001000;		//sets portB.3 high
	
	while (1)
	{
		PORTB = 0b00001000;	//sets portB.3 high, LED on
		_delay_ms(337.5);	//delay for 337.5ms
		PORTB = 0x00;		//sets portB low, LED off
		_delay_ms(412.5);	//delay for 412.5ms
	}
	return 1;
}