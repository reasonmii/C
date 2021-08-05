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

