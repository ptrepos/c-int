#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint256.h>

#include "mg_assert.h"

static void xor_test(const char *text1, const char *text2, const char *ret)
{
	char strbuf[1024];
	mg_uint256 v1, v2, v3;

	mg_uint256_test_hex_convert(text1, &v1);
	mg_uint256_test_hex_convert(text2, &v2);

	mg_uint256_xor(&v1, &v2, /*out*/&v3);

	mg_uint256_test_to_hex_string(&v3, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint256_xor_test()
{
	xor_test("FF00FFFFFFFFFFFFFFFF", "FF00FFFFFFFFFFFFFFFF", "0");
	xor_test("FF00FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFF", "FF00FFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFFFFF", "0");
	xor_test("FF000000", "FF000000", "0");
	xor_test("FF000000", "0000000F", "FF00000F");
	xor_test("FF00000000000000FF00000000000000", "FF00FF", "FF00000000000000FF00000000FF00FF");
	xor_test("FF00000000000000FF0000000FFFF000", "FF00FF", "FF00000000000000FF0000000F00F0FF");
	xor_test("FF00000000000000FF0000000FFFF000FF00000000000000FF0000000FFFF000", "FF00FF", "FF00000000000000FF0000000FFFF000FF00000000000000FF0000000F00F0FF");
	xor_test("FF00000000000000FF0000000FFFF000FF00000000000000FF0000000FFFF000", "FF00FF", "FF00000000000000FF0000000FFFF000FF00000000000000FF0000000F00F0FF");

	printf("TEST mg_uint256_xor(): OK\n");
}
