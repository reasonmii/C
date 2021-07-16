// 포인터 변수은 실제 값과 자료형이 같아야 함
// 자료형이 다르면 원래는 오류 발생
// ex) int i -> int* p
//     char c -> char* pc

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
