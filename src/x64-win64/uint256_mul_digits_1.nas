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
	
	pop			r12
	pop			rsi
	pop			rdi
	pop			rbx

	mov			rsp,	rbp
	pop			rbp
	ret
