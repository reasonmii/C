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

★ static : 해당 변수의 범위를 이 파일 내로 제한한다
-> 같은 프로젝트 내 다른 파일에서 사용 불가
*/

// ======================================================================
/* 결과
Do Something called
1024
1025
*/

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
Static Variables with External Linkage
정적 변수의 외부 연결

*/







// ======================================================================
/*
Internal Linkage
정적 변수의 내부 연결

*/






