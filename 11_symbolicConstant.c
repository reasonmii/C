/*
Symbolic Constant 기호 상수
Compiler 입장에서는 기호 상수를 쓰나 안 쓰나 똑같은 과정을 거쳐 계산해야 함
그러나, 프로그래머가 보기 편하고 실수도 줄어드니 사용

Method1)
use '#define'
관습적으로 define 할 때는 모두 대문자 사용
       
Method2)
use 'const'
최근에 이 방법 많이 사용하고, 특히 C++에서는 이 방법을 권장
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>
#define EX_RATE 1200

int main(void) {

	int dollar1 = 10;
	int dollar2 = 100;
	int dollar3 = 1000;

	int won1 = EX_RATE * dollar1;
	int won2 = EX_RATE * dollar2;
	int won3 = EX_RATE * dollar3;

	printf("%d원 = %d달러 \n", won1, dollar1);  // 12000원 = 10달러
	printf("%d원 = %d달러 \n", won2, dollar2);
	printf("%d원 = %d달러 \n", won3, dollar3);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PI 3.141592f
#define AI_NAME "Jarvis"

int main() {

	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius;
	circum = 2.0f * PI * radius;

	printf("Area is %f\n", area);
	printf("Circumstance is %f\n", circum);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define AI_NAME "Jarvis"

int main() {

	const float pi = 3.141592f;
	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Input radius\n");

	scanf("%f", &radius);

	area = pi * radius * radius;
	circum = 2.0f * pi * radius;

	printf("Area is %f\n", area);
	printf("Circumstance is %f\n", circum);

	return 0;
}

