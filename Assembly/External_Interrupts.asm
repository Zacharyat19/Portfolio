;***********************************************************
;*	 Author: Zach Taylor and Sara Vanaken
;*	 Date: 2/17/23
;***********************************************************

.include "m32U4def.inc"			; Include definition file

;***********************************************************
;*	Internal Register Definitions and Constants
;***********************************************************
.def    hitR = r14              ; Number of right whisker hits
.def    hitL = r15              ; Number of left whisker hits
.def	mpr = r16				; Multipurpose register
.def	waitcnt = r17			; Wait Loop Counter
.def	ilcnt = r18				; Inner Loop Counter
.def	olcnt = r19				; Outer Loop Counter

.equ	WTime = 100				; Time to wait in wait loop
.equ	WskrR = 0				; Right Whisker Input Bit
.equ	WskrL = 1				; Left Whisker Input Bit
.equ	EngEnR = 5				; Right Engine Enable Bit
.equ	EngEnL = 6				; Left Engine Enable Bit
.equ	EngDirR = 4				; Right Engine Direction Bit
.equ	EngDirL = 7				; Left Engine Direction Bit

;/////////////////////////////////////////////////////////////
;These macros are the values to make the TekBot Move.
;/////////////////////////////////////////////////////////////

.equ	MovFwd = (1<<EngDirR|1<<EngDirL)	; Move Forward Command
.equ	MovBck = $00				        ; Move Backward Command
.equ	TurnR = (1<<EngDirL)			    ; Turn Right Command
.equ	TurnL = (1<<EngDirR)			    ; Turn Left Command
.equ	Halt = (1<<EngEnR|1<<EngEnL)		; Halt Command

;***********************************************************
;*	Start of Code Segment
;***********************************************************
.cseg							; Beginning of code segment

;***********************************************************
;*	Interrupt Vectors
;***********************************************************
.org	$0000		; Beginning of IVs
		rjmp INIT	; Reset interrupt

; Set up interrupt vectors for any interrupts being used
.org    $0002
rcall HitRight      ; INT0
reti	

.org    $0004
rcall HitLeft       ; INT1
reti

.org    $0008
rcall Clear         ; INT3
reti

.org	$0056		; End of Interrupt Vectors

;***********************************************************
;*	Program Initialization
;***********************************************************
INIT:							; The initialization routine
		; Initialize Stack Pointer
		ldi	mpr, low(RAMEND)	; Load MPR with low byte of RAEMEND
		out	SPL, mpr		    ; Load SPL with low byte of RAMEND
		ldi	mpr, high(RAMEND)	; Load MPR with high byte of RAEMEND
		out	SPH, mpr		    ; Load SPH with high byte of RAMEND

		; Initialize Port B for output
		ldi	mpr, $FF		    ; Set Port B Data Direction Register
		out	DDRB, mpr		    ; for output
		ldi	mpr, $00		    ; Initialize Port B Data Register
		out	PORTB, mpr		    ; so all Port B outputs are low

		; Initialize Port D for input
		ldi	mpr, $00	     	; Set Port D Data Direction Register
		out	DDRD, mpr		    ; for input
		ldi	mpr, $FF		    ; Initialize Port D Data Register
		out	PORTD, mpr		    ; so all Port D inputs are Tri-State

		; Initialize LCD
		rcall LCDInit           ; Call initialization routine
		rcall LCDClr            ; Clear the initial display

		; Initialize external interrupts
		ldi mpr, 0b10101010     ; Set interrupt bits for falling edge
		sts EICRA, mpr          ; Set external control register

		; Configure the External Interrupt Mask
		ldi mpr, 0b00001011     ; Set interrupt bits for detection
		out EIMSK, mpr          ; Set which interrupts to detect

		; Turn on interrupts
		sei

;***********************************************************
;*	Main Program
;***********************************************************
MAIN:							
	    clr hitR              ; Clear right whisker count
		clr hitL              ; Clear left whisker count

		ldi mpr, 0            ; Load zero value into mpr
		ldi XL, low($0100)    ; Load starting address
		ldi XH, high($0100)   ; Load starting address

		rcall Bin2ASCII       ; Load new string into LCD address

		ldi XL, low($0110)    ; Load starting address
		ldi XH, high($0110)   ; Load starting address

		rcall Bin2ASCII       ; Load new string into LCD address
		rcall LCDWrite        ; Write zero to both lines

MAIN_LOOP:
		ldi mpr, MovFwd       ; Load FED command
		out PORTB, mpr        ; Send to motors
		rjmp MAIN_LOOP		  ; Create an infinite while loop to signify the end of the program.

;***********************************************************
;*	Functions and Subroutines
;***********************************************************

