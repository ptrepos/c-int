/**
* Copyright (C) Takuo Hada 2015-2016
* @author t.hada 2016/08/27
*
* 256 bit integer for decimal.
*/
#pragma once

#include <magica/int/uint64.h>
#include <magica/int/uint256.h>

#include "intop.h"

static inline void mg_uint256_set_zero(mg_uint256 *op1)
{
	op1->word[0] = 0;
	op1->word[1] = 0;
	op1->word[2] = 0;
	op1->word[3] = 0;
	op1->word[4] = 0;
	op1->word[5] = 0;
	op1->word[6] = 0;
	op1->word[7] = 0;
}

static inline void mg_uint256_set(mg_uint256 *op1, uint64_t value)
{
	op1->word[0] = (uint32_t)value;
	op1->word[1] = (uint32_t)(value >> 32);
	op1->word[2] = 0;
	op1->word[3] = 0;
	op1->word[4] = 0;
	op1->word[5] = 0;
	op1->word[6] = 0;
	op1->word[7] = 0;
}

static inline uint64_t mg_uint256_get_uint64(const mg_uint256 *op1)
{
	return (uint64_t)op1->word[0] | ((uint64_t)op1->word[1] << 32);
}

static inline void mg_uint256_swap(mg_uint256 **a, mg_uint256 **b)
{
	mg_uint256 *tmp = *a;
	*a = *b;
	*b = tmp;
}

static inline int mg_uint256_is_zero(const mg_uint256 *op1)
{
	return (op1->word[7] | op1->word[6] | op1->word[5] | op1->word[4] |
		    op1->word[3] | op1->word[2] | op1->word[1] | op1->word[0]) == 0;
}

static inline int mg_uint256_compare(const mg_uint256 *op1, const mg_uint256 *op2)
{
	if (op1->word[7] != op2->word[7])
		return op1->word[7] < op2->word[7] ? -1 : 1;
	if (op1->word[6] != op2->word[6])
		return op1->word[6] < op2->word[6] ? -1 : 1;
	if (op1->word[5] != op2->word[5])
		return op1->word[5] < op2->word[5] ? -1 : 1;
	if (op1->word[4] != op2->word[4])
		return op1->word[4] < op2->word[4] ? -1 : 1;
	if (op1->word[3] != op2->word[3])
		return op1->word[3] < op2->word[3] ? -1 : 1;
	if (op1->word[2] != op2->word[2])
		return op1->word[2] < op2->word[2] ? -1 : 1;
	if (op1->word[1] != op2->word[1])
		return op1->word[1] < op2->word[1] ? -1 : 1;
	if (op1->word[0] != op2->word[0])
		return op1->word[0] < op2->word[0] ? -1 : 1;
	return 0;
}

static inline int mg_uint256_add(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	unsigned char c;

	c = 0;
	c = mg_uint32_add(c, op1->word[0], op2->word[0], &ret->word[0]);
	c = mg_uint32_add(c, op1->word[1], op2->word[1], &ret->word[1]);
	c = mg_uint32_add(c, op1->word[2], op2->word[2], &ret->word[2]);
	c = mg_uint32_add(c, op1->word[3], op2->word[3], &ret->word[3]);
	c = mg_uint32_add(c, op1->word[4], op2->word[4], &ret->word[4]);
	c = mg_uint32_add(c, op1->word[5], op2->word[5], &ret->word[5]);
	c = mg_uint32_add(c, op1->word[6], op2->word[6], &ret->word[6]);
	c = mg_uint32_add(c, op1->word[7], op2->word[7], &ret->word[7]);

	return c;
}

static inline int mg_uint256_sub(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	unsigned char b;

	b = 0;
	b = mg_uint32_sub(b, op1->word[0], op2->word[0], &ret->word[0]);
	b = mg_uint32_sub(b, op1->word[1], op2->word[1], &ret->word[1]);
	b = mg_uint32_sub(b, op1->word[2], op2->word[2], &ret->word[2]);
	b = mg_uint32_sub(b, op1->word[3], op2->word[3], &ret->word[3]);
	b = mg_uint32_sub(b, op1->word[4], op2->word[4], &ret->word[4]);
	b = mg_uint32_sub(b, op1->word[5], op2->word[5], &ret->word[5]);
	b = mg_uint32_sub(b, op1->word[6], op2->word[6], &ret->word[6]);
	b = mg_uint32_sub(b, op1->word[7], op2->word[7], &ret->word[7]);

	return b;
}

