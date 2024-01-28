ORG 0H
LJMP MAIN
ORG 100H
MAIN:
MOV P1, #01H
CALL delay_5s
MOV P1, #00H
HERE: SJMP HERE
ORG 130H

delay_5s:
PUSH 00H
MOV R0, #200
H3: ACALL delay_1ms
DJNZ R0, H3
POP 00H
RET

delay_1ms:
PUSH 00H
MOV R0, #100
H2: ACALL delay_250us
DJNZ R0, H2
POP 00H
RET

delay_250us:
PUSH 00H
MOV R0, #244
H1: DJNZ R0, H1
POP 00H
RET

END