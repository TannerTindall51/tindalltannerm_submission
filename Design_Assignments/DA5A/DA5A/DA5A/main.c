//
//CPE301 - DA5A Task 2
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

const uint8_t segMapArray[]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90}; //taken from lect 13 summary

uint8_t segSelectArray[];
volatile int x;
volatile uint16_t tempC_value;

void startADC()
{
	DDRC &= ~(1<<4);												//set PC4 to input
	ADMUX = (1<<REFS1)| (1<<REFS0)|	(1<<MUX2);						//set Vref and set ADC4 as input
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) |	(1<<ADPS0);		//enable ADC and set prescalar to 128
	ADCSRB = 0x00;													//set ADCSRB to free running
}

uint16_t adcRead()
{
	ADCSRA |= (1<<6);				//enable ADC conversion
	while (!(ADCSRA & (1<<latch)));	//waits for conversion to complete by ADIF flag
	ADCSRA |= (1<<latch);			//reset when complete
	return ADC;						//return value once complete
}

void initPorts()
{
	DDRB |= (1<<3)|(1<<5);		//set MOSI and SCK output
	DDRD |= (1<<latch);			//latch clock output
	PORTD &= ~(1<<latch);		//initialize clock to 0
	SPCR0 = 0x07;				//set SPI to master mode
}

void transmitSPI(uint8_t data)
{
	SPDR0 = data;					//send data
	while (!(SPSR0&(1<<SPIF)));		//wait until data register in emptied and all is sent
	SPSR0 |= (1<<SPIF);				//reset flag
}

uint16_t tempC()
{
	uint16_t temperature = adcRead();				//record value from adc
	tempC_value = ((temperature)*(110.0/1023.0));	//convert to temp value
}

void Latch()
{
	PORTD |= (1<<latch);		//set
	_delay_ms(20);
	PORTD &= ~(1<<latch);		//reset
}

int main()
{
	initPorts();		//initialize ports
	startADC();			//initialize adc
	
	while(1)
	{
		tempC();		//collect a temp value from ADC
		segConvert();	//convert to segment display and transmit
	}
}

void segConvert()
{
	for (x = 0; x < 4; x++)		//loop for each segment select
	{
		segSelectArray[x] = ((uint8_t)((tempC_value/pow(10, x))) % 10);	//scale temp value according to for loop
		transmitSPI(segMapArray[segSelectArray[x]]);					//send the position value to defined array
		transmitSPI(1<<(4+x));											//shift transmitted value
		Latch();														//latch the clock before next iteration
	}
}