static inline void mg_uint256_neg(const mg_uint256 *op1, mg_uint256 *ret)
{
	unsigned char c;

	ret->word[0] = ~op1->word[0];
	ret->word[1] = ~op1->word[1];
	ret->word[2] = ~op1->word[2];
	ret->word[3] = ~op1->word[3];
	ret->word[4] = ~op1->word[4];
	ret->word[5] = ~op1->word[5];
	ret->word[6] = ~op1->word[6];
	ret->word[7] = ~op1->word[7];

	c = 0;
	c = mg_uint32_add(c, ret->word[0], 1, &ret->word[0]);
	c = mg_uint32_add(c, ret->word[1], 0, &ret->word[1]);
	c = mg_uint32_add(c, ret->word[2], 0, &ret->word[2]);
	c = mg_uint32_add(c, ret->word[3], 0, &ret->word[3]);
	c = mg_uint32_add(c, ret->word[4], 0, &ret->word[4]);
	c = mg_uint32_add(c, ret->word[5], 0, &ret->word[5]);
	c = mg_uint32_add(c, ret->word[6], 0, &ret->word[6]);
	c = mg_uint32_add(c, ret->word[7], 0, &ret->word[7]);
}

static inline int mg_uint256_mul256x64(
	const mg_uint256 *op1, 
	const mg_uint256 *op2, 
	/*out*/mg_uint256 *ret)
{
	int op1_digits = MG_UINT256_SIZE;
	while(op1_digits > 0 && op1->word[op1_digits-1] == 0)
		op1_digits--;

	int op2_digits = MG_UINT256_SIZE / 4;
	while(op2_digits > 0 && op2->word[op2_digits-1] == 0)
		op2_digits--;

	return mg_uint256_mul_digits(op1, op1_digits, op2, op2_digits, /*out*/ret);
}

static inline void mg_uint256_mul128(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint256 *ret)
{
	mg_uint128 lo, hi;

	mg_uint128_mul_1(op1, op2, /*out*/&lo, /*out*/&hi);

	ret->word[0] = lo.word[0];
	ret->word[1] = lo.word[1];
	ret->word[2] = lo.word[2];
	ret->word[3] = lo.word[3];
	ret->word[4] = hi.word[0];
	ret->word[5] = hi.word[1];
	ret->word[6] = hi.word[2];
	ret->word[7] = hi.word[3];
}

static inline void mg_uint256_mul_1(
	const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *_lo, /*out*/mg_uint256 *_hi)
{
	int op1_digits = MG_UINT256_SIZE;
	while(op1_digits > 0 && op1->word[op1_digits-1] == 0)
		op1_digits--;

	int op2_digits = MG_UINT256_SIZE;
	while(op2_digits > 0 && op2->word[op2_digits-1] == 0)
		op2_digits--;

	mg_uint256_mul_digits_1(op1, op1_digits, op2, op2_digits, /*out*/_lo, /*out*/_hi);
}

static inline int mg_uint256_mul(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	int op1_digits = MG_UINT256_SIZE;
	while(op1_digits > 0 && op1->word[op1_digits-1] == 0)
		op1_digits--;

	int op2_digits = MG_UINT256_SIZE;
	while(op2_digits > 0 && op2->word[op2_digits-1] == 0)
		op2_digits--;

	return mg_uint256_mul_digits(op1, op1_digits, op2, op2_digits, /*out*/ret);
}

static inline void mg_uint256_and(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	ret->word[0] = op1->word[0] & op2->word[0];
	ret->word[1] = op1->word[1] & op2->word[1];
	ret->word[2] = op1->word[2] & op2->word[2];
	ret->word[3] = op1->word[3] & op2->word[3];
	ret->word[4] = op1->word[4] & op2->word[4];
	ret->word[5] = op1->word[5] & op2->word[5];
	ret->word[6] = op1->word[6] & op2->word[6];
	ret->word[7] = op1->word[7] & op2->word[7];
}

