#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// 자동 형변환
	int x = 3.14;
	double y = 3;

	printf("%d\n", x); // 3
	printf("%f", y);   // 3.000000

	return 0;
}
