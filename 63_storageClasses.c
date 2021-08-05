/*
5 Storage Classes
1) Automatic
2) Register
3) Static with internal linkage
4) Static with external linkage
5) Static with no linkage
*/

// ======================================================================

/*
Automatic storage class : 지역변수
- Automatic storage duration, block scope, no linkage
- Any variable declared in a block or function header
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int k);

int main() {

	// keyword auto : a storage-class specifier
	// 보통은 auto 없이 그냥 'int a'로 씀
	// 지역변수라가 default이기 때문
	auto int a;
	a = 1024;

	// what happens if uninitialized? -> ERROR
	printf("%d\n", a);   // 1024
	
	auto int b = a * 3;

	int i = 1;
	int j = 2;

	printf("i %lld\n", (long long)& i);     // i 14810540

	{
		// 더 큰 영역에서 선언된 i는 hiding 됨
		int i = 3;
		printf("i %lld\n", (long long)&i); // i 14810516

		// j is visible here
		// 현재 block 안에서는 j가 없으니,
		// 더 큰 영역에서 j 값 가져옴
		printf("j = %d\n", j);  // j = 2
	}

	// which i? 첫 번째 i
	// block을 빠져나가면 더이상 해당 값 가져올 수 없음
	printf("i %lld\n", (long long)&i);     // i 14810540

	for (int m = 1; m < 2; m++)
		printf("m %lld\n", (long long)&m); // m 7339472

	for (int m = 3; m < 4; m++) {
		printf("m %lld\n", (long long)&m); // m 7339460
	}

	// In the function,
	// we cannot see any of the variables defined so far
	func(5);     // i 7339228

	return 0;
}

void func(int k) {
	int i = k * 2;
	printf("i %lld\n", (long long)&i);
}

// ======================================================================
/*
Register : CPU가 가지고 있는 임시 작업 공간
최근에는 컴퓨터 사양이 매우 좋아서 굳이 register까지 사용하며 속도를 높이지 않음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r) {
	// do something with r
}

int main() {

	register int r;
	r = 123;

	// register 값은 주소를 가져올 수 없음
    // printf("%p\n", &r); -> ERROR
	// int* ptr = &r; -> ERROR

	return 0;
}

// ======================================================================
/*
Static with internal Linkage
정적 변수의 내부 연결
- File scope, external linkage, static storage uration
- Internal storage class

Scope : 파일 안
선언 방법 : 모든 함수들 밖에서 static 키워드 사용
연결 상태 : translation unit(번역 단위)의 내부에서만 사용
           = 같은 파일 안에서만 연결 가능
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Defining declaration
// int g_int = 123;
// ★ static 붙이면 다른 파일과 linkage 막아버림
static int g_int = 123;

void func();
void func_second();
void func_third();

int main() {

	func();        // 124 00E5A000
	func_second(); // 1 005CA584
	func_third();  // 2 005CA584 -> ★ second.c 파일 g_int를 외부변수로 사용

	return 0;
}

void func() {
	// optional
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

void func_second(void) {
	g_int += 1;
	printf("g_int in func_second() %d %p\n", g_int, &g_int);
}

// -------------------------------------------
// Solution Explorer 창에서 현재 프로젝트 우클릭
// C파일 생성 ex) third.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// referencing declaration
extern int g_int;

void func_third(void) {
	g_int += 1;
	printf("g_int in func_second() %d %p\n", g_int, &g_int);
}

// ======================================================================
/*
Static Variables with External Linkage
정적 변수의 외부 연결
- File scope, external linkage, static storage duration
- External storage class
- External variables

Scope : 파일 안
선언 방법 : 모든 함수들 밖
연결 상태 : translation unit(번역 단위)의 외부로도 연결 가능
           = 파일 밖으로도 연결 가능
*/

// defining declaration vs referencing declaration

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ※ g_int : global int
// 전역변수는 compiler가 자동으로 초기화 : 0
// 그러나, 가능하면 직접 0으로 초기화하는 것 권장
// int g_int;
int g_int = 0;
double g_arr[1000] = { 0.0, };

