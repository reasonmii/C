#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// 변수선언 방법1
	int   iData;
	float fData;
	double dData;
	char  cData;
	
	// 변수선언 방법2
	int   a, b;

	// 변수에 값 대입
	iData = 50;
	fData = 5.2;
	dData = 3.14;
	cData = 'a';

	printf("iData = %8d \n", iData);
	printf("fData = %8.2f \n", fData);
	printf("dData = %8.2f \n", dData);
	printf("cData = %c \n", cData);

	// 변수 선언 & 대입 -> 변수 초기화
	int   c = 6;

	// -------------------------------------------

	printf("정수를 입력하세요: ");
	scanf("%d", &iData);
	printf("입력한 정수는 %d 입니다.", iData);

	// -------------------------------------------

	int x = 10;    // 10진수
	int y = 010;   // 8진수
	int z = 0x10;  // 16진수

	printf("x = %d \n", x);    // 10
	printf("y = %d \n", y);    // 8
	printf("z = %d \n", z);    // 16

	printf("x = %d (%d) \n", x, x, 10);   // x = 10 (10)
	printf("y = %o (%d) \n", x, x, 8);    // y = 12 (10)
	printf("z = %x (%d) \n", x, x, 16);   // z = a (10)

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

// 기호 상수 Symbolic Constant
#define EX_RATE 1200

int main(void) {

	int dollar1 = 10;
	int dollar2 = 100;
	int dollar3 = 1000;

	int won1 = EX_RATE * dollar1;
	int won2 = EX_RATE * dollar2;
	int won3 = EX_RATE * dollar3;

	printf("%d원 = %d달러 \n", won1, dollar1);  // 12000원 = 10달러
	printf("%d원 = %d달러 \n", won2, dollar2);
	printf("%d원 = %d달러 \n", won3, dollar3);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// const로 선언 시 밑에서 값 수정 불가능
	const int EX_RATE = 1200;

	int dollar1 = 10;
	int dollar2 = 100;
	int dollar3 = 1000;

	int won1 = EX_RATE * dollar1;
	int won2 = EX_RATE * dollar2;
	int won3 = EX_RATE * dollar3;

	printf("%d원 = %d달러 \n", won1, dollar1);  // 12000원 = 10달러
	printf("%d원 = %d달러 \n", won2, dollar2);
	printf("%d원 = %d달러 \n", won3, dollar3);

	return 0;

}

// ======================================================================

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
