/*
글자를 입력하고 선택한 것에 따라,
입력된 글자 형태 바꾸기

선택지)
u -> 대문자
l -> 소문자
t -> 대문자는 소문자, 소문자는 대문자
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main() {

	char options[] = { 'u', 'l', 't' };
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	while (true) {
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");
		printf("t) to transpose\n");

		char c;
		while (scanf("%c%*[^\n]%*c", &c) != 1)
			printf("Please try again.\n");

		bool found = false;

		for (int i = 0; i < n; i++)
			// option에 있는 선택지를 고른 경우 break
			if (options[i] == c) {
				(*(operations[i]))(input);
				found = true;
				break;
			}

		if (found)
			break;
		else
			printf("Wrong input, try again\n");
	}

	printf("%s\n", input);

	return 0;
}

void update_string(char* str, int(*pf)(int)) {
	while (*str) {
		*str = (*pf)(*str);
		str++;
	}
}

void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str) {
	while (*str) {
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

