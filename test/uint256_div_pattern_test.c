#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int.h>

#include "mg_assert.h"

static const uint64_t TABLE[8] = {
	0x0000000000000000ULL,
	0x000000000000FFFFULL,
	0x0000000000FFFFFFULL,
	0x00000000FFFFFFFFULL,
	0x000000FFFFFFFFFFULL,
	0x0000FFFFFFFFFFFFULL,
	0x00FFFFFFFFFFFFFFULL,
	0xFFFFFFFFFFFFFFFFULL
};

mg_uint256 mg_create_uint256(uint64_t index)
{
	mg_uint256 value1, shift, value2, tmp;
	int overflow;
	
	mg_uint256_set_zero(&value1);
	mg_uint256_test_convert("18446744073709551616", &shift);

	mg_uint256_set(&value2, TABLE[index & 0x7]);
	index >>= 3;
	overflow = mg_uint256_mul(&value1, &shift, /*out*/&tmp);
	mg_assert(overflow == 0);
	mg_uint256_add(&tmp, &value2, /*out*/&value1);

	mg_uint256_set(&value2, TABLE[index & 0x7]);
	index >>= 3;
	overflow = mg_uint256_mul(&value1, &shift, /*out*/&tmp);
	mg_assert(overflow == 0);
	mg_uint256_add(&tmp, &value2, /*out*/&value1);

	mg_uint256_set(&value2, TABLE[index & 0x7]);
	index >>= 3;
	overflow = mg_uint256_mul(&value1, &shift, /*out*/&tmp);
	mg_assert(overflow == 0);
	mg_uint256_add(&tmp, &value2, /*out*/&value1);

	mg_uint256_set(&value2, TABLE[index & 0x7]);
	index >>= 3;
	overflow = mg_uint256_mul(&value1, &shift, /*out*/&tmp);
	mg_assert(overflow == 0);
	mg_uint256_add(&tmp, &value2, /*out*/&value1);
	
	return value1;
}

void mg_uint256_div_pattern_test()
{
	for(uint64_t i = 0; i < 8*8*8*8; i++) {
		mg_uint256 value1 = mg_create_uint256(i);
		
		for(uint64_t j = 1; j < 8*8*8*8; j++) {
			mg_uint256 op1 = value1;
			mg_uint256 op2 = mg_create_uint256(j);
			mg_uint256 q, r, tmp;
			
			mg_assert(mg_uint256_div(/*inout*/&op1, &op2, /*out*/&q, /*out*/&r) == 0);
			
			int overflow;
			overflow = mg_uint256_mul(&q, &op2, /*out*/&tmp);
			mg_assert(overflow == 0);
			mg_uint256_add(&r, &tmp, &op1);
			
			mg_assert(mg_uint256_compare(&op1, &value1) == 0);
		}

		printf("%llu\r", i);
	}
	
	printf("TEST mg_uint256_div() pattern: OK\n");
}
