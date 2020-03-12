//
//Design Assignment 3A - Task 2
//Tanner Tindall
//

#define BAUD 9600
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>

volatile uint8_t overFlow;				//initializing a global variable to be used as primary overflow for timer

void USART_init(void)					//initialize UART
{										//the baud rate consists of 16 bits therefore a low and high is needed
	UBRR0H = UBRRH_VALUE;				//high end of baud rate
	UBRR0L = UBRRL_VALUE;				//low  end of baud rate
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); //assigning bit values to UCSR0C
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);	//enabling Reception Complete Interruption & turning on RX/TX
}

void USART_tx_string(char*data)			//outputs data to terminal
{
	while((*data!='\0'))				//loop until all data is emptied
	{
		while(!(UCSR0A & (1 << UDRE0)));	//wait until data register in emptied
		UDR0 = *data;						//once emptied, import into data register UDR0
		data++;								//increments pointer position for data
	}
}

void timer()							//timer function
{
	TCNT0 = 0;							//initializes the 8 bit timer0 register to begin at 0
	TCCR0A = 0;							//sets the timer to "Normal" Mode by WGM00
	TCCR0B |= (1 << CS02) | (1 << CS00);//sets prescaler value to 1024
	TIMSK0 = (1<<TOIE0);				//enable timer0 overflow interrupt
	sei();								//enable interrupts
}

ISR(TIMER0_OVF_vect)						//timer interrupt function
{
	overFlow++;								//increment overflow counter
}

int main(void){
	USART_init();							//initialize USART
	timer();								//call timer function
	int num = 51;							//integer value
	char array1[34];						//integer array
	char array2[34];						//float array
	
	while (1)								//primary loop
	{
		volatile float float_value = num *5;	//initialize float value
		
		if (overFlow == 61)
		{
		num = ((rand() * 5) % 100);			//randomizing the value
		itoa (num, array1, 10);					//making the integer into a string
		
		snprintf(array2,sizeof(array2), "%f\r\n", float_value);	//converting into a character array

		USART_tx_string("supercalifragilisticexpialidocious");	//print string
		USART_tx_string(" ");
		
		USART_tx_string(array1);		//print integer
		USART_tx_string(" ");
		
		USART_tx_string(array2);		//print float
		USART_tx_string("\n");
		USART_tx_string("\n");
		
		overFlow = 0;					//resetting overFlow counter
		}
	}
}
