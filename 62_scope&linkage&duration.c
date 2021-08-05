/*
변수의 영역과 연결 상태, 객체의 지속 기간
Scope, Linkage, Duration

Variable scopes (visibility)
- block, function, function prototype, file(global)
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g_i = 123;    // global variable
int g_j;          // global variable

void func1() {
	g_i++;
}

void func2() {
	g_i += 2;
}

// function prototype scope
void f1(int hello, double world);

double func_block(double d) {
	
	// block scope
	double p = 0.0;

	int i;
	for (i = 0; i < 10; i++) {
		double q = d * i;
		p *= q;

		// ★ goto문은 예외적으로
		// block 안에 있어도 jump 가능
		if (i == 5)
			goto hello;
	}

hello:
	printf("Hello, World!");

	return p;
}

int main() {

	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);     // 126

	// ★ 'g_j'를 초기화하지 않았는데 ERROR가 발생하지 않는 이유
	// 전역변수(정적변수)는 프로그래머가 초기화 값을 넣지 않아도
	// 파일이 시작되면서 자동으로 '0'으로 초기화 됨
	printf("%d\n", g_j);    // 0

	printf("%d\n", local);  // 1234

	return 0;
}

void f1(int hello, double world) {
	;
}

// ======================================================================

/*
Linkage
1) File scope variables
   External or internal linkage
   File scope는 파일 내 전체에서 다 쓰일 수 있기 때문에 전역 변수라고도 함
2) Variables with block scope, funcion scope, or function prototype scope
   - No linkage

File scope
같은 프로젝트 내에 파일 두 개 생성
두 파일의 실행 결과가 같음
이때 각 파일을 'translation unit'이라고 함

결과
Do Something called
1024
1025

★ static : 해당 변수의 범위를 이 파일 내로 제한한다
-> 같은 프로젝트 내 다른 파일에서 사용 불가
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// file scope : 현재 파일 내 모든 영역에서 사용 가능
int e1;           // file scope with external linkage (global variable)
static int i1;    // file scope with internal linkage

void testLinkage();

int main() {

	e1 = 1024;

	testLinkage();
	printf("%d\n", e1);

	return 0;
}

// -------------------------------------------
// 같은 프로젝트 내에 'second.c' 파일 생성

#include <stdio.h>

// extern : 다른 곳에 선언된 변수를 가져다 써라
extern int e1;
// extern int il; -> 

void testLinkage() {

	printf("Do Something called\n");
	printf("%d\n", e1);

	e1++;
}

// ======================================================================

/*
Storage duration : 메모리의 지속 기간
네 가지 종류

1) static storage duration
   프로그램 시작부터 끝날 때까지 메모리를 고정적으로 잡고 있는 것
   ※ Note : 'static' keyword indicates the linkage type, not the storage duration

2) automatic storage duration
   보통 지역변수를 의미
   stack에 메모리 저장

3) allocated storage duration
   동적할당과 관련 있음

4) thread storage duration
   multi threading 개념
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count() {
	// 이때, ct는 지역변수이기 때문에
	// 다시 부를 때마다 0으로 초기화되어, 계산함
	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

void static_count() {

	// static이 있어서 프로그램 시작부터 끝까지 메모리를 잡고 있는 변수
	// ★ 즉, block단위 지역변수가 아님
	// -> 다시 부르면 이전 값을 반영해서 반환
	static int ct = 0;
	printf("static count = %d\n", ct);
	ct++;
}

int main() {

	count();         // count = 0
	count();         // count = 0

	static_count();  // static count = 0
	static_count();  // ★ static count = 1

	return 0;
}

