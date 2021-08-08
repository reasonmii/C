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
