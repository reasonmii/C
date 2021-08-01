/*
Logical operator
&& : and
|| : or
!  : not

#include <iso646.h>
&& || ! -> and or not 으로 사용 가능

헷갈리지 않고 한 번에 알아볼 수 있게 괄호 사용하는 게 좋음
1) 보다 2) 방법 선호
1) a > b && b > c || b > d;
2) ((a > b) && (b > c)) || (b > d);
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void) {

	bool test1 = 3 > 2 || 5 > 6;  // true
	bool test2 = 3 > 2 && 5 > 6;  // false
	bool test3 = !(5 > 6);        // true, equivalent to 5 <= 6

	printf("%d %d %d\n", test1, test2, test3);   // 1 0 1

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define PERIOD '.'

int main(void) {

	char ch;
	int count = 0;

	while ((ch = getchar()) != PERIOD) {

		// 줄바꿈, 띄어쓰기 빼고 글자 count
		if (ch != '\n' && ch != ' ')
			count++;
	}

	printf("%d", count);

	return 0;
}

// ======================================================================

/*
Short-circuit Evaluation
- Logical expressions are evaluated from left to right
- && and || are sequence points

★ sequence points?
왼쪽부터 실행하고, 왼쪽이 맞지 않으면 오른쪽은 계산도 하지 않는 것

헷갈리고 복잡하니 가급적 사용하지 않는 게 좋지만
성능측면에서 차이가 나는 경우 사용함
*/

// ======================================================================

/*
아래에서 두 번째 경우는 왼쪽 'temp == 0'이 틀렸으니
오른쪽 '++temp == 1024'는 계산도 하지 않음
따라서, before, after 21 숫자에 변화가 없게 됨
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define PERIOD '.'

int main(void) {

	int temp = (1 + 2) * (3 + 4);

	printf("Before : %d\n", temp);

  // result 21 -> 22
	if ((++temp == 1024) && temp == 0)
		;  // do nothing

  // result : 21 -> 21
	//if (temp == 0 && (++temp == 1024))
	//	;  // do nothing
  
	printf("After : %d\n", temp);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define PERIOD '.'

int main(void) {

	// result : 2 2
	// 먼저 왼쪽에서 x가 0보다 크니 실행이 되고 x++를 통해 x는 2가 됨
	// 이에 따라 x+y는 4가 되어, 오른쪽 조건도 충족하게 됨
	int x = 1, y = 2;
	if (x++ > 0 && x + y == 4)
		printf("%d %d\n", x, y);

	return 0;
}

