/*
Union
1) Store different data types in the same memory space
  여러 type을 한 곳에 저장
  각 member가 메모리를 함께 사용함
2) Structure과 차이점
   구조체에서는 각 member가 메모리를 각각 차지함
   이때 padding이 들어갈 수도 있음
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

  // 공용체 선언
	union my_union {
		int    i;
		double d;
		char   c;
	};

	union my_union uni;

	// 공용체 내 member들은 메모리를 공유하기 때문에,
	// ★ 가장 큰 자료형의 크기에 맞춰서 전체 공용체 메모리 size 결정
	// int, double, char 중 가장 큰 자료형은 double
	// -> 이에 맞춰서 전체 공용체 size는 8 byte가 됨
	printf("%zd\n", sizeof(union my_union));  // 8
	printf("%lld\n", (long long)&uni);        // 9960616

	// 9960616 9960616 9960616
  // -> 공용체에서는 메모리를 공유하기 때문에
  //    ★ 첫 번째, 두 번째, 세 번째 등 모든 member의 주소가 동일함
	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);

	union my_union save[10];

	printf("%zd\n", sizeof(save));            // 80

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	union my_union {
		int    i;
		double d;
		char   c;
	};

	union my_union uni;

	// 공용체 내 member들은 메모리를 공유하기 때문에,
	// 가장 큰 자료형의 크기에 맞춰서 전체 공용체 메모리 size 결정
	// int, double, char 중 가장 큰 자료형은 double
	// -> 이에 맞춰서 전체 공용체 size는 8 byte가 됨
	printf("%zd\n", sizeof(union my_union));  // 8
	printf("%lld\n", (long long)&uni);        // 9960616

	// 9960616 9960616 9960616
	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);

	union my_union save[10];

	printf("%zd\n", sizeof(save));            // 80

	// -------------------------------------------
	/* Union of different types
	
	Debug 해서 확인하기
	1) Debugging 시작 : F5
	2) 하단 watch1 부분
	   &uni1 주소 복사
	   - Name : &uni1 + enter
	   - value 부분 우클릭 - Copy value
	2) 우측 Memory1 검색 : &uni1 주소 부분만 붙여넣기
	   0x0077fc00 부분이 모두 cc로 채워져 있음
	3) F10으로 Debugging Step Over
	   첫 번째 cc가 41로 바뀜
	   41 cc cc cc -> 거꾸로 읽으면 : CCCCCC41
	*/

	union my_union uni1;

	uni1.c = 'A';         // ★ Debug Break Point 찍기
	// result : A 41 -858993599
	// %x 16진수 : 0xCCCCCC41 -> 10진수 : -858993599
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);

	/*
	4) uni1.i = 0; 부분 지날 때
	   41을 포함한 앞 네 글자 cc가 모두 00으로 바뀜
	   00 00 00 00
	5) uni1.c = 'A'; 부분 지날 때
	   41 00 00 00 -> 거꾸로 읽으면 : 00000041
	*/

	uni1.i = 0;
	uni1.c = 'A';
	// result : A 41 65
	// 16진수 : 0x00000041 -> 10진수 : 65
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);

	/*
	6) uni1.d = 1.2; 부분 지날 때 8글자가 모두 바뀜
	   - double이니 8byte가 바뀜
	   33 33 33 33 33 33 f3 3f
	   -> 거꾸로 읽으면 3ff3333333333333
	   0x3ff3333333333333 = (decimal) 1.99999

	   int는 앞 4byte이기 때문에 33 33 33 33
	   -> 0x33333333 = (decimal) 858993459

	   char은 앞 1byte이기 때문에 33
	   -> 0x33 = (decimal) 51 -> ASCII code : (char) '3'
	*/

	uni1.d = 1.2;
	// result : 858993459 1.200000 51 3
	printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);

	// -------------------------------------------
	// Initialize unions
	// 공용체를 초기화 하는 방법

	// 1) Copy another union
	union my_union uni2 = uni1;

	/*
	2) First element (member) only
	공용체를 선언할 때는 원소가 세 가지가 있는 것처럼 했지만
	사실 서로 메모리를 공유하기 때문에
	★ 원소 하나만 초기화 하면 됨
	-> 그렇지 않으면 warning 발생
	*/
	union my_union uni3 = { 10 };

	// 3) Designated initializer
	union my_union uni4 = { .c = 'A' };

	/*
	4) Do NOT recommend
	출력해 보면 뒤에 member인 .i=100에 맞춰서 초기화됨

	절대 권장하지 않는 이유
	프로그래머의 의도가 1.23으로 하고 싶은 건지,
	100으로 하고 싶은 건지
	구조체를 만들고 싶었던 건 아니었는지
	혼란을 줄 수 있기 때문
	*/ 
	union my_union uni5 = { .d = 1.23, .i = 100 };
	// 100 0.000000 d
	printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);

	// 각 멤버에 값 대입 가능
	// 결과적으로는 k에 맞춰서 size 선정됨
	uni.i = 123;
	uni.d = 1.2;
	uni.c = 'k';

	// 858993515 1.200000 k
	printf("%d %f %c\n", uni.i, uni.d, uni.c);

	// Pointer to union
	union my_union* pu = &uni;
	
	// 포인터의 멤버 접근할 때 : '->' operator 사용
	// ※ 포인터 아닌 경우, '.' operator 사용
	int x = pu->i;

	// -------------------------------------------

	/*
	★ 실수주의
	값을 대입할 때는 char을 대입하고
	사용은 double로 사용하는 것
	- 프로그래머의 의도가 혼란스러움
	*/
	uni.c = 'A';
	double real = 3.14 * uni.d;   // Do not recommend

	return 0;
}
