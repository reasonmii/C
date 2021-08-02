/*
배열의 포인터 연산 총정리
- Assignment
- Value finding (Dereferencing)
- Taking a pointer address
- Adding an integer to a pointer
- Incrementing a pointer
- Subtracting an integer from a pointer
- Decrementing a pointer
- Differencing
- Comparisons
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, * ptr2, * ptr3;

	// Assignment
	// 배열은 자체가 주소처럼 작동하기 때문에 바로 주소 대입 가능
	// 일반 변수는 'ptr1 = &i;' 와 같이 코드 작성해야 함
	ptr1 = arr;

	// Dereferencing
	// *ptr1 : 포인터 값이 나타내는 메모리 주소로 가서,
	//         그 메모리 주소에서 값을 가져오는 것
	// &ptr1 : 포인터 변수의 주소 가져오기
	// Taking a pointer address
	printf("%p %d %p\n", ptr1, *ptr1, &ptr1);   // 012FF948 100 012FF93C

	// Address-of operator &
	ptr2 = &arr[2];
	printf("%p %d %p\n", ptr2, *ptr2, &ptr2);   // 012FF950 300 012FF930

	// Adding an integer from a pointer
	ptr3 = ptr1 + 4;
	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);   // 012FF958 500 012FF924

	// Differencing
	// ★ t is for pointer difference
	printf("%td\n", ptr3 - ptr1);               // 4

	// Subtracing an integer from a pointer
	ptr3 = ptr3 - 4;
	printf("%p %d %p\n", ptr3, *ptr3, &ptr3);   // 012FF948 100 012FF924

	// Incrementing & Decrementing
	ptr1++;   // 대입 후 증가
	ptr1--;
	--ptr1;   // 증가 후 대입
	++ptr1;

	// Comparisons
	// result : Same
	if (ptr1 == ptr3)
		printf("Same\n");
	else
		printf("Different\n");

	// Comparisons : int pointer vs. double pointer
	// 이런 비교는 잘 안 하기 때문에 프로그래머의 실수인 경우가 많음
	// warning 발생 : incompatible types
	// result : Different
	double d = 3.14;
	double* ptr_d = &d;
	//if ((void*)ptr1 == (void*)ptr_d)  -> type 맞춰서 warning 발생X
	//if (ptr1 == (int*)ptr_d)          -> type 맞춰서 warning 발생X
	if (ptr1 == ptr_d)
		printf("Same\n");
	else
		printf("Different\n");

	return 0;
}
