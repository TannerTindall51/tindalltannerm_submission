//
//CPE301 DA4B - Task 2
//Tanner Tindall
//

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

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
	TCCR1A |= (1<<COM1A1)| (1<<COM1B1)| (1<<WGM11);	//clear OC1 and OCRA on match
	TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS11) |(1<<CS10);	//CTC mode with ICR1 as top, set prescalar to 64
	ICR1 = 4999;
}

uint16_t adcVal()
{
	Value = adcRead()/1023;
	return Value;
}

int main()
{
	DDRB &= (1<<PINB1);		//set PB1 as output to servo
	DDRC &= ~(1<<PINC0);	//set PC0 to input for ADC values
	timer();
	startADC();
	
	while(1)
	{
		adcVal();			//collect a value from the ADC
		
		if (Value == 0) 	//min value
		{
			OCR1A = 0;			//0
			_delay_ms(20);		//time needed for proper servo instruction
		}
		else if (Value == 255) 	//max value (already prescaled)
		{
			OCR1A = 535;		//180
			_delay_ms(20);
		}
	}
}
	