#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수생성
void sort_asc(int a, int b) {
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
}

int main(void) {

	int a = 7, b = 5;
	sort_asc(a, b);           // 함수호출
	printf("%d <= %d\n\n", a, b);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수생성
// 변수의 주소
void sort_asc(int *a, int *b) {
	if (a > b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main(void) {

	int a = 7, b = 5;
	sort_asc(&a, &b);           // 함수호출
	printf("%d <= %d\n\n", a, b);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printLine(char c);    // 함수의 선언

int main(void) {

	// 작은 따옴표 사용 주의
	printLine('*');        // 함수호출
	printf("프로그램 결과\n");
	printLine('-');

	return 0;
}

// 함수의 정의
void printLine(char c) {
	for (int i = 0; i < 40; i++)
		printf("%c", c);
	printf("\n");
}

// 결과
// ****************************************
// 프로그램 결과
// ----------------------------------------

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>     // math 함수 활용하기

int main(void) {

	int a = 10;
	int b = 2;
	int c = 16;

	double result1 = pow(a, b);  // power : 제곱
	double result2 = sqrt(c);    // 제곱근

	// 10의   2승 =   100
	printf("%3d의 %3d승 = %5.0f\n", a, b, result1);

	// 16의 제곱근 =     4
	printf("%3d의 제곱근 = %5.0f\n", c, result2);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>              // 난수함수 포함

int main(void) {

	int a;

	for (int i = 1; i <= 5; i++) {
		printf("%d회 난수 = %5d \n", i, rand());
	}

	// 범위 제한 : 1~10 난수
	for (int i = 1; i <= 5; i++) {
		printf("%d회 난수 = %5d \n", i, (rand() % 10) + 1);
	}

	return 0;

}

// ======================================================================

#include <stdio.h>

int tmp = 1;       // 전역변수
void funcTmp();    // 함수의 선언

int main(void) {
	int tmp = 10;                    // 지역변수

	printf("%d in main()\n", tmp);

	for (int i = 0; i < 5; i++) {
		int tmp = 0;                 // 지역변수
		printf("%d in for\n", tmp++);
	}
	
	funcTmp();                      // 함수의 호출

	printf("%d in main() \n", tmp);

	return 0;
}

// 함수의 정의
void funcTmp() {
	int tmp = 99;
	printf("%d in funcTmp()\n", tmp);
}

// 결과
// 10 in main()
// 0 in for
// 0 in for
// 0 in for
// 0 in for
// 0 in for
// 99 in funcTmp()
// 10 in main()
