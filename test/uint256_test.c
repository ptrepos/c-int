#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int.h>

#include "mg_assert.h"

void mg_uint256_add_test();
void mg_uint256_mul_test();
void mg_uint256_div_test();
void mg_uint256_div_performance();
void mg_uint256_div_pattern_test();
void mg_uint256_left_shift_test();
void mg_uint256_right_shift_test();
void mg_uint256_and_test();
void mg_uint256_or_test();
void mg_uint256_xor_test();
void mg_uint256_not_test();

void mg_uint256_test()
{
	clock_t tm = clock();

	mg_uint256_add_test();
	mg_uint256_mul_test();
	mg_uint256_div_test();
#if defined(NDEBUG)
	//mg_uint256_div_pattern_test();
	mg_uint256_div_performance();
#endif
	mg_uint256_left_shift_test();
	mg_uint256_right_shift_test();
	mg_uint256_and_test();
	mg_uint256_or_test();
	mg_uint256_xor_test();
	mg_uint256_not_test();

	printf("mg_uint256 test: %fs\n", (float)(clock() - tm) / CLOCKS_PER_SEC);
}
