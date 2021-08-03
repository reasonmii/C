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
