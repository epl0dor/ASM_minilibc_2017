BITS		64

SECTION		.text
GLOBAL		memcpy

memcpy:
	ENTER	0, 0
	XOR	RCX, RCX

while:
	CMP	RDX, RCX
	JE	end
	MOV	R8B, BYTE [RSI + RCX]
	MOV	BYTE [RDI + RCX], R8B
	INC	RCX
	JMP	while

end:
	MOV	RAX, RDI
	LEAVE
	RET
