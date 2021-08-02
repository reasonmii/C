/*
우측 Solution Explorer창
파일명 변경 : 보통 main 함수를 포함하는 파일명은 main.c 사용

1. Header File 생성
우측 Solution Explorer창
1) 프로젝트 우클릭 - Add - New Item
   Header File 선택 - Name : my_print_functions.h
2) 해당 파일이 열림 - 잘 만들어졌는지 확인
   파일명 우클릭 - Open Containing Folder - my_print_functions.h 파일 확인
3) 파일 맨 위에 '#pragma once'라고 써 있음 -> header guard

※ 보통 Header File은 책에서 '차례'처럼 사용됨
실제 내용에 대한 C파일 새로 생성
★ Header File과 같은 이름으로 만들기

2. Header File에 대한 C파일 생성
우측 Solution Explorer창
1) 프로젝트 우클릭 - Add - New Item
   C++ File 선택 - Name : my_print_functions.c
2) Header File 내용 넣기

3. Filter 생성 - 코드를 모아서 깔끔하게 정리 가능
우측 Solution Explorer창
1) 프로젝트 우클릭 - Add - New Filter
  Name : My_Files
2) Header File인 'my_print_functions.h'을 Filter 안 경로로 옮기기

※ 주의점 : Visual Studio에서 만드는 Filter는 실제 directory에 반영되지는 않음
파일명 우클릭 - Open Containing Folder : 'My_Files' 라는 폴더 없음
*/

// ======================================================================
// main.c 파일

#define _CRT_SECURE_NO_WARNINGS

// my_print_function.h에서 <stdio.h>를 include 하면
// 여기서는 제외 가능
// 보통 header file을 깔끔하게 하기 위해, 여기서 작성함
#include <stdio.h>

#include "my_print_functions.h"

int main() {
	
	print_hello();
	print_hi();
	print_hello();
	print_hi();
	print_str("No one lives forever.");
	print_str("Valar morghulis");

	return 0;
}

// ======================================================================
// my_print_functions.h 파일

#pragma once  // header guard

void print_hello();
void print_hi();
void print_str(char* str);

// ======================================================================
// my_print_functions. 파일

#include "my_print_functions.h"
#include <stdio.h>

void print_hello() {
	printf("Hello\n");
}

void print_hi() {
	printf("Hi\n");
}

void print_str(char* str) {
	printf("%s\n", str);
}
