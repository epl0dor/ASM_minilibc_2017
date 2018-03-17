BITS		64
SECTION		.text
GLOBAL		strcspn

strcspn:
	ENTER	0, 0
	XOR	RDX, RDX
	XOR	RCX, RCX
	JMP	while

char_not_found:
	XOR	RCX, RCX
	INC	RSI

while:
	MOV	DL, BYTE [RSI]
	CMP	DL, BYTE [RDI + RCX]
	JE	found
	CMP	BYTE [RDI + RCX], 0
	JE	char_not_found
	INC	RCX
	JMP	while

found:
	MOV	RAX, RCX
	LEAVE
	RET
