#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int/uint128_def.h>
#include <magica/int/uint128_impl.h>

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

static void timeattack_mg_uint128_div_recovering_method(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint128_div_recovering_method(&v1, &v2, &v3, &v4);
	}
}

static void timeattack_mg_uint128_div_srt(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint128_div_srt(&v1, &v2, &v3, &v4);
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

static void timeattack_mg_uint128_div_goldschmidt(const char *text1, const char *text2)
{
	mg_uint128 v1, v2, v3, v4;

	mg_uint128_test_convert(text1, &v1);
	mg_uint128_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint128_div_goldschmidt(&v1, &v2, &v3, &v4);
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
		
		timeattack_mg_uint128_div_srt("1", "1");
		
		printf("mg_uint128_div_srt() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_recovering_method("1", "1");

		printf("mg_uint128_div_recovering_method() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_long_division("1", "1");
		
		printf("mg_uint128_div_long_division() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_goldschmidt("1", "1");

		printf("mg_uint128_div_goldschmidt() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div("15", "3");

		printf("mg_uint128_div() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_srt("15", "3");

		printf("mg_uint128_div_srt() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_recovering_method("15", "3");

		printf("mg_uint128_div_recovering_method() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_long_division("15", "3");

		printf("mg_uint128_div_long_division() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_goldschmidt("15", "3");

		printf("mg_uint128_div_goldschmidt() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div("987297981453211324156985645", "42645641216545153445640");
		
		printf("mg_uint128_div() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_srt("987297981453211324156985645", "42645641216545153445640");
		
		printf("mg_uint128_div_srt() large1 %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_recovering_method("987297981453211324156985645", "42645641216545153445640");

		printf("mg_uint128_div_recovering_method() large1 %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_long_division("987297981453211324156985645", "42645641216545153445640");
		
		printf("mg_uint128_div_long_division() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_goldschmidt("987297981453211324156985645", "42645641216545153445640");

		printf("mg_uint128_div_goldschmidt() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div("9999999999999999999999999999999", "99999999999");
		
		printf("mg_uint128_div() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	
	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_srt("9999999999999999999999999999999", "99999999999");
		
		printf("mg_uint128_div_srt() large2 %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_recovering_method("9999999999999999999999999999999", "99999999999");

		printf("mg_uint128_div_recovering_method() large2 %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();
		
		timeattack_mg_uint128_div_long_division("9999999999999999999999999999999", "99999999999");
		
		printf("mg_uint128_div_long_division() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_goldschmidt("9999999999999999999999999999999", "99999999999");

		printf("mg_uint128_div_goldschmidt() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_srt("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div_srt() large3 %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_recovering_method("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div_recovering_method() large3 %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_long_division("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div_long_division() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint128_div_goldschmidt("9999999999999999999999999999999999", "9999999");

		printf("mg_uint128_div_goldschmidt() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
}
