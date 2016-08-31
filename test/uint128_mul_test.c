#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int/uint128.h>
#include <magica/int/uint128_impl.h>

#include "mg_assert.h"

static void mul_test(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4, v5;

	mg_uint128_test_convert(text1, /*out*/&v1);
	mg_uint128_test_convert(text2, /*out*/&v2);

	mg_assert(mg_uint128_mul(&v1, &v2, /*out*/&v3) == 0);

	mg_uint128_div(&v3, &v2, /*out*/&v4, /*out*/&v5);

	mg_assert(mg_uint128_is_zero(&v5) != 0);
	mg_assert(mg_uint128_compare(&v1, &v4) == 0);
}

static void mul_overflow_test(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3;

	mg_uint128_test_convert(text1, /*out*/&v1);
	mg_uint128_test_convert(text2, /*out*/&v2);

	mg_assert(mg_uint128_mul(&v1, &v2, /*out*/&v3) != 0);
}

void mg_uint128_mul_test()
{
	mul_test("1351233333314541", "467827411531");
	mul_test("99999999999999999", "99999999999999999");
	mul_test("999999999999999999999", "9999999999999999");
	mul_test("500", "20");
	mul_test("8888888888888888141351", "4461651531188");
	mul_test("44616515311888888", "44616515311888888");
	mul_test("123465791234657912346579123465", "20");
	mul_test("3333333333333333", "999999999999999999999");
	mul_test("340282366920938463463374607431768211400", "1");
	mul_test("115792089237316195423570985008687907853", "1");
	mul_test("340282366920938463463374607431768211455", "1");
	mul_test("18446744073709551615", "18446744073709551615");
	mul_test("340282366920938463463374", "1844674");

	mul_overflow_test("340282366920938463463374607431768211455", "2");
	mul_overflow_test("34028236692093846346337460743176821", "100000");
	mul_overflow_test("340299999999999", "10000000000000000000000000");

	printf("TEST mg_uint128_mul(): OK\n");
}
