#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint128.h>

#include "mg_assert.h"

static void convert_test(const char *text1)
{
	char strbuf[1024];
	mg_uint128 v1;

	mg_uint128_test_convert(text1, &v1);

	mg_uint128_test_to_string(&v1, strbuf);

	mg_assert(strcmp(text1, strbuf) == 0);
}

static void hex_convert_test(const char *text1)
{
	char strbuf[1024];
	mg_uint128 v1;

	mg_uint128_test_hex_convert(text1, &v1);

	mg_uint128_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(text1, strbuf) == 0);
}


void mg_uint128_convert_test()
{
	convert_test("1");
	convert_test("9");
	convert_test("12345687");
	convert_test("123456789012345678901234567890");
	convert_test("9874564121234561");
	convert_test("340282");
	convert_test("3402823669209");
	convert_test("34028236692093846346337");
	convert_test("34028236692093846346337460743176");
	convert_test("340282366920938463463374607431768211455");
	convert_test("340282366920938463463374607431768211454");
	
	hex_convert_test("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
	hex_convert_test("FFFFFFFFFFFFFFFFFFFFFFFFFFFF");
	hex_convert_test("FFFFFFFFFFFFFFFFFFFFFF");
	hex_convert_test("FFFFFFFFFFFFFFF");
	hex_convert_test("FFFFFFF");
	hex_convert_test("FF");
	hex_convert_test("123456789ABCDEF123456789ABCDEF");
	hex_convert_test("123456789ABCDEF123456789A");
	hex_convert_test("123456789ABCDEF123456");
	hex_convert_test("123456789ABCDE");
	hex_convert_test("123456789");
	hex_convert_test("1234");
	
	printf("TEST mg_uint128 conversion: OK\n");
}
