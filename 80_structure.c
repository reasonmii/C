/*
기본 자료형 : int, char, double, void
파생 자료형 : 배열, 포인터, 구조체, 공용체
사용자정의 자료형 : typedef, enum

구조체 struct
여러 개의 서로 다른 자료형을 하나로 묶은 것
객체 지향 프로그램에서의 클레스의 모체
※ 배열 : 동일한 종류의 데이터들의 모임

구조체 선언
구조체의 틀만 정의
어떤 변수들이 포함되는 지만 있음
아직은 데이터 저장 불가능
; : 구조체 선언이 끝나면 반드시 필요

structure tag
구조체를 구별하기 위한 이름
생략 시 구조체 변수를 구조체 선언과 함께 선언하는 것
- 구조체 선언 후에 구조체 변수 선언 불가능

structure member
구조체에 포함되는 변수 (이름 중복 불가능)
모든 자료형이 가능
구조체도 가능

구조체 변수의 연산은 대입 연산 가능
구조체 변수 안의 자료 복사 가능

구조체 배열 : 동일한 구조체 여러 개의 모임
*/

// ======================================================================

#include <stdio.h>

// 날짜 구조체 선언
struct date {
	int year;
	int month;
	int day;
};

// 학생 구조체 선언
struct student {
	int num;
	char name[20];
	struct date birth;  // 다른 구조체 활용
	double grade;
};

// 좌표 구조체 선언
struct point {
	int x;
	int y;
};

int main(void) {
	int a;              // 정수 변수 선언
	int num[50];        // 정수 배열 선언
	struct student s1;  // 구조체 변수 선언
	
	a = 5;
	num[0] = 5;
	
	s1.num = 20;
	strcpy(s1.name, "Kim");
	s1.birth.year = 2000;
	s1.birth.month = 7;
	s1.birth.day = 7;
	s1.grade = 4.3;

	printf("%d\n", a);         // 5
	printf("%d\n\n", num[0]);    // 5

	printf("%d  %s  %.2f\n", s1.num, s1.name, s1.grade);   // 20 Kim 4.30
	printf("생일 : %d%0.2d%0.2d\n\n", s1.birth.year, s1.birth.month, s1.birth.day);  // 20200707

	// -------------------------------------------

	// 구조체 변수 초기화
	struct student st1 = { 20, "Kim", 2002, 3, 3, 4.3 };
	struct student st2 = { 10, "Lee", 2001, 12, 24, 4.5 };

	printf("%d  %s  %.2f\n", st1.num, st1.name, st1.grade);   // 20 Kim 4.30
	printf("%d  %s  %.2f\n\n", st2.num, st2.name, st2.grade);   // 10 LEE 4.50

	// -------------------------------------------

	// 구조체 변수 복사
	struct student s2, s3;

	s2.num = s1.num;
	strcpy(s2.name, s1.name);
	s2.grade = s1.grade;

	printf("%d  %s  %.2f\n", s1.num, s1.name, s1.grade);   // 20 Kim 4.30
	printf("%d  %s  %.2f\n\n", s2.num, s2.name, s2.grade);   // 20 Kim 4.30

	// -------------------------------------------

	struct point p1 = { 10, 20 };
	struct point p2 = { 20, 40 };

	printf("%d-%d\n", p1.x, p1.y);  // 10-20
	printf("%d-%d\n", p2.x, p2.y);  // 20-40

	// 복사
	p2 = p1;

	printf("%d-%d\n", p1.x, p1.y);  // 10-20
	printf("%d-%d\n\n", p2.x, p2.y);  // 10-20

	// p1 == p2 : 오류
	// 하나하나 비교해야 함
	// 결과 : 같음
	if ((p1.x == p2.x) && (p1.y == p2.y))
		printf("같음\n");
	else
		printf("다름\n");

	return 0;

}

// ======================================================================

#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

void main() {
	int i;
	struct employee Lee[4] = {
		{"샐리", 2018, 4200},
		{"베어", 2020, 5300},
		{"그린", 2021, 3700},
		{"토토", 2019, 6100}
	};

	for (i = 0; i < 4; i++) {
		printf("이름 : %s\t", Lee[i].name);
		printf("입사 : %d\t", Lee[i].year);
		printf("연봉 : %d\n", Lee[i].pay);
	}
	getchar();
}

