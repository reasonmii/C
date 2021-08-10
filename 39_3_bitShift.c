/*
Bitwise Shift Operator
비트 단위 Shift 연산자

1) Left Shift
- number << n
- multiply number by 2^n
  ★ 항상 2^n을 곱한 듯한 결과 나오는 건 아님

2) Right Shift
- number >> n
- divide by 2^n (for non-negative numbers)
  ★ 항상 2^n으로 나눈 듯한 결과 나오는 건 아님

★ Note : the signed result is machine dependent
- signed integer에 대해 빈칸을 0으로 채울지, 1로 채울지 여부는
  어떤 editor를 사용하는 지에 따라 달라질 수 있음
- 가장 많이 쓰이는 Visual Studio는 1로 채우고 있음
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>     // pow()
#include <limits.h>   // CHAR_BIT

void int_binary(const int num);

int main() {

	// 8 bit (= 1 byte) integer cases

	/*
	1의 2진수        :    00000001
	왼쪽으로 3칸 이동 : 00000001???
	결과             :    00001000 (8)
	-> 마치 1에 2^3을 곱한 듯한 결과가 나옴
	*/
	printf("%hhd\n", 1 << 3);

	/*
	8의 2진수          : 00001000
	오른쪽으로 1칸 이동 : ?00001000
	결과               : 00000100 (4)
	-> 마치 8을 2^1로 나눈 듯한 결과가 나옴
	*/
	printf("%hhd\n", 8 >> 1);

	// -------------------------------------------

	/*
	★ 음수 주의!!

	signed integer
	★ signed integer은 맨 앞 숫자가 부호를 의미
	★ 그런데 signed integer가 오른쪽으로 이동해서,
	   왼쪽에 빈칸들이 생기면 모두 1로 채움

	 -119의 2진수       : 10001001
	오른쪽으로 3칸 이동  : ???10001001
	결과                : 11110001 (-15)
	-> 즉, right shift라고 무조건
	   2^n으로 나눈 듯한 결과가 나오지 않음
	*/
	printf("%hhd\n", -119 >> 3);

	/*
	unsigned integer
	★ unsigned integer은 오른쪽으로 이동해서,
	   왼쪽에 빈칸들이 생기면 모두 0으로 채움

	※ signed integer -119와 unsigned integer 137은
	  모두 2진수 패턴이 10001001로 같음

	-119의 2진수        : 10001001
	오른쪽으로 3칸 이동  : ???10001001
	결과                : 00010001 (17)
	-> 마치 137을 2^1로 나눈 듯한 결과가 나옴
	*/
	printf("%hhu\n", 137 >> 3);

	// -------------------------------------------

	/*
	-119의 2진수    :     10001001
	왼쪽으로 4칸 이동 : 10001001????
	결과             :     10010000 (-112)
	-> 입력 글자가 signed integer인데
	   ★ 결과의 첫 번째 숫자가 1이니 음수인 -112 출력
	*/
	printf("%hhd\n", -119 << 4);

	/*
	137의 2진수      :     10001001
	왼쪽으로 4칸 이동 : 10001001????
	결과             :     10010000 (144)
	-> 입력 글자가 unsigned integer니
	   ★ 결과도 unsigned integer로 인식해서 출력
	*/
	printf("%hhu\n", 137 << 4);

	// -------------------------------------------
	// 연산자 줄여서 아래와 같이 사용 가능

	int a = 1;
	a <<= 3;
	a >>= 2;

	// -------------------------------------------

	/*
	Unsigned int 4294967295
	Signed int - 1
	Decimal          - 1 == Binary11111111111111111111111111111111
	Right shift by 3
	Decimal          - 1 == Binary11111111111111111111111111111111
	Decimal    536870911 == Binary00011111111111111111111111111111

	-> 오른쪽으로 3칸 옮기면 왼쪽에 빈칸이 생김
	- signed는 빈칸을 1로 채움
	- unsigned는 빈칸을 0으로 채움
	*/
	printf("Unsigned int %u\n", 0xffffffff);
	printf("Signed int %d\n", 0xffffffff);
	int_binary(0xffffffff);
	printf("Right shift by 3\n");
	int_binary(  (signed)0xffffffff >> 3);
	int_binary((unsigned)0xffffffff >> 3);

	/*
	★ 원래 2진수 값의 맨 앞이 0인 경우
	   signed와 unsigned 연산의 결과값은 동일함

	Unsigned int 16777215
	Signed int 16777215
	Decimal     16777215 == Binary00000000111111111111111111111111
	Right shift by 3
	Decimal      2097151 == Binary00000000000111111111111111111111
	Decimal      2097151 == Binary00000000000111111111111111111111

	-> 오른쪽으로 3칸 옮기면 왼쪽에 빈칸이 생김
	- signed는 빈칸을 1로 채움
	- unsigned는 빈칸을 0으로 채움
	*/
	printf("\nUnsigned int %u\n", 0x00ffffff);
	printf("Signed int %d\n", 0x00ffffff);
	int_binary(0x00ffffff);
	printf("Right shift by 3\n");
	int_binary(  (signed)0x00ffffff >> 3);
	int_binary((unsigned)0x00ffffff >> 3);

	return 0;
}

void int_binary(const int num) {
	printf("Decimal %12d == Binary", num);

	const size_t bits = sizeof(num) * CHAR_BIT;
	for (size_t i = 0; i < bits; ++i) {

		/*
		※ pow(2, (bits - 1 - i));
		-> 앞에서는 pow 함수를 사용했으나
		   이렇게 shift 이동 연산도 사용 가능
		★ 이게 더 효율적이고 C언어 다운 방법
		*/
		const int mask = 1 << (bits - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
