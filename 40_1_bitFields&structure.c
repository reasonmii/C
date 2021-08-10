// 구조체 안의 비트필드 Bit-Fields

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>   // CHAR_BIT
#include <stdbool.h>

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

	struct items {
		/*
		number means bits to use!
		몇 bit를 사용할지 결정

		bool has_sword    : 1;
		-> 1bit짜리 has_sword를 bool처럼 인식
		
		전체 : 1bit씩 8개 item -> 1byte
		*/
		bool has_sword    : 1;
		bool has_shield   : 1;
		bool has_potion   : 1;
		bool has_guntlet  : 1;
		bool has_hammer   : 1;
		bool has_key      : 1;
		bool has_ring     : 1;
		bool has_amulet   : 1;
	} items_flag;

	// flags = flags | MASK_SWORD;
	// 위에서 bool로 인식하라고 코딩했기 때문에
	// 1/0 대신 true/false로 해도 가능
	items_flag.has_sword   = 1;   // =true;
	items_flag.has_shield  = 1;
	items_flag.has_potion  = 0;
	items_flag.has_guntlet = 1;
	items_flag.has_hammer  = 0;
	items_flag.has_key     = 0;
	items_flag.has_ring    = 0;
	items_flag.has_amulet  = 0;

	printf("Size = %zd byte\n", sizeof(items_flag)); // Size = 1 byte

	// result : 00001011
	// input의 역순으로 나옴 -> ※ 출력 방식은 compiler에 따라 다름
	print_binary((char*)&items_flag, sizeof(items_flag));

	// -------------------------------------------
	// bit-field를 사용하면 이전에 bit Mask를 사용해서
	// Game programming을 했던 것보다 훨씬 간단하게 coding 가능

	// if ((flags & MASK_KEY) == MASK_KEY)
	if (items_flag.has_key == 1)
		printf(">> You can enter.\n");

	union {
		// union을 사용하면
		// 아래 bf와 uc가 차지하는 메모리가 동일함
		struct items bf;
		unsigned char uc;
	} uni_flag;

	uni_flag.uc = 0;
	printf("uc = 0 : ");
	print_binary((char*)&uni_flag, sizeof(uni_flag));  // 00000000

	uni_flag.bf.has_amulet = true;
	printf("has_amulet = true : ");
	print_binary((char*)&uni_flag, sizeof(uni_flag));  // 10000000

	uni_flag.uc |= (1 << 4);
	printf("1 << 4 : ");
	print_binary((char*)&uni_flag, sizeof(uni_flag));  // 10010000

	uni_flag.bf.has_key = false;
	printf("has_key = false : ");
	print_binary((char*)&uni_flag, sizeof(uni_flag));  // 10010000

	// -------------------------------------------
	/*
	KNK DOS example
	모든 파일에 공통적으로 들어가야 하는 정보는
	메모리가 작을 수록 좋음
	-> bit field 사용

	ex) 파일 생성 시간
	1) seconds : 5bit
	   -> 2^5 = 32, (0 ~ 29) 30*2 seconds
	   초를 1초단위로 모두 저장할만큼 정밀도가
	   필요하진 않아서, 5bit 사용
	   = 2초 단위 정밀도
	2) minutes : 6bit
	   -> 2^6 = 64, (0 ~ 59) 60 minutes
	3) hours : 5bit
	   -> 2^5 = 32, (0 ~ 23) 24 hours

	*/

	struct file_time {
		unsigned int seconds : 5;
		unsigned int minutes : 6;
		unsigned int hours   : 5;
	};

	struct file_date {
		// day를 unsigned int처럼 사용해라
		// - 실제로 사용하는 건 5bit
		unsigned int day   : 5;   // 2^5 = 32, 0~31
		unsigned int month : 4;   // 2^4 = 16, 1~12
		unsigned int year  : 7;   // 2^7 = 128, 1980~
	} fd;

	// 1988.12.28
	fd.day = 28;       // = 32; -> overflow -> 0 출력
	fd.month = 12;     // = 14; -> overflow
	fd.year = 8;

	printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);
	
	// bit-field는 scanf 사용 불가
	// scanf("%d", &fd.day);  -> ERROR

	return 0;
}
