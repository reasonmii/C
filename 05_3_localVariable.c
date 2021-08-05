// 지역변수 : 해당 범위 내에서만 인식

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a;
	a = 2;

	// 2       0113FEA4
	printf("%d\t", a);
	printf("%p\n", &a);

	{
		int a;
		a = 5;

		// 5       0113FE98
		printf("%d\t", a);
		printf("%p\n", &a);
	}

	// 2       0113FEA4
	printf("%d\t", a);
	printf("%p\n", &a);

}

