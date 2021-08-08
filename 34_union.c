/*
Union
1) Store different data types in the same memory space
  여러 type을 한 곳에 저장
  각 member가 메모리를 함께 사용함
2) Structure과 차이점
   구조체에서는 각 member가 메모리를 각각 차지함
   이때 padding이 들어갈 수도 있음
  */

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

  // 공용체 선언
	union my_union {
		int    i;
		double d;
		char   c;
	};

	union my_union uni;

	// 공용체 내 member들은 메모리를 공유하기 때문에,
	// ★ 가장 큰 자료형의 크기에 맞춰서 전체 공용체 메모리 size 결정
	// int, double, char 중 가장 큰 자료형은 double
	// -> 이에 맞춰서 전체 공용체 size는 8 byte가 됨
	printf("%zd\n", sizeof(union my_union));  // 8
	printf("%lld\n", (long long)&uni);        // 9960616

	// 9960616 9960616 9960616
  // -> 공용체에서는 메모리를 공유하기 때문에
  //    ★ 첫 번째, 두 번째, 세 번째 등 모든 member의 주소가 동일함
	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);

	union my_union save[10];

	printf("%zd\n", sizeof(save));            // 80

	return 0;
}

// ======================================================================

#include <stdio.h>

// 구조체 선언
struct exStruct {
	char c;
	int i;
	int j;
	int k;
};

// 공용체 선언
union example {
	char c;
	int i;
	int j;
	int k;
};

int main(void) {	

	struct exStruct est;          // 구조체
	union  example e = { 'a' };  // 공용체

	// 구조체 크기 : 16
	// -> padding으로 한 개당 4byte 처리
	printf("%d\n", sizeof(est));

	// 공용체 크기 : 4
	// 한 개의 사이즈만 잡음
	printf("%d\n", sizeof(e));

	// 공용체 출력
	// a  97  97  97
	printf("%c  %d  %d  %d\n", e.c, e.i, e.j, e.k);

	e.i = 500;
	// ? 500  500  500
	printf("%c  %d  %d  %d\n", e.c, e.i, e.j, e.k);

	return 0;
}

// ======================================================================




