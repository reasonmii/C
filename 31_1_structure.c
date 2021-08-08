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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

// ★ 구조체에서는 이렇게 template을 만드는
//    것만으로는 메모리를 차지하지 않음
// person : a tag of structure
struct person {
	// members of structure
	char name[MAX];
	int age;
	float height;
};

int main() {

	// Receives return value of scanf()
	int flag;

	// 이렇게 선언할 때 메모리를 할당하게 됨
	struct person genie;

	/*
	dot(.) is structure membership operator
	- member access operator
	- member operator
	*/

	strcpy(genie.name, "Will Smith");
	// strncpy(genie.name, "Will Smith", MAX);

	genie.age = 1000;

	// ※ dot(.) has higher precedence than &
	flag = scanf("%f", &genie.height);  // &(genie.height)
	printf("%f\n", genie.height);

	// -------------------------------------------
	// Initialization : 선언과 동시에 초기화하는 방법

	// 방법1
	struct person princess = { "Scott", 18, 160.0f };

	// 방법2
	struct person princess2 = {
		"Scott",
		18,
		180.0f
	};

	// 방법3
	strcpy(princess.name, "Scott");
	princess.age = 18;
	princess.height = 180.0f;

	// -------------------------------------------
	// Designated Initializers
	// 어떤 멤버를 어떤 값으로 초기화할 지 지정하는 것
	// ★ 지정이기 때문에 순서가 바뀌어도 됨

	// 방법1
	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 160.0f
	};

	// 방법2
	struct person beauty = { .age = 19, .name = "Bell", .height = 160.0f };

	// -------------------------------------------
	// Pointer to a structure variable

	struct person* someone;

	// 방법1
	// 이미 선언된 다른 structure 'genie'를 대입하기
	someone = &genie;

	// 방법2
	// 동적 할당을 이용해서 메모리 할당을 받고 주소 대입
	// free later
	// someone = (struct Person*)malloc(sizeof(struct Person));

	// 방법3
	// ★ Indirect membership operator or structure pointer operator
	// ★ Pointer의 경우 dot(.) 대신 arror(->) operator 사용
	someone->age = 1001;

	// ★ someone에서 값으로 indirection 한 후
	//    dot operator로 접근할 수도 있음
	printf("%s %d\n", someone->name, (*someone).age);

	// -------------------------------------------
	// Structure declarations in a function
	// 함수 안에서도 구조체 선언 가능
	// 이 함수 안에서만 구조체 사용하고 영역 벗어나면 사용 불가

	struct book {
		char title[MAX];
		float price;
	};

	// -------------------------------------------
	// No tag

	/*
	★ tag없이 구조체 template 생성 뒤에
	structure variable을 직접 선언도 가능
	-> 일반적으로 많이 사용하는 방법

	잠깐 사용할 구조체이면 이렇게 쓰는 것도 좋음
	
	단점
	다른 변수 (apple3) 선언하고 싶으면
	또 구조체 template 새로 만들고 뒤에 변수명 넣어야 함
	ex)
	struct {
		char farm[MAX];
		float price;
	} apple3;
	*/
	struct {
		char farm[MAX];
		float price;
	} apple, apple2;

	strcpy(apple.farm, "Trade Joe");
	apple.price = 1.2f;
	
	strcpy(apple2.farm, "Safeway");
	apple2.price = 5.6f;

	// -------------------------------------------
	// typedef and structure
	// 구조체를 사용자가 정의한 새로운 자료형처럼 사용 가능

	// 방법1
	// struct person이라는 type을 my_person으로 선언
	// ★ 이후에는 my_person이라는 자료형이 있는 것처럼
	//    int, float, double처럼 사용 가능
	typedef struct person my_person;
	my_person p3;

	// 방법2
	// ★ 보통은 이렇게 구조체랑 같은 이름으로 많이 사용함
	typedef struct person person;
	person p4;

	// 방법3
	// ★ 구조체를 선언할 때 아예 typedef 사용
	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f4;

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
