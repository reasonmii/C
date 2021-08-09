/*
Two's complement method
2의 보수 표현법
- comonly used in most systems
- Signed Integers
  부호가 "있는" 정수의 2진수를 계산할 때 2의 보수 표현법 사용
- 다른 방법에서는 0이 두 가지가 있는데 (+0, -0)
  2의 보수 표현법에서는 0을 하나로 봄
- To reverse the sign, invert each bit and add 1
  from -128 to 127
  2진수로 표현한 상태에서 숫자의 부호를 바꾸기 위해, 
  ★ 각 bit 값을 반대로 바꾸고 1을 더함

※ 0이 두 개 있는 다른 방법들
1) Sign-magnitude representation
   00000001 is 1 and 10000001 is -1
   00000000 is +0, 10000000 is -0
   Two zeros +0 -0, from -127 to +127
2) One's complement method
   To reverse the sign, invert each bit
   00000001 is 1 and 11111110 is -1
   11111111 is -0
   from -127 to +127
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>     // pow()

void print_binary(const char num);

int main() {

	print_binary(127);       // 01111111
	print_binary(-127);      // 10000001

	/*
	2의 보수 계산
	★ 127을 -127로 바꾸기
	1) ~ : bitwise NOT operator
		   0이면  1, 1이면 0으로 바꿈
	2) 결과에 1 더하기
	*/
	print_binary(~127 + 1);  // 10000001

	// 12를 -12로 바꾸기
	print_binary(12);        // 00001100
	print_binary(-12);       // 11110100
	print_binary(~12 + 1);   // 11110100

	// -7을 7로 바꾸기
	print_binary(7);         // 00000111
	print_binary(-7);        // 11111001
	print_binary(~-7 + 1);   // 00000111

	return 0;
}

// signed char을 입력받음
void print_binary(const char num) {

	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; i++) {

		/*
		사실 mask에서 필요한 건
		내부적으로 2진수로 저장되어 있는 형태인지가 중요하기 때문에
		signed인지 unsigned인지는 중요하지 않음
		-> 이전 코드처럼 const unsigned char 해도 문제 발생X
		*/
		const char mask = (char)pow((double)2, (double)(bits - 1 - i));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	printf("\n");
}
