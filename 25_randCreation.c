/*
rand()
- 0 to RAND_MAX (typically INT_MAX)
- defined in stdlib.h
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   // srand()
#include <time.h>     // time()

int main() {

	// random seed method1
	// srand(1);
	
	// random seed method2
	// 시간에 따라 seed값을 변경시키는 방법
	srand((unsigned int)time(0));

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
	}

	printf("\n");

	unsigned int next = 1;

	// 유사난수 생성
	// 보기에 난수같지만 사실 규칙이 있음
	// ※ 통계학적으로 정밀한 난수를 사용하고 싶은 경우에는 다른 방법 필요
	for (int i = 0; i < 10; ++i) {		

		// overflow 이용	
		next = next * 1103515245 + 1234;	

		// 음수가 나오지 않고 int type으로 자릿수 맞추기 위함
		next = (unsigned int)(next / 65536) % 32768;
		
		printf("%d\n", (int)next);
	}

	return 0;
}

// ======================================================================
// Random Number : 주사위 굴리기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   // srand()
#include <time.h>     // time()
#include "my_rand.h"

int main() {

	my_srand((unsigned int)time(0));

	for (int i = 0; i < 10; ++i)

		// % 6 : 6으로 나눴을 때 나머지 -> 0~5 범위
		// +1  : 1~6 범위
		printf("%d\n", my_rand() % 6 + 1);
	return 0;
}

// -------------------------------------------
// Solution Explorer 창에서 현재 프로젝트 우클릭
// Header 파일 생성 ex) my_rand.h

#pragma once

int my_rand();
void my_srand(unsigned int seed);

// -------------------------------------------
// Solution Explorer 창에서 현재 프로젝트 우클릭
// 파일 생성 ex) my_rand.c

#include "my_rand.h"
#include <stdio.h>

// static : 외부에서 next 변수에 접근하지 못하게 막기
static unsigned int next = 1;

int my_rand() {

	next = next * 1103515245 + 1234;
	next = (unsigned int)(next / 66536) % 32768;

	return (int)next;
}

void my_srand(unsigned int seed) {
	next = seed;
}
