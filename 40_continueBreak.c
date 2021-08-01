#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	// result : 012346789
	for (int i = 0; i < 10; ++i) {
		if (i == 5)
			continue;
		printf("%d", i);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	// result : 01234
	for (int i = 0; i < 10; ++i) {
		if (i == 5)
			break;
		printf("%d", i);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	// while and continue
	// aaaaaaaaaaaaaaaaaaaahelloworld
	// -> result : hello
	int count = 0;
	while (count < 5) {
		int c = getchar();
		if (c == 'a')
			continue;
		putchar(c);
		count++;
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	// for and continue
	// aaaaaaaaaaaaaaaaaaaaaaaaahelloworld -> result : nothing
	// aahelloaworld -> result : hellowo
	int count = 0;
	for (int count = 0; count < 10; ++count) {
		int c = getchar();
		if (c == 'a')
			continue;
		putchar(c);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	// ★ continue as a placeholder
	// placeholder : 자리만 차지하는 것
	while (getchar() != '\n')
		// 원래 그냥 ; 만 써서 null statement 표현해도 되는데
		// 무슨 의미인지 알기 위해 continue 명확히 써 주는 것 선호
		continue;

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

  // 무한루프인데 . 입력하면 종료
	while (1) {
		char c = getchar();
		if (c == '.')
			break;
		putchar(c);
	}

	return 0;
}

// ======================================================================
// ★ break는 자신을 감싸는 첫 번째 loop를 깨고 나옴

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5)
				break;
			printf("(%d %d) ", i, j);
		}
		printf("\n");
	}

	return 0;
}

/*
result
(0 0) (0 1) (0 2) (0 3) (0 4)
(1 0) (1 1) (1 2) (1 3) (1 4)
(2 0) (2 1) (2 2) (2 3) (2 4)
(3 0) (3 1) (3 2) (3 3) (3 4)
(4 0) (4 1) (4 2) (4 3) (4 4)
(5 0) (5 1) (5 2) (5 3) (5 4)
(6 0) (6 1) (6 2) (6 3) (6 4)
(7 0) (7 1) (7 2) (7 3) (7 4)
(8 0) (8 1) (8 2) (8 3) (8 4)
(9 0) (9 1) (9 2) (9 3) (9 4)
*/
