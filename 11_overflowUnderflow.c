// Error
// overflow : 입력 값이 해당 Type보다 너무 큰 메모리가 필요해서 (숫자가 너무 커서) 발생
// underflow : 숫자가 너무 작아서 발생

// ======================================================================

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {

	// Overflow
	unsigned int u_max = UINT_MAX + 1;

	// i to binary representation
	char buffer[33];
	_itoa(u_max, buffer, 2);

	// print decimal and binary : 오히려 가장 작은 값을 출력함
	// 10진수 4294967295 + 1 -> 0
	printf("decimal : %u\n", u_max);
	// 2진수 11111111111111111111111111111111 + 1 -> 0
	printf("binary : %s\n", buffer);

	return 0;
}

// ======================================================================

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {

	// Underflow
	unsigned int u_min = 0 - 1;

	// i to binary representation
	char buffer[33];
	_itoa(u_min, buffer, 2);

	// print decimal and binary : 오히려 가장 큰 값을 출력함
	// 10진수 0 - 1 -> 4294967295
	printf("decimal : %u\n", u_min);
	// 2진수 0 - 1 -> 11111111111111111111111111111111
	printf("binary : %s\n", buffer);

	return 0;
}
