#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x, y, z;

	// comma 연산자는 전체 중 가장 오른쪽 값이 들어가게 됨
	z = ((x = 1), (y = 2));
	printf("%d, %d, %d\n", x, y, z);  // 1, 2, 2

	int my_money = (123, 456);
	printf("%d\n", my_money);        // 456

	return 0;
}
