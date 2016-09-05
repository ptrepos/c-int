/**
 * Copyright (C) Takuo Hada 2015-2016
 * @author t.hada 2016/07/09
 *
 * 256 bit integer for decimal.
 * this source includes decimal implementation.
 */
#pragma once

#include <stdint.h>
#include <memory.h>
#include <assert.h>

#include <magica/int/uint128.h>
#include <magica/int/uint256_def.h>

/** 
 * value setter function.
 */
static inline void mg_uint256_set_zero(mg_uint256 *ret);
static inline void mg_uint256_set(mg_uint256 *ret, uint64_t value);
static inline void mg_uint256_set128(mg_uint256 *ret, const mg_uint128 *value);
static inline void mg_uint256_set_bit(mg_uint256 *op1, int bit_index);
static inline uint64_t mg_uint256_get_uint64(const mg_uint256 *op1);
static inline void mg_uint256_get_uint128(const mg_uint256 *op1, mg_uint128 *ret);

/** 
 * comparison functions
 */
static inline int mg_uint256_is_zero(const mg_uint256 *op1);
static inline int mg_uint256_compare(const mg_uint256 *op1, const mg_uint256 *op2);

/** 
 * swap pointer
 */
static inline void mg_uint256_swap(mg_uint256 **a, mg_uint256 **b);

/**
 * arithmetric functions
 */
static inline void mg_uint256_neg(const mg_uint256 *op1, /*out*/mg_uint256 *ret);

static inline int mg_uint256_add(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);
static inline int mg_uint256_sub(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);
static inline int mg_uint256_mul(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);
static inline void mg_uint256_mul_1(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *low, /*out*/mg_uint256 *high);
void mg_uint256_mul_digits_1(const mg_uint256 *op1, int op1_words, const mg_uint256 *op2, int op2_words, /*out*/mg_uint256 *low, /*out*/mg_uint256 *high);
int mg_uint256_mul_digits(const mg_uint256 *op1, int op1_digits, const mg_uint256 *op2, int op2_digits, /*out*/mg_uint256 *ret);

int mg_uint256_div(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *quotient, 
		/*out*/mg_uint256 *reminder);

int mg_uint256_div_maclaurin(
	const mg_uint256 *op1,
	const mg_uint256 *op2,
	/*out*/mg_uint256 *quotient,
	/*out*/mg_uint256 *reminder);

static inline void mg_uint256_mul128(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint256 *ret);
static inline int mg_uint256_mul256x64(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);

/**
 * bit operation functions
 */
static inline void mg_uint256_and(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);
static inline void mg_uint256_or(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);
static inline void mg_uint256_xor(const mg_uint256 *op1, const mg_uint256 *op2, /*out*/mg_uint256 *ret);
static inline void mg_uint256_not(const mg_uint256 *op1, /*out*/mg_uint256 *ret);

static inline void mg_uint256_left_shift(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret);
static inline void mg_uint256_left_shift_small(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret);

static inline void mg_uint256_right_shift(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret);
static inline void mg_uint256_right_shift_small(const mg_uint256 *op1, int shift, /*out*/mg_uint256 *ret);

static inline int mg_uint256_get_bit_size(const mg_uint256 *value);

/**
 * convert functions
 */
void mg_uint256_test_to_string(const mg_uint256 *value, char *buf);
void mg_uint256_test_convert(const char *buf, mg_uint256 *value);
void mg_uint256_test_to_hex_string(const mg_uint256 *value, char *buf);
void mg_uint256_test_hex_convert(const char *buf, mg_uint256 *value);
