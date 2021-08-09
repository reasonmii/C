/*
Bitwise Logical Operators
비트 단위 논리 연산자
- NOT : ~ (tilde)
- AND : & (ampersand)
- OR  : | (vertical bar)
- EXCLUSIVE OR (XOR) : ^ (caret)

OR과 XOR 차이
★ XOR : OR과 같은데 둘 다 1이면 0이 되는 것만 다름
*/

// ======================================================================

/*
1) 이진수를 십진수로 변환

2) &를 이용해서 십진수를 이진수로 변환
Decimal to binary

        Number     Mask          Mask
2^7  : (01000110 & 10000000)  != 10000000    print 0
2^6  : (01000110 & 01000000)  == 01000000    print 1
2^5  : (01000110 & 00100000)  != 00100000    print 0
2^4  : (01000110 & 00010000)  != 00010000    print 0
2^3  : (01000110 & 00001000)  != 00001000    print 0
2^2  : (01000110 & 00000100)  == 00000100    print 1
2^1  : (01000110 & 00000010)  == 00000010    print 1
2^0  : (01000110 & 00000001)  != 00000001    print 0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>     // pow()
#include <string.h>   // strlen()
#include <stdlib.h>   // exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main() {

	// 2진수 -> 10진수
	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("00000110"));   // 6
	printf("%d\n", to_decimal("00010110"));   // 22
	printf("%d\n", to_decimal("10010100"));   // 148

	// -------------------------------------------
	// 10진수 -> 2진수

	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	printf("%d\n", i);     // 70
	printf("%d\n", mask);  // 5

	/* result
	Decimal  70     == Binary 01000110
	Decimal   5     == Binary 00000101
	Decimal   4     == Binary 00000100
	*/
	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);

	// -------------------------------------------
	// 비트단위 논리연산

	unsigned char a = 6;
	unsigned char b = 5;

	// 6
	// Decimal   6 == Binary 00000110
	printf("%hhu\n", a);
	print_binary(a);

	// 5
	// Decimal   5 == Binary 00000101
	printf("%hhu\n", b);
	print_binary(b);

	// 4
	// Decimal   4 == Binary 00000100
	printf("%hhu\n", a & b);
	print_binary(a & b);

	// 7
	// Decimal   7 == Binary 00000111
	printf("%hhu\n", a | b);
	print_binary(a | b);

	// ★ XOR : OR과 같은데
	//          둘 다 1이면 0이 되는 것만 다름
	// 3
	// Decimal   3 == Binary 00000011
	printf("%hhu\n", a ^ b);
	print_binary(a ^ b);

	// 249
	// Decimal 249 == Binary 11111001
	printf("%hhu\n", ~a);
	print_binary(~a);

	return 0;
}

// 이진수를 십진수로 변환하는 함수
unsigned char to_decimal(const char bi[]) {

	// size_t : x86일 때는 unsigned int,
	//          x64일 때는 unsigned long long
	const size_t bits = strlen(bi);
	unsigned char sum = 0;

	for (size_t i = 0; i < bits; i++) {
		if (bi[i] == '1')
			sum += (int)pow(2, bits - 1 - i);
		// 1이나 0이 아닌 다른 문자가 입력된 경우
		else if (bi[i] != '0') {
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}
	return sum;
	// printf("Binary %s == Dcimal %d\n", bi, sum);
}

// &를 이용해서 십진수를 이진수로 변환하는 함수
void print_binary(const unsigned char num) {

	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; i++) {

		/*
		아래처럼 간단하게 코딩도 가능
		unsigned char mask = pow(2, (bits - 1 - i));
		-> warning 발생

		Why?
		power는 기본적으로 double에 대해서 연산함
		-> 결과값 = double
		unsigned char mask에 넣기 위해선 unsigned char로 변환 필요
		※ 굳이 변환 안 하더라도 사실 C언어에서는 compiler가 자동으로 변환해 줌
		*/
		const unsigned char mask =
			(unsigned char)pow((double)2, (double)(bits - 1 - i));

		// 자체적으로 이진수로 인식하고 비교
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	/*
	for (size_t i = bits - 1; i >= 0; --i)

	'--i'처럼 i를 감소시키는 코드일 때
	size_t 사용하면 ERROR 발생

	size_t는 결국 unsigned int 자료형인데
	i가 0일 때 -1을 하면 unsinged int에서 가장 큰 숫자로 돌아가기 때문
	for문이 무한 루프가 됨

	따라서 거꾸로 갈 때는 size_t 사용하면 안됨
	*/
	// 해결방법)
	/*for (int i = bits - 1; i >= 0; --i) {
		const unsigned char mask =
			(unsigned char)pow((double)2, (double)i);

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}*/

	printf("\n");
}
