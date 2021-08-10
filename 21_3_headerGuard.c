/*
★ 같은 Header File을 중복으로 include 하여
   ERROR가 발생하는 것 방지하는 Header Guard
   #endif, #define, #endif
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이미 Header_B.h에서 Header_A.h를 include했으니
// 둘 다 include한 것처럼 작동함
#include "Header_B.h"

/*
그런데 "Header_A.h"를 또 include 하는 경우 : 중복 include
-> ★ ERROR 발생 : already has a body

Header_A.h에서 header guard 입력해 주면
ERROR 발생하지 않음
- #endif, #define, #endif
*/
#include "Header_A.h"

int main() {

	test_function_A();
	test_function_B();

	return 0;
}

// ======================================================================
// Header_A.h

//#pragma once

// HEADER_A가 정의가 되어 있지 않다면, 정의한다는 IF 조건
#ifndef HEADER_A
#define HEADER_A

#include <stdio.h>

static void test_function_A() {
	printf("Hello, Header_A\n");
}

#endif

// ======================================================================
// Header_B.h

//#pragma once

#ifndef HEADER_B
#define HEADER_B

#include <stdio.h>
#include "Header_A.h"

static void test_function_B() {
	test_function_A();
	printf("Hello, Header_B\n");
}

#endif
