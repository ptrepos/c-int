	global _mg_uint256_mul_digits

section .text

;int mg_uint256_mul_digits()
; RETURN
;    unoverflow: 0, overflow: 1

; PARAMETERS
%define OP1				ebp+8		; const mg_uint256 *
%define OP1_DIGITS		ebp+12		; int
%define OP2				ebp+16		; const mg_uint256 *
%define OP2_DIGITS		ebp+20		; int
%define RET_VALUE		ebp+24		; mg_uint256 *

; LOCAL
%define BUFFER			esp			; uint32_t[17]

%define STACK_SIZE		72

_mg_uint256_mul_digits:
	push		ebp
	mov			ebp, esp
	
	push		ebx
	push		edi
	push		esi

	sub			esp, STACK_SIZE
	
	pxor		xmm1, xmm1
	movdqu		[BUFFER], xmm1
	movdqu		[BUFFER+16], xmm1
	movdqu		[BUFFER+32], xmm1
	movdqu		[BUFFER+48], xmm1

	xor			ecx, ecx
_LOOP_OP2:
	xor			esi, esi
	xor			ebx, ebx

	lea			edi, [BUFFER+ecx*4]
_LOOP_OP1:

	; OP1[i]
	mov			edx, [OP1]

	; OP2[j]
	mov			eax, [OP2]
	mov			eax, [eax+ecx*4]

	; OP1[i] * OP2[j]
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
	cmp			esi,	[OP1_DIGITS]

	jb			_LOOP_OP1;
	
	inc			ecx
	cmp			ecx,	[OP2_DIGITS]

	jb			_LOOP_OP2;

	mov			eax,	dword [esp+32]
	mov			ebx,	dword [esp+36]
	or			eax,	dword [esp+40]
	or			ebx,	dword [esp+44]
	or			eax,	dword [esp+48]
	or			ebx,	dword [esp+52]
	or			eax,	dword [esp+56]
	or			ebx,	dword [esp+60]
	or			eax,	ebx

	jz			_NOT_OVERFLOW;
	
	; return overflow
	mov			eax,	1
	
	jmp			_NOT_OVERFLOW_END;
_NOT_OVERFLOW:
	; return not overflow
	xor			eax,	eax

	; copy buffer
	mov			edi,			dword [RET_VALUE]

	movdqu		xmm1,			[BUFFER]
	movdqu		xmm2,			[BUFFER+16]
	movdqu		[edi+0],		xmm1
	movdqu		[edi+16],		xmm2
_NOT_OVERFLOW_END:

	add			esp,	STACK_SIZE

	pop			esi
	pop			edi
	pop			ebx

	mov			esp,	ebp
	pop			ebp
	ret
