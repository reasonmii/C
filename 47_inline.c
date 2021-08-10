/*
작은 함수가 여러 차례 반복적으로 사용될 때
실행 속도를 증가시킬 수 있는 방법

Function call has overhead
함수를 호출한 경우 함수 수행 외에 compiler가 추가적으로 하는 일
- set up the call, pass arguments, jump to the function code and return

이러한 overhead를 없애기 위해 할 수 있는 방법
1) macro 사용하기
   함수를 만드는 것이 아닌 그 위치에 코드를 그대로 복사, 붙여넣기함
   -> 함수 호출 overhead가 발생하지 않음
   but, macro 사용은 구조적 프로그래밍에서 방해가 됨
2) ★ 함수 앞에 'inline' keyword 붙이기

Inline function specifier
- suggests inline replacements
  ★ compiler에게 코드 중간에 이 함수의 내용을 바꿔치기 하라고 "제안"
  ★ 함수를 call하는 방식이 아닌 그냥 그대로 대입하는 방식
- Inline functions should be short
  복잡하고 큰 일을 수행하는 함수에 대해서는 inline 사용하지 않는 것이 일반적
- A function with internal linkage can be made inline (GCC, clang)
  일반적으로 internal linkage인 경우에 inline 함수를 사용할 수 있지만,
  Visual Studio는 그 외의 경우에도 허용함
- You can't take its address
  말 그대로 코드를 inline(복사, 붙여넣기)하기 때문에,
  다른 함수들과 달리 주소를 가져올 수 없음
*/

// ======================================================================

/*
Solution Explorer - 프로젝트 우클릭 - Properties
- Configuration Properties - C/C++
- All Options - 'inline' 검색 

1) inline 끄기 : 'Disabled' 선택
2) inline 켜기 : 'Only _inline' 선택
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ★ Visual Studio는 internal linkage가 아니어도
// inline 사용이 가능하기 때문에 static 붙이지 않아도 됨
// inline static int foo() {  -> GCC 방식
// static inline int foo() {  -> clang 방식
inline int foo() {
	return 5;
}

#define FOO 5

// Driver code
int main() {
	int ret;

	/*
	inline function이 꺼져 있는 경우
	작동방식 : ret = foo();
	-> 함수 foo() 호출해서 ret에 5 대입

	inline function이 켜져 있는 경우
	작동방식 : ret = 5;
	-> ★ 함수 call 없이 바로 값 대입
	*/
	ret = foo();

	/*
	macro도 아래 코드의 경우
	ret2 = 5; -> 이렇게 바로 대입되어서 작동
	즉, inline은 macro처럼 작동
	*/
  int ret2 = FOO;

	printf("Output is : %d\n", ret);  // 5

	return 0;
}

// ======================================================================
/*
★ 보통 inline은 Header File로 파일로 분리해서 작성
★ 이때, body가 다른 곳에 가 있으면 inline을 한 의미가 없기 때문에
   body도 header file에 같이 넣어야 함
*/

// MyHeader.h 파일 예시

#pragma once

#include <stdio.h>

inline static int hello() {
	return 123;
}
