BITS		64

SECTION		.text
GLOBAL		strncmp

strncmp:
	ENTER	0, 0
	XOR	RCX, RCX
	XOR	R8, R8

while:
	MOV     R8B, BYTE [RDI]
        MOV     CL, BYTE [RSI]
        CMP     BYTE [RDI], 0
	JE      end
	INC     RDI
	INC     RSI
	DEC	RDX
	CMP	RDX, 0
	JE	end
	CMP     R8B, CL
	JE      while

end:
	SUB	R8, RCX
	MOV	RAX, R8
	LEAVE
	RET
