/*
ternary
삼항연산자
x ? y : z
x 값이 true면 y, false 면 z 출력
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

  // true, false -> 1, 0 대체 가능
	int temp;
	temp = true ? 1024 : 7;
	printf("%d\n", temp);     // 1024

	temp = false ? 1024 : 7;  // 7
	printf("%d\n", temp);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	int number;
	scanf("%d", &number);

	// 선언과 동시에 const로 값 고정
	// 보기 편하게 괄호 사용
	const bool is_even = (number % 2 == 0) ? printf("Even") : printf("Odd");

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	int a = 1, b = 2;
	const int max = (a > b) ? a : b;

	printf("%d", max);   // 2

	return 0;
}

