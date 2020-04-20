//
//CPE301 - Midterm 2
//Tanner Tindall
//


#define F_CPU 16000000UL
#define BAUD 9600
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdbool.h>
#include <util/delay.h>

volatile uint16_t RPMx1_Value;
volatile uint16_t RPMx4_Value;
static char array[20];
volatile bool delay1;
volatile bool delay2;

void initializeUART()
{
	DDRD |= 0x01;													//set transmit port direction
	UBRR0 = 103;													//BAUD rate
	UCSR0C |= (0<<UPM01) | (0<<UPM00) | (1<<UCSZ01) | (1<<UCSZ00);  //disable parity and set to asynchronous
}

void startADC()
{
	DDRD &= ~(1<<0);												//set PD0 to input
	ADMUX = (1<<REFS0);												//set Vref and set ADC0 as input
	ADCSRA = (1<<ADEN) | (1<<ADATE)  | (1<<ADPS2) | (1<<ADPS1) |	(1<<ADPS0);		//enable ADC and set prescalar to 128
	ADCSRB = (1<<ADTS0);											//set analog compare match
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
	DDRD |= 0x01;								//transmit through PD1
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

void adcValue()
{
	uint16_t x = adcRead();
	float adcVal = ((x)*(110.0/1023.0));
	snprintf(array,sizeof(array), "%f\r\n", adcVal);
	USART_tx(array);
	return;
}

void setPorts()
{
	DDRB |= (1<<3) | (1<<4);//set output ports used for motor direction
	PORTB &= ~(1<<3);
	PORTB |= (1<<4);
	DDRD &= ~(1<<2);		//set INT0
	PORTD &= ~(1<<2);
	DDRD &= ~(1<<3);		//set INT1
	PORTD &= ~(1<<3);
	DDRD |= (1<<4);			//input capture 1
	PORTD &= ~(1<<4);
	DDRD |= (1<<5);			//input capture 2
	PORTD &= ~(1<<5);
}
int main()
{
	startADC();				//initialize functions above
	USART_tx_transmit();
	initializeUART();
	initializeTimer0();
	initializeTimer4();
	setPorts();
	sei();
	
	while(1)				//display RPMs to UART 
	{
		USART_tx("RPM:");
		RPMx1();
		USART_tx("\n");
		USART_tx("RPM:");
		RPMx2();
		USART_tx("\n");
		USART_tx("RPM:");
		RPMx4();
		USART_tx("\n");
		_delay_ms(10);
	}
}




void RPMx1()
{
	initializeTimer3();				//run counter
	initializeTimer4();				//run delay (100ms)
	delay1 = true; 					//set flag for while loop below
	
	while(delay1); 					//collect data until delay is finished
	
	PORTD &= ~(1<<4); 				//reset interrupts		
	PORTD &= ~(1<<5); 		
	
	return (float)(RPMx4_Value * (60.0/96.0)); //convert given value to rpm
}

void RPMx2()
{
	initializeTimer3();				//run counter
	initializeTimer4();				//run delay (100ms)
	EIMSK |= (1<<INT1); 			//set INT1 to handle interrupt for data collection
	EICRA |= (1<<ISC01) ; 			//enable external interrupt on falling edge
	delay1 = true; 					//set flag for while loop below
	
	while(delay1); 					//collect data until delay is finished
	
	disableTrigger();				//disable external interrupt
	PORTD &= ~(1<<4); 				//reset interrupts
	PORTD &= ~(1<<5); 				
	
	
	return (float)(RPMx4_Value * (60.0)/(192.0)); //convert given value to rpm
}

void RPMx4()
{
	initializeTimer1();					//run counter 1
	initializeTimer3();					//run counter 2
	initializeTimer4();					//run delay (100ms)
	EIMSK |= (1<<INT1) | (1<<INT0); 	//set INT0/1 to handle interrupt for data collection
	EICRA |= (1<<ISC11) | (1<<ISC00); 	//enable external interrupt on falling edge
	delay1 = true; 						//set flags
	delay2 = true;
	while(delay1 || delay2); 			//collect data until delay is finished
	disableTrigger();					//disable external interrupt
	PORTD &= ~(1<<4);					//reset interrupts
	PORTD &= ~(1<<5);

	return (float)((RPMx1_Value + RPMx4_Value) * (60.0)/(384.0)); //convert given value to rpm
}


void initializeTimer0() 						//PWM timer
{
	TCCR0A |= (1<<COM0A1) | (1<<WGM00);			//non-inverting, Fast PWM
	TCCR0B |= (1<<WGM02) | (1<<CS02);
	TIMSK0 |= (1<<TOIE0);						//enable interrupts
	TCNT0 = 0x00;
	OCR0A = 0x00;
}

void initializeTimer1()											//RPMx4
{
	DDRD &= ~(1<<7);
	TCNT1 = 0x00;
	TCCR1B |= (1<<FOC4B) | (1<<CS32) | (1<<CS31) | (1<<CS30);	//set CTC mode and prescaler of 64
	TIMSK1 |= (1<<ICIE1);

}

void initializeTimer3()											//RPMx1 & RPMx2 & RPMx4
{
	DDRD &= ~(1<<6);
	TCNT3 = 0x00;												//initialize timer3
	TCCR3B |= (1<<FOC4B) | (1<<CS32) | (1<<CS31) | (1<<CS30); 	//set to rising edge trigger
	TIMSK3 |= (1<<ICIE3); 										//set input compare interrupt
	
}

void initializeTimer4()								//ADC sampling delay timer
{
	TCNT4 = 0x00;  									//initialize timer
	TCCR4B |= (1<<WGM42) | (1<<CS41) | (1<<CS40); 	//set CTC mode and prescaler of 64
	TIMSK4 |= (1<<OCIE4A); 							//set output compare interrupt
	OCR4A  = 24999; 								//100ms in cycles
	
}

ISR(INT0_vect)
{
	motorDirection();			//motor changes direction on interrupt 
	if(delay1)					//if collecting data 
	{
		TCCR3B ^= (CS31);		//switch edge trigger
	}
}

ISR(INT1_vect)
{
	if(delay2)					//if collecting data 
	{
		TCCR1B ^= (CS11);		//switch edge trigger
	}
}

ISR(TIMER0_OVF_vect)			//PWM interrupt subroutine
{
	ADCSRA |= (1<<ADIE);		//set ADC interrupt
}

ISR(TIMER1_CAPT_vect)			//RPMx4 interrupt subroutine
{
	TIMSK1 &= ~(1U<<ICIE1);		//reset interrupt
	delay2 = false;				//change delay condition to enable calculations
	RPMx1_Value = (float) ICR1;	//store value from input data
	delay1 = false;				//change flag for calculation enable
}

ISR(TIMER3_CAPT_vect)			//RPMx1 & RPMx2 & RPMx4 interrupt subroutine
{
	TIMSK3 &= ~(1<<ICIE3);		//reset interrupt
	delay1 = false;				//change delay condition to enable calculations
	RPMx4_Value = (float) ICR3;	//store value from input data
	delay2 = false;				//change flag for calculation enable
}

ISR(TIMER4_COMPA_vect)
{
	TIMSK3 &= ~(TOIE0);
	PORTD |= (1<<4); 		//set interrupt
	if(delay2)
	{
		PORTD |= (1<<5);	//set interrupt for additional timer
	}
}

void disableTrigger()
{
	EIMSK = 0x00;			//disable INT1 interrupt
	EICRA = 0x00;			//disable external interrupt
}

void motorDirection()		//invert current direction of motor
{							//by reversing H-Bridge config
	PORTB ^= (1<<3);
	PORTB ^= (1<<4);
}
