// ※ goto문
// 옛날 loop 방식인데, 코드가 꼬이고,
// 에러가 발생할 확률이 많아서 요즘은 사용X -> 단종된 기술

#include <stdio.h>

int main() {

	int n = 1;

label:
	printf("%d\n", n);
	n = n + 1;

	if (n == 10) goto out;
	goto label;

out:

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	int n = 1;

	while (n < 11) {
		printf("%d\n", n);
		n = n + 1;
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	int start = 1;
	int end = 10;
	int sum = 0;
	int i = start;

	while (i <= end) {
		if (i % 3 == 0) {
			i++;
			continue;
		}

		sum = sum + i;
		i++;
	}

	printf("%d ~ %d의 합 (3의 배수 제외) = %d\n", start, end, sum);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int inData = 0;
	int sum = 0;

	printf("정수입력! (종료 999) : ");
	scanf("%d", &inData);

	while (inData != 999) {
		sum = sum + inData;
		printf("정수입력! (종료 999) : ");
		scanf("%d", &inData);
	}

	printf("총 합 = %d", sum);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int start = 1;
	int end = 10;
	int sum = 0;
	int i = start;

	for (i = start; i <= end; i = i + 2)
		sum = sum + i;

	printf("%d ~ %d의 홀수합 = %3d", start, end, sum);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int start = 3, i;

	for (i = 1; i < 10; i++)
		printf("구구단 : %3d * %d = %3d\n", start, i, start * i);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int dan, i;

	// 구구단 전체 : 2 ~ 9단
	for (dan = 2; dan <= 9; dan++) {
		printf("\n\n\n===================== %d단 =====================\n", dan);
		for (i = 2; i <= 9; i++)
			printf("%d * %d = %d\n", dan, i, dan * i);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int sum = 0;
	int i, inData;

	// 5개 정수 입력해서 더하기
	for (i = 0; i < 5; i++) {
		printf("%d번째 정수 입력 : ", i + 1);
		scanf("%d", &inData);
		sum = sum + inData;
	}

	printf("합 = %2d \n", sum);

	return 0;
}

// ======================================================================
// for, while 문과 달리 do-while 문은 최소 1번은 실행

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int i = 1000;

	// 한 번 실행 후, 이후에 i가 3보다 작지 않기 때문에 실행 중단
	do {
		printf("i = %d\n", i);
		i++;
	} while (i < 3);

	return 0;
}
