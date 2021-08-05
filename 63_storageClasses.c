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
Static with no linkage 블록 영역의 정적 변수
Scope : 블록 안
선언 방법 : 블록 안에서 static 키워드 사용
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

// ======================================================================

