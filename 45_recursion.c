/*
재귀호출
장점 : 구현이 간결
단점
1) 경우에 따라 memory inefficiency
2) redundant computation ex) 피보나치 수열
*/

// ======================================================================
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

// ======================================================================
/*
10진수를 2진수로 변환하기
ex) '10' 변환
10 / 2 = 5, remainder = 0
5  / 2 = 2, remainder = 1
2  / 2 = 1, remainder = 0
1  / 2 = 0, remainder = 1
result : 1010
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_binary_loop(unsigned long n);
void print_binary(unsigned long n);

int main() {
	unsigned long num = 10;
	
	// 1010이 나와야 하는데 loop으로 하면 0101이 나옴
	// Loop에서 원하는 결과를 얻으려면 배열에 담고 거꾸로 출력해야 함
	print_binary_loop(num);  // 0101
	print_binary(num);       // 1010

	printf("\n");

	return 0;
}

// ★ Printing order should be reversed!
void print_binary_loop(unsigned long num) {

	while (1) {
		int quotient = num / 2;
		int remainder = num % 2;

		printf("%d", remainder);
		num = quotient;

		if (num == 0) break;
	}
	printf("\n");
}

void print_binary(unsigned long num) {

	int remainder = num % 2;

	if (num >= 2)
		print_binary(num / 2);

	printf("%d", remainder);
	return;
}

// ======================================================================
/*
Fibonacci Sequence
1 1 2 3 5 8 13 21 24 55 89 144 ...
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibonacci(int number);

int main() {
	
	for (int count = 1; count < 13; ++count)
		printf("%d ", fibonacci(count));

	return 0;
}

int fibonacci(int num) {

	int remainder = num % 2;

	if (num > 2)
		// double recursion
		return fibonacci(num - 2) + fibonacci(num - 1);
	else
		return 1;

}

