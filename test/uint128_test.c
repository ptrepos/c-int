#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int/uint128_def.h>

#include "mg_assert.h"

void mg_uint128_add_test();
void mg_uint128_mul_test();
void mg_uint128_div_test();
void mg_uint128_div_pattern_test();
void mg_uint128_div_performance();
void mg_uint128_left_shift_test();
void mg_uint128_right_shift_test();
void mg_uint128_and_test();
void mg_uint128_or_test();
void mg_uint128_xor_test();
void mg_uint128_not_test();
void mg_uint128_get_bit_size_test();
void mg_uint128_set_bit_test();

void mg_uint128_test()
{
	clock_t tm = clock();

	mg_uint128_add_test();
	mg_uint128_mul_test();
	mg_uint128_div_test();
	mg_uint128_div_pattern_test();
#if defined(NDEBUG)
	mg_uint128_div_performance();
#endif
	mg_uint128_left_shift_test();
	mg_uint128_right_shift_test();
	mg_uint128_and_test();
	mg_uint128_or_test();
	mg_uint128_xor_test();
	mg_uint128_not_test();
	mg_uint128_get_bit_size_test();
	mg_uint128_set_bit_test();

	printf("mg_uint128 test: %fs\n", (float)(clock() - tm) / CLOCKS_PER_SEC);
}
