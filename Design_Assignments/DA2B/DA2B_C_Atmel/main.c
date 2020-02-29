
//
//Design Assignment 2B C Code Variant
//Tanner Tindall
//

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

 int main(void)
 {
	 DDRB = (1<<3);			//setting PORTB.3 as an output
	 PORTB = (1<<3);		//setting LED off (active low)
	 PORTD = (1<<2);		//turn on pull-up port (PD2)
	 
	 EIMSK = (1<<INT0);		//turns on INT0 (external interrupt)
	 EICRA = 0x2;			//INT0 triggers on 0x2 = falling edge 
	 sei ();				//turn on interrupts interrupts
	 
	 while (1)
	 {
		 PORTB &= ~(1<<3);	//turns LED on
		 _delay_ms(412.5);	//delay for 55% of .75s period
		  PORTB |= (1<<3);	//turns LED off
		 _delay_ms(337.5);	//delay for 45% of .75s period
	 }
 }
 
 ISR (INT0_vect)			// ISR for external interrupt INT0
 {		
	 PORTB &= ~(1<<3);		//set LED at PORTB.3 on 
	 _delay_ms(2000);		//delay for 2 sec
 }