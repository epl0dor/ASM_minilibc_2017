BITS		64

SECTION		.text
GLOBAL		strpbrk

strpbrk:
	ENTER	0, 0
	XOR	RAX, RAX
	XOR	RDX, RDX
	XOR	RCX, RCX
	JMP	while

inc_str:
	XOR	RDX, RDX
	INC	RSI

while:
	CMP	BYTE [RSI], 0
	JE	end
	CMP	BYTE [RDI + RDX], 0
	JE	inc_str
	MOV	CL, BYTE [RSI]
	CMP	CL, BYTE [RDI + RDX]
	JE	found
	INC	RDX
	JMP	while

found:
	ADD	RDI, RDX
	MOV	RAX, RDI

end:
	LEAVE
	RET
