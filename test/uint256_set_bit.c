#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/uint256.h>

#include "mg_assert.h"

static void set_bit_test(int bit_index, const char *ret)
{
	char strbuf[1024];
	mg_uint256 v1;

	mg_uint256_set_zero(&v1);
	mg_uint256_set_bit(&v1, bit_index);
	
	mg_uint256_test_to_hex_string(&v1, strbuf);

	mg_assert(strcmp(ret, strbuf) == 0);
}

void mg_uint256_set_bit_test()
{
	set_bit_test(0, "1");
	set_bit_test(1, "2");
	set_bit_test(3, "8");
	set_bit_test(4, "10");
	set_bit_test(16, "10000");
	set_bit_test(32, "100000000");
	set_bit_test(64, "10000000000000000");
	set_bit_test(65, "20000000000000000");
	set_bit_test(66, "40000000000000000");
	set_bit_test(67, "80000000000000000");
	set_bit_test(96, "1000000000000000000000000");
	set_bit_test(98, "4000000000000000000000000");
	set_bit_test(127, "80000000000000000000000000000000");
	set_bit_test(255, "8000000000000000000000000000000000000000000000000000000000000000");

	printf("TEST mg_uint256_set_bit_test(): OK\n");
}
