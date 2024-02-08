org 00h
ljmp main
DELAY_OF_50_MS:
	MOV R2,#185
	BACK1:
	MOV R1,#0FFH
	BACK :
	DJNZ R1, BACK
	DJNZ R2, BACK1
RET
DELAY_1_S:
	MOV R3,#20
	LOOP123:
	ACALL DELAY_OF_50_MS
	DJNZ R3,LOOP123
RET
DELAY_5_S:
	MOV R4,#5
	LOOP1234:
		ACALL DELAY_1_S
	DJNZ R4,LOOP1234
RET
READ_NIBBLE:
	;MOV P1,#0FH
	MOV P1,#0xFF
	ACALL DELAY_5_S
	MOV A,P1
	ANL A,#0FH
	MOV P1,#0
	MOV @R0,A
	ACALL DELAY_1_S
	SWAP A
	MOV P1,A
	acall DELAY_5_S
RET

checksum_byte:
MOV A,@R1
SWAP A ;MSB
INC R1
ADD A,@R1
MOV R2,A
INC R1
MOV A,@R1
SWAP A
INC R1
ADD A,@R1
ADD A,R2
CPL A
INC A
MOV R4,A
MOV @R0,A
RET

org 100h
main:
	;MOV P1,#0FH
	MOV R0,#4EH
	ACALL READ_NIBBLE
	INC R0
	ACALL READ_NIBBLE
	INC R0
	ACALL READ_NIBBLE
	INC R0
	ACALL READ_NIBBLE
	INC R0
	MOV R1,#4EH
	ACALL checksum_byte
	
	MOV P1,A ; SHOWING UPPER BYTE
	ACALL DELAY_1_S
	ACALL DELAY_1_S
	
	
	MOV A,R4
	SWAP A
	MOV P1,A
	HERE:SJMP HERE
	END