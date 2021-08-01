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

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>    // float max, float min

int main(void) {

	float max = -FLT_MAX;
	float min = FLT_MAX;
	float sum = 0.0f;
	float input;
	int n = 0;

	while (scanf("%f", &input) == 1) {

		// Ignore negative value and the number larger than 100
		if (input < 0 || input > 100.0f) continue;

		max = (input > max) ? input : max;
		min = (input < min) ? input : min;
		sum += input;

		// Count number of inputs
		n++;
	}

	if (n > 0)
		printf("min = %f, max = %f, avg = %f\n", min, max, sum / n);
	else
		printf("No input\n");

	return 0;
}
