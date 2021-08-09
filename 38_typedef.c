/*
typedef specifier
- Give symbolic names (or aliases) to types
  어떤 자료형이 있는데, 새로운 이름으로 부를 수 있게 별명을 붙여줌
- Does not create new types
  새로운 자료형을 만드는 것은 아님

장점)
- 반복적으로 사용할 때 짧고 쉬운 이름으로 사용 가능
- 별명을 사용하는 게 편리할 때
  ex) unsigned char 자체를 byte라는
      정보의 양을 측정하는 단위로 인식하고 싶을 때

★ 복잡한 선언문을 이해할 때,
typedef로 잘게 쪼개서 보면 더 이해하기 좋음
"One good way to synthesize declarations is in small steps with typedef"
- KNR ch 5.12
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>    // time()

int main() {

	// Note the scope of BYTE
	// typedef [이름을 바꾸고 싶은 자료형] [별명]
	typedef unsigned char BYTE;

	// BYTE 위에 마우스 대보면 unsigned char 이라고 나타남
	BYTE x, y[10] = { 0, }, * z = &x;

	{
		// You can use lowercases as well
		typedef unsigned char byte;

		/*
		Portable data types
		이식성이 높은 데이터 자료형
		
		'sizeof'는 x86에서는 unsigned int로,
		x64에서는 unsigned long long으로 인식됨

		그렇다고 x86일 때와 x64일 때 코딩을 다르게 하면,
		실행 측면에서는 어떤 설정에서 실행을 할 지 알 수 없어
		매우 비효율적이고 근본적 해결이 아님
		unsigned int s = sizeof(byte);         // x86
		unsigned long long s = sizeof(byte);   // x64

		★ 그래서 이 때는 size_t 라는 자료형이 있는 것처럼 만듦
		x86일 때 size_t에 마우스 대보면 unsigned int라고 나오고
		x64일 때 size_t에 마우스 대보면 unsigned long long이라고 나옴
		-> 환경에 따라 다른 자료형으로 작동
		*/
		size_t s = sizeof(byte);   
	}

	/*
	typedef definition has a scope
	여기 밖에서는 block 안에서 선언한 typedef 사용 불가
	byte b; -> ERROR
	*/
	
	/*
	Portable data types
	
	time()
	This function returns the time
	since 00:00:00 UTC, January 1, 1970 (Unix timestamp) in seconds

	-> compiler에 따라 32bit or 64bit 사용
	-> time_t 사용해서 현재 환경에 맞게 구현되도록 할 수 있음
	*/
	time_t t = time(NULL);

	printf("%lld\n", t);

	// -------------------------------------------
	// #define보다 typedef를 선호하는 이유

	typedef char* STRING;

	// STRING을 char처럼 사용
	STRING name = "John Wick", sign = "World";

	/*
	★ typedef interpretation is performed by the compiler,
	not the preprocessor
	-> More flexible than #define

	#define 사용 시 코딩
	------------------------
	#define STRING char *

	STRING name, sign;
	char * name, sign;   // Note the type of sign
	------------------------
	즉, #define은 preprocessor(전처리기)이기 때문에
	STRING 부분에 char * 이 그냥 대입이 됨
	-> ★ 의도와 달리 name만 string pointer가 되고
	   sign은 포인터가 아니게 됨
	*/

	// -------------------------------------------
	
	// typedef를 구조체와 같이 사용하면
	// typedef struct complex COMPLEX
	// -> 이 코드를 따로 한 번 더 작성하지 않아도 됨
	typedef struct complex {
		float real;
		float imag;
	} COMPLEX;

	typedef struct { double width; double height; } rect; // no tag
	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;
	printf("%f %f\n", r2.width, r2.height);    // 1.100000 2.200000
	
	return 0;
}

// ======================================================================
// Complicated Function Declarations

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char char3[3] = { 'A', 'B', 'C' };

// Function Returns Pointer to Char[3]
char(*complicated_function1())[3]
{
	// returns a pointer to char[3]
	return &char3;
}

// Function Returns Pointer to Char[3]
typedef char(*FRPTC3())[3];
typedef char(*(*PTFRPTC3)())[3];

