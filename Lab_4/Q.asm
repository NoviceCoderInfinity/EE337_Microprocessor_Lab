ORG 0H
LJMP MAIN
ORG 100H

MAIN:
ACALL TAKE_INP
ACALL QUANT_ENC
loop: ACALL LED_DISP
JMP loop
 
HERE: SJMP HERE

ORG 130H

TAKE_INP:
	//FIRST input 00H
	MOV P1, #1FH //P1 = 00011111
	ACALL delay_8s
	MOV A, P1
	MOV B, #16
	MUL AB //left shifts A by 4 bits
	MOV 00H, A
	CLR P1.4
	SETB P1.5
	ACALL delay_8s
	MOV A, P1
	XRL A, #20H
	ADD A, 00H
	MOV 00H, A

	//SECOND input 01H
	SETB P1.4
	SETB P1.5
	ACALL delay_8s
	MOV A, P1
	MOV B, #16
	MUL AB
	MOV 01H, A
	CLR P1.4
	CLR P1.5
	SETB P1.6
	acall delay_8s
	MOV A, P1
	XRL A, #40H//make the sixth bit 0
	ADD A, 01H
	MOV 01H, A

	//THIRD input 02H
	SETB P1.4
	CLR P1.5
	SETB P1.6
	ACALL delay_8s
	MOV A, P1
	MOV B, #10H
	MUL AB
	MOV 02H, A
	CLR P1.4
	SETB P1.5
	SETB P1.6
	ACALL delay_8s
	MOV A, P1
	XRL A, #60H
	ADD A, 02H
	MOV 02H, A

	//FOURTH input 03H
	SETB P1.4
	SETB P1.5
	SETB P1.6
	ACALL delay_8s
	MOV A, P1
	MOV B, #10H
	MUL AB
	MOV 03H, A
	CLR P1.4
	CLR P1.5
	CLR P1.6
	SETB P1.7
	ACALL delay_8s
	MOV A, P1
	XRL A, #80H
	ADD A, 03H
	MOV 03H, A
	
	CLR P1.4
	CLR P1.5
	CLR P1.6
	CLR P1.7
RET

QUANT_ENC:
	//first output IN 04H
	MOV A, 00H
	SUBB A, #0C0H
	JNC out_1d
	
	MOV A, 00H
	SUBB A, #80H
	JNC out_1c

	MOV A, 00H
	SUBB A, #40H
	JNC out_1b

	MOV 04H, #10H//00010000 
	JMP out_2
	out_1b: MOV 04H, #20H//00100000
	JMP out_2
	out_1c: MOV 04H, #40H//01000000
	JMP out_2
	out_1d: MOV 04H, #80H//10000000

	//second output IN 05H
	out_2:
	MOV A, 01H
	SUBB A, #0C0H
	JNC out_2d

	MOV A, 01H
	SUBB A, #80H
	JNC out_2c

	MOV A, 01H
	SUBB A, #40H
	JNC out_2b

	MOV 05H, #10H//00010000 
	JMP out_3
	out_2b: MOV 05H, #20H//00100000
	JMP out_3
	out_2c: MOV 05H, #40H//01000000
	JMP out_3
	out_2d: MOV 05H, #80H//10000000

	//third output IN 06H
	out_3:
	MOV A, 02H
	SUBB A, #0C0H
	JNC out_3d

	MOV A, 02H
	SUBB A, #80H
	JNC out_3c

	MOV A, 02H
	SUBB A, #40H
	JNC out_3b


	MOV 06H, #10H//00010000 
	JMP out_4
	out_3b: MOV 06H, #20H//00100000
	JMP out_4
	out_3c: MOV 06H, #40H//01000000
	JMP out_4
	out_3d: MOV 06H, #80H//10000000

	//fourth output IN 07H
	out_4: 
	MOV A, 03H
	SUBB A, #0C0H
	JNC out_4d

	MOV A, 03H
	SUBB A, #80H
	JNC out_4c

	MOV A, 03H
	SUBB A, #40H
	JNC out_4b

	MOV 07H, #10H//00010000 
	JMP out
	out_4b: MOV 07H, #20H//00100000
	JMP out
	out_4c: MOV 07H, #40H//01000000
	JMP out
	out_4d: MOV 07H, #80H//10000000
	out:	
RET

LED_DISP:
	MOV P1, 04H
	acall delay_4s

	MOV P1, 05H
	acall delay_4s

	MOV P1, 06H
	acall delay_4s

	MOV P1, 07H
	acall delay_4s
RET
 

delay_8s:
push 16h
push 17h
mov 17h, #0A0h
f11: mov 16h, #0C8H
h22: acall delay_250us
djnz 16h, h22
djnz 17h, f11
pop 17h
pop 16h
RET

delay_4s:
push 16h
push 17h
mov 17h, #50h
f1: mov 16h, #0C8H
h2: acall delay_250us
djnz 16h, h2
djnz 17h, f1
pop 17h
pop 16h
RET

delay_250us:
push 16h
mov 16h, #244
h1: djnz 16h, h1
pop 16h
RET

END