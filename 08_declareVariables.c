// 변수명 한 번에 변경하기
// 해당 변수명 우클릭 - Rename - 입력 - Apply

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

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {

	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U;    // 3'000'000'000U
	long l = 65537L;
	long long ll = 12345678908642LL; 

	printf("char         = %hhd, %d, %c\n", c, c, c);  // 65, 65, A
	printf("short        = %hhd, %hd, %d\n", s, s, s); // -56(overflow), 200, 200
	printf("unsigned int = %u, %d\n", ui, ui);         // 3000000000, -1294967296(overflow)
	printf("long         = %ld, %hd\n", l, l);         // 65537, 1
	printf("long long    = %lld, %ld\n", ll, ll);      // 12345678908642, 1942899938

	return 0;
}

