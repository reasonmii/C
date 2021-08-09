/*
비트 단위 연산자는 특히 게임 프로그래밍 같이
메모리를 효율적으로 잘 사용해야 하는 경우에 매우 유용하게 사용 가능
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
MASK 만들 때 shift 사용하는 것이 일반적
Binary 부분에서 보이듯이 해당 아이템 여부를
8자리 중 특정 자리에 1/0으로 표시
*/
//                     Shift       Decimal   Binary    Hex   Octet
#define MASK_SWORD    (1 << 0)  // 2^0       00000001  0x01  01
#define MASK_SHIELD   (1 << 1)  // 2^1       00000010  0x02  02
#define MASK_POTION   (1 << 2)  // 2^2       00000100  0x04  04
#define MASK_GUNTLET  (1 << 3)  // 2^3       00001000  0x08  010
#define MASK_HAMMER   (1 << 4)  // 2^4       00010000  0x10  020
#define MASK_KEY      (1 << 5)  // 2^5       00100000  0x20  040
#define MASK_RING     (1 << 6)  // 2^6       01000000  0x40  0100
#define MASK_AMULET   (1 << 7)  // 2^7       10000000  0x80  0200

void char_binary(const char num);
void int_binary(const int num);

/*
flag           01011010
mask           00000011
mask & flag == 00000010
-> mask가 0인 부분은 전부 0으로 출력
   mask = 1 & flag = 1인 부분만 1 출력
*/

int main() {

	/*
	게임에서 해당 캐릭터가 8가지 item을
	가지고 있는지 여부를 8가지 변수로 설정하는 방법
	-> 단점)
	   단순히 있는지 없는지 여부라 1bit로도 충분한데,
	   1byte (8bit)를 차지하고 있음
	-> 해결방법 : #define 2진수 사용

	bool has_sword   = false;
	bool has_shield  = false;
	bool has_potion  = false;
	bool has_guntlet = false;
	bool has_hammer  = false;
	bool has_key     = false;
	bool has_ring    = false;
	bool has_amulet  = false;
	*/

	// 아무 아이템도 없는 상태로 시작
	char flags = 0;      // MASK flags
	char_binary(flags);  // 00000000

	// -------------------------------------------
	// 특정 bit 켜기 : OR 연산자 사용

	printf("\nTurning Bits On (Setting Bits)\n");

	// 칼 item 획득
	flags = flags | MASK_SWORD;    // flags |= MASK_SWORD;
	char_binary(flags);            // 00000001

	// 목걸이 item 획득
	flags |= MASK_AMULET;
	char_binary(flags);            // 10000001

	// -------------------------------------------
	// 특정 bit를 켰다 끄기 : OR -> & NOT

	printf("\nTurning Bits Off (Cleaning Bits)\n");

	// 포션 item 획득
	flags = flags | MASK_POTION;
	char_binary(flags);            // 10000101

	// 포션 item 사용
	flags = flags & ~MASK_POTION;  // flags &= ~MASK_POTION;
	char_binary(flags);            // 10000001

	// -------------------------------------------
	// 특정 bit를 껐다 켰다 껐다 켰다 : ^

	printf("\nToggling Bits\n");

	// 해머 item을 가방에 넣기
	flags = flags ^ MASK_HAMMER;   // 10010001
	char_binary(flags);

	// 해머 item을 가방에서 꺼내서 장착하기
	flags = flags ^ MASK_HAMMER;   // 10000001
	char_binary(flags);

	// 해머 item을 가방에 넣기
	flags = flags ^ MASK_HAMMER;   // 10010001
	char_binary(flags);

	// -------------------------------------------
	// 특정 bit가 켜져 있는지 확인

	printf("\nChecking the Value of a Bit\n");

	// 열쇠 item을 가지고 있는지 확인
	// 현재는 열쇠가 없음
	// result : You can not enter.
	if ((flags & MASK_KEY) == MASK_KEY)
		printf(">> You can enter.\n");
	else
		printf(">> You can not enter.\n");

	// 열쇠 획득
	flags |= MASK_KEY;   // Obtained a key!

	// result : You can enter.
	if ((flags & MASK_KEY) == MASK_KEY)
		printf(">> You can enter.\n");
	else
		printf(">> You can not enter.\n");

	// -------------------------------------------
	// bit의 일부분만 보기

	printf("\nTrimming\n");

	// 원래는 아래와 같이 32bit flag
	// Decimal - 1 == Binary 11111111111111111111111111111111
	int int_flag = 0xffffffff;
	int_binary(int_flag);
	
	// 1byte인 8bit만 보고 싶은 경우
	// ★ 마지막 8bit만 빼고 모두 0으로 변경
	// 마지막 8bit만 새로운 1byte 변수에 넣을 수도 있음
	// Decimal 255 == Binary 00000000000000000000000011111111
	int_flag &= 0xff;
	int_binary(int_flag);

	return 0;
}

void char_binary(const char num) {
	printf("Decimal %3d \t == Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i) {
		const char mask = 1 << (bits - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}

void int_binary(const int num) {
	printf("Decimal %3d \t == Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i) {
		const int mask = 1 << (bits - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
