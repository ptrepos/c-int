#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int.h>

#define COUNT		(10000000)

static void timeattack_mg_uint256_div(const char *text1, const char *text2)
{
	mg_uint256 v1, v2, v3, v4;

	mg_uint256_test_convert(text1, &v1);
	mg_uint256_test_convert(text2, &v2);

	for(int i = 0; i < COUNT; i++) {
		mg_uint256_div(&v1, &v2, &v3, &v4);
	}
}

static void timeattack_mg_uint256_div_maclaurin(const char *text1, const char *text2)
{
	mg_uint256 v1, v2, v3, v4;

	mg_uint256_test_convert(text1, &v1);
	mg_uint256_test_convert(text2, &v2);

	for (int i = 0; i < COUNT; i++) {
		mg_uint256_div_maclaurin(&v1, &v2, &v3, &v4);
	}
}

void mg_uint256_div_performance()
{
	printf("PERFORMANCE TEST\n");
	{
		clock_t tm = clock();
		
		timeattack_mg_uint256_div("1", "1");
		
		printf("mg_uint256_div() 1/1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();

		timeattack_mg_uint256_div("15", "3");

		printf("mg_uint256_div() 15/3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();
		
		timeattack_mg_uint256_div("987297981453211324156985645", "42645641216545153445640");
		
		printf("mg_uint256_div() large1: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();
		
		timeattack_mg_uint256_div("9999999999999999999999999999999", "99999999999");
		
		printf("mg_uint256_div() large2: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();

		timeattack_mg_uint256_div("9999999999999999999999999999999999", "9999999");

		printf("mg_uint256_div() large3: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();

		timeattack_mg_uint256_div("99999999999999999999999999999999999999999999999999999999999999999999", "999999999999999999999");

		printf("mg_uint256_div() large4: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}

	{
		clock_t tm = clock();

		timeattack_mg_uint256_div_maclaurin("99999999999999999999999999999999999999999999999999999999999999999999", "999999999999999999999");

		printf("mg_uint256_div_maclaurin() large4: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
	printf("//---\n");
	{
		clock_t tm = clock();

		timeattack_mg_uint256_div("9999999999999999999999999999999999", "999999999999999999999");

		printf("mg_uint256_div() large5: %fms\n", (double)(clock() - tm) / CLOCKS_PER_SEC);
	}
}