static inline void mg_uint256_or(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	ret->word[0] = op1->word[0] | op2->word[0];
	ret->word[1] = op1->word[1] | op2->word[1];
	ret->word[2] = op1->word[2] | op2->word[2];
	ret->word[3] = op1->word[3] | op2->word[3];
	ret->word[4] = op1->word[4] | op2->word[4];
	ret->word[5] = op1->word[5] | op2->word[5];
	ret->word[6] = op1->word[6] | op2->word[6];
	ret->word[7] = op1->word[7] | op2->word[7];
}

static inline void mg_uint256_xor(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	ret->word[0] = op1->word[0] ^ op2->word[0];
	ret->word[1] = op1->word[1] ^ op2->word[1];
	ret->word[2] = op1->word[2] ^ op2->word[2];
	ret->word[3] = op1->word[3] ^ op2->word[3];
	ret->word[4] = op1->word[4] ^ op2->word[4];
	ret->word[5] = op1->word[5] ^ op2->word[5];
	ret->word[6] = op1->word[6] ^ op2->word[6];
	ret->word[7] = op1->word[7] ^ op2->word[7];
}

static inline void mg_uint256_not(const mg_uint256 *op1, /*out*/mg_uint256 *ret)
{
	ret->word[0] = ~op1->word[0];
	ret->word[1] = ~op1->word[1];
	ret->word[2] = ~op1->word[2];
	ret->word[3] = ~op1->word[3];
	ret->word[4] = ~op1->word[4];
	ret->word[5] = ~op1->word[5];
	ret->word[6] = ~op1->word[6];
	ret->word[7] = ~op1->word[7];
}

static inline void mg_uint256_left_shift(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret)
{
	uint32_t buf[MG_UINT256_SIZE * 2] = { 0 };

	int words = shift / MG_UINT256_WORD_BITS;
	int bits = shift % MG_UINT256_WORD_BITS;

	if (bits != 0) {
		buf[0 + words] = (op1->word[0] << bits);
		buf[1 + words] = (op1->word[0] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[1] << bits);
		buf[2 + words] = (op1->word[1] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[2] << bits);
		buf[3 + words] = (op1->word[2] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[3] << bits);
		buf[4 + words] = (op1->word[3] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[4] << bits);
		buf[5 + words] = (op1->word[4] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[5] << bits);
		buf[6 + words] = (op1->word[5] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[6] << bits);
		buf[7 + words] = (op1->word[6] >> (MG_UINT256_WORD_BITS - bits)) | (op1->word[7] << bits);
	}
	else {
		buf[0 + words] = op1->word[0];
		buf[1 + words] = op1->word[1];
		buf[2 + words] = op1->word[2];
		buf[3 + words] = op1->word[3];
		buf[4 + words] = op1->word[4];
		buf[5 + words] = op1->word[5];
		buf[6 + words] = op1->word[6];
		buf[7 + words] = op1->word[7];
	}

	ret->word[0] = buf[0];
	ret->word[1] = buf[1];
	ret->word[2] = buf[2];
	ret->word[3] = buf[3];
	ret->word[4] = buf[4];
	ret->word[5] = buf[5];
	ret->word[6] = buf[6];
	ret->word[7] = buf[7];
}

static inline void mg_uint256_left_shift_small(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret)
{
	ret->word[0] = (op1->word[0] << shift);
	ret->word[1] = (op1->word[1] << shift) | (op1->word[0] >> (MG_UINT256_WORD_BITS - shift));
	ret->word[2] = (op1->word[2] << shift) | (op1->word[1] >> (MG_UINT256_WORD_BITS - shift));
	ret->word[3] = (op1->word[3] << shift) | (op1->word[2] >> (MG_UINT256_WORD_BITS - shift));
	ret->word[4] = (op1->word[4] << shift) | (op1->word[3] >> (MG_UINT256_WORD_BITS - shift));
	ret->word[5] = (op1->word[5] << shift) | (op1->word[4] >> (MG_UINT256_WORD_BITS - shift));
	ret->word[6] = (op1->word[6] << shift) | (op1->word[5] >> (MG_UINT256_WORD_BITS - shift));
	ret->word[7] = (op1->word[7] << shift) | (op1->word[6] >> (MG_UINT256_WORD_BITS - shift));
}