// ======================================================================

// 구조체에서 포인터가 사용되는 경우
// - 구조체를 가리키는 포인터
// - 포인터를 멤버로 가지는 구조체

// 구조체 포인터 변수를 이용한 구조체 멤버 접근

// 포인터 변수 p가 가리키는 구조체의 멤버 name
// p->name
// (*p).name

// 구조체 p의 멤버 (포인터 변수) name이 가리키는 내용
// *p.name
// *(p.name)

// p가 가리키는 구조체의 멤버 (포인터 변수) name이 가리키는 내용
// *p->name
// *(p->name)

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

void main() {

	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "이순신");
	Sptr->year = 2015;
	Sptr->pay = 3700;

	printf("이름 : %s\n", Sptr->name);
	printf("입사 : %d\n", Sptr->year);
	printf("연봉 : %d\n", Sptr->pay);

	getchar();

}

// ======================================================================

#include <stdio.h>

// 날짜 구조체 선언
struct date {
	int year;
	int month;
	int day;
};

// 학생 구조체 선언
struct student {
	int num;
	char name[20];
	double grade;
};

// 함수 생성
// 함수는 마지막에 ; 하지 않음
int equal(struct student s1, struct student s2) {
	if (s1.num == s2.num)
		return 1;
	else
		return 0;
}

int pointEqual(struct student* p1, struct student* p2) {
	if (p1->num == p2->num)
		return 1;
	else
		return 0;
}

struct student create() {
	struct student s;
	s.num = 3;
	strcpy(s.name, "Kim");
	s.grade = 3.5;

	return s;
}

int main(void) {
	
	struct student s = { 24, "Kim", 4.3 };

	struct student* p;
	p = &s;

	// 같은 결과 : 학번 = 24        이름 = Kim     , 점수 = 4.30
	printf("학번 = %d\t 이름 = %s\t, 점수 = %.2f\n", (*p).num, (*p).name, (*p).grade);
	printf("학번 = %d\t 이름 = %s\t, 점수 = %.2f\n", p->num, p->name, p->grade);

	// -------------------------------------------

	struct student s1 = { 1, "Kim", 4.2 };
	struct student s2 = { 2, "Lee", 4.4 };

	// 결과 : 구조체 번호 다름
	if (equal(s1, s2) == 1)
		printf("구조체 번호 같음\n");
	else
		printf("구조체 번호 다름\n");

	// -------------------------------------------

	// 결과 : 구조체 번호 다름
	if (pointEqual(&s1, &s2) == 1)
		printf("구조체 번호 같음\n");
	else
		printf("구조체 번호 다름\n");

	// -------------------------------------------

	struct student s3 = create();

	// 학번 = 3         이름 = Kim      점수 = 3.5
	printf("학번 = %d \t 이름 = %s \t 점수 = %.1f\n", s3.num, s3.name, s3.grade);

	return 0;

}

// ======================================================================

#include <stdio.h>

// 구조체 선언
struct exStruct {
	char c;
	int i;
	int j;
	int k;
};

// 공용체 선언
union example {
	char c;
	int i;
	int j;
	int k;
};

int main(void) {	

	struct exStruct est;          // 구조체
	union  example e = { 'a' };  // 공용체

	// 구조체 크기 : 16
	// -> padding으로 한 개당 4byte 처리
	printf("%d\n", sizeof(est));

	// 공용체 크기 : 4
	// 한 개의 사이즈만 잡음
	printf("%d\n", sizeof(e));

	// 공용체 출력
	// a  97  97  97
	printf("%c  %d  %d  %d\n", e.c, e.i, e.j, e.k);

	e.i = 500;
	// ? 500  500  500
	printf("%c  %d  %d  %d\n", e.c, e.i, e.j, e.k);

	return 0;
}

// ======================================================================

#include <stdio.h>

// 구조체 선언
//enum days { SUN, MON, TUE, WED, THU, FRI, SAT };
//enum days { SUN = 7, MON, TUE, WED, THU, FRI, SAT };
enum days { SUN = 7, MON = 2, TUE, WED, THU, FRI, SAT };

int main(void) {

	enum days today;
	today = TUE;
	printf("%d\n", today);  // 2 -> 9 -> 3

	return 0;
}
