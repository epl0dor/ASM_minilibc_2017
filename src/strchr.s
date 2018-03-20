BITS		64

SECTION		.text
GLOBAL		strchr

strchr:
	ENTER	0, 0
	XOR	RAX, RAX

while:
	CMP	BYTE [RDI], SIL
	JE	end1
	CMP	BYTE [RDI], 0
	JE	end2
	INC	RDI
	JMP	while

end1:
	MOV	RAX, RDI

end2:
	LEAVE
	RET
