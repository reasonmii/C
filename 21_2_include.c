/*
Header File 목적
코드가 너무 길어지니,
공통이 되고 반복해서 사용하는 부분을 다른 파일에 묶는 것

#pragma once
-> Header guard
아래 두 가지 경우가 발생했을 때 에러가 발생하지 않도록 막아줌
1) 하나의 Header File을 여러 곳에서 include 하다 보면
   이미 include 한 곳에 또 include하게 될 수도 있음
2) Header File이 자기 자신을 include 하는 경우
   -> Header guard가 없으면 ERROR 발생
      too many include files
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS

// 공식 header file은 <> 사용
#include <stdio.h>

// 직접 만든 header file은 "" 사용
#include "my_functions.h"
#include "my_structures.h"

/*
파일명 우클릭 - Open Containing Folder
폴더생성 : my_headers
★ 안에 파일 생성 : my_macros.h
※ windows에서는 \ 사용

이렇게 절대 경로로 써도 되지만 보통 이렇게 코딩 안 함
#include "C:\Users\User\Desktop\C_inflearn\myFirstSolution\myFirstPrj\my_headers\my_macros.h"

보통은 이렇게 상대 경로 지정
#include "my_headers\my_macros.h"  // path

Solution Explorer - 프로젝트 우클릭 - Properties
Configuration Properties - C/C++ - General
Additional Include Directories
입력방법
1) .
2) ./my_headers
3) my_headers

Compiler는 Additional Include Directories에 입력된
폴더들도 한 번씩 경유하며 찾아 봄
-> 3) 방식으로 입력한 경우
*/
#include "my_macros.h"  // -> 잘 가져옴
// #include <my_macros.h>
// -> 이렇게 써도 됨
//    그러나 표준 library에 대해서만 <> 쓰는 것이 일반적

extern int status;

int main() {

	/*
	#include는 복사 붙여넣기와 비슷함
	hello_world.h 파일 내에 있는
	아래 코드를 그대로 붙여 넣는 것과 똑같은 효과

	printf("Hello, world from a header file.");

	그러나 이렇게 함수 안에 include 넣는 방식은
	절대로 사용하지 말 것
	그냥 이런 방법도 된다는 것을 보여주기 위함
	*/
#include "hello_world.h"       // Hello, world from a header file.

	printf("PI = %f\n", PI);   // PI = 3.141592
	
	printf("%p %d\n", &status, status); // 00F3A144 0

	print_status();                     // Address = 00F3A144, Value = 0

	printf("%d\n", multiply(51, 2));    // 102

	printf("main()\n");
	printf("Static function address %p\n", multiply);  // 00E71960
	printf("Static variable address %p\n", &si);       // 00E7A140

	// Static function address 00E71A90
	// Static variable address 00E7A148
	print_address();

	patient_info james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };
	
	return 0;
}

// ======================================================================
// Header File 생성1 : my_structures.h

#pragma once

typedef struct {
	char name[100];
	int age;
} patient_info;

// ======================================================================
// Header File 생성2 : hello_world.h

printf("Hello, world from a header file.\n");

// ======================================================================
// Header File 생성3 : my_macros.h
// 

#pragma once

#define MAX(X,Y)      ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y)      ((X) < (Y) ? (X) : (Y))
#define ABS(X,Y)      ((X) <  0 ? -(X) : (X))

#define GRAVITY   9.8
#define PI        3.141592

// ======================================================================
// Header File 생성4 : my_functions.h

#pragma once

/*
header guard 없이 파일이 자기 자신을 include 해도
ERROR가 발생하지 않도록 방지하는 방법
- 파일 맨 위에 #ifndef, #define 작성
- 파일 맨 아래 #endif 작성

// if '__MY_FUNCTIONS__' is not defined
#ifndef __MY_FUNCTIONS__
// define it
#define __MY_FUNCTIONS__
*/

extern int status;

static int si = 0;

// header파일에서는 선언만 하고
// funcion의 body는 c 파일에 몰아 넣음
extern int add(int a, int b);

// static으로 함수 선언하면 body도 넣을 수 있음
static int multiply(int a, int b) {
	return a * b;
}

// int subtract(int a, int b)
inline int subtract(int a, int b) {
	return a - b;
}

void print_status();
void print_address();

//#endif

// ======================================================================
// C File 생성 : my_functions.c
// 'my_functions.h'에 대응하는 파일

#include "my_functions.h"

#include <stdio.h>

int status = 0;

int add(int a, int b) {
	return a + b;
}

void print_status() {
	printf("Address = %p, Value = %d\n", &status, status);
}

void print_address() {
	printf("print_address()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);
}

