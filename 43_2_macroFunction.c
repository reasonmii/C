/*
Function-like macros
#define    ADD(X,Y)     ((X)+(Y))
X and Y : macro arguments

● Macro
- no space in the macro name
- Use parantheses
- Use capital letters for macro function names
  대부분의 macro 이름은 대문자
- Speed up?
  최근에는 compiler가 자동으로 최적화를 하기 때문에
  macro를 쓴다고 속도가 빨라지지는 않음
- 장점 : 코딩 분량을 줄여줌

● Macro or Function?
Macro보다는 Function 사용하는 것이 좋음
compiler는 macro가 이미 적용된 후의 값만 볼 수 있어서,
macro가 어떻게 생겼는지 알 수 없고,
따라서 macro에 문제가 있을 때 발견할 수가 없음
- Debugging이 어려움
-> 가급적이면 macro보다 function 사용하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 이렇게 쓰면 X+Y의 결과값이 아닌 X+Y를 그대로 출력
#define ADD1(X, Y)    X+Y
// 이렇게 써야 함
#define ADD2(X, Y)    ((X)+(Y))

#define SQUARE1(X)     X*X
#define SQUARE2(X)     ((X)*(X))

// stringizing operator #
// - converts macro parameters to string literals
//   전처리기에서 #x 부분 자체를 string literal로 바꾸어서 compile
#define SQUARE(X)     (X)*(X)
#define PRINT_SQR1(x) printf("The square of %d is %d.\n", x, SQUARE(x))
#define PRINT_SQR2(x) printf("The square of " #x " is %d.\n", SQUARE(x))

// ## operator combines two tokens into a single token
#define XNAME(n)      x ## n  // x와 n 합치기 : x는 그냥 x 아무 의미 없음
#define PRT_XN(n)     printf("x" #n " = %d\n", x ## n);

int main() {

	int sqr = SQUARE1(3);

	int a = 1;

	printf("%d\n", 2 * ADD1(1, 3));       // 2 *X + Y = 2 * 1 + 3 = 5
	printf("%d\n", 2 * ADD2(1, 3));       // 2 * (1 + 3) = 8

	printf("%d\n", SQUARE1(1 + 2));       // 1 + 2 * 1 + 2 = 1 + 2 + 2 = 5
	printf("%d\n", 100 / SQUARE1(3 + 1)); // 100 / 3 + 1 * 3 + 1 = 33 + 3 + 1 = 37

	// ★ macro함수, 일반 함수에서 증감연산자 사용 시 주의 필요
	// 첫 번째 ++a 에서 1이 증가, 두 번째 ++a에서 1이 증가 -> a = 3
	// ★ 컴파일러에 따라 결과가 다를 수됬음
	printf("%d\n", SQUARE1(++a));         // ++a * ++a = 3 * 3 = 9

	printf("%d\n", SQUARE2(1 + 2));       // 9
	printf("%d\n", 100 / SQUARE2(3 + 1)); // 6
	printf("%d\n", SQUARE2(++a));         // 25

	// -------------------------------------------

	PRINT_SQR1(10);  // The square of 10 is 100.
	PRINT_SQR2(10);  // The square of 10 is 100

	int XNAME(1) = 1;  // n부분에 1 대입
	int XNAME(2) = 2;  // n부분에 2 대입

	PRT_XN(1);  // x1 = 1
	PRT_XN(2);  // x2 = 2

	return 0;
}

// 이런 macro function은 정말 많이 사용되었었음
// 최근에는 표준 LIBRARY에 있는 함수를 많이 사용함
#define MAX(X, Y)     ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y)     ((X) < (Y) ? (X) : (Y))
#define ABS(X, Y)     ((X) < 0 ? -(X) : (X))


