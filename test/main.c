#include <stdio.h>

void mg_uint128_test();
//void mg_uint256_test();

#include <stdint.h>
#include <magica/int/uint64.h>

int main(void)
{
	mg_uint128_test();
	//mg_uint256_test();
	
	fgetc(stdin);

	return 0;
}
