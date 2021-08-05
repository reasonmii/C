/*
Object
- "An object is simply a block of memory that can store a value" (KNK p.487)
- Object has more developed meaning in C++ and Object Oriented Programming (OOP)
  ※ OOP : 객체지향형프로그래밍

Identifier
- Names for variables, functions, macros, and other entities (KNK p.25)

L-value
1) left side of an assignment
2) L-value is an expression 'referring' to an object (KNK p.197)

R-value : right side, variable, constant, expressions (KNK p.67)

Identifiers have scope
Objects have storage duration
Variables and functions have one of the following linkages:
  external linkage, internal linkage, or no linkage

*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// creates an object called 'var_name'
	// ※ memory 공간 : object
	//   var_name : identifier
	//              modifiable lvalue
	int var_name = 3;

	// -------------------------------------------

	// pt is an identifier
	// ★ *pt is not an identifier -> It's an expression (표현식)
	// *pt designates an object (실질적인 object를 지명하는 역할)
	// *pt is an modifiable lvalue expression
	int* pt = &var_name;
	*pt = 1;
	*pt = 7;

	// -------------------------------------------

	// arr is an identifier
	// Is arr an object? No, 첫 원소에 대한 주소임
	// ★ arr[0] is an object
	int arr[100];
	arr[0] = 7;

	// 포인터 변수에 arr의 주소값 저장 가능
	int* ptr = arr;
	
	// -------------------------------------------

	// arr + 2 * var_name : 연산을 통해 나온 address 값이기 때문에 rvalue
	int* ptr2 = arr + 2 * var_name;

	// 앞에 indirection operator *를 붙이면 lvalue expression처럼 사용 가능
	*(arr + 2 * var_name) = 456;

	// -------------------------------------------

	// str is a modifiable lvalue
	// ※ "Constant string" = "Second String" -> impossible
	const char* str = "Constant string";
	str = "Second string";
	puts(str);

	// ※ Debugg에서는 오류나지만 release에서는 강제 실행될 수도 있음
	// str[0] = 'A' -> ERROR
	// puts(str);

	// result : Atring is an array
	char str2[] = "String is an array";
	str2[0] = 'A';
	puts(str2);

	return 0;
}
