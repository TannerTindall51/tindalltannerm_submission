//
//CPE301 - DA5A Task 1
//Tanner Tindall
//

#define BAUD 9600
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

#define latch 4
#define clock 7
#define data 0

const uint8_t SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
const uint8_tSEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};

volatile uint16_t tempC_value;

void shift_out_init(void)
{
	DDRB |= (1<<data);
	DDRD|=(1<<clock)|(1<<latch); //PD7 = SCLK & PD4 = latch
}

uint16_t adcRead()
{
	ADCSRA |= (1<<6);				//enable ADC conversion
	while (!(ADCSRA & (1<<latch)));	//waits for conversion to complete by ADIF flag
	ADCSRA |= (1<<latch);			//reset when complete
	return ADC;						//return value once complete
}

void startADC()
{
	DDRC &= ~(1<<4);												//set PC4 to input
	ADMUX = (1<<REFS1)| (1<<REFS0)|	(1<<MUX2);						//set Vref and set ADC4 as input
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) |	(1<<ADPS0);		//enable ADC and set prescalar to 128
	ADCSRB = 0x00;													//set ADCSRB to free running
}

void shift_out(uint8_t indata)
{
	for (uint8_t i = 0; i < 8; i++)
	{
		/* Write bit to data port. */
		if (0 == (indata & _BV(7 - i)))
		{
			// digital_write(SHIFT_OUT_DATA, LOW);
			PORTB &= (0 << data);
		}
		else
		{
			// digital_write(SHIFT_OUT_DATA, HIGH);
			PORTB |= (1 << data);
		}
		/* Pulse clock to write next bit. */
		PORTD |= (1<<clock);
		PORTD &= (0<<clock);
	}
}

uint16_t tempC()
{
	uint16_t temperature = adcRead();				//record value from adc
	tempC_value = ((temperature)*(110.0/1023.0));	//convert to temp value
	shift_out(tempC_value);							//send the value out to display
	
}

int main(void)
{
	shift_out_init();
	startADC();
	while (1)
	{
		adcRead();
		tempC();
		PORTD |= (1<<latch);
	}
}

