#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint256.h>

#include "mg_assert.h"

static void not_test(const char *text1, const char *ret)
{
	char strbuf[1024];
	mg_uint256 v1, v2;

	mg_uint256_test_hex_convert(text1, &v1);

	mg_uint256_not(&v1, /*out*/&v2);

	mg_uint256_test_to_hex_string(&v2, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint256_not_test()
{
	not_test("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", "0");
	not_test("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00", "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000000000000FF");
	not_test("0000FFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFF00", "FFFF00000000000000000000000000FFFFFF00000000000000000000000000FF");
	not_test("0000FFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFF00", "FFFF00000000000000000000000000FFFFFF00000000000000000000000000FF");

	printf("TEST mg_uint256_not(): OK\n");
}
