/**
 * Copyright (C) Takuo Hada 2015-2016
 * @author t.hada 2016/08/27
 *
 * 128 bit integer for decimal.
 * this source includes decimal implementation.
 */
#pragma once

#include <stdint.h>
#include <memory.h>
#include <assert.h>

#define MG_UINT128_SIZE			(2)
#define MG_UINT128_WORD_BITS	(64)

typedef struct mg_uint256 mg_uint256;

/**
 * 256bit integer implementation for 64bit.
 */
typedef struct mg_uint128
{
	uint64_t word[MG_UINT128_SIZE];
} mg_uint128;

/** 
 * value setter function.
 */
void mg_uint128_set_zero(mg_uint128 *op1);
void mg_uint128_set(mg_uint128 *op1, uint64_t value);
void mg_uint128_set_bit(mg_uint128 *op1, int bit_index);
uint64_t mg_uint128_get_uint64(const mg_uint128 *op1);

/** 
 * comparison functions
 */
int mg_uint128_is_zero(const mg_uint128 *op1);
int mg_uint128_compare(const mg_uint128 *op1, const mg_uint128 *op2);

/** 
 * swap pointer
 */
void mg_uint128_swap(mg_uint128 **a, mg_uint128 **b);

/**
 * arithmetric functions
 */
void mg_uint128_neg(const mg_uint128 *op1, /*out*/mg_uint128 *ret);

int mg_uint128_add(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
int mg_uint128_sub(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
int mg_uint128_mul(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);

int mg_uint128_div(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *quotient, 
		/*out*/mg_uint128 *reminder);
int mg_uint128_div_recovering_method(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *quotient, 
		/*out*/mg_uint128 *reminder);
int mg_uint128_div_srt(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *quotient, 
		/*out*/mg_uint128 *reminder);
int mg_uint128_div_long_division(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *quotient, 
		/*out*/mg_uint128 *reminder);
int mg_uint128_div_maclaurin(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *quotient, 
		/*out*/mg_uint128 *reminder);

void mg_uint128_mul_1(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *_lo, /*out*/mg_uint128 *_hi);

/**
 * bit operation functions
 */
void mg_uint128_and(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
void mg_uint128_or(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
void mg_uint128_xor(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
void mg_uint128_not(const mg_uint128 *op1, /*out*/mg_uint128 *ret);

void mg_uint128_left_shift(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);
void mg_uint128_left_shift_small(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);

void mg_uint128_right_shift(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);
void mg_uint128_right_shift_small(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);

int mg_uint128_get_bit_size(const mg_uint128 *value);

/**
 * convert functions
 */
void mg_uint128_test_to_string(const mg_uint128 *value, char *buf);
void mg_uint128_test_convert(const char *buf, mg_uint128 *value);
void mg_uint128_test_to_hex_string(const mg_uint128 *value, char *buf);
void mg_uint128_test_hex_convert(const char *buf, mg_uint128 *value);
