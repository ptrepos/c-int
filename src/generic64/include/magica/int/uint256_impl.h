/**
 * Copyright (C) Takuo Hada 2015-2016
 * @author t.hada 2016/07/09
 *
 * 256 bit integer for decimal.
 * this source includes decimal implementation.
 */
#pragma once

#include <magica/uint64.h>
#include <magica/uint128.h>
#include <magica/uint256.h>

#include "intop.h"

static inline int mg_uint256_set_zero(/*out*/mg_uint256 *op1)
{
	ret->word[0] = 0;
	ret->word[1] = 0;
	ret->word[2] = 0;
	ret->word[3] = 0;
}

static inline void mg_uint256_set(/*out*/mg_uint256 *ret, uint64_t value)
{
	ret->word[0] = value;
	ret->word[1] = 0;
	ret->word[2] = 0;
	ret->word[3] = 0;
}

static inline uint64_t mg_uint256_get_uint64(const mg_uint256 *op1)
{
	return op1->word[0];
}

static inline uint64_t mg_uint256_get_uint128(const mg_uint256 *op1, mg_uint128 *ret)
{
	ret->word[0] = op1->word[0];
	ret->word[1] = op1->word[1];
}

static inline void mg_uint256_swap(mg_uint256 **a, mg_uint256 **b)
{
	mg_uint256 *tmp = *a;
	*a = *b;
	*b = tmp;
}

static inline int mg_uint256_is_zero(const mg_uint256 *op1)
{
	return (op1->word[3] | op1->word[2] | op1->word[1] | op1->word[0]) == 0;
}

static inline int mg_uint256_compare(const mg_uint256 *op1, const mg_uint256 *op2)
{
	if(op1->word[3] != op2->word[3]) 
		return op1->word[3] < op2->word[3] ? -1: 1;
	if(op1->word[2] != op2->word[2]) 
		return op1->word[2] < op2->word[2] ? -1: 1;
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
	c = mg_uint64_add(c, op1->word[0], op2->word[0], &ret->word[0]);
	c = mg_uint64_add(c, op1->word[1], op2->word[1], &ret->word[1]);
	c = mg_uint64_add(c, op1->word[2], op2->word[2], &ret->word[2]);
	c = mg_uint64_add(c, op1->word[3], op2->word[3], &ret->word[3]);

	return c;
}

static inline int mg_uint256_sub(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	unsigned char b;

	b = 0;
	b = mg_uint64_sub(b, op1->word[0], op2->word[0], &ret->word[0]);
	b = mg_uint64_sub(b, op1->word[1], op2->word[1], &ret->word[1]);
	b = mg_uint64_sub(b, op1->word[2], op2->word[2], &ret->word[2]);
	b = mg_uint64_sub(b, op1->word[3], op2->word[3], &ret->word[3]);

	return b;
}

static inline void mg_uint256_neg(const mg_uint256 *op1, /*out*/mg_uint256 *ret)
{
	unsigned char c;
	
	ret->word[0] = ~op1->word[0];
	ret->word[1] = ~op1->word[1];
	ret->word[2] = ~op1->word[2];
	ret->word[3] = ~op1->word[3];

	c = 0;
	c = mg_uint64_add(c, ret->word[0], 1, &ret->word[0]);
	c = mg_uint64_add(c, ret->word[1], 0, &ret->word[1]);
	c = mg_uint64_add(c, ret->word[2], 0, &ret->word[2]);
	c = mg_uint64_add(c, ret->word[3], 0, &ret->word[3]);
}

static inline int mg_uint256_mul256x64(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *ret)
{
	unsigned char carry, carry2;
	uint64_t hi, lo;

	mg_uint256_set_zero(ret);

	carry2 = 0;

	lo = mg_uint64_mul(op1->word[0], op2->word[0], &hi);

	carry = mg_uint64_add(0, ret->word[0], lo, &ret->word[0]);
	carry = mg_uint64_add(carry, ret->word[1], hi, &ret->word[1]);
	carry2 = mg_uint64_add(carry, ret->word[2], carry2, &ret->word[2]);

	lo = mg_uint64_mul(op1->word[1], op2->word[0], &hi);

	carry = mg_uint64_add(0, ret->word[1], lo, &ret->word[1]);
	carry = mg_uint64_add(carry, ret->word[2], hi, &ret->word[2]);
	carry2 = mg_uint64_add(carry, ret->word[3], carry2, &ret->word[3]);

	lo = mg_uint64_mul(op1->word[2], op2->word[0], &hi);

	carry = mg_uint64_add(0, ret->word[2], lo, &ret->word[2]);
	carry = mg_uint64_add(carry, ret->word[3], hi, &ret->word[3]);
	if(carry != 0 || carry2 != 0) {
		return 1;
	}

	lo = mg_uint64_mul(op1->word[3], op2->word[0], &hi);

	carry = mg_uint64_add(0, ret->word[3], lo, &ret->word[3]);
	if(carry != 0 || hi != 0) {
		return 1;
	}

	return 0;
}

static inline void mg_uint256_mul128(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint256 *ret)
{
	unsigned c;
	uint64_t lo, hi;
	
	lo = mg_uint64_mul(op1->word[0], op2->word[0], &hi);
	
	ret->word[0] = lo;
	ret->word[1] = hi;
	
	lo = mg_uint64_mul(op1->word[1], op2->word[1], &hi);
	
	ret->word[2] = lo;
	ret->word[3] = hi;

	lo = mg_uint64_mul(op1->word[0], op2->word[1], &hi);
	
	c = 0;
	c = mg_uint64_add(c, ret->word[1], lo, &ret->word[1]);
	c = mg_uint64_add(c, ret->word[2], hi, &ret->word[2]);
	c = mg_uint64_add(c, ret->word[3], 0, &ret->word[3]);

	lo = mg_uint64_mul(op1->word[1], op2->word[0], &hi);

	c = 0;
	c = mg_uint64_add(c, ret->word[1], lo, &ret->word[1]);
	c = mg_uint64_add(c, ret->word[2], hi, &ret->word[2]);
	c = mg_uint64_add(c, ret->word[3], 0, &ret->word[3]);
}

