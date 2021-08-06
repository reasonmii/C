/*
Type Qualifiers 자료형 한정자들
const, volatile, restrict, _Atomic

● const
★ header file에 변수 생성해서 가져다 쓸 수도 있음
※ C99 ideompotent
C99 부터 type 한정자를 여러 번 써도 문제 발생X
ex) const const const int n = 6;

● volatile
- 특정 변수를 volatile로 선언하면,
  이 변수의 값을 OS나 다른 파일에서
  (내가 모르는 상황에서) 바꿔버릴 수 있음
- Do not optimize
  따라서, 컴파일러가 직접 최적화하면 안됨
- 캐싱을 못하게 막아버림
- ex) hardware clock

● restrict (__rstrict in VS)
- sole initial means of accessing a data object
  data object에 접근하는 방법이 이거 하나 뿐이라는 의미
- compiler can't check this restriction
  compiler 입장에서는 사실 정말로 접근할 수 있는 방법이
  해당 변수밖에 없는지 체크할 수 없음
  따라서, 프로그래머가 스스로 restrict를 쓴 변수에는
  다른 포인터로 접근하지 않도록 코딩해야 함
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // memcpy
#include "constants.h" 

int main() {

	// const int n = 6;
	const const const int n = 6;

	// ex) const int를 zip이라는 type으로 정의
	typedef const int zip;
	// 아래 코드는 결국 'const const int zip' 이라는 의미
	// C99부터는 const 여러 번 써도 문제 없으니 ERROR 발생X
	// -> compile 잘 됨
	const zip q = 8;

	// -------------------------------------------

	/*
	const는 값을 바꿀 수 없기 때문에 반드시 초기화 해야 함

	ERROR
	const int i;        // not initialized
	i = 12;
	printf("%d\n", i);
	*/

	// -------------------------------------------

	const int j = 123;
	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	// 방법1)
	// 포인터 변수 pf1 자체는 변경 가능한 경우
	const float* pf1 = &f1;
	//*pf1 = 5.0f -> ERROR
	pf1 = &f2;

	// 방법2)
	// 포인터 변수의 indirection 값은 변경 가능한 경우
	float* const pf2 = &f1;
	*pf2 = 6.0f;
	// pf2 = &f2; -> ERROR

	// 방법3)
	// 어떤 것도 변경 불가능한 경우
	const float* const pf3 = &f1;
	// *pf3 = 7.0f -> ERROR
	// pf3 = &pf2  -> ERROR

	// -------------------------------------------

	// PI : header file에서 const 변수 가져와서 활용하기
	double area_circle = PI * 2.0f * 2.0f;

	// -------------------------------------------

	// volatile : 캐싱을 못하게 막아버림
	volatile int vi = 1;       // valatile location
	volatile int* pvi = &vi;   // points to a volatile location

	// 컴파일러는 이때 vi를 자동으로 임시 저장 공간에 저장해서
	// 나중에 다시 vi를 불러도 바로 가져올 수 있게 (캐싱)
	// 최적화할 수 있음
	int i1 = vi;

	// 이렇게 하면 compiler는 위와 아래 vi가 같다고 생각해서
	// 임시 저장된 공간에서 vi 값을 가져올 수 있음
	// 그러나, vi는 volatile 값이기 때문에
	// os나 다른 프로그램에 의해 값이 바뀌었을 수 있음
	// 그러면, 위에서 사용한 vi값과 이후 사용하는 vi 값은 다름
	// -> 즉, 컴파일러가 vi 값을 최적화하면
	// 임시공간에서 잘못된 vi값을 가져올 수 있음
	int i2 = vi;

	// -------------------------------------------

	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	// restrict
	// 다른 포인터나 다른 수단으로 해당 변수를 접근하지 않고
	// 선언한 변수 'restar'로만 접근하겠다는 의미
	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)exit(1);

	// par이 어차피 ar을 가리키고 있기 때문에
	// 3을 더하고 5를 더하는 건 한 번에 8을 더하는 것과 같음
	// 그러나 compiler 입장에는 두 개가 다른 이름이기 때문에
	// par[0] += 8; 로 최적화해서 계산하지 못함
	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;

	// 그러나 restrict를 사용하면
	// compiler가 restar에 접근할 수 있는 수단이
	// restar 자체밖에 없다는 것을 알기 때문에
	// restar[0] += 3; & restar[0] += 5; 가 결국
	// restar[0] += 8; 와 같다는 것을 알 수 있음
	// 따라서 효율적인 방법으로 최적화를 해서 계산함
	restar[0] += 3;
	restar[0] += 5;
	// restar[0] += 8;

	return 0;
}
 
// ======================================================================

/*
HEADER FILE 생성 : constants.h
*/

#pragma once

static const double gravity = 9.8;
static const double PI = 3.141592;
