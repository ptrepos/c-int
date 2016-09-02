	global _mg_uint128_mul_digits

section .text

;int mg_uint128_mul_digits()
;	[ebp+8]		op1				const mg_uint128 *
;	[ebp+12]	op1_digits		int
;	[ebp+16]	op2				const mg_uint128 *
;	[ebp+20]	op2_digits		int
;	[ebp+24]	ret				mg_uint128 *
;
;	return		unoverflow: 0, overflow: 1

_mg_uint128_mul_digits:
	push		ebp
	mov			ebp, esp
	
	; [esp]		buf		40byte
	; ecx		j
	; esi		i
	; ebx		carry

	push		ebx
	push		edi
	push		esi

	sub			esp,	40
	
	pxor		xmm1, 		xmm1
	movdqu		[esp],		xmm1
	movdqu		[esp+16],	xmm1

	xor			ecx,	ecx
_LOOP_OP2:
	xor			esi,	esi
	xor			ebx,	ebx

	lea			edi,	[esp+ecx*4]
_LOOP_OP1:

	; op1[i]
	mov			edx,	[ebp+8]

	; op2[j]
	mov			eax,	[ebp+16]
	mov			eax,	[eax+ecx*4]

	; op1[i] * op2[j]
	mul			dword [edx+esi*4]
	
	add			eax,		[edi+0]
	adc			edx,		[edi+4]
	adc			ebx,		[edi+8]
	mov			[edi+0],	eax	
	mov			[edi+4],	edx	
	mov			[edi+8],	ebx	
	mov			ebx,		0
	setb		bl
	
	lea			edi,	[edi+4]

	inc			esi
	cmp			esi,	[ebp+12]

	jb			_LOOP_OP1;
	
	inc			ecx
	cmp			ecx,	[ebp+20]

	jb			_LOOP_OP2;

	mov			eax,	dword [esp+16]
	mov			ebx,	dword [esp+20]
	or			eax,	dword [esp+24]
	or			ebx,	dword [esp+28]
	or			eax,	ebx

	jz			_NOT_OVERFLOW;
	
	; return overflow
	mov			eax,	1
	
	jmp			_NOT_OVERFLOW_END;
_NOT_OVERFLOW:
	; return not overflow
	xor			eax,	eax

	; copy buffer
	mov			edi,			dword [ebp+24]

	movdqu		xmm1,			[esp]
	movdqu		[edi+0],		xmm1
_NOT_OVERFLOW_END:

	add			esp,	40

	pop			esi
	pop			edi
	pop			ebx

	mov			esp,	ebp
	pop			ebp
	ret
