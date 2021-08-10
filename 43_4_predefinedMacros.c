// Predefined Macros 미리 정의된 매크로들
// #line, #error

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "DifferentFile.h"

void different_function();

int main() {

	// 현재 매크로 사용된 파일의 이름 (문자열)
	// __FILE__: C:\Users\User\Desktop\C_inflearn\myFirstSolution\myFirstPrj\myFirstPrj.c
	printf("__FILE__ : %s\n", __FILE__);

	// 전처리(compile)가 된 순간의 날짜, 시간
	// __DATE__ : Aug 10 2021
	printf("__DATE__ : %s\n", __DATE__);
	// __TIME__ : 17 : 59 : 26
	printf("__TIME__ : %s\n", __TIME__);

	// 현재 VS에서 이 코드가 있는 줄
	// __LINE__ : 22
	printf("__LINE__ : %d\n", __LINE__);

	// 현재 이 코드를 포함하고 있는 함수 : main
	// __func__ : main
	printf("__func__ : %s\n", __func__);

	// This function is different_function
	// This is line 46
	different_function();

	// __FILE__ : C : \Users\User\Desktop\C_inflearn\myFirstSolution\myFirstPrj\DifferentFile.h
	// __func__ : different_func_in_different_file
	different_func_in_different_file();

	// -------------------------------------------
	/*
	// Not defined in VS
	// Visual Studio에서는 제공X
	// 온라인 Compiler에서 확인해보기

	// conforms to the C standard
	// C언어 표준을 만족하는지 확인
	printf("__STDC__%d\n", __STDC__);

	// hosted vs freestanding implementation KNK p.330
	// C언어 표준을 더 엄격하게 따르는지 여부 확인
	printf("__STDC_HOSTED__ %d\n", __STDC_HOSTED__);

	// 현재 사용 중인 C언어 표준의 버전 확인
	printf("__STDC-VERSION__ %ld\n", __STDC_VERSION__);
	*/
	// -------------------------------------------

	// 현재 VS에서 아래 코드의 line number는 59인데
	// 강제로 line number를 7로 변경
	// __LINE__after #line 7
#line 7
	printf("__LINE__after #line %d\n", __LINE__);

	// 현재 파일명은 myFirstPrj.c인데
	// 파일명을 "hello.txt"로 강제로 변경
	// __LINE__ after #line 1
	// __FILE__: hello.txt
#line 1 "hello.txt"
	printf("__LINE__ after #line %d\n", __LINE__);
	printf("__FILE__ : %s\n", __FILE__);

	// 현재 LINE이 70이 아니라면 ERROR 발생
//#if __LINE__ != 70
//#error Not line 70
//#endif

	// 현재 환경이 x64가 아니라면 ERROR 발생
//#if defined(_WIN64) != 1
//#error Not WIN64 platform
//#endif

	// C언어 버전이 201112L 버전이 아닌 경우 ERROR 발생
//#if __STDC_VERSION__ != 201112L
//#error Not C11
//#endif

	return 0;
}

void different_function() {
	printf("This function is %s\n", __func__);
	printf("This is line %d\n", __LINE__);
}

// ======================================================================
// Header File 생성 : DifferentFile.h

#pragma once

#include <stdio.h>

static void different_func_in_different_file() {
	printf("__FILE__ : %s\n", __FILE__);
	printf("__func__ : %s\n", __func__);
}
