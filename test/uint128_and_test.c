#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint128.h>

#include "mg_assert.h"

static void and_test(const char *text1, const char *text2, const char *ret)
{
	char strbuf[1024];
	mg_uint128 v1, v2, v3;

	mg_uint128_test_hex_convert(text1, &v1);
	mg_uint128_test_hex_convert(text2, &v2);

	mg_uint128_and(&v1, &v2, /*out*/&v3);

	mg_uint128_test_to_hex_string(&v3, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint128_and_1(/*inout*/&v1, &v2);

	mg_uint128_test_to_hex_string(&v1, strbuf);
}

void mg_uint128_and_test()
{
	and_test("FF00", "00FF", "0");
	and_test("FF000000", "FF0000", "0");
	and_test("FF000000", "FF00FF", "0");
	and_test("FF000000", "FF000000", "FF000000");
	and_test("FF0000FF", "FF00000F", "FF00000F");
	and_test("FF00000000000000FF00000000000000", "FF00FF", "0");
	and_test("FF00000000000000FF0000000FFFF000", "FF00FF", "FF0000");

	printf("TEST mg_uint128_and(): OK\n");
}
