#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint128.h>

#include "mg_assert.h"

static void right_shift_test(const char *text1, int shift, const char *ret)
{
	char strbuf[1024];
	mg_uint128 v1, v2;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_uint128_right_shift(&v1, shift, &v2);

	mg_uint128_test_to_hex_string(&v2, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint128_right_shift_1(/*inout*/&v1, shift);

	mg_uint128_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

static void right_shift_small_test(const char *text1, int shift, const char *ret)
{
	char strbuf[1024];
	mg_uint128 v1, v2;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_uint128_right_shift_small(&v1, shift, &v2);

	mg_uint128_test_to_hex_string(&v2, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint128_right_shift_small_1(&v1, shift);

	mg_uint128_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint128_right_shift_test()
{
	right_shift_test("FF", 1, "7F");
	right_shift_test("FF000000000", 1, "7F800000000");
	right_shift_test("FF00000000000000000", 1, "7F80000000000000000");

	right_shift_test("FF00FF", 16, "FF");
	right_shift_test("FF00FF0000", 16, "FF00FF");
	right_shift_test("FF00FF0000000000000000", 16, "FF00FF000000000000");
	
	right_shift_test("FF00000000", 33, "7F");
	right_shift_test("FF000000000", 33, "7F8");
	right_shift_test("FF00000000000000000", 33, "7F800000000");
	right_shift_test("FF0000000000000000000000000", 33, "7F80000000000000000");
	right_shift_test("FF000000000000000000000000000000", 33, "7F8000000000000000000000");

	right_shift_test("FF0000000000000000", 64, "FF");
	right_shift_test("FF000000000000000000000", 64, "FF00000");
	right_shift_test("FF00000000000000000000000000", 64, "FF0000000000");

	right_shift_test("FF0FF00FF00FF00FF00FF00000C00D0", 40, "FF0FF00FF00FF00FF00FF");
	right_shift_test("FF0FF00FF00FF00FF00FF0000000000", 60, "FF0FF00FF00FF00F");

	right_shift_test("80000000000000000000000000000000", 127, "1");

	right_shift_small_test("FF", 1, "7F");
	right_shift_small_test("FF000000000", 1, "7F800000000");
	right_shift_small_test("FF00000000000000000", 1, "7F80000000000000000");

	right_shift_small_test("FF00FF", 16, "FF");
	right_shift_small_test("FF00FF0000", 16, "FF00FF");
	right_shift_small_test("FF00FF0000000000000000", 16, "FF00FF000000000000");

	printf("TEST mg_uint128_right_shift_test(): OK\n");
}
