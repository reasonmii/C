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




