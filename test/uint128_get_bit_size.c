#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int/uint128_def.h>
#include <magica/int/uint128_impl.h>

#include "mg_assert.h"

static void get_bit_size_test(const char *text1, int ret)
{
	mg_uint128 v1;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_assert(mg_uint128_get_bit_size(&v1) == ret);
}

void mg_uint128_get_bit_size_test()
{
	get_bit_size_test("1", 1);
	get_bit_size_test("8", 4);
	get_bit_size_test("F", 4);
	get_bit_size_test("FFFFFFFFFFF", 44);
	get_bit_size_test("F0000000000", 44);
	get_bit_size_test("F0000000000000000000", 80);
	get_bit_size_test("F000000000000000000000000", 100);
	get_bit_size_test("F0000000000000000000000000000", 116);
	get_bit_size_test("F0000000000000000000000000000000", 128);

	printf("TEST mg_uint128_get_bit_size_test(): OK\n");
}
