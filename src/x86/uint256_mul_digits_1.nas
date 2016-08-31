	global _mg_uint256_mul_digits_1

section .text

; void mg_uint256_mul_digits_1();
;	[ebp+8]		op1				const mg_uint256 *
;	[ebp+12]	op1_digits		int
;	[ebp+16]	op2				const mg_uint256 *
;	[ebp+20]	op2_digits		int
;	[ebp+24]	low				mg_uint256 *
;	[ebp+28]	high			mg_uint256 *

_mg_uint256_mul_digits_1:
	push		ebp
	mov			ebp, esp
	
	; [esp]		buf		72byte
	; ecx		j
	; esi		i
	; ebx		carry

	push		ebx
	push		edi
	push		esi

	sub			esp,	72
	
	pxor		xmm1, 		xmm1
	movdqu		[esp],		xmm1
	movdqu		[esp+16],	xmm1
	movdqu		[esp+32],	xmm1
	movdqu		[esp+48],	xmm1

	xor			ecx,	ecx
_LOOP_OP2:
	xor			esi,	esi
	xor			ebx,	ebx

_LOOP_OP1:
	; k = i + j
	lea			edx,	[ecx+esi]
	; &buf[k]
	lea			edi,	[esp+edx*4]

	; op1[i]
	mov			edx,	[ebp+8]

	; op2[j]
	mov			eax,	[ebp+16]
	mov			eax,	[eax+ecx*4]

	; op1[i] * op2[j]
	mul			dword [edx+esi*4]
	
	add			[edi+0],	eax
	adc			[edi+4],	edx
	adc			[edi+8],	ebx
	setb		bl

	inc			esi
	cmp			esi,	[ebp+12]

	jb			_LOOP_OP1;
	
	inc			ecx
	cmp			ecx,	[ebp+20]

	jb			_LOOP_OP2;

	; copy buffer
	mov			edi,			dword [ebp+24]
	mov			esi,			dword [ebp+28]

	movdqu		xmm0,			[esp]
	movdqu		xmm1,			[esp+16]
	movdqu		xmm2,			[esp+32]
	movdqu		xmm3,			[esp+48]
	movdqu		[edi+0],		xmm0
	movdqu		[edi+16],		xmm1
	movdqu		[esi+0],		xmm2
	movdqu		[esi+16],		xmm3

	add			esp,	72

	pop			esi
	pop			edi
	pop			ebx

	mov			esp,	ebp
	pop			ebp
	ret
