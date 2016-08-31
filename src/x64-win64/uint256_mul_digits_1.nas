	bits 64
	global mg_uint256_mul_digits_1

section .text

; void mg_uint256_mul_digits_1();
;	rcx			op1				const mg_uint256 *
;	rdx			op1_digits		int
;	r8			op2				const mg_uint256 *
;	r9			op2_digits		int
;	[rbp+48]	low				mg_uint256 *
;	[rbp+56]	high			mg_uint256 *
mg_uint256_mul_digits_1:
	push		rbp
	mov			rbp, rsp
	
	; ëÂÇ´Ç¢ï˚Çì‡ë§ÉãÅ[ÉvÇ÷
	cmp			rdx,	r9
	jae			_MUL_BODY
	xchg		rcx,	r8
	xchg		rdx,	r9
_MUL_BODY:
	test		rdx,	rdx
	jz			_MUL_0x0
	dec			rdx
	jz			_MUL_1x1
	dec			rdx
	jz			_MUL_2xN
	dec			rdx
	jz			_MUL_3xN
	dec			rdx
	jz			_MUL_4xN

;----------------------------------------------------------------
; multiply 0 * N
;----------------------------------------------------------------
_MUL_0x0:
	mov		r10,		qword [rbp+48]
	mov		r11,		qword [rbp+56]

	pxor	xmm0,		xmm0
	movdqu	[r10],		xmm0
	movdqu	[r10+16],	xmm0

	movdqu	[r11],		xmm0
	movdqu	[r11+16],	xmm0

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
	mov		r11,		qword [rbp+56]

	pxor	xmm0,		xmm0
	mov		[r10],		rax
	mov		[r10+8],	rdx
	movdqu	[r10+16],	xmm0

	movdqu	[r11],		xmm0
	movdqu	[r11+16],	xmm0

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
	; copy buffer
	mov			rdi,			qword [rbp+48]
	mov			rsi,			qword [rbp+56]

	movdqu		xmm0,			[rsp]
	movdqu		xmm1,			[rsp+16]
	movdqu		xmm2,			[rsp+32]
	movdqu		xmm3,			[rsp+48]
	movdqu		[rdi],			xmm0
	movdqu		[rdi+16],		xmm1
	movdqu		[rsi],			xmm2
	movdqu		[rsi+16],		xmm3

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
