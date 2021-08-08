/*
※ Padding이 없다면?
1) Padding은 Compiler가 자동으로 작업하는 것
2) Solution Explorer창 - 프로젝트 우클릭 - Properties
   - Configuration Properties - C/C++ - All Options
   - Struct Member Alighment : Default
   -> 1Byte로 변경 = Padding을 끄겠다는 의미
3) 프로그램 다시 실행해 보면
   순수 자료형들 크기 합으로 전체 Structure 크기 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	struct Aligned
	{
		// 4byte + 4byte + 8byte = 16byte
		int a;
		float b;
		double c;
	};

	struct Aligned a1, a2;

	// 메모리 사용량 및 포인터 확인
	printf("struct Aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct Aligned));  // 16
	printf("%lld\n", (long long)&a1);       // 17823596
	printf("%lld\n", (long long)&a1.a);     // 17823596
	printf("%lld\n", (long long)&a1.b);     // 17823600
	printf("%lld\n", (long long)&a1.c);     // 17823604

	printf("struct Aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2));     // 16
	printf("%lld\n", (long long)&a2);       // 17823572
	printf("%lld\n", (long long)&a2.a);     // 17823572
	printf("%lld\n", (long long)&a2.b);     // 17823576
	printf("%lld\n", (long long)&a2.c);     // 17823580

	struct Padded1
	{
		// 1byte + 4byte + 8byte = 13byte
		char a;
		float b;
		double c;
	};

	struct Padded1 p1;

	/*
	★ 실제 메모리 보면 13byte가 아닌 16byte
	compiler가 char에 대해 빈 공간 3byte를 더 넣어,
	총 4byte로 만들었기 때문 -> Padding

	★ Padding
	- struct member alignment
	  구조체 멤버들의 줄맞춤을 해 주는 것
	- 1 word : 4 bytes in x86, 8 bytes in x64
	  ※ 메모리와 CPU가 데이터를 주고 받을 때 1byte씩 주고 받지 않음
	    빠르게 처리하기 위해, 여러 개씩 묶어서 효율적으로 주고 받음
	    이때, 최소 얼마나 주고 받을지 결정하는 것을 word라고 함
		그 최소 단위가 x86에서는 4byte
		-> 내가 보낼 데이터가 word 크기만큼 꽉 차지 않았으면,
		   빈공간으로 채워서 같이 보냄
	*/
	printf("struct Padded p1\n");
	printf("Sizeof %zd\n", sizeof(p1));     // 16
	printf("%lld\n", (long long)&p1);       // 17823548
	printf("%lld\n", (long long)&p1.a);     // 17823548
	printf("%lld\n", (long long)&p1.b);     // 17823552
	printf("%lld\n", (long long)&p1.c);     // 17823556

	/*
	★ struct 내 자료형 순서에 따라서도 효율성이 달라짐
	★ CPU가 8 byte씩 데이터 처리하는데,
	1) char -> float -> double 순인 경우
	   char, float 한 번에 처리 후 double 처리하면 됨
	   = 8 byte + 8 byte = 16 byte
	2) char -> double -> float 순인 경우
	   char, double 하면 4 byte + 8 byte = 12 byte이기 때문에 한 번에 처리 불가능
	   즉, char 먼저 처리, double 처리, float 처리 순으로 3단계에 나눠 진행해야 함
	   = 8 byte + 8 byte + 8 byte = 24 byte
	   -> 엄청 비효율적
	*/

	struct Padded2
	{
		float a;
		double b;
		char c;
	};

	struct Padded2 p2;

	printf("struct Padded p2\n");
	printf("Sizeof %zd\n", sizeof(p2));     // 24
	printf("%lld\n", (long long)&p2);       // 17823516
	printf("%lld\n", (long long)&p2.a);     // 17823516
	printf("%lld\n", (long long)&p2.b);     // 17823524
	printf("%lld\n", (long long)&p2.c);     // 17823532

	struct Padded3
	{
		char a;
		double b;
		float c;
	};

	struct Padded3 p3;

	printf("struct Padded p3\n");
	printf("Sizeof %zd\n", sizeof(p3));     // 24
	printf("%lld\n", (long long)&p3);       // 7339592
	printf("%lld\n", (long long)&p3.a);     // 7339592
	printf("%lld\n", (long long)&p3.b);     // 7339600
	printf("%lld\n", (long long)&p3.c);     // 7339608

	// -------------------------------------------
	// ★ 배열일 경우에도 Padding 발생

	struct Person
	{
		char name[41];
		int age;
		float height;
	};

	struct Person a;

	// 5634356 - 5634312 = 44
	// name은 41 byte인데 차이가 44인 이유
	// -> 3 byte가 padding 들어감
	printf("struct Person\n");
	printf("Sizeof %zd\n", sizeof(a));        // 52
	printf("%lld\n", (long long)&a.name[0]);  // 5634312
	printf("%lld\n", (long long)&a.age);      // 5634356
	printf("%lld\n", (long long)&a.height);   // 5634360

	// -------------------------------------------
	// 구조체의 배열을 만들었을 때, 메모리 사용량

	// 52 byte * 4 = 208 byte
	struct Person f[4];
	printf("Sizeof a structure array %zd\n", sizeof(f));  // 208

	return 0;
}
