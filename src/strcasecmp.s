BITS		64

SECTION		.text
GLOBAL		strcasecmp

strcasecmp:
	ENTER	0, 0
	XOR	RDX, RDX
	XOR	RCX, RCX
	JMP	detect_capital1

set_char_min1:
	ADD	DL, 32
	JMP	detect_capital2

is_capitalized1:
	CMP	DL, 'Z'
	JBE	set_char_min1
	JMP	detect_capital2

set_char_min2:
	ADD	CL, 32
	JMP	while

is_capitalized2:
	CMP	CL, 'Z'
	JBE	set_char_min2
	JMP	while

detect_capital1:
        MOV     DL, BYTE [RDI]
	CMP	DL, 'A'
	JAE	is_capitalized1

detect_capital2:
        MOV     CL, BYTE [RSI]
	CMP	CL, 'A'
	JAE	is_capitalized2

while:
	CMP     BYTE [RDI], 0
	JE      end
	INC     RDI
	INC     RSI
	CMP     DL, CL
	JE      detect_capital1

end:
	SUB     RDX, RCX
        MOV     RAX, RDX
	LEAVE
        RET
