;***********************************************************
;*	 Author: Zach Taylor and Sara Vanaken
;*	 Date: 2/7/23
;***********************************************************
.include "m32U4def.inc"			; Include definition file


;***********************************************************
;*	Internal Register Definitions and Constants
;***********************************************************
.def	mpr = r16				; Multipurpose register is required for LCD Driver
.def    prior = r24             ;Temp register for prior value
.def	waitcnt = r17			; Wait Loop Counter
.def	ilcnt = r18				; Inner Loop Counter
.def	olcnt = r19				; Outer Loop Counter

.equ	WTime = 25				; Time to wait in wait loop

		
;***********************************************************
;*	Start of Code Segment
;***********************************************************
.cseg							; Beginning of code segment


;***********************************************************
;*	Interrupt Vectors
;***********************************************************
.org	$0000					; Beginning of IVs
		rjmp INIT				; Reset interrupt

.org	$0056					; End of Interrupt Vectors


;***********************************************************
;*	Program Initialization
;***********************************************************
INIT:
		; Initialize Stack Pointer
		ldi		mpr, low(RAMEND)
		out		SPL, mpr		; Load SPL with low byte of RAMEND
		ldi		mpr, high(RAMEND)
		out		SPH, mpr		; Load SPH with high byte of RAMEND

		rcall LCDInit           ;Call LCDInit function
		rcall LCDClr            ;Clear the initial LCD display

		;Initialize PORTD Pins for Input
		ldi		mpr, $00		; Set Port D Data Direction Register
		out		DDRD, mpr		; for input
		ldi		mpr, $FF		; Initialize Port D Data Register
		out		PORTD, mpr		; so all Port D inputs are Tri-State


;***********************************************************
;*	Main Program
;***********************************************************
MAIN:						
		in	mpr, PIND           ;Get input from port D
		cpi mpr, 0b11101111     ;Check if PIND is pin 4
		brne NEXT               ;Move on if not equal
		rcall CLEAR             ;Call the clear function
		rjmp MAIN               ;Return to MAIN

NEXT:	cpi mpr, 0b11011111     ;Check if PIND is pin 5
		brne FINAL              ;Move on if not equal
		rcall DISPLAY           ;Call the display function
		rjmp MAIN               ;Return to MAIN

FINAL: cpi mpr, 0b01111111      ;Check if PIND is pin 7
	   brne MAIN                ;Move on to MAIN if not equal
	   rcall MOVE               ;Call the move function
	   rjmp MAIN                ;Return to MAIN
								

;***********************************************************
;*	Functions and Subroutines
;***********************************************************
;-----------------------------------------------------------
; Func: CLEAR
; Desc: Clears the first and second lines of text
;       displayed on the screen
;-----------------------------------------------------------
CLEAR:
		rcall LCDClr            ;Clear the initial display
		ret	                    ;Return


;-----------------------------------------------------------
; Func: DISPLAY
; Desc: Displays the first two lines of text
;-----------------------------------------------------------
DISPLAY:							
		rcall LCDClr            ;Clear the initial display

		ldi ZL, low(STRING1_BEG<<1)     ;Load the low byte of string 1 into Z
		ldi ZH, high(STRING1_BEG<<1)    ;Load the high byte of string 1 into Z
		ldi YL, $00             ;Load the low byte of the LCD line 1 address
		ldi YH, $01             ;Load the high byte of the LCD line 1 address
		ldi r23, $0B            ;Set counter for loop 1

loop1:  cpi r23, $00            ;Check the loop counter
		breq wrln1              ;Break out if equal
		lpm mpr, Z+             ;Load the first character into mpr, post inc Z
		st Y+, mpr              ;Load mpr into the address space of the Ith character
		dec r23                 ;Decrement the counter
		rjmp loop1              ;Jump to begining of loop 1
		
wrln1:
		rcall LCDWrLn1          ;Call the write line 1 function

