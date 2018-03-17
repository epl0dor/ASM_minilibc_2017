BITS		64

SECTION		.text
GLOBAL		rindex

rindex:
	ENTER	0, 0
	XOR	RAX, RAX
	XOR	RDX, RDX

strlen:
	CMP	BYTE [RDI + RDX], 0
	JE	while
	INC	RDX
	JMP	strlen

while:
 	CMP	BYTE [RDI + RDX], SIL
 	JE	occ_found
	CMP	RDX, 0
	JE	end
	DEC	RDX
 	JMP	while

occ_found:
	ADD	RDI, RDX
	MOV	RAX, RDI
	JMP	end

end:
	LEAVE
	RET
