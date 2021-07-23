/*
operator : 연산자
operand : 피연산자

Data object
어떤 데이터가 메모리 안에 존재하고 있을 때
정수 한 개 ex) int i
이 개념이 발전해서 객체지향 프로그램이 등장

L-value : object locator value
메모리를 차지하고 있는 특정 데이터 객체
L-value는 R-value도 될 수 있음 ex) i = i + 1
등호 기준 왼쪽 값

R-value : value of an expression
숫자 (값) 자체
수정 가능한 L-value에 대입될 수는 있지만 L-value가 될 수는 없음
등호 기준 오른쪽 값

ex)
a = 42;
b = a;              -> a, b 모두 L-value
c = TWO * (a + b);  -> a+b 값은 R-value

-------------------------------------------

Binary operator 이항 연산자
피연산자 2개 ex) 3 - 2

Unary operator 단항 연산자
피연산자 1개
ex) -16

복합 연산자 : 이항 연산자 & 단항 연산자
ex) -(12-11)
*/

// ======================================================================

#include <stdio.h>

int main() {

	int income, salary, bonus;

	// triple assignment
	// income = (salary = (bonus = 100))
	income = salary = bonus = 100;

	salary = 100;
	bonus = 30;

	// income : L-value
	// salary + bonus : R-value
	income = salary + bonus;

	// -------------------------------------------

	int a, b;
	a = -7;
	b = -a;

	printf("%d %d\n", a, b);  // -7 7

	b = +a; // ★ + does nothing
	printf("%d %d\n", a, b);  // -7 -7

	return 0;
}

// ======================================================================
// 복리 계산하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	double start, target, interest;

	printf("Input seed money : ");
	scanf("%lf", &start);

	printf("Input target money : ");
	scanf("%lf", &target);

	printf("Input annual interest (%%) : ");
	scanf("%lf", &interest);

	double fund = start;
	int year_count = 0;

	while (fund < target) {
		fund += fund * interest / 100.0;
		year_count += 1;
		//year_count++;

		printf("Year %d, fund %f\n", year_count, fund);
	}

	printf("It takes %d years\n", year_count);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 절대 반올림이 아닌 절사로 소수점 없애버림
	printf("Integer divisions\n");
	prnitf("%d\n", 14 / 7);  // 2
	printf("%d\n", 7 / 2);   // 3
	printf("%d\n", 7 / 3);   // 2
	printf("%d\n", 7 / 4);   // 1
	printf("%d\n", 8 / 4);   // 2

	printf("Truncating toward zero (C99)\n");
	prnitf("%d\n", -7 / 2);  // -3
	printf("%d\n", -7 / 3);  // -2
	printf("%d\n", -7 / 4);  // -1
	printf("%d\n", -8 / 4);  // -2

	printf("Floting divisions\n");
	printf("%f\n", 9.0 / 4.0);  // 2.250000

	// Note : 4 is integer
	// CPU는 자료형이 다른 것끼리 계산 불가
	// compiler가 내부적으로 4를 double 형태인 4.0으로 자동 변환하여 계산
	// 가능하면, 같은 type으로 연산할 것
	printf("%f\n", 9.0 / 4);    // 2.250000

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int a = 10, b = 10;
	int x1, y1;

	x1 = ++a;
	y1 = --b;

	// 전위연산자: 11, 9 -> 11, 9
	printf("전위연산자 : %d, %d -> %d, %d\n", a, b, x1, y1);

	int c = 10, d = 10;
	int x2, y2;

	x2 = c++;
	y2 = d--;

	//후위연산자 : 11, 9 -> 10, 10
	printf("후위연산자 : %d, %d -> %d, %d", c, d, x2, y2);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// 관계 연산자

	int x, y;

	printf("두 개의 정수를 입력하시요 : ");
	scanf("%d", &x);
	scanf("%d", &y);

	printf("%d == %d의 결과 : %d\n", x, y, x == y);
	printf("%d != %d의 결과 : %d\n", x, y, x != y);
	printf("%d >  %d의 결과 : %d\n", x, y, x >  y);
	printf("%d <  %d의 결과 : %d\n", x, y, x <  y);
	printf("%d >= %d의 결과 : %d\n", x, y, x >=  y);
	printf("%d <= %d의 결과 : %d\n", x, y, x <= y);

	// -------------------------------------------
	// 조건 연산자

	int a, b;

	printf("첫 번째 수는? ");
	scanf("%d", &x);
	printf("두 번째 수는? ");
	scanf("%d", &y);

	// x가 y보다 크면 x 출력, 아니면 y 출력
	printf("큰수 = %d\n", (x > y) ? x : y);

	// x가 y보다 작으면 x 출력, 아니면 y 출력
	printf("작은수 = %d", (x < y) ? x : y);

	return 0;

}


