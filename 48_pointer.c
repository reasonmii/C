/*
포인터 변수은 실제 값과 자료형이 같아야 함
자료형이 다르면 원래는 오류 발생
ex) int i -> int* p
    char c -> char* pc

Pointer 코딩 스타일 변경하기
상단 Tools - Options - Text Editor
- C/C++ - Formatting - General
1) Visual Studio 선택 : int* a
2) LLVM : int *a
3) Google : int *a / int* a -> 둘 다 가능 (int * b : 이것만 안 됨)

★ 쓰레기값
int *ptr;
Pointer에 아무것도 넣지 않고 선언했을 때,
Pointer에 들어있는 default value를 '쓰레기값'이라고 함
컴퓨터가 쓰레기값 주소를 출력하려고 하면,
이 주소는 존재하는 지도 사실 불확실 하고 어디 있는 지도 모름
결국 찾지 못해 ERROR 발생 - Compile도 해 주지 않음

★ Runtime Error
int *ptr = 1234;
User가 Pointer에 직접 값 대입하는 경우, Runtime Error 발생
why? 컴퓨터가 정말 이 주소 '1234'로 가서 값을 가져오려고 했는데,
     이 프로그램에서 사실 할당받은 주소가 아님
     강제 종료됨

★ NULL pointer 선언
int *ptr = NULL;
포인터에 확실한 주소 값을 대입하면 문제 없음
그러나 보통 포인터를 사용할 때는 불확실한 변수를 많이 이용함
ex) 특정 조건에 만족하면 포인터에 값 넣기
이러한 경우 조건에 만족하지 않으면 포인터에는 최종적으로 값이 아무것도 안 넣어짐 -> ERROR 발생
★ 따라서 포인터를 처음부터 NULL 값으로 선언하면, 이후에 설령 값이 대입되지 않더라도 에러 발생X

※ Debug에서 전체 메모리 상황 확인하기
상단 Debug - Windows - Memory - Memory1
변수 주소 복사 후 Address에서 검색
*/

// ======================================================================

#include <stdio.h>

int main(void) {
	int i = 0;

	// 포인터 변수는 보통 NULL로 초기화
	int* p = NULL;
	

	p = &i;
	printf("%d\n", i);
	printf("%d\n", *p);  // 간접 참조 연산자

	i = 10;
	printf("%d\n", i);  // 10
	printf("%d\n", *p); // 10

	*p = 20;
	printf("%d\n", i);  // 20
	printf("%d\n", *p); // 20

	printf("&a = %d\n", &i);  // 6225276
	printf("p = %d\n", p);    // 6225276

	// -------------------------------------------

	int in;
	char c;
	float f;

	int* pi = &in;
	char* pc = &c;
	float* pf = &f;

	// 포인터 사이즈 : 4
	printf("sizeof(pi) = %d\n", sizeof(pi));
	printf("sizeof(pc) = %d\n", sizeof(pc));
	printf("sizeof(pf) = %d\n", sizeof(pf));

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int a, b;

	a = 123;

	int *a_ptr;
	a_ptr = &a;

	// 123 123 012FFD64
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	// -------------------------------------------

	*a_ptr = 456;

	// 456 456 012FFD64
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	// -------------------------------------------

	// 거의 사용하지 않는 방법
	// *a_ptr이 아니기 때문에, warning 발생
	b = a_ptr;
	printf("%d\n", b);   // 19922276

	b = *a_ptr;
	printf("%d\n", b);   // 456

	// -------------------------------------------

	*a_ptr = 789;

	// b는 영향 받지 않음
	printf("%d\n", b);   // 456

	// 789 789 012FFD64 012FFD58
	// a_ptr 주소는 여전히 같음
	// a의 주소와 b의 주소는 다름
	printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);

	// -------------------------------------------

	b = 12;
	printf("%d\n", b);   // 12

	// b의 변화가 a의 값에 영향을 주지는 않음
	// 789 789 012FFD64
	printf("%d %d %p\n", a, *a_ptr, a_ptr);

	// -------------------------------------------

	a = 1004;
	// 1004 1004 012FFD64 12
	printf("%d %d %p %d\n", a, *a_ptr, a_ptr, b);

	return 0;
}

