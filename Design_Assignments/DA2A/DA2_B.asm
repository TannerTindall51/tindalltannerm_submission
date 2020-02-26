;
;Design Assignment 2B ASM
;Tanner Tindall 
;

.org 0x00

	ldi  r16, 28	;initializing register values
    ldi  r17, 101	;for delay loops below
    ldi  r18, 233
	ldi  r19, 34
    ldi  r20, 124
    ldi  r21, 86
	ldi  r22, 163
    ldi  r23, 87
    ldi  r24, 3
	
	ldi R25, 0xFF 	;loading all 1's into r25 
	out DDRB, r25 	;portB is set to output sonce r25 = 0xFF
	out PORTB, r25 	;intiliazes all LED's to turn off
	ldi r25, 0x00 	;loading 0 into r25 for next step
	out DDRC, r25 	;sets the switches to inputs

Duty_Cycle:			;primary loop
	cbi PORTB, 3	;turn on port needed
	
delay1: 			;delay1 = 337.5ms
	dec  r18
    brne delay1
    dec  r17
    brne delay1
    dec  r16
    brne delay1
    nop
 
	sbi PORTB, 3 		;turns off port
    
delay2: 				;delay2 = 412.5ms
	dec  r21
    brne delay2
    dec  r20
    brne delay2
    dec  r19
    brne delay2
	
	sbis PINC, 3		;if button is pressed, then continue otherwise skip next instruction
	rjmp Button_Press	;go to button_press loop 
	rjmp Duty_Cycle		;otherwise jump back to top and repeat

Button_Press:
	cbi PORTB, 2		;turns on LED D4 
	
delay3: 				;delay3 = 2s
	dec  r24
    brne delay3
    dec  r23
    brne delay3
    dec  r22
    brne delay3
    nop
	
	sbi PORTB, 2		;turns off LED D4
	rjmp Duty_Cycle		;go back to primary loop and start over
	    
	


	

	
