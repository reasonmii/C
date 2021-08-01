#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

get_long(void);

int main() {

	long number;

	while (1) {

		// between : 해당 숫자 포함하지 않음
		// between 1 and 100 -> 2 ~ 99
		printf("Please input an integer between 1 and 100.\n");

		// 사용자로부터 안전하게
		// long type의 정수만 입력받을 수 있는 방법
		number = get_long();
		
		if (number > 1 && number < 100) {
			printf("OK. Thank you.\n");
			break;
		}
		else
			printf("Wrong input. Please try again.\n");
	}

	printf("Your input %d is between 1 and 100. Thank you.\n", number);
	return 0;
}

get_long(void) {

	printf("Please input an integer and press enter.\n");

	long input;
	char c;

	// 큰 정수도 받을 수 있게 long으로 받음
	// 입력이 한 개만 있으면 while문으로 들어가지 않음
	while (scanf("%ld", &input) != 1) {
		printf("Your input - ");

		// input left in buffer
		while ((c = getchar()) != '\n')
			putchar(c);

		printf(" - is not an integer. Please try again.\n");
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}
