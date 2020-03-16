//
//Design Assignment 3B
//Tanner Tindall
//

#define BAUD 9600
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/setbaud.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>

volatile uint16_t delay = 6249;				//initializing a global variable to be used as primary overflow for timer
volatile uint8_t counter = 5;				//initializing a global variable to be used as counter for delay
volatile uint8_t adcTemp_C;					//initializing a global variable to be used as Celsius value
volatile uint8_t adcTemp_F;					//initializing a global variable to be used as Fahrenheit value


void USART_init(void)					//initialize UART
{										//the baud rate consists of 16 bits therefore a low and high is needed
	UBRR0H = UBRRH_VALUE;				//high end of baud rate
	UBRR0L = UBRRL_VALUE;				//low  end of baud rate
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); //assigning bit values to UCSR0C
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);	//enabling Reception Complete Interruption & turning on RX/TX
}


void USART_tx(char*data)					//outputs data to terminal
{
	while((*data!='\0'))					//loop until all data is emptied
	{
		while(!(UCSR0A & (1 << UDRE0)));	//wait until data register in emptied
		UDR0 = *data;						//once emptied, import into data register UDR0
		data++;								//increments pointer position for data
	}
}


void timer(){
	OCR1A = delay;
	TCNT1 = 0x00;						//initializes the 16 bit timer1 register
	TCCR1A = 0x00;						//sets the timer to "CTC" Mode
	TCCR1B |= (1<<WGM12) | (1 << CS12); //sets the timer to "CTC" Mode & prescaler value to 256
	TIMSK1 = (1<<OCIE1A);				//enable timer0 overflow interrupt
	sei();								//enable interrupts
}


ISR(TIMER1_COMPA_vect){					//timer interrupt function
	TIFR1 |= 0x02;                    	//reset/clear interrupt
	counter++;							//increment delay counter
}

void ADC_init (void)
{
	ADMUX = (0<<REFS1)| (1<<REFS0)|		//set Vref
	(0<<ADLAR)|							//set ADC LEFT adjust
	(1<<MUX2)|(0<<MUX1)|(0<<MUX0);		//set ADC/PC5
	
	ADCSRA = (1<<ADEN)|					//enable ADC
	(0<<ADSC)|							//enable ADC conversion
	(0<<ADATE)|							//enable ADC trigger
	(0<<ADIF)|							//enable ADC interrupt flag
	(0<<ADIE)|							//enable ADC interrupt
	(1<<ADPS2)|	(0<<ADPS1)|(1<<ADPS0);  //set ADC prescaler
	
}

void adcRead(void){
	
	for(int i = 0; i < 10; i++) 
	{
		adcTemp_F = 0;					//initialize/reset value upon reloop
		ADCSRA |= (1<<6);               //enable ADC conversion
		while (!(ADCSRA&(1<<4)));       //waits for conversion to complete by ADIF flag
		ADCSRA |= (1<<4);               //reset when complete
		adcTemp_F += ADC;
		i++;
	}
	adcTemp_F = (adcTemp_F/10);			//divide by 10 to avg 10 samples from above
	adcTemp_C = (adcTemp_F - 32) * 5 / 9;	//convert to C
	
}

int main(void)
{
	USART_init();							//initialize USART
	ADC_init(); 							//initialize ADC
	timer();								//calls timer function
	
	char array1[30];
	char array2[30];
	
	while (1)
	if (counter >= 5) 						//since 100ms*5 = 500ms, this will serve as .5s delay
	{
		adcRead();							//call function to read values 
		
		USART_tx("\n");						//output info to terminal 
		snprintf(array1,sizeof(array1), "%f\r\n", adcTemp_C);
		USART_tx("Celsius: ");
		USART_tx(array1);
		snprintf(array2,sizeof(array2), "%f\r\n", adcTemp_F);
		USART_tx("Fahrenheit: ");
		USART_tx(array2);
		USART_tx("\n");
		
		counter = 0;
	}
}

