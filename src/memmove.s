BITS	64

SECTION	.text
; GLOBAL	memmove

; memmove:
; 	ENTER	0, 0
; 	CMP	RDI, RSI
; 	JE	end

; if:
; 	JL	src_before_dest
; 	JMP	src_after_dest

; src_before_dest:
; 	ADD	RSI, RDX
; 	DEC	RSI
; 	ADD	RDI, RDX
; 	DEC	RDI

; while1:
; 	CMP	RDX, 0
; 	JE	end
; 	MOV	DIL, SIL
; 	DEC	RSI
; 	DEC	RDI
; 	DEC	RDX
; 	JMP	while1

; src_after_dest:
;  	CMP	RDX, 0
;  	JE	end
;  	MOV	DIL, SIL
;  	DEC	RDX
; 	INC	RDI
; 	INC	RSI
;  	JMP	src_after_dest

; end:
; 	MOV	RAX, RDI
; 	LEAVE
; 	RET
