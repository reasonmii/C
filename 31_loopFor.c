#include <stdio.h>

int main() {

	for (int i = 1; i <= 10; i++)
		printf("%d\n", i);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	for (int i = 0; i < 100; i = i + 8)
		printf("%d\n", i);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c\n", c);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	for (int i = 0; i * i < 10; i++)
		printf("%d\n", i);   // 0 1 2 3

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	// 같은 자료형일 때만 여러 개 input 가능
	for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)
		printf("%d %d\n", x, y);
	// 1 5
	// 2 16
	// 3 19

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	int i, n;
	n = 2;

	for (i = 2; n < 10; ) {
		n = n * i;
		printf("%d\n", n);  // 4 8 16
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	// 무한LOOP
	for (; ;)
		printf("I love you!");

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 입력 숫자가 7이 아니면 계속 LOOP
	// 너무 복잡해서 권장하지 않는 코드
	int i = 0;
	for (printf("Let's go!\n"); i != 7; scanf("%d", &i))
		;

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

#define NUM_ROWS 5
#define FIRST_CHAR 'A'
#define LAST_CHAR 'K'

int main() {

	int r;    // row loop
	int c;    // character loop

	// A~K 5번 출력
	for (r = 0; r < NUM_ROWS; ++r) {
		for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)
			printf("%c", c);
		printf("\n");
	}

	return 0;
}

// ======================================================================
/*
A
AB
ABC
ABCD
ABCDE
ABCDEF
ABCDEFG
ABCDEFGH
ABCDEFGHI
ABCDEFGHIJ
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'

int main() {

	int r;    // row loop
	int c;    // character loop

	// A~K 5번 출력
	for (r = 0; r < NUM_ROWS; ++r) {
		for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)
			printf("%c", c);
		printf("\n");
	}

	return 0;
}

// ======================================================================
/*
ABCDEFGHIJK
ABCDEFGHIJ
ABCDEFGHI
ABCDEFGH
ABCDEFG
ABCDEF
ABCDE
ABCD
ABC
AB
A
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'

int main() {

	int r;    // row loop
	int c;    // character loop

	// A~K 5번 출력
	for (r = NUM_ROWS; r >= 0; --r) {
		for (c = FIRST_CHAR; c <= FIRST_CHAR + r; c++)
			printf("%c", c);
		printf("\n");
	}

	return 0;
}

// ======================================================================
/*
ABCDEFGHIJK
BCDEFGHIJK
CDEFGHIJK
DEFGHIJK
EFGHIJK
FGHIJK
GHIJK
HIJK
IJK
JK
K
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define FIRST_CHAR 'A'

int main() {

	const char last_char;

	printf("What's your last character? (upper case) :");
	scanf("%c", &last_char);

	const int num_rows = last_char - FIRST_CHAR + 1;

	int r;    // row loop
	int c;    // character loop

	// A~K 5번 출력
	for (r = 0; r < num_rows; ++r) {
		for (c = FIRST_CHAR + r; c < FIRST_CHAR + num_rows; ++c)
			printf("%c", c);
		printf("\n");
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
// Zeno's Paradox 제논의 역설
// 매 step마다 시간 간격을 반으로 줄이는 것
// Step1 : 1.0 * 1.0 = 1.0, 1.0
// Step2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
// Step3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	const double speed = 1.0;

	// 최대 반복횟수는 보통 0 이상이니 unsigned 사용하기도 함
	const unsigned repeat_max = 50;

	double time = 0.0;       // Elapsed time
	double dist_arch = 0.0;  // Archilleus distance from start point
	double dist_turt = 1.0;  // Turtle distance from start point
	double speed_arch = 10.0;
	double speed_turt = 0.001;
	double dt = 0.01;       // 시간간격

	unsigned i;

	printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n", time, dt, dist_arch, dist_turt);

	for (i = 0; i < repeat_max; ++i) {
		dist_arch += speed_arch * dt;   // dist = dist + speed * dt;
		dist_turt += speed_turt * dt;
		time += dt;

		printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n", time, dt, dist_arch, dist_turt);

		// dt가 실수니까 2로 나눌 때, 2.0 쓸 것
		// dt /= 2.0;

		// ★ 곱하기가 나누기보다 빠름
		// 가능하면 곱하기 사용할 것
		dt *= 0.5;
	}

	return 0;
}

