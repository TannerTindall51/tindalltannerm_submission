//
//CPE301 - Midterm1
//Tanner Tindall
//

#define BAUD 9600
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdbool.h>

volatile static char helpScreen[] = " h - Help \n t - Display temp. in C \n T - Display temp. in F \n o - Turn on LED at PB5  \n O - Turn off LED at PB5  \n s - Send a string \n i - Send an integer \n";
volatile static char string[] = "supercalifragilisticexpialidocious \n";
volatile static char array[20]; 
volatile int randomNumber;

void initializeUART()
{
	DDRD |= 0x02;
	UBRR0 = 103;
	UCSR0C |= (0<<UPM01) | (0<<UPM00) | (1<<UCSZ01) | (1<<UCSZ00);  //disable parity and set to asynchronous
}

void startADC() 
{
	DDRC &= ~(1<<4);												//set PC4 to input 				
	ADMUX = (1<<REFS1)| (1<<REFS0)|	(1<<MUX2);						//set Vref and set ADC4 as input
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) |	(1<<ADPS0);		//enable ADC and set prescalar to 128 			
	ADCSRB = 0x00;			//Since ADFR is NOT a bit in ADCSRA, setting ADCSRB to 0 enables free running
}

uint16_t adcRead()
{
	ADCSRA |= (1<<6);				//enable ADC conversion
	while (!(ADCSRA & (1<<4)));		//waits for conversion to complete by ADIF flag
	ADCSRA |= (1<<4);				//reset when complete
	return ADC;						//return value once complete
}

void USART_tx_transmit() 
{
	UBRR0 = 103;
	UCSR0B |= (1 << TXCIE0) | (1<<TXEN0);		//enable data transmission
	DDRD |= 0x02;								//transmit through PD2 
}

void USART_tx(char*data)						//outputs data to terminal
{
	while((*data != '\0'))						//loop until all data is emptied
	{
		while(!(UCSR0A & (1 << UDRE0)));		//wait until data register in emptied
		UDR0 = *data;							//once emptied, import into data register UDR0
		data++;									//increments pointer position for data
	}
}

void USART_rx_receive() 
{
	UBRR0 = 103;
	UCSR0B |= (1 << RXCIE0) | (1<<RXEN0);		//enable data transmission
	DDRD |= 0x01;								//receive from PD1
}

char USART_rx()						//inputs data from terminal
{
	while (!(UCSR0A & (1<<7)));		//loop until all data is received
	return UDR0;					//returns received values to UDR0
}

int main(void)
{
	startADC();				//initialize 
	USART_tx_transmit();
	USART_rx_receive();
	initializeUART();


	DDRB = 0b00100100;			//sets DDRB to OUTPUT
	PORTB = 0b00100100;			//initialize PB5
	
	while (1)
	 {	 
		 char input = USART_rx();
		 
		 if (input == 'h')				
		 {
			 USART_tx(helpScreen);
		 }
		 else if (input == 't')
		 {
			 USART_tx("\n");
			 tempC();
		 }
		 else if (input == 'T')
		 {
			 USART_tx("\n");
			 tempF();
		 }
		 else if (input == 'o')
		 {
			 PORTB &= ~(1<<5);
		 }
		 else if (input == 'O')
		 {
			 PORTB |= (1<<5);
		 }
		 else if (input == 's')
		 {
			 USART_tx("\n");
			 USART_tx(string);
		 }
		 else if (input == 'i')
		 {
			 USART_tx("\n");
			 randomValue();
			 blinkLED();
		 }
	}
}

void tempC()
{
	uint16_t temperature = adcRead();
	float tempC_float = ((temperature)*(110.0/1023.0));
	snprintf(array,sizeof(array), "%f\r\n", tempC_float);
	USART_tx(array);
	return;
}

void tempF()
{
	uint16_t temperature = adcRead();
	float  tempF_float = ((((temperature) * (110/1023.0)) * 9.0/5.0) + 32.0);
	snprintf(array,sizeof(array), "%f\r\n", tempF_float);
	USART_tx(array);
	PORTB = (1<<2);
	return;
}

void randomValue()
{
	int max = 3;
	int min = 0;
	randomNumber = rand() % (max - min + 1) + min;
	snprintf(array,sizeof(array), "%d\r\n", randomNumber);
	USART_tx(array);
	return;
}
	
void blinkLED()
{
	if(randomNumber == 3)
	{
		PORTB = (0<<2);
		_delay_ms(3000);
		PORTB = (1<<2);
	}
	else if(randomNumber == 2)
	{
		PORTB = (0<<2);
		_delay_ms(2000);
		PORTB = (1<<2);
	}
	else if(randomNumber == 1)
	{
		PORTB = (0<<2);
		_delay_ms(1000);
		PORTB = (1<<2);
	}
	return;
}



