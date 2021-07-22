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

// ======================================================================

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {

	// Maximum numbers
	unsigned int decimal = 4294967295;
	unsigned int binary = 0b11111111111111111111111111111111;  // 32개
	unsigned int oct = 037777777777;
	unsigned int hex = 0xffffffff;

	printf("%u\n", decimal);   // 4294967295
	printf("%u\n", binary);    // 4294967295
	printf("%u\n", oct);       // 4294967295
	printf("%u\n", hex);       // 4294967295

	// %o : 8진수
	// %x : 16진수
	// %#o : 앞에 0을 붙여서 출력  -> 8진수임을 알 수 있음
	// %#x : 앞에 0x을 붙여서 출력 -> 16진수임을 알 수 있음
	// 37777777777 ffffffff 037777777777 0xffffffff, 0XFFFFFFFF
	printf("%o %x %#o %#x, %#X", decimal, decimal, decimal, decimal, decimal);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	// float형은 뒤에 f 붙이기
	float f = 123.456f;
	double d = 123.456;

	// 123.456001 123.456001 1.234560e+02 1.234560E+02
	printf("%f %F %e %E\n", f, f, f, f);
	// 123.456000 123.456000 1.234560e+02 1.234560E+02
	printf("%f %F %e %E\n", d, d, d, d);

	// double은 메모리를 두 배 사용
	// float에 '123.456'처럼 double 값을 넣으면
	// 작은 공간에 큰 값을 넣으려고 하는 것이기 때문에 warning 발생
	float f2 = 123.456;

	// 큰 공간에 작은 값 넣기 때문에 경고 발생X
	double d2 = 123.456f;

	int i = 3;
	// .입력 -> 실수라는 것 알려줌
	float f3_1 = 3.f;
	float f3_2 = 3.0f;
	double d3_1 = 3.;
	double d3_2 = 3.0;

	// e, E 모두 가능
	float f4 = 1.234e10f;

	// 0x : 16진수
	// p, P -> e, E와 같은 역할
	float f5_1 = 0x1.1p1;
	float f5_2 = 0xa.1p1;
	float f5_3 = 0xb.1p1;

	// %a, %A : 16진수 출력
	printf("%a, %A\n", f5_1, f5_1);  // 0x1.1000000000000p+1, 0X1.1000000000000P+1
	printf("%a, %A\n", f5_2, f5_2);  // 0x1.4200000000000p+4, 0X1.4200000000000P+4
	printf("%a, %A\n", f5_3, f5_3);  // 0x1.6200000000000p+4, 0X1.6200000000000P+4

	// 1 / 16 = 0.0625
	double d5 = 1.0625e0;

	printf("%a, %A\n", d5, d5);      // 0x1.1000000000000p+0, 0X1.1000000000000P+0

	return 0;
}
