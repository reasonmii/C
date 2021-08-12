/*
Debug mode는 개발과정에서 문제가 생길 수 있는 상황을
해결하기 위한 목적으로 만들어졌고,
Release mode는 개발이 끝났고 오류가 없으니
사용자들에게 배포를 하려는 목적에서 만들어짐
-> release mode는 assert문을 포함해서 실행하지 않음
 
Debug mode 실행
1) 상단 x86 왼쪽 'Release'를 'Debug'로 변경
2) 실행 : ctrl + F5 
3) 입력 : 5 0
4) 결과 : Assertion failed: b != 0,
         file C:\Users\User\Desktop\C_inflearn\myFirstSolution\myFirstPrj\myFirstPrj.c,
		 line 26

Release mode & Debugging 실행
1) 상단 x86 왼쪽 'Debug'를 'Release'로 변경
2) F5 Debugging 실행
3) 입력 : 5 0
4) 결과 : return a / b 부분에서 Error 발생했다는 것 표시

Release mode 실행 - ctrl + F5
-> runtime Error 발생
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

int divide(int a, int b);

int main() {

	int a, b;
	int f = scanf("%d%d", &a, &b);

	printf("a / b = %d", divide(a, b));
	return 0;
}

int divide(int a, int b) {

	/*
	assert
	반드시 만족해야 하는 조건
	이 조건을 만족하지 않는 경우,	debug 모드에서 문제 발생
	*/
	assert(b != 0);

	
	/*
	아주 효율이 높은 프로그램을 위해서는
	최소한의 기능만 담아야 하는데,
	assert가 아닌, 이런 식으로 조건을 달면
	효율도 떨어지고 overhead가 발생할 수 있음
	
	if (b == 0) {
		printf("Cannot divide\n");
		exit(1);
	}
	*/

	return a / b;
}

// ======================================================================
/*
_Static_assert
- Compile time에서 문제를 찾아내는 assert
- 상황이 조금씩 다를 수 있는 Multi-Platform
  환경에서 개발할 때 많이 사용

Visual Studio에서 지원하지 않음
Online Compiler 사용하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

/*
원래 CHAR_BIT은 8bit인데,
CHAR_BIT가 9bit가 아니면, 찾아내는 assert문 작성
-> 실행결과 : ERROR 발생
*/
#include <limits.h>
_Static_assert(CHAR_BIT == 9, "9-bit char falsely assumed");

int main() {
    return 0;
}
