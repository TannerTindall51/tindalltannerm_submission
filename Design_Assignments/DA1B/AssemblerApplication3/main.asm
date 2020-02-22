;
; AssemblerApplication2.asm
;
; Created: 2/21/2020 3:23:09 PM
; Author : tanne
;

	.equ STARTADDS = 0x0300		;starting address
	.equ SEVENADDS = 0x0500		;address for numbers divisible by 7
	.equ THREEADDS = 0x0600		;address for numbers divisible by 7
	.equ BOTHADDS = 0x0700		;address for numbers divisible by 7
	.equ ELSEADDS = 0x0800		;address for any other values
	
	.def Store = r18
	.def Counter7 = r19
	.def Counter3 = r20
	;.def CounterBoth = r21
	;.def CounterNeither = r22
	;.def MainCounter = r23
	


start:
	ldi	XL, LOW(STARTADDS)		;Declaring lower bounds of pointer 
	ldi XH, HIGH(STARTADDS)		;Declaring upper bounds of pointer
	ldi	YL, LOW(SEVENADDS)
	ldi	YH, HIGH(SEVENADDS)

	ldi r16, 0x19				;Loads r22 with lowest value (25)
	ldi r17, 0xE2				;Loads r23 with highest value (226)

POPULATE:	st	X+, r16			;Loop for populating the memory address, starting with (25)	 
				inc r16			;increments lowest value register (r16)			
				dec	r17			;decrements highest value register (r17)
				cpi r17, 24		
				brne POPULATE	;once the highest value register reaches 0, exits loop and continues

PARSE:		ld	 Store, -X		;loads memory address location into register Store from highest to lowest
			CP XL, R0			;compares the value to 0 
			BREQ end			;if 0, parsing os completed and code ends
div7:
			subi Store, 0x7		;subtracts 7 from value in Store
			cpi Store, 7		;
			brsh div7			;
			cpse Store, r0		;
			jmp Skip			;	
			ld Store, X			;
			st Y+, Store		;
			ld Counter7, Y		;
		
;div3: 
			;subi Store, 0x3
			;cpi Store, 3
			; div3
			;cpse Store, r0
			;jmp Skip
			;ld Store, X
			;ldi	YL, LOW(THREEADDS)
			;ldi	YH, HIGH(THREEADDS)
			;st Y+, Store
			;ld Counter3, Y

Skip:
	jmp PARSE

end: jmp end