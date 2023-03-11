;***********************************************************
;*	 Author: Zach Taylor and Sara Vanaken
;*	   Date: 2/22/23
;***********************************************************

.include "m32U4def.inc"			; Include definition file

;***********************************************************
;*	Internal Register Definitions and Constants
;***********************************************************
.def	mpr = r16				; Multipurpose register	
.def	waitcnt = r17			; Wait Loop Counter
.def	ilcnt = r18				; Inner Loop Counter
.def	olcnt = r19				; Outer Loop Counter	
.def    maxSpeed = r20          ; Max speed
.def	speedLvl = r21	        ; Current speed level

.equ	WTime = 20				; Time to wait in wait loop
.equ	EngEnR = 5				; right Engine Enable Bit
.equ	EngEnL = 6				; left Engine Enable Bit
.equ	EngDirR = 4				; right Engine Direction Bit
.equ	EngDirL = 7				; left Engine Direction Bit

;***********************************************************
;*	Start of Code Segment
;***********************************************************
.cseg							; beginning of code segment

;***********************************************************
;*	Interrupt Vectors
;***********************************************************
.org	$0000
		rjmp	INIT			; reset interrupt

.org	$0056					; end of interrupt vectors

;***********************************************************
;*	Program Initialization
;***********************************************************
INIT:
		; Initialize the Stack Pointer
		ldi	mpr, low(RAMEND)		; Load MPR with low byte of RAEMEND
		out	SPL, mpr				 ; Load SPL with low byte of RAMEND
		ldi	mpr, high(RAMEND)		; Load MPR with high byte of RAEMEND
		out	SPH, mpr				; Load SPH with high byte of RAMEND

		; Initialize Port B for output
		ldi	mpr, $FF				; Set Port B Data Direction Register
		out	DDRB, mpr				; for output
		ldi	mpr, $00				; Initialize Port B Data Register
		out	PORTB, mpr				; so all Port B outputs are low

		; Initialize Port D for input
		ldi	mpr, $00				; Set Port D Data Direction Register
		out	DDRD, mpr				; for input
		ldi	mpr, $FF				; Initialize Port D Data Register
		out	PORTD, mpr				; so all Port D inputs are Tri-State

		; Configure 16-bit Timer/Counter 1
		ldi	mpr, 0b11110001			; Set values in TCCR1A reg
		sts	TCCR1A, mpr				; 8-bit fast PWM, no pres-scaling

		ldi	mpr, 0b00001001			; Set values in TCCR1B reg
		sts	TCCR1B, mpr

		; Set TekBot to Move Forward on Port B
		ldi	mpr, (1<<EngDirR|1<<EngDirL)	; Load Move Forward Command
		out	PORTB, mpr						; Send command to motors

		; Set initial speed, display on Port B pins 3:0
		ldi	mpr, 0b11110000			; initial display (halt, speed level 0)
		out	PORTB, mpr				; and output to Port B

		ldi speedLvl, $00           ; Initial speed
		ldi mpr, $00				; Load 0 into mpr

		sts OCR1AH, mpr             ; Load high byte
		sts OCR1AL, mpr				; Load low byte

		sts OCR1BH, mpr				; Load high byte
		sts OCR1BL, mpr				; Load low byte

;***********************************************************
;*	Main Program
;***********************************************************
MAIN:
		in mpr, PIND				; get speed input from PORT D

		cpi mpr, 0b11101111			; Check if pin 4
		brne NEXT					; Move on if not
		rcall SPEED_UP				; Call speed up
		rjmp MAIN					; Loop back MAIN
NEXT:
		cpi mpr, 0b11011111         ; Check if pin 4
		brne NEXT2                  ; Move on if not
		rcall SPEED_DOWN            ; Call speed down
		rjmp MAIN                   ; Loop back MAIN
NEXT2:
		cpi mpr, 0b10111111         ; Check if pin 6
		brne MAIN                   ; Move on if not
		rcall SPEED_MAX             ; Call speed max
		rjmp MAIN                   ; Loop back MAIN