static inline int mg_uint256_mul(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	int op1_digits = MG_UINT256_WORD_COUNT;
	while(op1_digits > 0 && op1->word[op1_digits-1] == 0)
		op1_digits--;

	int op2_digits = MG_UINT256_WORD_COUNT;
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
}

static inline void mg_uint256_or(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	ret->word[0] = op1->word[0] | op2->word[0];
	ret->word[1] = op1->word[1] | op2->word[1];
	ret->word[2] = op1->word[2] | op2->word[2];
	ret->word[3] = op1->word[3] | op2->word[3];
}

static inline void mg_uint256_xor(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret)
{
	ret->word[0] = op1->word[0] ^ op2->word[0];
	ret->word[1] = op1->word[1] ^ op2->word[1];
	ret->word[2] = op1->word[2] ^ op2->word[2];
	ret->word[3] = op1->word[3] ^ op2->word[3];
}

static inline void mg_uint256_left_shift(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret)
{
	uint64_t buf[MG_UINT256_SIZE * 2] = { 0 };

	int words = shift / 64;
	int bits = shift % 64;

	if (bits != 0) {
		buf[0 + words] = (op1->word[0] << bits);
		buf[1 + words] = (op1->word[0] >> (64 - bits)) | (op1->word[1] << bits);
		buf[2 + words] = (op1->word[1] >> (64 - bits)) | (op1->word[2] << bits);
		buf[3 + words] = (op1->word[2] >> (64 - bits)) | (op1->word[3] << bits);
		buf[4 + words] = (op1->word[3] >> (64 - bits));
	}
	else {
		buf[0 + words] = op1->word[0];
		buf[1 + words] = op1->word[1];
		buf[2 + words] = op1->word[2];
		buf[3 + words] = op1->word[3];
	}

	ret->word[0] = buf[0];
	ret->word[1] = buf[1];
	ret->word[2] = buf[2];
	ret->word[3] = buf[3];
}

static inline void mg_uint256_left_shift_small(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret)
{
	ret->word[0] = (op1->word[0] << shift);
	ret->word[1] = (op1->word[1] << shift) | (op1->word[0] >> (64 - shift));
	ret->word[2] = (op1->word[2] << shift) | (op1->word[1] >> (64 - shift));
	ret->word[3] = (op1->word[3] << shift) | (op1->word[2] >> (64 - shift));
}

static inline void mg_uint256_right_shift(/*inout*/mg_uint256 *op1, int op2)
{
	uint64_t buf[MG_UINT256_SIZE * 2] = { 0 };

	int words = shift / 64;
	int bits = shift % 64;

	if (bits != 0) {
		buf[4 - words] = (op1->word[0] >> shift) | (op1->word[1] << (64 - shift));
		buf[5 - words] = (op1->word[1] >> shift) | (op1->word[2] << (64 - shift));
		buf[6 - words] = (op1->word[2] >> shift) | (op1->word[3] << (64 - shift));
		buf[7 - words] = (op1->word[3] >> shift);
	}
	else {
		buf[4 - words] = op1->word[0];
		buf[5 - words] = op1->word[1];
		buf[6 - words] = op1->word[2];
		buf[7 - words] = op1->word[3];
	}

	ret->word[0] = buf[4];
	ret->word[1] = buf[5];
	ret->word[2] = buf[6];
	ret->word[3] = buf[7];
}

static inline void mg_uint256_right_shift_small(mg_uint256 *op1, int shift)
{
	mg_uint256 buf;

	buf.word[0] = (op1->word[0] >> shift) | (op1->word[1] << (64 - shift));
	buf.word[1] = (op1->word[1] >> shift) | (op1->word[2] << (64 - shift));
	buf.word[2] = (op1->word[2] >> shift) | (op1->word[3] << (64 - shift));
	buf.word[3] = (op1->word[3] >> shift);

	*op1 = buf;
}

static inline void mg_uint256_get_bits(/*inout*/mg_uint256 *op1, int op2)
{
	int bytes = op2 / MG_UINT256_WORD_BITS;
	int bits = op2 % MG_UINT256_WORD_BITS;

	for(int i = bytes + (bits > 0 ? 1 : 0); i < MG_UINT256_WORD_COUNT; i++) {
		op1->word[i] = 0;
	}

	if(bits != 0) {
		op1->word[bytes] = (op1->word[bytes] << (MG_UINT256_WORD_BITS - bits)) >> (MG_UINT256_WORD_BITS - bits);
	}
}

static inline int mg_uint128_get_bit_size(const mg_uint256 *value)
{
	if(value->word[3] != 0) {
		return 3 * MG_UINT128_WORD_BITS + mg_uint64_get_bit_size(value->word[3]);
	}
	if(value->word[2] != 0) {
		return 2 * MG_UINT128_WORD_BITS + mg_uint64_get_bit_size(value->word[2]);
	}
	if(value->word[1] != 0) {
		return 1 * MG_UINT128_WORD_BITS + mg_uint64_get_bit_size(value->word[1]);
	}
	if(value->word[0] != 0) {
		return mg_uint64_get_bit_size(value->word[1]);
	}
	return 0;
}

static inline void mg_uint256_set_bit(mg_uint256 *op1, int bit)
{
	int words = bit / 64;
	int bits = bit % 64;

	op1->word[words] |= (uint64_t)1ULL << (uint64_t)bits;
}
