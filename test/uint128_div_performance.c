#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int.h>

#define COUNT		(10000000)

static void timeattack_mg_uint128_div(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint128_div(&v1, &v2, &v3, &v4);
	}
}

static void timeattack_mg_uint128_div_long_division(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint128_div_long_division(&v1, &v2, &v3, &v4);
	}
}

static void timeattack_mg_uint128_div_maclaurin(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint128_div_maclaurin(&v1, &v2, &v3, &v4);
	}
}

void mg_uint128_div_performance()
{
	printf("PERFORMANCE TEST\n");
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div("1", "1");
		
		printf("mg_uint128_div() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_long_division("1", "1");
		
		printf("mg_uint128_div_long_division() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_maclaurin("1", "1");

		printf("mg_uint128_div_maclaurin() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();

		timeattack_mg_uint128_div("15", "3");

		printf("mg_uint128_div() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_long_division("15", "3");

		printf("mg_uint128_div_long_division() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_maclaurin("15", "3");

		printf("mg_uint128_div_maclaurin() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div("987297981453211324156985645", "42645641216545153445640");
		
		printf("mg_uint128_div() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_long_division("987297981453211324156985645", "42645641216545153445640");
		
		printf("mg_uint128_div_long_division() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_maclaurin("987297981453211324156985645", "42645641216545153445640");

		printf("mg_uint128_div_maclaurin() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div("9999999999999999999999999999999", "99999999999");
		
		printf("mg_uint128_div() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_long_division("9999999999999999999999999999999", "99999999999");
		
		printf("mg_uint128_div_long_division() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_maclaurin("9999999999999999999999999999999", "99999999999");

		printf("mg_uint128_div_maclaurin() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();

		timeattack_mg_uint128_div("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	
	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_long_division("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div_long_division() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_maclaurin("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div_maclaurin() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
}
