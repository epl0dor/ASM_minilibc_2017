BITS		64

SECTION		.text
GLOBAL		strlen

strlen:
	ENTER	0, 0
 	XOR	RSI, RSI

while:
 	CMP	BYTE [RDI + RSI], 0
 	JE	end
 	INC	RSI
 	JMP	while

end:
	MOV	RAX, RSI
	LEAVE
	RET
