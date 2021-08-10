// Variadic Macros accept a variable number of arguments

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
variadic macro가 몇 개가 들어올지 모를 때
-> ellipses 사용 : ...
-> 이렇게 ... 부분에 들어온 걸 __VA_ARGS__ 부분에 통째로 옮겨 넣음
   __VA_ARGS__: one of the predefined macros
*/
#define PRINT(X, ...) printf("Message " #X ": " __VA_ARGS__)


int main() {

	double x = 48;
	double y;

	y = sqrt(x);

	// compiler 내부 처리 방식
	// printf("Message " "1" ": " "x = %g\n", x);
	PRINT(1, "x = %g\n", x);   // Message 1: x = 48

	// 둘 다 같은 결과
	// Message 2 : x = 48.00, y = 6.9282
	printf("Message " "2" ": " "x = %.2f, y = %.4f\n", x, y);
	PRINT(2, "x = %.2f, y = %.4f\n", x, y);
	
	return 0;
}
