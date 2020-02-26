;
;Design Assignment 2A ASM
;Tanner Tindall 
;
	ldi  r19, 28	;initializing register values
    ldi  r20, 101	;for delay loops below
    ldi  r21, 233
	ldi  r16, 34
    ldi  r17, 124
    ldi  r18, 86
	sbi DDRB, 3

Duty_Cycle:			;primary loop
	sbi PORTB, 3	;sets portB.3 high 
	call delay1		;delay for 337.5ms
	cbi PORTB, 3	;clears portB setting it low
	call delay2 	;delay for 412.5ms
	jmp Duty_Cycle	;jump back to primary loop and restart

delay1: 			;delay1 = 337.5ms
	dec  r21
    brne delay1
    dec  r20
    brne delay1
    dec  r19
    brne delay1
    nop
	ret
	
delay2: 			;delay2 = 412.5ms
	dec  r18
    brne delay2
    dec  r17
    brne delay2
    dec  r16
    brne delay2
	ret