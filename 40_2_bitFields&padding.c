#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>   // CHAR_BIT
#include <stdbool.h>
#include <string.h>

void char_to_binary(unsigned char uc) {
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; i--)
		printf("%d", (uc >> i) & 1);
}

// Note : extended for any sizes
void print_binary(char* data, int bytes) {
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]);
	printf("\n");
}

int main() {

	struct {
		// 7 bit + 1 bit = 1 byte
		bool option1 : 7;
		bool option2 : 1;
	} bbf;

	printf("%zu bytes\n", sizeof(bbf));

	struct {
		// result : 16 byte
		// -> why? ★ Padding
		// 메모리 안에서 unsigned long long이 잘리지 않기 위해
		// bool 두 개에 8 byte를 배정하고
		// unsigned long long이 다음 8 byte를 차지
		bool option1 : 1;
		bool option2 : 1;
		unsigned long long option3 : 1;
	} bbf2;

	printf("%zu bytes\n", sizeof(bbf2));

	struct {
		bool option1 : 1;
		// ★ Padding이 많이 들어가도 상관 없으니
		// 강제로 메모리를 더 할당받는 방법
		// -> 하드웨어 가속을 위해 많이 사용됨
		bool         : 0;
		bool option2 : 1;
	} bbf3;

	printf("%zu bytes\n", sizeof(bbf3));  // 2

	struct {
		bool option1          : 1;
		unsigned long long    : 0;
		bool option2          : 1;
	} bbf4;

	printf("%zu bytes\n", sizeof(bbf4));  // 16

	// -------------------------------------------

	struct {
		// 8 + 7 + 1 = 16 bit = 2 byte
		unsigned short option1 : 8;
		unsigned short option2 : 7;
		unsigned short option3 : 1;
	} usbf;
	
	printf("%zu bytes\n", sizeof(usbf));

	struct {
		// result : 2 byte
		// -> why? 최소 단위가 short 자료형처럼 설정됨
		unsigned short option1 : 1;
		unsigned short option2 : 1;
		unsigned short option3 : 1;
	} usbf2;

	printf("%zu bytes\n", sizeof(usbf2));

	struct {
		// result : 4 bytes
		// -> why? 최소 단위가 int 자료형처럼 설정됨
		unsigned int option1 : 1;
		unsigned int option2 : 1;
	} uibf;

	printf("%zu bytes\n", sizeof(uibf));

	// -------------------------------------------
	/*
	memset: bbf2의 메모리를 sizeof만큼 전부 1로 초기화
	16 * 8개만큼 1이 나열됨

	11111111111111111111111111111111
	11111111111111111111111111111111
	11111111111111111111111111111111
	11111111111111111111111111111111
	*/
	memset((char*)&bbf2, 0xff, sizeof(bbf2));
	print_binary((char*)&bbf2, sizeof(bbf2));

	/*
	11111111111111111111111111111111
	11111111111111111111111111111110
	11111111111111111111111111111111
	11111111111111111111111111111100
	-> ★ 1 부분은 Padding
	*/
	bbf2.option1 = 0;
	bbf2.option2 = 0;
	bbf2.option3 = 0;
	print_binary((char*)&bbf2, sizeof(bbf2));

	printf("%zu bytes\n", sizeof(bbf2));  // 16

	// -------------------------------------------
	/*
	memset: bbf2의 메모리를 sizeof만큼 전부 0으로 초기화
	16 * 8개만큼 0이 나열됨

	00000000000000000000000000000000
	00000000000000000000000000000000
	00000000000000000000000000000000
	00000000000000000000000000000000
	*/ 
	memset((char*)&bbf2, 0x00, sizeof(bbf2));
	print_binary((char*)&bbf2, sizeof(bbf2));

	/*
	00000000000000000000000000000000
	00000000000000000000000000000001
	00000000000000000000000000000000
	00000000000000000000000000000011
	-> ★ 0 부분은 Padding
	*/
	bbf2.option1 = 1;
	bbf2.option2 = 1;
	bbf2.option3 = 1;
	print_binary((char*)&bbf2, sizeof(bbf2));

	printf("%zu bytes\n", sizeof(bbf2));  // 16

	/*
	★ 이때 bbf.option3 = 2; 하면 결과 제대로 안 나옴
	bbf2.option3는 결국 unsigned long long만큼
	실제 메모리가 있는 게 아니고
	option3는 사실 1bit이기 때문에
	bbf.option3 = 2;로 바꿨을 때 이를 표현할 수 있는 메모리가 없음
	*/ 

	return 0;
}
