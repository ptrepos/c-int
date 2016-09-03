	global _mg_uint128_mul_digits_1

section .text

;void mg_uint128_mul_digits_1()
; PARAMETERS
%define OP1				ebp+8		; const mg_uint128 *
%define OP1_DIGITS		ebp+12		; int
%define OP2				ebp+16		; const mg_uint128 *
%define OP2_DIGITS		ebp+20		; int
%define LOW_VALUE		ebp+24		; mg_uint128 *
%define HIGH_VALUE		ebp+28		; mg_uint128 *

; LOCAL
%define BUFFER			esp			; uint32_t[9]
%define OP2_PTR			esp+40		; int

%define STACK_SIZE		44

_mg_uint128_mul_digits_1:
	push		ebp
	mov			ebp, esp
	
	push		ebx
	push		edi
	push		esi

	sub			esp, STACK_SIZE
	
	pxor		xmm1, xmm1
	movdqu		[BUFFER], xmm1
	movdqu		[BUFFER+16], xmm1

	; 大きい方を内側ループへ
	mov			eax, [OP1_DIGITS]
	mov			edx, [OP2_DIGITS]
	cmp			eax, edx
	jae			_MUL_BODY
	mov			ebx, [OP1]
	mov			ecx, [OP2]

	xchg		eax, edx
	xchg		ebx, ecx

	mov			[OP1_DIGITS], eax
	mov			[OP2_DIGITS], edx
	mov			[OP1], ebx
	mov			[OP2], ecx
_MUL_BODY:
	; DIGITSのポインタ化
	mov			eax,	[OP1]
	mov			ebx,	[OP1_DIGITS]
	lea			ebx,	[eax+ebx*4]
	mov			ecx,	[OP2]
	mov			edx,	[OP2_DIGITS]
	lea			edx,	[ecx+edx*4]

	mov			[OP1_DIGITS], ebx
	mov			[OP2_DIGITS], edx

	mov			ecx, [OP2]
_LOOP_OP2:
	lea			edi, [BUFFER+ecx*4] 

	mov			[OP2_PTR], ecx
	mov			eax, [OP2]
	mov			ecx, [eax+ecx*4]

	mov			esi, [OP1]
	xor			ebx, ebx
_LOOP_OP1:
	; OP2[j]
	mov			eax, ecx
	; OP1[i] * OP2[j]
	mul			dword [esi]
	
	add			eax, [edi+0]
	adc			edx, [edi+4]
	adc			ebx, [edi+8]
	mov			[edi+0], eax	
	mov			[edi+4], edx	
	mov			[edi+8], ebx	
	mov			ebx,  0
	setb		bl
	
	lea			edi, [edi+4]

	lea			esi, [esi+4]
	cmp			esi, [OP1_DIGITS]

	jb			_LOOP_OP1;
	
	mov			ecx, [OP2_PTR]
	lea			ecx, [ecx+4]
	cmp			ecx, [OP2_DIGITS]

	jb			_LOOP_OP2;

	; copy buffer
	mov			edi,			dword [LOW_VALUE]
	mov			esi,			dword [HIGH_VALUE]

	movdqu		xmm0,			[BUFFER]
	movdqu		xmm1,			[BUFFER+16]
	movdqu		[edi+0],		xmm0
	movdqu		[esi+0],		xmm1
_NOT_OVERFLOW_END:

	add			esp,	STACK_SIZE

	pop			esi
	pop			edi
	pop			ebx

	mov			esp,	ebp
	pop			ebp
	ret
