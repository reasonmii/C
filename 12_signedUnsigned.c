#include <stdio.h>
#include <limits.h>

int main() {

	// Range of unsigned and signed
	unsigned int i = 0b11111111111111111111111111111111;
	unsigned int u_max = UINT_MAX;
	unsigned int u_min = 0;
	signed int i_max = INT_MAX;
	signed int i_min = INT_MIN;

	printf("max of uint = %u\n", u_max);  // 4294967295
	printf("min of uint = %u\n", u_min);  // 0
	printf("max of uint = %d\n", i_max);  // 2147483647
	printf("min of uint = %d\n", i_min);  // -2147483648

	return 0;
}
