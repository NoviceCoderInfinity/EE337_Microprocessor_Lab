// -- DO NOT CHANGE ANYTHING UNTIL THE **** LINE--//
ORG 0H
LJMP MAIN
ORG 100H
MAIN:
lCALL MAX
HERE: 
mov 70h, r3
SJMP HERE
ORG 130H
// *****************
MAX:
	MOV R0, #60H
	mov r3, 60h
	
	MOV r1, #08h
	LOOP:	
	DEC r1
	mov a, r1
	jz here
	
	inc r0
	mov a, @r0
	clr c
	mov b, a
	subb a, r3
	JC LOOP
	mov r3, b
	jmp LOOP
	
// ADD YOUR CODE HERE
END