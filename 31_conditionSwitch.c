// 간단한 case가 여러 개일 때는 switch가 보기 좋기 때문에 많이 사용함

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

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>    // float max, float min

int main(void) {

	char c;
	while ((c = getchar()) != '.') {
		printf("You love : ");

		// Note : integer types only
		switch (c) {
		case 'a':
		case 'A':
			printf("apple");
			break;
		case 'b':
		case 'B':
			printf("baseball");
			break;
		case 'c':
		case 'C':
			printf("cake");
			break;
		default:
			printf("nothing");
		}

		printf(".\n");

		// ※ 여러 문자를 입력했을 때
		// 같은 줄에 있는 첫 글자 외 모든 글자 무시
		while (getchar() != '\n')
			continue;
	}

	return 0;
}
