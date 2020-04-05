//
//CPE301 - DA4A
//Tanner Tindall
//

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>

volatile unsigned int dutyCycle;	//value of duty cycle (changed with potentiometer)
volatile bool state = false;		//determines the state of motor

void configPWM()
{
	TCCR0A = 0b10000011;			//set noninverting, fast PWM
	TCCR0B = 0b00000011;			//set prescalar 1024
}

void startADC()
{
	ADMUX = (1<<REFS0);								//set Vref and set ADC0 as input
	ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADATE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}													//enable ADC and set prescalar to 128

void configDC()
{
	dutyCycle = (adcRead()/1023.0) * 95;	//take value read from ADC, prescale it then take 95% of it
	OCR0A = (dutyCycle/100.0)*255;		//convert dutyCycle into corresponding 8 bit value
}

int adcRead()
{
	ADCSRA |= (1<<6);				//enable ADC conversion
	while (!(ADCSRA & (1<<4)));		//waits for conversion to complete by ADIF flag
	ADCSRA |= (1<<4);				//reset when complete
	return ADC;						//return value once complete
}

int main(void)
{
	DDRB |= (1<<2);				//set DDRB to output
	DDRC &= ~(1<<PINC1|1<<PINC0);//set DDRC TO input
	DDRD |= (1<<PIND6); 		//set DDRD to output (PWM)
	
	PORTB |= (1<<2);			//set PB1 to HIGH
	PORTC |= (0<<PINC0) | (1<<PINC1);//set PC0 to input (potentiometer) & PC1 to output (interrupt)
	
	PCICR = (1<<PCIE1);			//enable pin interrupt
	PCMSK1 = (1<<PCINT9);		//set interrupt on PC1
	sei();						//enable interrupts
	
	configPWM();				//config PWM
	startADC();			//initialize ADC
	
	while (1)
	{
		configDC();			//set duty cycle to corresponding potentiometer value
	}
}

ISR(PCINT1_vect)				//PC1 interrupt subroutine
{
	if(!(PINC & (1 << PINC1)))	//if button is pressed begin
	{
		if(state == false)		//if the DC motor is off
		{
			TCCR0B = 0x00;		// Turns off timer.
			DDRD &= ~(1<<PIND6);
		}
		else if(state == true)	//if the DC is on
		{
			TCCR0B = 0b00000011;			//set prescalar 1024
			DDRD |= (1<<PIND6);				
		}
		PCIFR = (1<<PCIF1);		//clear interrupt
		state = !state;			//invert current state
	}
}
