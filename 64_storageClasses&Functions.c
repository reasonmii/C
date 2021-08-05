/*
Storage Classes and Functions
- Functions external (by default) or static
- A function declaration is assumed to be extern
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 원래 모든 함수 선언은 앞에
// extern이 있는데 생략하는 것
extern void func();
extern void func_second();

int main() {

	func();
	func_second();

	return 0;
}

void func() {
	extern int g_int;

	g_int += 1;
	printf("g_int in func_second() %d %p\n", g_int, &g_int);
}

// -------------------------------------------
// Solution Explorer 창에서 현재 프로젝트 우클릭
// C파일 생성 ex) second.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// referencing declaration
int g_int;

// 만약 이 tool이라는 함수는 여기 파일 내에서만 사용되고
// 외부파일에서는 사용할 일이 전혀 없다면
// ★ 앞에 static을 붙여서 외부에서 link하지 못하게 막을 수 있음
static void tool(void) {
	;
}

// static으로 파일 안에서만 사용할 수 있게 막으면
// main함수 파일 실행시 Linking이 되지 않아 ERROR 발생
// static void func_second(void) {
void func_second(void) {

	tool();

	g_int += 1;
	printf("g_int in func_second() %d %p\n", g_int, &g_int);
}



