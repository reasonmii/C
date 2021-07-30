#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	_Bool a = (2 > 1);
	_Bool b = (1 > 2);

	printf("True is %d\n", a);   // 1
	printf("False is %d\n", b);  // 0

	// x ? y : z
	// x가 true면 y, false면 z 출력 
	printf(a ? "true\n" : "false\n");   // true
	printf(b ? "true\n" : "false\n");   // false

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>   // bool

int main() {

	bool bt = true;
	bool bf = false;

	printf("True is %d\n", bt);    // 1
	printf("False is %d\n", bf);   // 0

	return 0;
}

// ======================================================================

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
