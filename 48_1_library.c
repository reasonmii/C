/*
Library 함수 파일 특징
1) main 함수가 없음
   실행 하려면 반드시 main 함수 필요
2) library 종류 : Dynamic vs Static Library

※ main함수
운영체제가 프로그램을 실행할 때 가장 먼저 main 함수를 찾고
main 함수 안 코드를 차례로 실행

'Library' 파일이 있는 프로젝트 설정하기
Solution Explorer - 프로젝트 우클릭 - Properties
- Configuration Properties - General
- Configuration Type
★ 상단 Configuration이 'Debug' 모드일 때,
   'Release' 모드일 때 각각에 대해 모두 설정해야 함
1) Application (.exe)
   지금까지 우리가 사용한 프로젝트 상태
2) Dynamic Library
   프로그램 자체가 library를 가지고 있는 것이 아닌
   실행을 할 때마다 가져다 쓰는 방식
3) Static Library : 작성하는 프로그램에 library가 포함되어 있는 것

Static Library 선택
Solution Explorer - 'library' 프로젝트 우클릭 - Project Only - Build only 'library'
결과 - C:\Users\User\Desktop\C_inflearn\myFirstSolution\Release\library.lib
-> 해당 경로에 lib 파일이 생성됨

★ Release mode, Debug mode 잘 맞출 것
   파일 경로도 Release 폴더 or Debug 폴더로 달라짐
*/

// -------------------------------------------
// MyLibrary.h 파일 작성

#pragma once

// some useful functions...
void say_hello();
void say_world();

// -------------------------------------------
// MyLibrary.c 파일 작성
#include "MyLibrary.h"

#include <stdio.h>

void say_hello() {
	printf("Hello\n");
}

void say_world() {
	printf("World\n");
}

// ======================================================================
// 생성한 library를 다른 Project에서 사용하기
/*
파일 실행결과
Hello
World
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1) 절대경로로 가져오는 방법
상단 MyLibrary.h 파일명 우클릭 - Copy Full Path
#include "C:\Users\User\Desktop\C_inflearn\myFirstSolution\library\MyLibrary.h"

2) 더 간단한 방법
보통은 'C:\Users\User\Desktop\C_inflearn\myFirstSolution\library\' 경로 복사
Solution Explorer - 프로젝트 우클릭 - Properties
- Configuration Properties - C/C++ - General
- Additonal Include Directories : 경로 붙여넣기
*/
#include <MyLibrary.h>

int main() {

	say_hello();
	say_world();

	return 0;
}

/*
현재 프로젝트 파일과 library 프로젝트 파일을 Linking 하기

현재 프로젝트에서 환경설정
1) library.lib 파일이 있는 경로 설정
   Solution Explorer - 프로젝트 우클릭 - Properties
   - Configuration Properties - Linker - General
   - Additional Library Directories :
   'C:\Users\User\Desktop\C_inflearn\myFirstSolution\Release'
   -> 'library.lib' 파일이 있는 경로
2) library.lib 파일명 설정
   Solution Explorer - 프로젝트 우클릭 - Properties
   - Configuration Properties - Linker - Input
   - Additional Dependencies : 맨 앞 쪽에 파일명 다음과 같이 작성 'library.lib;'
*/