// 원래 이렇게 굉장히 복잡하게 쓰는데
char(*(*fptr1)())[3] = complicated_function1;
// typedef를 쓰면 이렇게 간단하게 쓸 수 있음
FRPTC3* fptr2 = complicated_function1;
PTFRPTC3 fptr3 = complicated_function1;

// -------------------------------------------
// ★ Use typedef to make declarations simpler
// 위보다 더 간단하게 선언하는 방법
typedef char c3[3];

c3* complicated_functions2() {
	// returns a pointer to char[3]
	return &char3;
}

int main() {

	char(*ret_val)[3] = fptr1();
	printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);  // A B C

	c3* my_c3 = fptr2();
	printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);        // A B C
	
	return 0;
}

// ======================================================================
/*
Deciphering Complex Delcarations (KNK 18.4)
복잡한 선언을 해석하는 요령
- Always read declarations from the inside out
- When there's a choice, always favor [] and () over *(asterisk)
  언제나 *보다 [], ()의 우선순위가 높음

*   : indicates a pointer
()  : indicates a function
[]  : indicates an array
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int temp(int a) {
	return 0;
}

int (*g(int a))(int) {
	return temp;
}

int main() {

	// Identifier ap is an array of pointers
	// -> ap는 int pointer 10개짜리 배열
	int* ap[10];

	// 같은 의미를 풀어 써 보기
	// int pointer 10개짜리 배열
	typedef int* pint;
	pint ap2[10];

	// -------------------------------------------

	// () : function
	// ※ fp is a function that returns a pointer
	// fp는 float를 매개변수로 받는 함수이고,
	// 그 함수의 return 값을 float pointer로 받음
	float* fp(float);

	typedef float* pfloat;
	pfloat fp2(float);

	// -------------------------------------------

	// 함수에 대한 포인터이고
	// 정수형 하나를 매개변수로 받고
	// 반환값은 void
	void (*pf)(int);
	/*
	void (*pf)(int);
	       1           1. pointer to
		        2	   2. function with int argument
	 3				   3. returning void
	*/

	// x는 배열인데 포인터에 대한 배열
	// 매개변수는 없고 반환값은 int의 포인터
	int* (*x[10])(void);
	/*
	int*(*x[10])(void);
	        1		   1. array of
		 2			   2. pointers to
				   3   3. functions with no arguments
	 4				   4. returning pointer to int
	*/

	// -------------------------------------------
	
	/*
	A function can't return an array
	int f(int)[];    // Wrong
	★ But it can return a pointer to an array
	*/
	int(*f(int))[];

	/*
	A function can't return a function
	int g(int)(int); // Wrong
	★ But it can return a pointer to a function
	*/
	int (*g(int))(int);

	/*
	An array of functions aren't possible
	함수의 배열은 불가능
	int a[10](int);  // Wrong
	★ But an array of function pointers are possible
	함수의 포인터의 배열은 가능
	- x2가 배열인데 포인터의 배열
	- 무엇에 대한 포인터? int를 받고 int pointer를 return 하는 함수
	*/
	int (*x2[10])(int);

	// Using typedef to simplify declarations
	// int (*x2[10])(int); 와 같은 의미
	typedef int FCN(int);
	typedef FCN* FCN_PTR;
	typedef FCN_PTR FCN_PTR_ARRAY[10];
	FCN_PTR_ARRAY x3;

	// -------------------------------------------
	// More examples
	
	int board[6][4];  // an array of arrays of int
	int** ptr;

	int* risks[10];   // A 10-element array of pointers to int
	int(*rusk)[10];   // A pointer to an array of 10 ints

	int* off[3][4];   // A 4x3 array of pointers to int
	int(*uff)[3][4];  // A pointer to a 3x4 array of ints
	int(*uof[3])[4];  // A 3-element array of pointers to 4-element arrays of int

	char* fump(int);       // function returning pointer to char
	char (*frump)(int);    // pointer to a function that returns type char
	char (*flump[3])(int); // array of 3 pointers to functions that return type char

	typedef int arr5[5];
	typedef arr5* p_arr5;
	typedef p_arr5 arrp10[10];

	arr5 togs;
	p_arr5 p2;
	arrp10 arp;

	return 0;
}
