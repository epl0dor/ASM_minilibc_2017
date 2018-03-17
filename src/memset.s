BITS		64

SECTION		.text
GLOBAL		memset

memset:
	ENTER	0, 0

while:
	CMP	RDX, 0
	JE	end
	MOV	BYTE [RDI], SIL
	DEC	RDX
	INC	RDI
	JMP	while

end:
	MOV	RAX, RDI
	LEAVE
	RET