static inline void mg_uint256_right_shift(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret)
{
	uint32_t buf[MG_UINT256_SIZE * 2] = { 0 };

	int words = shift / MG_UINT256_WORD_BITS;
	int bits = shift % MG_UINT256_WORD_BITS;

	if (bits != 0) {
		buf[8 - words] = (op1->word[0] >> shift) | (op1->word[1] << (MG_UINT256_WORD_BITS - shift));
		buf[9 - words] = (op1->word[1] >> shift) | (op1->word[2] << (MG_UINT256_WORD_BITS - shift));
		buf[10 - words] = (op1->word[2] >> shift) | (op1->word[3] << (MG_UINT256_WORD_BITS - shift));
		buf[11 - words] = (op1->word[3] >> shift) | (op1->word[4] << (MG_UINT256_WORD_BITS - shift));
		buf[12 - words] = (op1->word[4] >> shift) | (op1->word[5] << (MG_UINT256_WORD_BITS - shift));
		buf[13 - words] = (op1->word[5] >> shift) | (op1->word[6] << (MG_UINT256_WORD_BITS - shift));
		buf[14 - words] = (op1->word[6] >> shift) | (op1->word[7] << (MG_UINT256_WORD_BITS - shift));
		buf[15 - words] = (op1->word[7] >> shift);
	}
	else {
		buf[8 - words] = op1->word[0];
		buf[9 - words] = op1->word[1];
		buf[10 - words] = op1->word[2];
		buf[11 - words] = op1->word[3];
		buf[12 - words] = op1->word[4];
		buf[13 - words] = op1->word[5];
		buf[14 - words] = op1->word[6];
		buf[15 - words] = op1->word[7];
	}

	ret->word[0] = buf[8];
	ret->word[1] = buf[9];
	ret->word[2] = buf[10];
	ret->word[3] = buf[11];
	ret->word[4] = buf[12];
	ret->word[5] = buf[13];
	ret->word[6] = buf[14];
	ret->word[7] = buf[15];
}

static inline void mg_uint256_right_shift_small(const mg_uint256 *op1, int shift, mg_uint256 *ret)
{
	ret->word[0] = (op1->word[0] >> shift) | (op1->word[1] << (MG_UINT256_WORD_BITS - shift));
	ret->word[1] = (op1->word[1] >> shift) | (op1->word[2] << (MG_UINT256_WORD_BITS - shift));
	ret->word[2] = (op1->word[2] >> shift) | (op1->word[3] << (MG_UINT256_WORD_BITS - shift));
	ret->word[3] = (op1->word[3] >> shift) | (op1->word[4] << (MG_UINT256_WORD_BITS - shift));
	ret->word[4] = (op1->word[4] >> shift) | (op1->word[5] << (MG_UINT256_WORD_BITS - shift));
	ret->word[5] = (op1->word[5] >> shift) | (op1->word[6] << (MG_UINT256_WORD_BITS - shift));
	ret->word[6] = (op1->word[6] >> shift) | (op1->word[7] << (MG_UINT256_WORD_BITS - shift));
	ret->word[7] = (op1->word[7] >> shift);
}

static inline int mg_uint256_get_bit_size(const mg_uint256 *value)
{
	if(value->word[7] != 0) {
		return 7 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[7]);
	}
	if(value->word[6] != 0) {
		return 6 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[6]);
	}
	if(value->word[5] != 0) {
		return 5 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[5]);
	}
	if(value->word[4] != 0) {
		return 4 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[4]);
	}
	if(value->word[3] != 0) {
		return 3 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[3]);
	}
	if(value->word[2] != 0) {
		return 2 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[2]);
	}
	if(value->word[1] != 0) {
		return 1 * MG_UINT256_WORD_BITS + mg_uint64_get_bit_size(value->word[1]);
	}
	if(value->word[0] != 0) {
		return mg_uint64_get_bit_size(value->word[0]);
	}
	return 0;
}

static inline void mg_uint256_set_bit(mg_uint256 *op1, int bit_index)
{
	int words = bit_index / MG_UINT256_WORD_BITS;
	int bits = bit_index % MG_UINT256_WORD_BITS;

	op1->word[words] |= (uint32_t)1 << (uint32_t)bits;
}