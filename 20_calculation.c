#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// 산술 연산
	int num1 = 5;
	int num2 = 3;

	int  sum1 = num1 + num2;
	int  sub1 = num1 - num2;
	int  mul1 = num1 * num2;
	double div1 = num1 / num2;
	double div2 = (double)num1 / num2;
	double div3 = num1 / (double)num2;

	printf("%5d \n", sum1);
	printf("%5d \n", sub1);
	printf("%5d \n", mul1);
	printf("%5f \n", div1);   // 1.000000
	printf("%5f \n", div2);   // 1.666667
	printf("%5f \n", div3);   // 1.666667

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int div, mod;

	div = 11 / 5;
	mod = 11 % 5;
	printf("div = %d, mod = %d\n", div, mod);  // 2 1

	// 앞 피연산자가 양수이면 mod 값은 양수
	div = 11 / -5;
	mod = 11 % -5;
	printf("div = %d, mod = %d\n", div, mod);  // -2, 1

	// 앞 피연산자가 음수이면 mod 값은 음수
	div = -11 / -5;
	mod = -11 % -5;
	printf("div = %d, mod = %d\n", div, mod);  // 2, -1

	div = -11 / 5;
	mod = -11 % 5;
	printf("div = %d, mod = %d\n", div, mod);  // -2, -1

	return 0;
}
