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

	int x;

	printf("정수 입력 (1~3) : ");
	scanf("%d", &x);

	switch (x) {
	case 1: printf("1번\n");
		break;
	case 2: printf("2번\n");
		break;
	case 3: printf("3번\n");
		break;

	default: printf("1~3까지 입력하세요");
	}

	// -------------------------------------------
	// 누적 값 출력

	int y;

	printf("정수 입력 (0~2) : ");
	scanf("%d", &y);

	switch (y) {
	case 0: printf("delete 권한 있음\n");   // delete + write + read 권한
	case 1: printf("write 권한 있음\n");    // write + read 권한
	case 2: printf("read 권한 있음\n");     // read 권한
		break;

	default: printf("1~3까지 입력하세요");
	}

	return 0;

}





