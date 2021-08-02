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

	my_func(1);    // Debug Red dot 찍기
	return 0;
}

void my_func(int n) {

	// 주소는 기본적으로 16진수
	// 이해하기 좋게 아래와 같이 10진수로 출력 가능
	//printf("Level %d, address of variable n = %d\n", n, (int)&n);
	printf("Level %d, address of variable n = %p\n", n, &n);

	if (n <= 4)
		my_func(n + 1);

	// Debug Red dot 찍기
	//printf("Level %d, address of variable n = %d\n", n, (int)&n);
	printf("Level %d, address of variable n = %p\n", n, &n);
}

// ======================================================================
// 팩토리얼 : loop vs. recursion

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

	int num = 5;
	printf("%d\n", loop_factorial(num));
	printf("%d\n", recursive_factorial(num));

	return 0;
}

long loop_factorial(int n) {

	int rst;
	for (rst = 1; n > 1; n--)
		rst *= n;

	return rst;
}

long recursive_factorial(int n) {

	if (n > 0)
		// tail/end recursion
		// return 바로 뒤에 recursive call을 하는 것
		return n * recursive_factorial(n - 1);
	else
		return 1;

}

// ======================================================================
// 팩토리얼 : 숫자 입력받기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long factorial(int n);     // 함수선언

int main(void) {
	int n;
	printf("정수 입력 : ");
	scanf("%d", &n);
	printf("%d! = ", n);  // ex)  4! = 4 * 3 * 2 * 1
	factorial(n);

	return 0;
}

long factorial(int n) {
	printf("%d", n);
	if (n == 1)
		return 1;
	else {
		printf(" * ");
		return n * factorial(n - 1);
	}
}

// ======================================================================
/*
하노이의 탑
A에서 원반 1를 C로 옮김
*****A에서 원반 2를 B로 옮김
#####C에서 원반 1를 B로 옮김
=====*****A에서 원반 3를 C로 옮김
#####B에서 원반 1를 A로 옮김
*****B에서 원반 2를 C로 옮김
#####A에서 원반 1를 C로 옮김
==========
*/

#include <stdio.h>

void hanoi(int n, int start, int work, int target);

void main() {
	hanoi(3, 'A', 'B', 'C');
	getchar();
}

void hanoi(int n, int start, int work, int target) {
	if (n == 1)
		printf("%c에서 원반 %d를 %c로 옮김 \n", start, n, target);
	else {
		hanoi(n - 1, start, target, work);
		printf("*****");
		printf("%c에서 원반 %d를 %c로 옮김 \n", start, n, target);
		printf("#####");
		hanoi(n - 1, work, start, target);
		printf("=====");
	}
}

