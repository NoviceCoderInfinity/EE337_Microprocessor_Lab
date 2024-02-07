 ORG 0H
 LJMP MAIN
 ORG 100H
 MAIN:
 CALL TAKE_INP
 CALL QUANT_ENC
 CALL LED_DISP
 HERE: SJMP HERE
 ORG 130H


TAKE_INP:
 // ADD YOUR CODE HERE
 QUANT_ENC:
 // ADD YOUR CODE HERE
 LED_DISP:
 // ADD YOUR CODE HERE
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