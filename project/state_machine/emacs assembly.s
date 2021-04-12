Main:
	mov.b &P2IN, R8
	xor.b #0x0F, R8
	mov.b R8, R4
	mov.b R8, R5
	mov.b R8, R6
	mov.b R8, R7

	cmp #0x01, R4
	jeq green
	cmp #0x02, R5
	jeq red
	cmp #0x04, R6
	jeq both
	cmp #0x08, R7
	jeq off
	jmp Main
green:
	mov.b #0x01, &P1OUT
	jmp Main
red:
	mov.b #0x40, &P1OUT
	jmp Main
both:
	mov.b #0x42, &P1OUT
	jmp Main
off:
	mov.b #0x00, &P1OUT
	jmp Main
