/*
Conditional Compilation
조건에 따라 다르게 컴파일하기
- #define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

// ======================================================================
/*
#undef
- 'undefine'의 줄임말
- define했던 것을 다시 무효화
- It's ok to undefine previously NOT defined macro
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LIMIT 400
#undef LIMIT

// 정의한 적 없어도 문제없음
#undef APPLE

int main() {

	printf("%d\n")
	
	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TYPE 1

// ★ 전처리기에서 IF문 사용
#if TYPE == 1
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function() {
	printf("Wrong compile option!");
}
#endif

int main() {

	my_function();

	return 0;
}

// -------------------------------------------
// my_function_1.h 파일

//#pragma once

#ifndef MY_FUNCTION_1
#define MY_FUNCTION_1

#include <stdio.h>

static void my_function() {
	printf("my_function_1.h\n");
}

#endif

// -------------------------------------------
// my_function_2.h 파일
//#pragma once

#ifndef MY_FUNCTION_2
#define MY_FUNCTION_2

#include <stdio.h>

static void my_function() {
	printf("my_function_2.h\n");
}

#endif

// ======================================================================
/*
1) #define REPORT를 주석 처리한 경우 결과 : 55
2) 주석 처리 하지 않은 경우 결과
   1  1
   3  2
   6  3
   10  4
   15  5
   21  6
   28  7
   36  8
   45  9
   55  10
   55

#define REPORT를 굳이 쓰지 않아도, 쓴 것처럼 나타나게 설정하기
Solution Explorer - 프로젝트 우클릭 - Properties
Configuration Properties - C/C++ - Preprocessor
★ Preprocessor Definitions 설정하기
방법1) 맨 앞에 'REPORT;'라고 입력
방법2) 오른쪽 화살표 클릭 - Edit
       - Enter 치고 맨 위에 'REPORT' 입력 - OK

★ 보통은 REPORT 자리에 '_DEBUG'로 많이 씀
이렇게 하면 자동으로 Debug mode 때는 실행이 되고
Release mode 때는 실행되지 않음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
보통 #define REPORT 25
이렇게 쓰는데 뒤에 아무것도 없는 경우
empty macro라고 함
*/
#define REPORT

int sum(int i, int j) {
	int s = 0;
	for (int k = i; k <= j; ++k) {
		s += k;

		// REPORT가 정의가 되어 있으면
		// 세부 항목 모두 출력
// ★ #ifdef _DEBUG -> Debug 모드 때만 실행
#ifdef REPORT
		printf("%d  %d\n", s, k);
#endif
	}
	return s;
}

int main() {

	printf("\n%d \n", sum(1, 10));

	return 0;
}

// ======================================================================
// Multi Platform에서 작동할 수 있는 코드 작성하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void say_hello() {
#ifdef _WIN64        // #if defined (_WIN64)
	// x64인 경우
	printf("Hello, WIN64");
#elif _WIN32
	// x86인 경우
	printf("Hello, WIN32");
#elif __linux__
	printf("Hello, Linux");
#endif
}

int main() {

	say_hello();

	return 0;
}
