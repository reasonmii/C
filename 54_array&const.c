/*
type qualifiers (한정자) : const, volatile, ...
필요한 곳엔 모두 const 사용해서 혹시 발생할 수 있는 실수 방지
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 값 변경 불가
	const double PI = 3.14159;
	// PI = 2.14159;

	// 배열 각각의 원소 변경 불가
	const int arr[5] = { 1, 2, 3, 4, 5 };
	// arr[1] = 123;

	const double arr2[5] = { 1.0, 2.0, 3.0, 4.0 };

	// 포인터에 배열 주소 대입
	// -> pd는 arr2의 첫 번째 원소의 주소
	double* pd = arr2;
	*pd = 3.0;          // 의미 : arr2[0] = 3.0; pd[0] = 3.0;

	// ※ pd는 포인터지만 배열처럼 사용 가능
	// arr2는 const
	// 즉, arr2의 원소는 아무것도 바뀌면 안 됨
	// 그런데 이 값을 pd라는 다른 포인터에 대입하고 값을 바꾸려고 시도
	// -> warning 발생 (작동은 함)
	// pd 생성 시 const로 생성하면 바꿀 수 없음
	// ★ const double* pd = arr2;
	// 그러나, 이렇게 해도 pd++ 같은 증감연산은 가능
	// 이것도 못 바꾸게 하려면, 포인터 변수의 값 자체를 못 바꾸게 해야 함
	// ★ const double* const pd = arr2;
	pd[2] = 1024.0;     // 의미 : arr2[2] = 1024.0;

	// 1024.000000 1024.000000
	printf("%f %f\n", pd[2], arr2[2]);

	// ★ pd를 const로 생성해도 아래처럼 증감연산은 가능
	// 포인터 변수의 주소값은 변경이 가능
	pd++;

	// 4.000000 1024.000000
	// 맨 처음 pd가 가리키는 것 : arr[0]
	// pd[2]가 의미하는 것 : arr[2]
	// pd가 1씩 증가한 후 pd[2]가 의미하는 것 : arr[3]
	printf("%f %f", pd[2], arr2[2]);

	return 0;
}
