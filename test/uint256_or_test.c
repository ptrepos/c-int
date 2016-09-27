#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint256.h>

#include "mg_assert.h"

static void or_test(const char *text1, const char *text2, const char *ret)
{
	char strbuf[1024];
	mg_uint256 v1, v2, v3;

	mg_uint256_test_hex_convert(text1, &v1);
	mg_uint256_test_hex_convert(text2, &v2);

	mg_uint256_or(&v1, &v2, /*out*/&v3);

	mg_uint256_test_to_hex_string(&v3, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint256_or_1(/*inout*/&v1, &v2);

	mg_uint256_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint256_or_test()
{
	or_test("FF00", "00FF", "FFFF");
	or_test("FF000000", "FF0000", "FFFF0000");
	or_test("FF000000", "FF00FF", "FFFF00FF");
	or_test("FF00000000000000FF00000000000000", "FF00FF", "FF00000000000000FF00000000FF00FF");
	or_test("FF00000000000000FF00000000000000FF00000000000000FF00000000000000", "FF00FF", "FF00000000000000FF00000000000000FF00000000000000FF00000000FF00FF");
	or_test("FF00000000000000FF00000000000000FF00000000000000FF00000000000000", "FF00000000000000FF00000000000000FF00000000000000FF00000000000000", "FF00000000000000FF00000000000000FF00000000000000FF00000000000000");
	or_test("FFFF000000000000FF00000000000000FF00000000000000FF000000000000FF", "FF00000000000000FF000000000000FFFF00000000000000FF00000000000000", "FFFF000000000000FF000000000000FFFF00000000000000FF000000000000FF");

	printf("TEST mg_uint256_or(): OK\n");
}
