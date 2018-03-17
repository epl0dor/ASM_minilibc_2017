BITS		64

SECTION		.text
GLOBAL		strchr

strchr:
	ENTER	0, 0
	XOR	RAX, RAX
	XOR	RDX, RDX

while:
	CMP	BYTE [RDI + RDX], 0
	JE	end2
	CMP	BYTE [RDI + RDX], SIL
	JE	end1
	INC	RDX
	JMP	while

end1:
	MOV	RAX, RDI
	ADD	RAX, RDX

end2:
	LEAVE
	RET
