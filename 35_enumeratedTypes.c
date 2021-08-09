/*
Enumerated type 열거형
- Symbolic names to represent integer constants
  정수형 상수가 이름이 있는 것처럼 사용
- Improve readability and make it easy to maintain
- enum-specifier (struct-specifier, union-specifier)

Enumerators
- The symbolic constants

Motivation
보통은 이름 대신 index 많이 사용
ex) red = 0, orange = 1, yellow = 2, blue = 3, ...
    그런데 이렇게 하면 가독성도 떨어지고,
    유지보수할 때 헷갈릴 수 있음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	enum spectrum {red, orange, yellow, green, blue, violet};
	//              0      1      2       3      4      5

	enum spectrum color;
	color = blue;

	// result : 현재 color는 blue이기 때문에 if 조건에 안 걸림
	// yellow 위에 마우스만 대도 2라고 알려줌
	if (color == yellow)
		// ★ Note: enumerators are not strings
		// -> 문자열이 아니기 때문에 printf(yellow)
		//    이렇게 하면 출력 못함
		printf("yellow");

	// 사실 정수형이기 때문에 연산, 비교가 가능
	// ※ C++에서는 열거형에 대해서 ++ 증가연산자 사용 불가
	for (color = red; color <= violet; color++)
		// 0 1 2 3 4 5
		printf("%d\n", color);

	// red = 0, orange = 1
	printf("red = %d, orange = %d\n", red, orange);

	// -------------------------------------------

	enum kids { jackjack, dash, snoopy, nano, pitz };
	// nano has a value of 3
	enum kids my_kid = nano;
	printf("nano %d %d\n", my_kid, nano);  // 3 3

	// -------------------------------------------

	enum levels { low = 100, medium = 500, high = 2000 };

	// result : Good job
	int score = 800;  // user input
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job\n");
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");

	// -------------------------------------------

	// 정수 지정을 꼭 0, 1, 2, 3.. 이렇게 안 해도 됨
	// 중간에 = 10 이렇게 지정 가능
	// 대신 이때 다음 숫자는 이전 숫자에 +1한 숫자
	// -> ★ lion은 11이 됨
	enum pet {cat, dog = 10, lion, tiger};

	printf("cat %d\n", cat);     // 0
	printf("lion %d\n", lion);   // 11

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   // strcmp (HINT!)
#include <stdbool.h>  // C99

enum spectrum {red, orange, yellow, green, blue};
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN 30

int main() {

	char choice[LEN] = { 0, };
	enum spectrum color;
	bool color_is_found = false;

	while (1) {

		puts("Input a color name (empty line to quit):");

		if (scanf("%[^\n]%*c", choice) != 1)
			break;

		for (color = red; color <= blue; color++) {
			if (strcmp(choice, colors[color]) == 0) {
				color_is_found = true;
				break;
			}
		}

		if (color_is_found)
			switch (color)
			{
			case red:
				puts("Red roses");
				break;
			case orange:
				puts("Orange are delicious");
				break;
			case yellow:
				puts("Yellow sunflowers");
				break;
			case green:
				puts("Green apples");
				break;
			case blue:
				puts("Blue ocean");
				break;
			}
		else
			printf("Please try different color %s.\n", choice);
		color_is_found = false;
	}

	puts("Goodbye!");

	return 0;
}
