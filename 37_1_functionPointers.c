#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>   // toupper(), tolower()

// 입력 : 문자열, 출력 : void
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

/*
ToUpper와 ToLower는 구성이 거의 비슷함
두 개를 합치면 가독성도 좋고
유지보수 할 때도 아주 편리해짐
-> 함수 포인터를 통해 합칠 수 있음

int(*pf)(int)
함수 포인터를 통해서
기능을 수행할 함수 자체를 매개변수로 받고 있음

※ Note : __cdecl is function calling convention!
*/
// void UpdateString(char* str, int(__cdecl *pf)(int)) {
void UpdateString(char* str, int(*pf)(int)) {
	while (*str) {
		*str = (*pf)(*str);  // 함수를 실행
		str++;
	}
}

int main() {

	char str[] = "Hello, World!";

	// 함수 포인터 선언
	// ★ 반환값 (*함수포인터명)(parameter);
	void (*pf)(char*);

	// ★ Name of a function is a pointer
	//    ToUpper = &ToUpper
	pf = ToUpper;
	// pf = &ToUpper;      // Acceptable

	// (str)을 쓰면 함수를 실행시켜서
	// 그 반환값을 pf에 대입하겠다는 의미
	// -> Not acceptable in C
	// pf = ToUpper(str);

	// 아래에서 첫 번째, 두 번째는 메모리 공간 중 text segment 부분에 저장됨
	// -> 두 개의 주소 값이 비슷함
	printf("String literal %lld\n", (long long)("Hello, World!"));  // 2063380
	printf("Function pointer %lld\n", (long long)ToUpper);          // 2036687
	printf("Variable %lld\n", (long long)str);                      // 17823732

	// 실행방법1)
	(*pf)(str);

	// 실행방법2)
	// 함수 이름 자체도 주소이기 때문에 이렇게 사용 가능
	// ※ KNR X, ANSI OK
	// pf(str);

	// result : HELLO, WORLD!
	printf("ToUpper %s\n", str);

	pf = ToLower;
	pf(str);
	// result : hello, world!
	printf("ToLower %s\n", str);

	// -------------------------------------------
	// ★ Passing function pointers to functions

	UpdateString(str, toupper);
	printf("ToUpper %s\n", str); // HELLO, WORLD!

	UpdateString(str, tolower);
	printf("ToLower %s\n", str); // hello, world!

	return 0;
}
