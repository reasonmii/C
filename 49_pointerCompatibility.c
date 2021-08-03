// 포인터의 호환성

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n = 5;
	double x;

	// 정수를 실수에 대입할 때는 no error
	// double이 int보다 큼
	x = n;  

	// 그러나 정수 포인터를
	// 실수 포인터에 대입할 때는 warning
	int* p1 = &n;
	double* pd = &x;
	// pd = p1;           // warning

	 // 이렇게 하면 warning X
	// -> 그러나 권장하지 않음 (코드 실력을 의심하게 되는 코딩)
	pd = (double*)p1;

	int* pt;
	int(*pa)[3];       // 원소가 3개인 배열에 대한 포인터
	int ar1[2][3] = { 3, };
	int ar2[3][2] = { 7, };
	int** p2;          // a pointer to a pointer

	// 2차원 배열의 한 원소의 주소 담기
	pt = &ar1[0][0];   // pointer-to-int

	// 이 포인터로 배열 내 원소 6개 모두 출력 가능
	// 다만 포인터만 가지고는 원소가 사실 몇 개인지 알 수 없음
	// 지금은 우리가 알고 있으니 i < 6 조건 넣음
	// 3 0 0 0 0 0
	for (int i = 0; i < 6; ++i)
		printf("%d %d\n", pt[i], *(pt+i));

	// pt = ar1; -> Warning (Error)
	// ar1은 2차원 배열이기 때문에 그냥 포인터에 담을 수 없음
	pt = ar1[0];       // pointer-to-int

	// pa : 원소가 3개인 배열에 대한 포인터
	// ar1 : 원소가 3개인 배열 (행 2개)
	// -> 따라서 담기 가능
	pa = ar1;          // pointer-to-int[3]

	// pa = ar2; -> Warning or error
	// ar2 : 원소가 2개인 배열 (행 3개)
	// 따라서, pa에 담으려고 하면 warning 발생

	p2 = &pt;          // pointer-to-int
	*p2 = ar2[0];      // pointer-to-int
	
	// ★ p2 = ar2; -> Error
	// p2 : pointer to pointer to int
	//      int에 대한 포인터의 포인터
	// ar2 : a pointer to array-of-two-ints
	//       2개 int를 가진 배열의 포인터
	// 두 가지가 달라서 호환이 안 됨

	return 0;
}

// ======================================================================
// Pointer and const

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 20;
	const int y = 23;
	// y = 123; -> ERROR

	int* p1 = &x;
	const int* p2 = &y;
	const int** pp2 = &p1;

	// Warning
	p1 = p2;
	
	// *p2 = 123; -> ERROR
	// y의 값을 바꾸려는 것과 동일
	// const int* p2는 indirection 값을 못 바꾼다는 의미
	// 따라서 p2 자체의 값은 변경 가능
	// p2를 아예 못 바꾸게 하고 싶은 경우 코드
	// const int* const p2 = &y
	p2 = p1;

	int x2 = 30;
	int* p3 = &x2;
	*pp2 = p3;      // no error
	pp2 = &p1;      // no error

	{
		// 돌아돌아 const 변수를 바꾸는 방법
		// compiler가 허용을 해 주는데 매우 안 좋은 방식
		// 애초에 const를 사용하지 않아야 하는 변수면 그렇게 코딩해야 함

		const int** pp2;
		int* p1;
		const int n = 13;
		pp2 = &p1;

		// Sets p1 to point at n
		// *pp2 = p1값
		// 여기에 const n의 주소를 넣고자 함
		// 문제 없이 잘 실행 됨
		*pp2 = &n;

		// change n
		// const의 값을 바꾸는 형태인데 잘 실행 됨
		*p1 = 10;
	}

	return 0;
}
