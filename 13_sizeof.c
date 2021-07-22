#include <stdio.h>

int main() {

	int x;
	double d;
	char ch;

	printf("변수 x의 크기  : %d\n", sizeof(x));   // 4
	printf("변수 d의 크기  : %d\n", sizeof(d));   // 8
	printf("변수 ch의 크기 : %d\n", sizeof(ch));  // 1

	printf("자료형 int의 크기         : %d\n", sizeof(int));         // 4
	printf("자료형 short의 크기       : %d\n", sizeof(short));       // 2
	printf("자료형 long의 크기        : %d\n", sizeof(long));        // 4
	printf("자료형 float의 크기       : %d\n", sizeof(float));       // 4
	printf("자료형 double의 크기      : %d\n", sizeof(double));      // 8
	printf("자료형 long double의 크기 : %d\n", sizeof(long double)); // 8
	printf("자료형 char의 크기        : %d\n", sizeof(char));        // 1

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	unsigned int i = 0;

	// 마우스를 위에 올리면 '4U' 글자 보임
	// -> 4byte 라는 의미
	sizeof(unsigned int);
	sizeof(i);

	printf("%u\n", sizeof(unsigned int));   // 4
	printf("%u\n", sizeof(i));              // 4

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct MyStruct {
	int i;
	float f;
};

int main() {

	// -------------------------------------------
	// sizeof basic types
	// sizeof is an operator (not a function)

	int a = 0;
	// 3 ways to use sizeof
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);

	// size_t : typedef - unsigned int
	// Why we use 'size_t' instead of 'unsinged int'?
	// because 'sizeof(a)' can be the value that is not 'unsigned int'
	// 값의 이식성을 더 높여줌
	size_t int_size4 = sizeof(a);
	size_t float_size = sizeof(float);

	// %zu : size_t의 형식 지정자
	printf("Size of int type is %u bytes. \n", int_size1);      // 4
	printf("Size of int type is %zu bytes. \n", int_size4);     // 4
	printf("Size of float type is %zu bytes. \n", float_size);  // 4

	// -------------------------------------------
	// sizeof arrays

	// 선언되는 순간 메모리 할당 : 4 * 30 = 120 byte
	int int_arr[30];

	// 선언 후 메모리 할당
	int* int_ptr = NULL;
	// malloc : memory allocation
	// sizeof(int) * 30 = 4 * 30 = 120 byte
	// -> 120 byte 메모리 공간을 할당하고, 그 메모리 공간을 대표하는 주소를 int_ptr에 대입
	// 즉, int_ptr은 주소를 적는 메모지
	int_ptr = (int*)malloc(sizeof(int) * 30);

	printf("Size of array = %zu bytes\n", sizeof(int_arr));   // 차지하는 공간 : 120
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr)); // 주소의 사이즈 : 4

	// -------------------------------------------
	// sizeof character array

	// 'a' 위에 마우스 대보면 'int 97'이라고 뜸
	// 글자는 이처럼 숫자로 바껴서 저장됨
	char c = 'a';

	// Save 10 characters
	// Language C needs '/0' (null character) always at the end for string
	// So 10 means : maximally 9 character + '/0' (null character)
	char string[10];

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("Size of char type = %zu bytes\n", char_size);  // 1
	printf("Size of string type = %zu bytes\n", str_size); // 10

	// -------------------------------------------
	// sizeof structure

	// result : 8
	// why? This structure has int and float
	// -> 4 + 4 = 8
	printf("Size of struct = %zu bytes\n", sizeof(struct MyStruct));

	return 0;
}
