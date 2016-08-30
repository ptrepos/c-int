#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <magica/int.h>

#include "mg_assert.h"

void mg_uint256_div_performance();

void mg_uint256_test()
{
	clock_t tm = clock();

#if defined(NDEBUG)
	mg_uint256_div_performance();
#endif

	printf("mg_uint256 test: %fs\n", (float)(clock() - tm) / CLOCKS_PER_SEC);
}