;***********************************************************
;*	Functions and Subroutines
;***********************************************************
;-----------------------------------------------------------
; Func:	SPEED_MAX
; Desc:	Set the speed to max at 255
;-----------------------------------------------------------
SPEED_MAX:
		push	mpr				; Save mpr register
		push	waitcnt			; Save wait register
		in		mpr, SREG		; Save program state
		push	mpr				; Save SREG

		ldi		waitcnt, WTime	; Wait for 1 second
		rcall	Wait			; Call wait function

		cpi speedLvl, 15		; Check current speed level
		breq SKIP               ; Break out if at max

		ldi speedLvl, 15		; Load max speed level
		ldi maxSpeed, $FF		; Load max speed compare value

		sts OCR1AL, maxSpeed	; Set OCR1A to max speed
		sts OCR1BL, maxSpeed	; Set OCR1B to max speed
		
		ldi	mpr, 0b10011111		; Display level change on
		out	PORTB, mpr			; PORTB pins 3:0

SKIP:
		pop		mpr				; Restore program state
		out		SREG, mpr		; Restore SREG
		pop		waitcnt			; Restore wait register
		pop		mpr				; Restore mpr
		ret						; Return from subroutine

;-----------------------------------------------------------
; Func:	SPEED_UP
; Desc:	Increase speed by 17, cannot go above speed level 15
;-----------------------------------------------------------
SPEED_UP:
		push	mpr				; Save mpr register
		push	waitcnt			; Save wait register
		in		mpr, SREG		; Save program state
		push	mpr				; Save SREG

		ldi		waitcnt, WTime	; Wait for 1 second
		rcall	Wait			; Call wait function
		
		cpi speedLvl, 15		; Check current speed level
		breq SKIP_UP			; Break out if at max
		inc speedLvl			; Inc speed level

		ldi r22, 17				; Load 17 into mpr for add
		lds mpr, OCR1AL			; load stored value into mpr
		add mpr, r22			; Add 17 to compare value
		sts OCR1AL, mpr			; Restore compare value

		lds mpr, OCR1BL			; Load the compare value into mpr
		add mpr, r22			; Add 17 to compare value
		sts OCR1BL, mpr			; Restore compare value

		in mpr, PORTB			; Load PORTB into mpr
		inc mpr					; Inc its value
		out PORTB, mpr			; Load value back into PORTB
		
		
SKIP_UP:
		pop		mpr				; Restore program state
		out		SREG, mpr		; Restore SREG
		pop		waitcnt			; Restore wait register
		pop		mpr				 ; Restore mpr
		ret						; Return from subroutine

;-----------------------------------------------------------
; Func:	SPEED_DOWN
; Desc:	Decrease speed by 17, cannot go below speed level 0
;-----------------------------------------------------------
SPEED_DOWN:
		push	mpr				; Save mpr register
		push	waitcnt			; Save wait register
		in		mpr, SREG		; Save program state
		push	mpr				; Save SREG

		ldi		waitcnt, WTime	; Wait for 1 second
		rcall	Wait			; Call wait function

		cpi speedLvl, 0			; Check current speed level
		breq SKIP_DOWN			; Break out if at max
		dec speedLvl			; Inc speed level

		ldi r22, 17				; Load 17 into mpr for add
		lds mpr, OCR1AL			; load stored value into mpr
		sub mpr, r22			; Add 17 to compare value
		sts OCR1AL, mpr			; Restore compare value

		lds mpr, OCR1BL			; Load the compare value into mpr
		sub mpr, r22			; Subtract 17 to compare value
		sts OCR1BL, mpr			; Restore compare value
		
		in mpr, PORTB			; Load PORTB into mpr
		dec mpr					; Inc its value
		out PORTB, mpr			; Load value back into PORTB

SKIP_DOWN:
		pop		mpr				; Restore program state
		out		SREG, mpr		; Restore SREG
		pop		waitcnt			; Restore wait register
		pop		mpr				; Restore mpr
		ret						; Return from subroutine

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
		dec		olcnt			; decrement olcnt
		brne	OLoop			; Continue Outer Loop
		dec		waitcnt			; Decrement wait
		brne	Loop			; Continue Wait loop

		pop		olcnt			; Restore olcnt register
		pop		ilcnt			; Restore ilcnt register
		pop		waitcnt			; Restore wait register
		ret						; Return from subroutine