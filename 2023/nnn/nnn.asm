ORG 0H
LJMP MAIN
ORG 100H
MAIN:
MOV P1, #01H
CALL delay_1ms
MOV P1, #00H
HERE: SJMP HERE
ORG 130H
// *****************

delay_1ms:
push 00h
mov r0, #4
h2: acall delay_250us
djnz r0, h2
pop 00h
ret
delay_250us:
push 00h
mov r0, #244
h1: djnz r0, h1
pop 00h
ret

RET
END