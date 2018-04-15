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
	INC	RDI

while:
	CMP	BYTE [RDI], 0
	JE	end
	CMP	BYTE [RSI + RDX], 0
	JE	inc_str
	MOV	CL, BYTE [RDI]
	CMP	CL, BYTE [RSI + RDX]
	JE	found
	INC	RDX
	JMP	while

found:
	MOV	RAX, RDI

end:
	LEAVE
	RET
