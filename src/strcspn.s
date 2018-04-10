BITS		64
SECTION		.text
GLOBAL		strcspn

strcspn:
	ENTER	0, 0
	XOR	RDX, RDX
	XOR	RCX, RCX
	XOR	R8, R8
	JMP	while

char_not_found:
	XOR	RCX, RCX
	INC	R8

while:
	MOV	DL, BYTE [RDI + R8]
	CMP	DL, BYTE [RSI + RCX]
	JE	found
	CMP	BYTE [RSI + RCX], 0
	JE	char_not_found
	INC	RCX
	JMP	while

found:
	MOV	RAX, R8
	LEAVE
	RET
