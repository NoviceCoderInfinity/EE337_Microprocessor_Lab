ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL MAC
HERE: SJMP HERE
ORG 130H
MAC:
//E char I:70h = DFh, E4h, 01h,00h, FFh, F1h
//use this operation to insert values of a1,a2,a3,b1,b2,b3 values respectively
MOV A, 70H // A1 = val at 70H
MOV B, 73H // B1 = val at 73H
MUL AB // A1*B1

MOV R0, A // LSB of A*B
MOV R1, B // MSB of A*B

MOV A, 71H // A = val at 71H
MOV B, 74H // B = val at 74H
MUL AB // A2*B2
MOV 50H, #00H
LCALL ADD16

MOV A, 72H // A = val at 72H
MOV B, 75H // B = val at 75H
MUL AB // A3*B3

MOV R0, 52H
MOV R1, 51H
LCALL ADD16
RET

ADD16:
CLR C
ADD A, R0
MOV 52H, A

MOV A, B
ADDC A, R1
MOV 51H, A

JNC ABC
INC 50H
ABC:RET

END