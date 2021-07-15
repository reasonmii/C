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






