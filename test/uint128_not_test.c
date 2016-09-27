#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint128.h>

#include "mg_assert.h"

static void not_test(const char *text1, const char *ret)
{
	char strbuf[1024];
	mg_uint128 v1, v2;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_uint128_not(&v1, /*out*/&v2);

	mg_uint128_test_to_hex_string(&v2, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);

	mg_uint128_not_1(/*inout*/&v1);

	mg_uint128_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint128_not_test()
{
	not_test("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", "0");
	not_test("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00", "FF");
	not_test("0000FFFFFFFFFFFFFFFFFFFFFFFFFF00", "FFFF00000000000000000000000000FF");

	printf("TEST mg_uint128_not(): OK\n");
}
