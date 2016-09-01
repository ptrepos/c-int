	bits 64
	global mg_uint256_mul_digits

section .data
	JmpTable:	dq	_MUL_0x0, _MUL_1x1, _MUL_2xN, _MUL_3xN, _MUL_4xN, 0, 0, 0

section .text

; int mg_uint256_mul_digits();
;	rcx			op1				const mg_uint256 *
;	rdx			op1_digits		int
;	r8			op2				const mg_uint256 *
;	r9			op2_digits		int
;	[rbp+48]	ret				mg_uint256 *
;
;	return		unoverflow: 0, overflow: 1
mg_uint256_mul_digits:
	push		rbp
	mov			rbp, rsp
	
	; ëÂÇ´Ç¢ï˚Çì‡ë§ÉãÅ[ÉvÇ÷
	cmp			rdx,		r9
	jae			_MUL_BODY
	xchg		rcx,		r8
	xchg		rdx,		r9
_MUL_BODY:
	and			rdx,		0x7
	lea			rax,		[REL JmpTable]
	jmp			[rax+rdx*8]

;----------------------------------------------------------------
; multiply 0 * N
;----------------------------------------------------------------
_MUL_0x0:
	mov		r10,		qword [rbp+48]

	pxor	xmm0,		xmm0
	movdqu	[r10],		xmm0
	movdqu	[r10+16],	xmm0

	xor		rax,		rax

	mov		rsp,	rbp
	pop		rbp
	ret

;----------------------------------------------------------------
; multiply 1 * N
;----------------------------------------------------------------
_MUL_1x1:
	; op1[i]
	mov		rax,		[rcx]
	; op1[i] * op2[j]
	mul		qword [r8]
	
	mov		r10,		qword [rbp+48]

	pxor	xmm0,		xmm0
	mov		[r10],		rax
	mov		[r10+8],	rdx
	movdqu	[r10+16],	xmm0
	
	xor		rax,		rax

	mov		rsp,	rbp
	pop		rbp
	ret

;----------------------------------------------------------------
; multiply 2 * N
;----------------------------------------------------------------
_MUL_2xN:
	push	rbx
	push	rdi
	push	rsi
	push	r12
	push	r13
	push	r14
	push	r15
	
	sub		rsp,	72
	
	pxor	xmm0,		xmm0
	movdqu	[rsp],		xmm0
	movdqu	[rsp+16],	xmm0
	movdqu	[rsp+32],	xmm0
	movdqu	[rsp+48],	xmm0

	xor		r10,	r10
_MUL_2xN_LOOP_OP2:
	xor		rbx,	rbx

	; &buf[k]
	lea		rdi,	[rsp+r10*8]

	; op1[i]
	mov		rax,	[rcx]

	; op1[i] * op2[j]
	mul		qword [r8+r10*8]

	add		rax,	[rdi+0]
	adc		rdx,	[rdi+8]
	mov		r11,	rbx
	adc		r11,	[rdi+16]
	setb	bl
	
	mov		r12,	rax
	mov		r13,	rdx
	mov		r14,	r11

	mov		rax,	[rcx+8]

	; op1[i+1] * op2[j]
	mul		qword [r8+r10*8]
	
	add		rax,	r13
	adc		rdx,	r14
	mov		r11,	rbx
	adc		r11,	[rdi+24]

	mov		[rdi+0],	r12
	mov		[rdi+8],	rax
	mov		[rdi+16],	rdx
	mov		[rdi+24],	r11

	inc			r10
	cmp			r10,	r9

	jb			_MUL_2xN_LOOP_OP2
	
	jmp			_EXIT

;----------------------------------------------------------------
; multiply 3 * N
;----------------------------------------------------------------
_MUL_3xN:
	push	rbx
	push	rdi
	push	rsi
	push	r12
	push	r13
	push	r14
	push	r15
	
	sub		rsp,	72
	
	pxor	xmm0,		xmm0
	movdqu	[rsp],		xmm0
	movdqu	[rsp+16],	xmm0
	movdqu	[rsp+32],	xmm0
	movdqu	[rsp+48],	xmm0

	xor		r10,	r10
_MUL_3xN_LOOP_OP2:
	xor		rbx,	rbx

	; &buf[k]
	lea		rdi,	[rsp+r10*8]

	; op1[0]
	mov		rax,	[rcx]

	; op1[0] * op2[j]
	mul		qword [r8+r10*8]

	add		rax,	[rdi+0]
	adc		rdx,	[rdi+8]
	mov		r11,	rbx
	adc		r11,	[rdi+16]
	setb	bl
	
	mov		r12,	rax
	mov		r13,	rdx
	mov		r14,	r11

	; op1[1]
	mov		rax,	[rcx+8]

	; op1[1] * op2[j]
	mul		qword [r8+r10*8]
	
	add		rax,	r13
	adc		rdx,	r14
	mov		r11,	rbx
	adc		r11,	[rdi+24]
	setb	bl

	mov		r13,	rax
	mov		r14,	rdx
	mov		r15,	r11
	
	; op1[2]
	mov		rax,	[rcx+16]

	; op1[2] * op2[j]
	mul		qword [r8+r10*8]
	
	add		rax,	r14
	adc		rdx,	r15
	mov		r11,	rbx
	adc		r11,	[rdi+32]

	mov		[rdi+0],	r12
	mov		[rdi+8],	r13
	mov		[rdi+16],	rax
	mov		[rdi+24],	rdx
	mov		[rdi+32],	r11

	inc			r10
	cmp			r10,	r9

	jb			_MUL_3xN_LOOP_OP2
	
	jmp			_EXIT

;----------------------------------------------------------------
; multiply 4 * N
;----------------------------------------------------------------
_MUL_4xN:
	push	rbx
	push	rdi
	push	rsi
	push	r12
	push	r13
	push	r14
	push	r15
	
	sub		rsp,	72
	
	pxor	xmm0,		xmm0
	movdqu	[rsp],		xmm0
	movdqu	[rsp+16],	xmm0
	movdqu	[rsp+32],	xmm0
	movdqu	[rsp+48],	xmm0

	xor		r10,	r10
_MUL_4xN_LOOP_OP2:
	xor		rbx,	rbx

	; &buf[k]
	lea		rdi,	[rsp+r10*8]

	; op1[0]
	mov		rax,	[rcx]

	; op1[0] * op2[j]
	mul		qword [r8+r10*8]

	add		rax,	[rdi+0]
	adc		rdx,	[rdi+8]
	mov		r11,	rbx
	adc		r11,	[rdi+16]
	setb	bl
	
	mov		r12,	rax
	mov		r13,	rdx
	mov		r14,	r11

	; op1[1]
	mov		rax,	[rcx+8]

	; op1[1] * op2[j]
	mul		qword [r8+r10*8]
	
	add		rax,	r13
	adc		rdx,	r14
	mov		r11,	rbx
	adc		r11,	[rdi+24]
	setb	bl

	mov		r13,	rax
	mov		r14,	rdx
	mov		r15,	r11
	
	; op1[2]
	mov		rax,	[rcx+16]

	; op1[2] * op2[j]
	mul		qword [r8+r10*8]
	
	add		rax,	r14
	adc		rdx,	r15
	mov		r11,	rbx
	adc		r11,	[rdi+32]
	setb	bl

	mov		r14,	rax
	mov		r15,	rdx
	mov		rsi,	r11

	; op1[3]
	mov		rax,	[rcx+24]

	; op1[3] * op2[j]
	mul		qword [r8+r10*8]
	
	add		rax,	r15
	adc		rdx,	rsi
	mov		r11,	rbx
	adc		r11,	[rdi+40]

	mov		[rdi+0],	r12
	mov		[rdi+8],	r13
	mov		[rdi+16],	r14
	mov		[rdi+24],	rax
	mov		[rdi+32],	rdx
	mov		[rdi+40],	r11

	inc			r10
	cmp			r10,	r9

	jb			_MUL_4xN_LOOP_OP2
	
	jmp			_EXIT


;----------------------------------------------------------------
; EXIT
;----------------------------------------------------------------
_EXIT:
	mov			rax,	qword [rsp+32]
	mov			rbx,	qword [rsp+40]
	or			rax,	qword [rsp+48]
	or			rbx,	qword [rsp+56]
	or			rax,	rbx

	jz			_NOT_OVERFLOW;
	
	; return overflow
	mov			rax,	1
	
	jmp			_NOT_OVERFLOW_END;
_NOT_OVERFLOW:
	; return not overflow
	xor			rax,	rax

	; copy buffer
	mov			rdi,			qword [rbp+48]

	movdqu		xmm0,			[rsp]
	movdqu		xmm1,			[rsp+16]
	movdqu		[rdi],			xmm0
	movdqu		[rdi+16],		xmm1
_NOT_OVERFLOW_END:

	add			rsp,	72
	
	pop			r15
	pop			r14
	pop			r13
	pop			r12
	pop			rsi
	pop			rdi
	pop			rbx

	mov			rsp,	rbp
	pop			rbp
	ret
