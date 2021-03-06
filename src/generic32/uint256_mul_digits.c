/**
 * Copyright (C) Takuo Hada 2015-2016
 * @author t.hada 2016/07/09
 *
 * 128 bit integer for decimal.
 * this source includes decimal implementation.
 */
#include <math.h>

#include <magica/int/mgcompat.h>
#include <magica/int/uint256_def.h>
#include <magica/int/uint256_impl.h>

MG_PRIVATE int mg_uint256_mul_digits(const mg_uint256 *op1, int op1_words, const mg_uint256 *op2, int op2_words, /*out*/mg_uint256 *ret)
{
	uint8_t carry, carry2;
	uint32_t lo, hi;
	uint32_t buf[MG_UINT256_SIZE * 2 + 1] = { 0 };

	for (int j = 0; j < op2_words; j++) {
		carry2 = 0;
		for (int i = 0; i < op1_words; i++) {
			int k = i + j;
			lo = mg_uint32_mul(op1->word[i], op2->word[j], &hi);

			carry = mg_uint32_add(0, buf[k], lo, &buf[k]);
			carry = mg_uint32_add(carry, buf[k + 1], hi, &buf[k + 1]);
			carry2 = mg_uint32_add(carry, buf[k + 2], carry2, &buf[k + 2]);
		}
	}

	if ((buf[8] | buf[9] | buf[10] | buf[11] | buf[12] | buf[13] | buf[14] | buf[15]) != 0) {
		return 1;
	}

	memcpy(&ret->word[0], buf, sizeof(buf[0]) * MG_UINT256_SIZE);

	return 0;
}
