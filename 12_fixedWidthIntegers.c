// 고정 너비 정수

#include <stdio.h>
//#include <stdint.h>  // also included in inttypes.h
#include <inttypes.h>

int main() {

	int i;
	int32_t i32;          // 32 bit integer
	int_least8_t i8;      // smallest 8 bit
	int_fast8_t f8;       // fastest minimum
	intmax_t imax;        // biggest signed integers
	uintmax_t uimax;      // biggest unsigned integers

	i32 = 1004;

	printf("me32 = %d\n", i32);        // 1004

	// printf문 쪼개기
	printf("me32 = %" "d" "\n", i32);  // 1004

	// "d" 부분을 매크로 "PRId32"로 교체
	// PRI : print
	// d32 : decimal integer 32 bit
	// -> multi platform 실무 때 많이 사용됨
	printf("me32 = %" PRId32 "\n", i32);  // 1004

	return 0;
}
