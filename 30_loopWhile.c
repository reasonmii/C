/*
어떤 조건인지에 따라 다른 Loop 사용
1) 진입조건 : while, for
2) 탈출조건 : do while

거의 모든 loop에서 for loop 사용
특히, 명확한 정의가 있는 상황에서 간단한 구현할 때
for(int i = 0; i < 100; ++i)

정확한 정의가 없는 상황에서 계속 입력을 받아야 할 때 while 많이 사용
while(scanf("%d", &num) == 1)

※ goto문
옛날 loop 방식인데, 코드가 꼬이고,
에러가 발생할 확률이 많아서 요즘은 사용X -> 단종된 기술
*/

// ======================================================================

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

int main() {

	int i = 0;
	while (i++ < 5)
		printf("Hi\n");

	return 0;
}

// ======================================================================
// 0 : False
// 그 외 모든 값 : True

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int tv, fv;
	tv = (1 < 2);
	fv = (1 > 2);

	printf("True is %d\n", tv);    // 1
	printf("False is %d\n", fv);   // 0

	int i = -5;
	while (i)
		printf("%d is true\n", i++);
	printf("%d is false\n", i);

	/*-5 is true
	  - 4 is true
	  - 3 is true
	  - 2 is true
	  - 1 is true
	  0 is false*/

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

int main() {

	int seconds = 0, minutes = 0, hours = 0;

	printf("Input seconds : ");
	scanf("%d", &seconds);

	while (seconds >= 0) {

		minutes = seconds / 60;
		seconds %= 60;

		hours = minutes / 60;
		minutes %= 60;

		// print result
		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

		printf("Input seconds : ");
		scanf("%d", &seconds);
	}

	printf("Good bye\n");

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	int i;
	// 숫자가 아닌 값을 입력할 때까지 계속 새로 입력 받기
	while (scanf("%d", &i) == 1)
		;    // null statement

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");

	// 정수를 입력하지 않으면 status는 0이 됨
	// status = scanf("%d", &num);

	while (scanf("%d", &num) == 1) {
		sum += num;
		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d", sum);
	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char c = 'A';
	while (c != 'Z')
		// output : A~Y
		printf("%c\n", c++);

	return 0;
}

// ======================================================================
// 완전히 똑같은 값을 입력하기 어려운 경우
// 비슷한 값을 입력하고, 그 차이가 거의 없으면 잘 맞췄다고 판단하는 방법

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>    // fabs() : 절대값

int main() {

	const double PI = 3.1415926535897932384626433832795;
	double guess = 0.0;

	printf("Input PI : ");
	scanf("%lf", &guess);

	while (fabs(guess - PI) > 0.01) {
		printf("Fool! Try Again!");
		scanf("%lf", &guess);
	}
	
	printf("Good!");

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

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	const int secret_code = 337;
	int guess = 0;

	do {
		printf("Enter secret code  :");
		scanf("%d", &guess);
	} while (secret_code != guess);

	return 0;
}
