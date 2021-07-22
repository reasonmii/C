#include <stdio.h>
#include <stdbool.h>   // bool

int main() {

	// Boolean 사이즈는 원래 1비트
	// 그러나, 자료형이 가질 수 있는 최소 단위가 byte
	// 따라서, boolean도 1byte가 됨
	printf("%u\n", sizeof(_Bool));    // 1byte

	_Bool b1;
	b1 = 0;   // False
	b1 = 1;   // True

	printf("%d\n", b1);   // 1

	bool b2, b3;
	b2 = true;
	b3 = false;

	printf("%d %d\n", b2, b3);  // 1 0

	return 0;
}
