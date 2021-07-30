#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// 자동 형변환
	int x = 3.14;
	double y = 3;

	printf("%d\n", x); // 3
	printf("%f", y);   // 3.000000

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	// Promotions in assigments
	// 크기가 큰 자료형에 작은 자료형을 넣는 것은 문제 없음
	short s = 64;
	int i = s;
	float f = 3.14f;
	double d = f;

	// -------------------------------------------

	// Demotion in assignments
	// demotion : 크기가 더 큰 자료형을 작은 자료형에 넣는 것
	// 뒤에 f 안 쓰면 double 형 (8 bytes)
	// 1.25는 숫자 특성 상 double과 float 차이가 없는데 1.123은 미묘하게 다름
	// -> warning 발생 : truncation from 'double' to 'float'
	d = 1.25;
	f = 1.25;
	f = 1.123;

	// -------------------------------------------

	// Ranking of types in operations
	// long double > double > float
	// 정수형 간 Ranking 우선순위 아래와 같음
	// (메모리가 클수록 ranking 높음)
	// 1) unsigned long long, long long
	// 2) unsigned long, long
	// 3) unsigned, int
	// 4) short int, unsigned short int
	// 5) signed char, char, unsigned char
	// 6) _Bool
	// ref) Google 'Integer coversion rank'

	// float + double -> 결과 : double
	// 내부적으로 float는 double로 바꿔서 계산됨
	// d도 double type이니 문제 없음
	d = f + 1.234;

	// float + double -> 결과 : double
	// double을 float인 f에 넣으려고 하니, warning 발생
	// 'possible loss of data'
	f = f + 1.234;

	// -------------------------------------------

	// Casting operators
	// 우리가 의도적으로 형변환을 하는 것
	// 자료형에 따라 결과가 크게 달라질 수 있으니, 항상 형변환 조심해야 함

	d = (double)3.14f;        // double

	// double + double -> double
	// 그런데 integer에 넣으려고 하니 truncate 발생
	// 1.6 + 1.7 -> 3이 됨
	i = 1.6 + 1.7;        

	// (int)1.6 -> 1
	// (int)1.7 -> 1
	// 1 + 1 -> 2가 됨
	i = (int)1.6 + (int)1.7;

	// -------------------------------------------

	// more examples
	char c;
	f = i = c = 'A';
	printf("%c %d %f\n", c, i, f);  // A 65 65.000000
	c = c + 2;                      // 67
	i = f + 2 * c;                  // 65.0f + 2 * 67 -> 199
	printf("%c %d %f\n", c, i, f);  // C 199 65.000000

	// char에는 1106 너무 커서 입력 불가
	// 1106 -> (2진수) 0b10001010010
	// 그런데 char type은 1byte이기 때문에 앞 8글자만 인식하게 됨
	// 0b10001010 -> (10진수) 82 -> R
	// ★ 나머지 연산자 계산할 때의 값과 같음
	//    ex) 1106 % 256 -> 82 
	c = 1106;
	printf("%c\n", c);              // R

	// 반올림이 아닌 절삭이 됨
	// 83.99 -> 83 -> S
	c = 83.99;
	printf("%c\n", c);              // S

	return 0;
}