line2:
		ldi ZL, low(STRING2_BEG<<1)     ;Load the low byte of string 2 into Z
		ldi ZH, high(STRING2_BEG<<1)    ;Load the high byte of string 2 into Z
		ldi YL, $10             ;Load the low byte of the LCD line 2 address
		ldi YH, $01             ;Load the high byte of the LCD line 2 address
		ldi r23, $0C            ;Set counter for loop 2

loop2:  cpi r23, $00            ;Check the loop counter
		breq wrln2              ;Break out if equal
		lpm mpr, Z+             ;Load the first character into mpr, post inc Z
		st Y+, mpr              ;Load mpr into the address space of the Ith character
		dec r23                 ;Decrement the counter
		rjmp loop2              ;Jump to begining of loop 2
		
wrln2:
		rcall LCDWrLn2          ;Call the write line 2 function
		
		ret	                    ;Return


;-----------------------------------------------------------
; Func: MOVE
; Desc: Displays the input strings as a scrolling, 
;       marquee-style message
;-----------------------------------------------------------
MOVE:
	  rcall DISPLAY             ;Call display to set inital text

scroll:
	  in mpr, PIND              ;Get input from port D
	  cpi mpr, 0b10111111       ;Check if PD6 was pressed
	  breq MAIN                 ;Break on if not equal

	  ldi YL, $1F               ;Load the next address after line 2 ends into Y
	  ldi YH, $01               ;Load the next address after line 2 ends into Y

	  ld mpr, Y                ;Load the last element into mpr

	  ldi YL, $00               ;Load starting LCD address into Y
	  ldi YH, $01               ;Load starting LCD address into Y

	  ldi r23, $20              ;Load loop counter

	  inner:
			ld prior, Y         ;Load the first element into temp register prior
			st Y+, mpr          ;Place the last element into the first position
			mov mpr, prior      ;Swap temp element into mpr for next pass
			dec r23             ;Decrement the count
			brne inner          ;Break to start of loop if not equal

	  rcall LCDWrite
	  ldi waitcnt, WTime	    ;Wait for .25 seconds
	  rcall	Wait			    ;Call wait function

	  rjmp scroll               ;Jump to start of loop

	  ret                       ;Return


;----------------------------------------------------------------
; Sub:	Wait
; Desc:	A wait loop that is 16 + 159975*waitcnt cycles or roughly
;		waitcnt*10ms.  Just initialize wait for the specific amount
;		of time in 10ms intervals. Here is the general eqaution
;		for the number of clock cycles in the wait loop:
;			(((((3*ilcnt)-1+4)*olcnt)-1+4)*waitcnt)-1+16
;----------------------------------------------------------------
Wait:
		push	waitcnt			; Save wait register
		push	ilcnt			; Save ilcnt register
		push	olcnt			; Save olcnt register

Loop:	ldi		olcnt, 224		; load olcnt register
OLoop:	ldi		ilcnt, 237		; load ilcnt register
ILoop:	dec		ilcnt			; decrement ilcnt
		brne	ILoop			; Continue Inner Loop
		dec		olcnt		    ; decrement olcnt
		brne	OLoop			; Continue Outer Loop
		dec		waitcnt		    ; Decrement wait
		brne	Loop			; Continue Wait loop

		pop		olcnt		    ; Restore olcnt register
		pop		ilcnt		    ; Restore ilcnt register
		pop		waitcnt		    ; Restore wait register
		ret				        ; Return from subroutine


;***********************************************************
;*	Stored Program Data
;***********************************************************
STRING1_BEG:
.DB "Zach Taylor",0	            ; Declaring data in ProgMem for string 1
STRING2_BEG:
.DB	"Sara Vanaken"		        ; Declaring data in ProgMem for string 2


;***********************************************************
;*	Additional Program Includes
;***********************************************************
.include "LCDDriver.asm"		; Include the LCD Driver
