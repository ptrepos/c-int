	bits 64
	global mg_uint256_mul_digits

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
	
	; [rsp]		buf		72byte
	; rcx		j
	; rsi		i
	; rbx		carry

	push		rbx
	push		rdi
	push		rsi
	push		r12

	sub			rsp,	72
	
	mov			r10,	rcx
	mov			r11,	rdx
	
	pxor		xmm1, 		xmm1
	movdqu		[rsp],		xmm1
	movdqu		[rsp+16],	xmm1
	movdqu		[rsp+32],	xmm1
	movdqu		[rsp+48],	xmm1

	xor			rcx,	rcx
_LOOP_OP2:
	xor			rsi,	rsi
	xor			rbx,	rbx

_LOOP_OP1:
	; k = i + j
	lea			rdx,	[rcx+rsi]
	; &buf[k]
	lea			rdi,	[rsp+rdx*8]

	; op1[i]
	mov			rax,	[r10+rsi*8]

	; op1[i] * op2[j]
	mul			qword [r8+rcx*8]

	add			rax,	[rdi+0]
	adc			rdx,	[rdi+8]
	mov			r12,	rbx
	adc			r12,	[rdi+16]
	setb		bl
	
	mov	[rdi+0],	rax
	mov	[rdi+8],	rdx
	mov	[rdi+16],	r12

	inc			rsi
	cmp			rsi,	r11

	jb			_LOOP_OP1;
	
	inc			rcx
	cmp			rcx,	r9

	jb			_LOOP_OP2;

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

	movdqu		xmm1,			[rsp]
	movdqu		xmm2,			[rsp+16]
	movdqu		[rdi],			xmm1
	movdqu		[rdi+16],		xmm2
_NOT_OVERFLOW_END:

	add			rsp,	72
	
	pop			r12
	pop			rsi
	pop			rdi
	pop			rbx

	mov			rsp,	rbp
	pop			rbp
	ret