// ======================================================================

#include <stdio.h>

void main() {
	int i = 10, j = 20;
	int* ptr;
	
	// i의 값 = 10      i의 메모리 주소 (&i) = 11532336
	printf("i의 값 = %d \t i의 메모리 주소 (&i) = %u\n", i, &i);
	// j의 값 = 20      j의 메모리 주소 (&j) = 11532324
	printf("j의 값 = %d \t j의 메모리 주소 (&j) = %u\n", j, &j);

	ptr = &i;
	// ptr의 메모리 주소(&ptr) = 11532312
	printf("ptr의 메모리 주소(&ptr) = %u\n", &ptr);
	// ptr의 값 (ptr) = 11532336
	printf("ptr의 값 (ptr) = %u\n", ptr);
	// ptr의 참조 값 (*ptr) = 10
	printf("ptr의 참조 값 (*ptr) = %d\n", *ptr);

	ptr = &j;
	// ptr의 메모리 주소(&ptr) = 11532312
	printf("ptr의 메모리 주소(&ptr) = %u\n", &ptr);
	// ptr의 값 (ptr) = 11532324
	printf("ptr의 값 (ptr) = %u\n", ptr);
	// ptr의 참조 값 (*ptr) = 20
	printf("ptr의 참조 값 (*ptr) = %d\n", *ptr);

	i = *ptr;
	printf("i의 값 = %d\n", i);   // i의 값 = 20
	getchar();

}

// ======================================================================
// 포인터 변수의 크기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	char a;
	float b;
	double c;

	char* ptr_a = &a;
	float* ptr_b = &b;
	double* ptr_c = &c;

	printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));                // 1 4 8
	printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));    // 4 4 4
	printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));             // 4 4 4
	printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*)); // 4 4 4

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ★ C언어에서 void 포인터는 산술연산 불가 -> ERROR!
	// int* ptr = 0;
	// char* ptr = 0;
	// double* ptr = 0;
	long long* ptr = 0;

	// 00000000 0
	printf("%p %lld\n", ptr, (long long)ptr);

	// 자료형의 사이즈만큼 더하게 됨
	// Try : -=, ++, --, -, +
	ptr++;

	// int       : 00000004 4
	// char      : 00000001 1
	// double    : 00000008 8
	// long long : 00000008 8
	printf("%p %lld\n", ptr, (long long)ptr);

	// -------------------------------------------

	// Subtraction
	int arr[10];
	int* ptr1 = &arr[3], * ptr2 = &arr[5];

	// 포인터 간 덧셈 불가능
	// 주소 두 개를 더해서 새로 나온 주소 값은 아무 의미가 없음
	// int ptr3 = ptr1 + ptr2 -> Error

	// ★ 뺄셈은 가능
	// 주소 두 개 값의 차이는 주소 간 거리를 의미
	int i = ptr2 - ptr1;

	// result : 7076972 7076980 2
	// int 자료형이 4byte이니 arr[3]과 arr[5]의 주소 차이값은 8
	// 8 / (자료형 크기) 4 = 2
	printf("%d %d %d\n", (int)ptr1, (int)ptr2, i);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {
	char* pc = (char*) 10000;
	int* pi = (int*) 10000;
	double* pd = (double*) 10000;

	printf("증가 전\n");
	// pc = 10000, pi = 10000, pd = 10000
	printf("pc = %d, pi = %d, pd = %d \n\n", pc, pi, pd);

	pc++;
	pi++;
	pd++;

	printf("증가 후\n");
	// pc = 10001, pi = 10004, pd = 10008
	printf("pc = %d, pi = %d, pd = %d \n\n", pc, pi, pd);

}

// ======================================================================

#include <stdio.h>

int main(void) {
	
	int i = 10;
	int* pi = &i;

	// i = 10, *pi = 10, pi = 7600360
	printf("i = %d, *pi = %d, pi = %d \n\n", i, *pi, pi);

	(*pi)++;
	// (*pi)++; : i = 11, *pi = 11, pi = 7600360
	printf("(*pi)++; : i = %d, *pi = %d, pi = %d\n", i, *pi, pi);

	*pi++;  // 주소 자체 변경
	// (*pi)++; : i = 11, *pi = -858993460, pi = 7600364
	printf("*pi++; : i = %d, *pi = %d, pi = %d\n", i, *pi, pi);

	return 0;
}

