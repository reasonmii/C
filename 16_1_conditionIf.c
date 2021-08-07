#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int big, small;
	int temp;

	printf("첫 번째 수 : ");
	scanf("%d", &big);
	printf("두 번째 수 : ");
	scanf("%d", &small);

	if (big < small) {
		temp = big;
		big = small;
		small = temp;
	}

	printf("%d >= %d", big, small);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int a, b;
	int big, small;

	printf("첫 번째 수 : ");
	scanf("%d", &a);
	printf("두 번째 수 : ");
	scanf("%d", &b);

	if (a >= b) {
		big = a;
		small = b;
	}
	else {
		big = b;
		small = a;
	}

	printf("%d >= %d", big, small);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int x;

	printf("정수 입력 : ");
	scanf("%d", &x);

	if (x == 0)
		printf("0");
	else if (x > 0)
		printf("양수");
	else
		printf("음수");

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	if (num % 2 == 0)
		printf("\n%d : 짝수!", num);
	else
		printf("\n%d : 홀수!", num);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int num;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	if (5 >= num && num >= 1)
		printf("\n작은수!", num);
	else if (10 >= num && num >= 6)
		printf("\n큰수!", num);
	else
		printf("1~10까지만 가능");

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int number;

	printf("Your number? ");
	scanf("%d", &number);

	if (number > 5) {
		if (number < 10)
			printf("Larger than 5 smaller than 10\n");
		else
			printf("Larger than 10");
	}
	else
		printf("Less than or equal to 5");

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	unsigned num;

	// ★ FLAG - try bool type
	bool isPrime = true;

	// Check if num is a prime number

	scanf("%u", &num);
	
	// 사칙연산 : div와 num type 같은 게 좋음 - 다른 경우 warning
	// ★ div*div < num -> for문 반복을 줄일 수 있음
	for (unsigned div = 2; (div*div) <= num; ++div) {
		if (num % div == 0) {
			isPrime = false;

			if (num == div * div)
				printf("%u is divisible by %u.\n", num, div);
			else
				printf("%u is divisible by %u and %u.\n", num, div, num/div);
		}
	}

	if (isPrime)
		printf("%u is a prime number.\n", num);
	else
		printf("%u is not a prime number.\n", num);

	return 0;
}

