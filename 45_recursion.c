/*
Debug 해서 n 값 변화 확인
1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 4 -> 3 -> 2 -> 1

Level 1, address of variable n = 0095F808
Level 2, address of variable n = 0095F730
Level 3, address of variable n = 0095F658
Level 4, address of variable n = 0095F580
Level 5, address of variable n = 0095F4A8
Level 5, address of variable n = 0095F4A8
Level 4, address of variable n = 0095F580
Level 3, address of variable n = 0095F658
Level 2, address of variable n = 0095F730
Level 1, address of variable n = 0095F808
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void my_func(int);

int main() {

	my_func(1);  // Debug Red dot 찍기
	return 0;
}

void my_func(int n) {
	printf("Level %d, address of variable n = %p\n", n, &n);

	if (n <= 4)
		my_func(n + 1);

	// Debug Red dot 찍기

}

// ======================================================================