// ======================================================================

#include <stdio.h>
void swap1(int x, int y);
void swap2(int* px, int* py);

int main(void) {
	
	int a = 10, b = 50;

	// 바뀌지 않음
	printf("swap1 : a = %d, b = %d\n", a, b);  // 10, 50
	swap1(a, b);
	printf("swap1 : a = %d, b = %d\n", a, b);  // 10, 50

	// 포인터를 사용해야 바뀜
	printf("swap2 : a = %d, b = %d\n", a, b);  // 10, 50
	swap2(&a, &b);
	printf("swap2 : a = %d, b = %d\n", a, b);  // 50, 10

	return 0;
}

// SWAP 함수 만들기
void swap1(int x, int y) {
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

void swap2(int* px, int* py) {
	int tmp;

	tmp = *px;
	*px = *py;
	*py = tmp;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	int a[] = { 1, 2, 3, 4, 5 };
	// 주소는 %d 로 쓰면 warning 발생
	// %p로 써야 함
	printf("시작주소 : a = %p\n", a);  // 012FFDD4
	printf("a + 1 = %p\n", a + 1);     // 012FFDD8

	printf("*a = %d\n", *a);               // 1
	printf("*(a + 1) = %d\n", *(a + 1));   // 2

	return 0;
}

// ======================================================================

#include <stdio.h>
#define SIZE 5

int main(void) {

	int a[] = { 1, 2, 3, 4, 5 };
	int* p;

	// p는 포인터인데 배열처럼 사용 가능
	p = a;
	for (int i = 0; i < SIZE; i++) {
		// 같은 결과
		// a[0] ~ a[4] : 1~5
		// p[0] ~ p[4] : 1~5
		printf("a[%d] = %d \t", i, a[i]);
		printf("p[%d] = %d \n", i, p[i]);
	}

	for (int i = 0; i < SIZE; i++) {
		p[i] = 10 * i;
	}

	for (int i = 0; i < SIZE; i++) {
		// 같은 결과
		// a[0] ~ a[4] : 0~40
		// p[0] ~ p[4] : 0~40
		printf("a[%d] = %d \t", i, a[i]);
		printf("p[%d] = %d \n", i, p[i]);
	}

	return 0;
}

// ======================================================================
// 포인터를 이용해 문자열 처리하기

#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!", string2[20], * ptr1, * ptr2;
	ptr1 = string1;

	// string1의 주소 = 4126628         ptr1 = 4126628
	printf("string1의 주소 = %u \t ptr1 = %u\n", string1, ptr1);

	// string1 = Dreams come true!      ptr1 = Dreams come true!
	printf("string1 = %s \t ptr1 = %s\n", string1, ptr1);

	// come true!
	printf("ptr1 + 7 : %s\n", ptr1 + 7);

	// come true!
	ptr2 = &string1[7];
	printf("ptr2 : %s\n\n", ptr2);

	// 문자 거꾸로 출력
	// !eurt emoc smaerD
	for (i = 16; i >= 0; i--) putchar(*(ptr1 + i));

	for (i = 0; i < 20; i++) string2[i] = *(ptr1 + i);

	// string1 = Dreams come true!
	printf("\nstring1 = %s\n", string1);
	// string2 = Dreams come true!
	printf("string2 = %s\n", string2);

	// string1 = Peaces come true!
	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("string1 = %s\n", string1);
	getchar();
}

// ======================================================================

#include <stdio.h>

void main() {

	int i;
	char* ptrArray[4] = { {"Korea"}, {"Seoul"}, {"Mapo"}, {"152번지"} };

	// Korea Seoul Mapo 152번지
	for (i = 0; i < 4; i++)	printf("\n %s", ptrArray[i]);

	printf("\n\n");

	// 문자 바꾸기
	// Korea Seoul Jongno 152번지
	ptrArray[2] = "Jongno";
	for (i = 0; i < 4; i++)	printf("\n %s", ptrArray[i]);
	getchar();

}
