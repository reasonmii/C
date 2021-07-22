/*
Error
1) overflow : 입력 값이 해당 Type보다 너무 큰 메모리가 필요해서 (숫자가 너무 커서) 발생
2) underflow : 숫자가 너무 작아서 발생
3) round-off error : 정밀도 문제
   ex. 0.01을 0.0099로 인지하는 작은 오차로 인해 0.01을 100번 더해도 1이 되지 않음
*/

// ======================================================================

#include <stdio.h>
#include <float.h>
#include <math.h>   // asinf

int main() {

	// overflow
	float max = 3.402823466e+38F;
	printf("%f\n", max);
	max = max * 100.0f;
	printf("%f\n", max);   // inf

	// -------------------------------------------

	// underflow
	float min = 1.40129864e-45F;
	printf("%f\n", min);  // 0.000000

	// subnormal : 너무 작아서 정밀도를 잃고, 숫자가 사라져버리는 것
	min = min / 2.0f;
	printf("%f\n", min);  // 0.000000

	// -------------------------------------------

	// 0으로 나누기
	float f = 104.0f;
	printf("%f\n", f);
	f = f / 0.0f;       // warning 발생
	printf("%f\n", f);  // inf

	// -------------------------------------------

	float as = asinf(1.0f);
	printf("%f\n", as);   // 1.570796

	// sin은 원래 2.0 값을 갖지 못함
	as = asinf(2.0f);
	printf("%f\n", as);  // -nan(ind) : not a number

	return 0;
}

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

// ======================================================================

#include <stdio.h>

int main() {

	// round-off errors (ex1)
	float a, b;
	a = 1.0E20f + 1.0f;
	b = a - 1.0E20f;
	// result : 1.0이 아닌 0.000000
	// 숫자가 너무 커서 메모리 사용 정밀도가 떨어짐
	printf("%f\n", b);

	// -------------------------------------------

	// round-off errors (ex2)
	float d = 0.0f;
	int i = 0;

	// a = 0에 0.01을 100번 더함
	// result : 1.0이 아닌 0.999999
	// 부동소수점은 0.01을 깔끔하게 0.01로 인식하지 못함
	// 그 오차가 누적이 되어, 1.0이 나오지 않게 됨
	for (i = 0; i < 100; i++) {
		d = d + 0.01f;
	}

	printf("%f\n", d);

	return 0;
}
