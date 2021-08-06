/*
scanf() vs gets()
scanf() reads one word
gets() reads one line and removes \n and add \0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

	// Creating Space
	// 입력할 공간 먼저 확보

	// char* name = "";  -> Runtime ERROR
	// 배열로 만들어야 함
	// 배열 자체가 포인터 역할 하기 때문에
	// scanf에서 &name이 아닌 name 작성
	/*char name[128];
	int result = scanf("%s", name);*/

	// -------------------------------------------

	// Warning without initialization
	// 초기화 안 하면 warning 발생하니 빈공간 초기화
	// ※ char words[5]; 인 경우
	//    더 큰 개수의 문자열 입력하면 Runtime Error 발생
	char words[STRLEN] = "";

	// gets receives a "pointer"
	// gets 입장에서는 point만 받으니
	// 어디서 시작하는지는 알지만 어디서 끝나는 지는 모름
	// No idea when string ends
	// gets(words);

	// 그 단점을 보완하기 위해, 최근에는 gets보다 gets_s 사용
	// 포인터와 사이즈를 모두 argument로 입력받음
	gets_s(words, sizeof(words));
	// int result = scanf("%s, words");

	printf("START\n");
	printf("%s\n", words); // need \n at the end
	puts(words);           // puts() adds \n at the end
	puts("END.");
	
	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char str[] = "Just do it, do it!";
	printf("%s\n", str);
	puts(str);             // 자동으로 \n 입력됨

	return 0;
}

// ======================================================================
// puts : \0을 만날 때까지 계속 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST "A string from #define."

int main() {

	char str[60] = "String array initialized";
	const char* ptr = "A pointer initialized";

	puts("String without \\n");   // String without \n
	puts("END");                  // END
	puts(TEST);                   // A string from #define.
	puts(TEST + 5);               // ing from #define.
	puts(&str[3]);                // ing array initialized
	puts(ptr + 3);                // ointer initialized

	// No \0 at the end
	char str2[] = { 'H', 'I', '!' };

	// puts 함수는 \0을 만날 때까지 계속 출력하기 때문에
	// 메모리에 우연히라도 존재하는 \0를 만날 때까지 이상한 문자들 출력
	// HI!儆儆儆儆?{?
	puts(str2);

	return 0;
}