// Initializing External Variables
// 초기화하는 방법
int x = 5;               // ok, constant expression
inty = 1 + 2;            // ok, constant expression
size_t z = sizeof(int);  // ok, sizeof is a constant expression
// int x2 = 2 * x;       // ERROR, x is a variable

void func() {
	printf("g_int in func() %d %p\n", g_int, &g_int);
	g_int += 10;
}

// ★ 같은 프로젝트 내 다른 파일의 함수 선언
// -> linker가 자동으로 연결시켜 줌
void func_sec();

int main() {

	// Referencing declaration : Optional
	// extern : block scope 바깥에서 찾아서 link
	extern int g_int;
	// extern int g_int = 1024; -> ERROR

	// hides global g_int
	// int g_int = 123;

	// optional, size is not necessary
	// 사이즈는 이미 전역변수에서 결정했기 때문
	extern double g_arr[];

	// g_int in func() 0 001BA150
	printf("g_int in func() %d %p\n", g_int, &g_int);
	g_int += 1;

	// g_int in func() 1 001BA150
	func();

	// g_int in func() 1018 001BA150
	func_sec();

	return 0;
}

// -------------------------------------------
// Solution Explorer 창에서 현재 프로젝트 우클릭
// C파일 한 개 더 생성 ex) second.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// main함수 있는 파일의 전역변수 값 가져오기
// 방법1) 파일 내에서 전역변수로 제일 위에 한 번 선언
// 방법2) 각 함수 내에서 각각 선언

// extern int g_int;

// main함수 파일에서 초기화 안 했으면 ERROR X
// main함수 파일에서 초기화 했으면 ERROR
// 가능하면 main함수에서 초기화 하고,
// 이렇게 extern으로 가져올 때는 초기화하지 않는 방법이 깔끔함
// extern int g_int = 77;

void temp() {

	extern int g_int;

	// block scope에서는 어떤 방법으로도
	// 초기화 불가능
	// extern int g_int = 77; -> ERROR

	g_int += 1000;
}

void func_sec() {

	temp();

	extern int g_int;

	g_int += 7;
	printf("g_int in func() %d %p\n", g_int, &g_int);

}

// ======================================================================
/*
Static with no linkage 블록 영역의 정적 변수
Scope : 블록 안
선언 방법 : 블록 안에서 static 키워드 사용

※ 함수 parameter에 static 사용
ex) int func(static int i) {}
-> Warning (Error in GCC)
함수가 실행될 때는 새로운 stack이 배정이 됨
즉, 함수 parameter 변수는 함수가 실행될 때 메모리를 배정받음
그런데 변수 앞에 static을 붙인다는 건,
paramter 변수를 static한 공간에 억지로 넣어 메모리를 차지하고 있겠다는 의미
이렇게 static이 필요한 변수면 전역변수를 쓰거나 다른 방법을 해야 함

★ 매우 안 좋은 프로그래밍
지역변수의 포인터를 반환하는 함수인데 ct는 이 block이 끝나면 사라짐
> Warning 발생 : returning address of local variable or temporary
int* count() {
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}

아래처럼 static 변수인 경우 고정된 메모리 자리를 가지고 있기 때문에,
권장하지 않지만 어쩔 수 없는 경우에는 사용해도 됨
이런 경우에는 차라리 전역변수 쓸 것
int* static_count() {
	static int ct = 0;
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count() {
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;
}

void static_count() {
	// ★ initialized only once!
	static int ct = 0;
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;
}

void counter_caller() {
	count();
}

void static_counter_caller() {
	static_count();
}

int main() {

	count();           // count = 0 11532536
	count();           // count = 0 11532536
	counter_caller();  // count = 0 11532324 -> 메모리가 계속 새롭게 배정됨

	static_count();           // static count = 0 14459192
	static_count();           // ★ static count = 1 14459192
	static_counter_caller();  // ★ static count = 2 14459192 -> 주소 변화X

	return 0;
}

