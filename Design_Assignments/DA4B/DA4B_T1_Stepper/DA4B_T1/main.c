//
//CPE301 - DA4B - Task 1
//Tanner Tindall
//

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile float Value;

void startADC()
{
	ADMUX = (1<<REFS0);											
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //enable ADC, set prescalar to 128
}

float adcRead()
{
	ADCSRA |= (1<<6);				//enable ADC conversion
	while (!(ADCSRA & (1<<4)));		//waits for conversion to complete by ADIF flag
	ADCSRA |= (1<<4);				//reset when complete
	return ADC;						//return value once complete
}

void timer()
{
	TCCR1A |= 0x00;								
	TCCR1B |= (1<<WGM12)| (1<<CS12) | (1<<CS10);//set timer to CTC mode and set prescaler to 1024
	TIFR1 |= (1<<OCF1A);						//clear interrupt flag
	TCNT1 = 0x00;								//initialize timer
}

uint16_t adcVal()
{
	Value = adcRead()/1023;
	return Value;
}

int main()
{
	DDRD = 0x0F;					//set PD0:3 as output to driver
	DDRC &= ~(1<<PINC0);		//set PC0 to input for ADC values
	timer();
	startADC();
	
	while(1)
	{
		adcVal();				//collect a value from the ADC setting
								//delay times based on value received from ADC
		if (Value <= 205)		//the delays available are the following:
			OCR1A = 77;			//5ms
		else if (Value <= 410)	//different increments in the potentiometer...
			OCR1A = 155;		//10ms
		else if (Value <= 615)	//yield different speeds depending on its position
			OCR1A = 389;		//25ms
		else if (Value <= 820)
			OCR1A = 780;		//50ms
		else if (Value <= 1024)
			OCR1A = 1562;		//100ms
		
		//the following while statements loop until the flag is set, then reset & continue
		
		while(!(TIFR1 & (1 << OCF1A)));
			PORTD = 0x05;
			TIFR1 |= (1 << OCF1A);
		while(!(TIFR1 & (1 << OCF1A)));
			PORTB = 0x09;
			TIFR1 |= (1 << OCF1A);
		while(!(TIFR1 & (1 << OCF1A)));
			PORTD = 0x0A;
			TIFR1 |= (1 << OCF1A);
		while(!(TIFR1 & (1 << OCF1A)));
			PORTD = 0x06;
			TIFR1 |= (1 << OCF1A);
	}
}