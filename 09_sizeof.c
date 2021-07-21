#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int x;
	double d;
	char ch;

	printf("변수 x의 크기  : %d\n", sizeof(x));   // 4
	printf("변수 d의 크기  : %d\n", sizeof(d));   // 8
	printf("변수 ch의 크기 : %d\n", sizeof(ch));  // 1

	printf("자료형 int의 크기    : %d\n", sizeof(int));     // 4
	printf("자료형 short의 크기  : %d\n", sizeof(short));   // 2
	printf("자료형 long의 크기   : %d\n", sizeof(long));    // 4
	printf("자료형 float의 크기  : %d\n", sizeof(float));   // 4
	printf("자료형 double의 크기 : %d\n", sizeof(double));  // 8
	printf("자료형 char의 크기   : %d\n", sizeof(char));    // 1

}

// ======================================================================

#include <stdio.h>

int main() {

	unsigned int i = 0;

	// 마우스를 위에 올리면 '4U' 글자 보임
	// -> 4byte 라는 의미
	sizeof(unsigned int);
	sizeof(i);

	printf("%u\n", sizeof(unsigned int));   // 4
	printf("%u\n", sizeof(i));              // 4

	return 0;
}
