#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	char code1 = 'A';
	char code2 = 65;

	printf("%c(%d) \n", code1, code2);    // A(65)

	printf("%3c - %3c - %3c\n", code1, code1 + 1, code1 + 2);   // A  - B  - C
	printf("%3d - %3d - %3d\n", code1, code1 + 1, code1 + 2);   // 65 - 66 - 67

	return 0;
}
