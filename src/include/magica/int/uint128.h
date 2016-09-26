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

#include <magica/int/uint128_def.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void mg_uint128_set_zero(mg_uint128 *dest);
static inline void mg_uint128_set(mg_uint128 *dest, uint64_t value);
static inline void mg_uint128_set_bit(mg_uint128 *dest, int bit_index);
static inline uint64_t mg_uint128_get_uint64(const mg_uint128 *value);

static inline int mg_uint128_is_zero(const mg_uint128 *value);
static inline int mg_uint128_compare(const mg_uint128 *value1, const mg_uint128 *value2);

static inline void mg_uint128_swap(mg_uint128 **a, mg_uint128 **b);

static inline void mg_uint128_neg(const mg_uint128 *op1, /*out*/mg_uint128 *ret);
static inline void mg_uint128_neg_1(/*inout*/mg_uint128 *op1);

static inline int mg_uint128_add(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
static inline int mg_uint128_add_1(/*inout*/mg_uint128 *op1, const mg_uint128 *op2);
static inline int mg_uint128_sub(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
static inline int mg_uint128_sub_1(/*inout*/mg_uint128 *op1, const mg_uint128 *op2);
static inline int mg_uint128_mul(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
static inline void mg_uint128_mul_1(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *low, /*out*/mg_uint128 *high);
static inline int mg_uint128_mul_digits(const mg_uint128 *op1, int op1_digits, const mg_uint128 *op2, int op2_digits, /*out*/mg_uint128 *ret);
static inline void mg_uint128_mul_digits_1(const mg_uint128 *op1, int op1_words, const mg_uint128 *op2, int op2_words, /*out*/mg_uint128 *low, /*out*/mg_uint128 *high);

int mg_uint128_div(
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

/**
 * bit operation functions
 */
static inline void mg_uint128_and(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
static inline void mg_uint128_and_1(/*inout*/mg_uint128 *op1, const mg_uint128 *op2);
static inline void mg_uint128_or(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
static inline void mg_uint128_or_1(/*inout*/mg_uint128 *op1, const mg_uint128 *op2);
static inline void mg_uint128_xor(const mg_uint128 *op1, const mg_uint128 *op2, /*out*/mg_uint128 *ret);
static inline void mg_uint128_xor_1(/*inout*/mg_uint128 *op1, const mg_uint128 *op2);
static inline void mg_uint128_not(const mg_uint128 *op1, /*out*/mg_uint128 *ret);
static inline void mg_uint128_not_1(/*inout*/mg_uint128 *op1);

static inline void mg_uint128_left_shift(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);
static inline void mg_uint128_left_shift_1(/*inout*/mg_uint128 *op1, int shift);
static inline void mg_uint128_left_shift_small(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);
static inline void mg_uint128_left_shift_small_1(/*inout*/mg_uint128 *op1, int shift);

static inline void mg_uint128_right_shift(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);
static inline void mg_uint128_right_shift_1(/*inout*/mg_uint128 *op1, int shift);
static inline void mg_uint128_right_shift_small(const mg_uint128 *op1, int shift, /*out*/mg_uint128 *ret);
static inline void mg_uint128_right_shift_small_1(/*inout*/mg_uint128 *op1, int shift);

static inline int mg_uint128_get_bit_size(const mg_uint128 *value);

/**
 * convert functions
 */
void mg_uint128_test_to_string(const mg_uint128 *value, char *buf);
void mg_uint128_test_convert(const char *buf, mg_uint128 *value);
void mg_uint128_test_to_hex_string(const mg_uint128 *value, char *buf);
void mg_uint128_test_hex_convert(const char *buf, mg_uint128 *value);

#ifdef __cplusplus
}
#endif