;----------------------------------------------------------------
; Sub:	HitRight
; Desc:	Handles functionality of the TekBot when the right whisker
;		is triggered.
;----------------------------------------------------------------
HitRight:
		push mpr			; Save mpr register
		push waitcnt		; Save wait register
		in mpr, SREG	    ; Save program state
		push mpr			; Save SREG

		; Update the LCD count
		inc hitR            ; Increase hit count
		mov mpr, hitR       ; Load right hit count
		ldi XL, low($0100)  ; Load starting address
		ldi XH, high($0100) ; Load starting address

		rcall Bin2ASCII     ; Load new string into LCD address
		rcall LCDWrLn1      ; Write to line one in LCD

		; Move Backwards for a second
		ldi	mpr, MovBck	    ; Load Move Backward command
		out	PORTB, mpr	    ; Send command to port
		ldi	waitcnt, WTime	; Wait for 1 second
		rcall Wait			; Call wait function

		; Turn left for a second
		ldi	mpr, TurnL	    ; Load Turn Left Command
		out	PORTB, mpr	    ; Send command to port
		ldi	waitcnt, WTime	; Wait for 1 second
		rcall Wait			; Call wait function

		; Move Forward again
		ldi	mpr, MovFwd	    ; Load Move Forward command
		out	PORTB, mpr	    ; Send command to port

		; Clear the interrupt queue
		ldi mpr, 0b00001011 ; Load clear bits into mpr
		out EIFR, mpr       ; Clear the interrupt flag

		pop	mpr		        ; Restore program state
		out	SREG, mpr	    ; Restore SREG
		pop	waitcnt		    ; Restore wait register
		pop	mpr		        ; Restore mpr
		ret				    ; Return from subroutine
		  
;----------------------------------------------------------------
; Sub:	HitLeft
; Desc:	Handles functionality of the TekBot when the left whisker
;		is triggered.
;----------------------------------------------------------------
HitLeft:
		push mpr			; Save mpr register
		push waitcnt	    ; Save wait register
		in mpr, SREG	    ; Save program state
		push mpr		    ; Save SREG
		
		; Update the LCD count
		inc hitL            ; Increase hit count
		mov mpr, hitL       ; Load left hit count
		ldi XL, low($0110)  ; Load starting address
		ldi XH, high($0110) ; Load starting address

		rcall Bin2ASCII     ; Load new string into LCD address
		rcall LCDWrLn2      ; Write to line two in LCD

		; Move Backwards for a second
		ldi	mpr, MovBck	    ; Load Move Backward command
		out	PORTB, mpr	    ; Send command to port
		ldi	waitcnt, WTime	; Wait for 1 second
		rcall Wait			; Call wait function

		; Turn right for a second
		ldi	mpr, TurnR	    ; Load Turn Left Command
		out	PORTB, mpr	    ; Send command to port
		ldi	waitcnt, WTime	; Wait for 1 second
		rcall Wait			; Call wait function

		; Move Forward again
		ldi	mpr, MovFwd	    ; Load Move Forward command
		out	PORTB, mpr	    ; Send command to port

		; Clear the interrupt queue
		ldi mpr, 0b00001011 ; Load clear bits into mpr
		out EIFR, mpr       ; Clear the interrupt flag

		pop	mpr		        ; Restore program state
		out	SREG, mpr	    ; Restore SREG
		pop	waitcnt		    ; Restore wait register
		pop	mpr		        ; Restore mpr
		ret				    ; Return from subroutine

;-------------------------------------------------------------
; Sub:	Clear
; Desc:	Clears both lines in the LCD and resets counts to zero
;-------------------------------------------------------------
Clear:
	    clr hitR             ; Clear right whisker count
		clr hitL             ; Clear left whisker count

		ldi mpr, 0           ; Load zero value into mpr
		ldi XL, low($0100)   ; Load starting address
		ldi XH, high($0100)  ; Load starting address

		rcall Bin2ASCII      ; Load new string into LCD

		ldi XL, low($0110)   ; Load starting address
		ldi XH, high($0110)  ; Load starting address

		rcall Bin2ASCII      ; Load new string into LCD
		rcall LCDWrite       ; Write to both lines in the LCD

		ret                  ; Return from subroutine
;------------------------------------------------------------------
; Sub:	Wait
; Desc:	A wait loop that is 16 + 159975*waitcnt cycles or roughly
;		waitcnt*10ms.  Just initialize wait for the specific amount
;		of time in 10ms intervals. Here is the general eqaution
;		for the number of clock cycles in the wait loop:
;			(((((3*ilcnt)-1+4)*olcnt)-1+4)*waitcnt)-1+16
;------------------------------------------------------------------
Wait:
		push waitcnt	; Save wait register
		push ilcnt		; Save ilcnt register
		push olcnt		; Save olcnt register

Loop:	ldi	olcnt, 224	; load olcnt register
OLoop:	ldi	ilcnt, 237	; load ilcnt register
ILoop:	dec	ilcnt		; decrement ilcnt
		brne ILoop		; Continue Inner Loop
		dec	olcnt		; decrement olcnt
		brne OLoop		; Continue Outer Loop
		dec	waitcnt		; Decrement wait
		brne Loop		; Continue Wait loop

		pop	olcnt		; Restore olcnt register
		pop	ilcnt		; Restore ilcnt register
		pop	waitcnt		; Restore wait register
		ret				; Return from subroutine

;***********************************************************
;*	Additional Program Includes
;***********************************************************
.include "LCDDriver.asm"
