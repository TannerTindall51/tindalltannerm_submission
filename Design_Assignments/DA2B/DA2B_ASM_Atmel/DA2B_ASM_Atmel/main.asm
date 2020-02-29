;
;Design Assignment 2B ASM Code Variant
;Tanner Tindall 
;

.org 0x00
jmp Interrupt_Handler
.org 0x02
jmp Interrupt

Interrupt_Handler:			;utilizing a stack to handle interrupts
	
	ldi r25, HIGH(RAMEND) 	;initilizing high end of the stack
	out SPH, r25
	ldi R20, LOW(RAMEND)	;initilizing low end of the stack
	out SPL, r25

	ldi r25, 0x02 			;loading value to determine trigger 
	sts EICRA, r25			;interrupt control register set to trigger on 0x2 = falling edge 

	sbi DDRB, 3 			;sets DDRB3 as output
	sbi PORTB, 3 			;sets PORTB3 to logic level HIGH
	sbi PORTD, 2 			;sets INT0 flag 
	cbi DDRC, 3 			;sets DDRC3 as input
	sbi PORTC,3 			;sets PORTC3 to logic level HIGH
	
	ldi r25, 1<<INT0		;loading a logic level HIGH value into INT0	
	out EIMSK, r25			;loads the flag INT0 into EIMSK reggister with logic level HIGH
	sei 					;turns on interrupt

Duty_Cycle:					;primary loop for blinking LED
	
	cbi PORTB, 3			;turns on the LED at PORTB.3
	
	ldi  r16, 28			;register values for delay1
    ldi  r17, 101	
    ldi  r18, 233
	
delay1: 					;delay1 = 337.5ms
	dec  r18
    brne delay1
    dec  r17
    brne delay1
    dec  r16
    brne delay1
    nop
 
	sbi PORTB, 3 			;turn off the LED at PORTB.3
	
	ldi  r19, 34			;register values for delay2
    ldi  r20, 124
    ldi  r21, 86  
delay2: 					;delay2 = 412.5ms
	dec  r21
    brne delay2
    dec  r20
    brne delay2
    dec  r19
    brne delay2
	
	jmp Duty_Cycle			;otherwise jump back to top and repeat

Interrupt:					;loop which executes interrupt instruction

	in r26, PORTB			;loads value of PORTB into r26
	ldi r27, (1<<2)			;loading value into r27 for XOR operation below
	eor r26, r27			;XOR operation with value of PORTB and r27
	out PORTB, r26			;load value in r26 into PORTB
	
	ldi  r22, 163			;register values for delay3
    ldi  r23, 87
    ldi  r24, 3
delay3: 					;delay3 = 2s
	dec  r24
    brne delay3
    dec  r23
    brne delay3
    dec  r22
    brne delay3
    nop
reti						;reti = returns from "Interrupt" loop 
