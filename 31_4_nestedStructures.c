/*
Nested Structure 중첩 구조체
구조체를 다른 구조체의 멤버로 사용하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names {
	char given[LEN];   // first name
	char family[LEN];  // last name
};

struct reservation {
	struct names guest;  // nested structure
	struct names host;   // nested structure
	char place[LEN];
	char food[LEN];

	// time
	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main() {

	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"The Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	// ★ format string이 너무 긴 경우 분리 가능
	const char* formatted =
		"\Dear %s %s, \nI would like to serve you %s.\n\
Please visit%s on %d/%d/%d at %d:%d.\n\
Sincerely,\n%s %s";

	printf(formatted, res.guest.given, res.guest.family, res.food,
		res.place, res.day, res.month, res.year, res.hours, res.minutes,
		res.host.given, res.host.family);

	/*
	printf("Dear %s %s,\n", res.guest.given, res.guest.family);
	printf("I would like to serve you %s.\n", res.food);
	printf("Please visit %s on %d/%d/%d at %d:%d.\n",
		res.place, res.day, res.month, res.year, res.hours, res.minutes);
	printf("Sincerely,\n%s %s", res.host.given, res.host.family);
	*/

	return 0;
}
