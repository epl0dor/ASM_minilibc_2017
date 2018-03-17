BITS		64

SECTION		.text
GLOBAL		strstr

strstr:
	ENTER	0, 0
	MOV	RAX, RDI
	CMP	BYTE [RSI], 0
	JE	end
	JMP	reset_vars

inc_haystack:
	ADD	RAX, RCX
	JMP	reset_vars

inc_counter:
	INC	RCX

match:
	CMP	BYTE [RSI + RCX], 0
	JE	end
	MOV	DL, BYTE [RSI + RCX]
	CMP	DL, BYTE [RAX + RCX]
	JE	inc_counter
	JNE	inc_haystack

reset_vars:
	XOR	RDX, RDX
	XOR	RCX, RCX

find_first_letter:
	CMP	BYTE [RAX], 0
	JE	end1
	MOV	DL, BYTE [RSI]
	CMP	DL, BYTE [RAX]
	JE	match
	INC	RAX
	JMP	find_first_letter

end1:
	XOR	RAX, RAX

end:
	LEAVE
	RET
