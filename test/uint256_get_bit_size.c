#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint256.h>

#include "mg_assert.h"

static void get_bit_size_test(const char *text1, int ret)
{
	mg_uint256 v1;

	mg_uint256_test_hex_convert(text1, &v1);

	mg_assert(mg_uint256_get_bit_size(&v1) == ret);
}

void mg_uint256_get_bit_size_test()
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
	get_bit_size_test("F0000000000000000000000000000000F000000000000000000000000000", 240);
	get_bit_size_test("F0000000000000000000000000000000F0000000000000000000000000000000", 256);

	printf("TEST mg_uint256_get_bit_size_test(): OK\n");
}
