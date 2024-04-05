ORG 0H
LJMP MAIN
ORG 100H

MAIN:
CALL DET

HERE: SJMP HERE
ORG 130H

DET:
MOV A, 61H
MOV B, 62H
MUL AB // A has LSB and B has MSB of b*c
MOV 71H, A
MOV 70H, B

MOV A, 60H
MOV B, 63H
MUL AB // A has LSB and B has MSB of a*d

MOV R0, 71H // LSB of b*c
MOV R1, 70H // MSB of b*c

SUBB A, R0 // LSB of a*d - LSB of b*c
MOV 71H, A

MOV A, B
SUBB A, R1 // MSB of a*d - LSB of b*c
MOV 70H, A

RET
END