#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int/uint128_def.h>
#include <magica/int/uint128_impl.h>

#include "mg_assert.h"

static void add_sub_test(const char *text1, const char *text2)
{
	char strbuf[1024];
	mg_uint128 v1, v2, v3;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	mg_assert(mg_uint128_add(&v1, &v2, /*out*/&v3) == false);
	mg_assert(mg_uint128_sub(&v3, &v2, /*out*/&v1) == false);

	mg_uint128_test_to_string(&v1, strbuf);

	mg_assert(strcmp(text1, strbuf) == 0);
}

static void add_carry_test(const char *text1, const char *text2)
{
	char strbuf[1024];
	mg_uint128 v1, v2, v3;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	mg_assert(mg_uint128_add(&v1, &v2, /*out*/&v3) == true);

	mg_uint128_test_to_string(&v1, strbuf);

	mg_assert(strcmp(text1, strbuf) == 0);
}

static void sub_borrow_test(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	mg_assert(mg_uint128_sub(&v1, &v2, /*out*/&v3) == true);
}

void mg_uint128_add_test()
{
	add_sub_test("123456789", "12346578979152132165413");
	add_sub_test("12346578979152132165413", "12346578979152132165413");
	add_sub_test("6324810344444111111111111111", "6324810344444111111111111111");
	add_sub_test("10", "30");
	add_sub_test("9846537167456411113333333333333333", "9999999");
	add_sub_test("99999999999999999999999999999999999", "99999999999999999999999999999999999");
	add_sub_test("99999999999999999999999999999999", "1");
	add_sub_test("99999999999999999999999999999999", "3");
	add_sub_test("999999999999999999999999999999999", "7");
	add_sub_test("3", "999999999999999999999999999999999");
	add_sub_test("7", "999999999999999999999999999999999");
	add_sub_test("88888888888881", "88888888888881");
	add_sub_test("999999999999999999999999999999999999", "935");
	add_sub_test("664", "1024");
	add_sub_test("1024", "1024");
	add_sub_test("97446154111", "4561");
	add_sub_test("4561", "97446154111");

	add_carry_test("340282366920938463463374607431768211455", "1");
	add_carry_test("340282366920938463463374607431768211455", "100000000001");

	sub_borrow_test("3402823669209384", "3402823669209385");
	sub_borrow_test("340282366920938463463374607431768211454", "340282366920938463463374607431768211455");

	printf("TEST mg_uint128_add() and mg_uint128_subtract(): OK\n");
}
