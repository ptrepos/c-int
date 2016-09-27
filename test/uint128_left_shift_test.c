#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint128.h>

#include "mg_assert.h"

static void left_shift_test(const char *text1, int shift, const char *ret)
{
	char strbuf[1024];
	mg_uint128 v1, v2;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_uint128_left_shift(&v1, shift, /*out*/&v2);

	mg_uint128_test_to_hex_string(&v2, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint128_left_shift_1(/*inout*/&v1, shift);

	mg_uint128_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

static void left_shift_small_test(const char *text1, int shift, const char *ret)
{
	char strbuf[1024];
	mg_uint128 v1, v2;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_uint128_left_shift_small(&v1, shift, /*out*/&v2);

	mg_uint128_test_to_hex_string(&v2, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint128_left_shift_small_1(/*inout*/&v1, shift);

	mg_uint128_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint128_left_shift_test()
{
	left_shift_test("FF", 1, "1FE");
	left_shift_test("FF0000000000000000000", 1, "1FE0000000000000000000");
	left_shift_test("FF000000000000000000000000000", 1, "1FE000000000000000000000000000");

	left_shift_test("FF", 16, "FF0000");
	left_shift_test("FF0000000000000000000", 16, "FF00000000000000000000000");

	left_shift_test("FF", 20, "FF00000");
	left_shift_test("FF0000000000000000000", 20, "FF000000000000000000000000");

	left_shift_test("FF", 33, "1FE00000000");
	left_shift_test("FF00000000", 33, "1FE0000000000000000");

	left_shift_test("FF", 66, "3FC0000000000000000");
	left_shift_test("FF00000000", 66, "3FC000000000000000000000000");

	left_shift_test("FF", 120, "FF000000000000000000000000000000");
	left_shift_test("FF", 127, "80000000000000000000000000000000");

	left_shift_test("FF0FF00FF00FF00FF00FF", 40, "FF0FF00FF00FF00FF00FF0000000000");
	left_shift_test("FF0FF00FF00FF00FF", 60, "FF0FF00FF00FF00FF000000000000000");

	left_shift_test("1", 127, "80000000000000000000000000000000");

	left_shift_small_test("FF", 1, "1FE");
	left_shift_small_test("FF0000000000000000000", 1, "1FE0000000000000000000");
	left_shift_small_test("FF000000000000000000000000000", 1, "1FE000000000000000000000000000");

	left_shift_small_test("FF", 16, "FF0000");
	left_shift_small_test("FF0000000000000000000", 16, "FF00000000000000000000000");

	left_shift_small_test("FF", 20, "FF00000");
	left_shift_small_test("FF0000000000000000000", 20, "FF000000000000000000000000");

	printf("TEST mg_uint128_left_shift_test(): OK\n");
}
