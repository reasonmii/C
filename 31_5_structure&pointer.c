/*
구조체에서 포인터가 사용되는 경우
- 구조체를 가리키는 포인터
- 포인터를 멤버로 가지는 구조체

구조체 포인터 변수를 이용한 구조체 멤버 접근

포인터 변수 p가 가리키는 구조체의 멤버 name
p->name
(*p).name

구조체 p의 멤버 (포인터 변수) name이 가리키는 내용
*p.name
*(p.name)

p가 가리키는 구조체의 멤버 (포인터 변수) name이 가리키는 내용
*p->name
*(p->name)
*/

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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names {
	char given[LEN];   // first name
	char family[LEN];  // last name
};

struct friend {
	struct names full_name;  // nested structure
	char mobile[LEN];
};

int main() {

	struct friend my_friends[2] = {
		{{"Ariana", "Grande"}, "1234-1234"},
		{{"Taylor", "Swift"}, "6550-8888"}
	};

	// friend라는 구조체를 가리키는 pointer
	struct friend* girl_friend;

	girl_friend = &my_friends[0];

	// friend 구조체의 사이즈
	printf("%zd\n", sizeof(struct friend));    // 60

	// girl_friend 포인터의 주소
	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);      // 291359028544 Ariana
	// printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
	// -> : indirect member access operator

	girl_friend++;

	// dot(.) has higher precedence than *
	// ★ dot(.)이 연산자 우선순위가 *보다 높기 때문에 괄호 필요
	printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);    // 291359028604 Taylor

	return 0;
}

// ======================================================================
	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct my_data {
	int a;
	char c;
	float arr[2];
};

int main() {

	// struct my_data d1 = { 1234, 'A', {1.1f, 2.2f} };
	struct my_data d1 = { 1234, 'A', };
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);   // 1234 A 725951182384
	printf("%f %f\n", d1.arr[0], d1.arr[1]);                 // 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);  // 725951182384 725951182388

  // ★ 복사하면 메모리 값이 복사됨 (같은 주소를 쓰지는 않음)
  //    -> 서로 다른 메모리를 사용함
	struct my_data d2 = d1;
	// d2.a = d1.a;
	// d2.c = d1.c;
	// d2.arr[0] = d1.arr[0]
	// d2.arr[1] = d1.arr[1]

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);   // 1234 A 725951182432
	printf("%f %f\n", d2.arr[0], d2.arr[1]);                 // 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);  // 725951182432 725951182436

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct my_data {
	int a;
	char c;
	float* arr;   // ★ Pointer
};

int main() {

	struct my_data d1 = { 1234, 'A', NULL };
	// 동적할당으로 메모리 받기
	d1.arr = (float*)malloc(sizeof(float) * 2);
	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);   // 1234 A 2479863845392
	printf("%f %f\n", d1.arr[0], d1.arr[1]);                 // 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);  // 2479863845392 2479863845396

	// ★ 두 structure 주소가 아예 같음
	//    -> 메모리를 서로 공유하고 있음
	struct my_data d2 = d1;

	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);   // 1234 A 2479863845392
	printf("%f %f\n", d2.arr[0], d2.arr[1]);                 // 1.100000 2.200000
	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);  // 2479863845392 2479863845396

	return 0;
}
