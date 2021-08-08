#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct names {
	char first[20];
	char last[20];
};

struct person {
	int id;
	// nested structure member
	struct names name;
};

struct person2 {
	int id;
	// ★ anonymous structure
	// 구조체 안에 구조체를 넣었는데,
	// 'names'라는 tag(이름) 없이 사용
	struct { char first[20]; char last[20]; };
};

int main() {

	struct person ted1 = { 123, {"Bill", "Gates"} };
	struct person ted2 = { 124, "Robert", "Hand"};

	puts(ted1.name.first);  // Bill
	puts(ted2.name.first);  // Robert

	struct person2 ted3 = { 125, {"Steve", "Wozniak"} };
	struct person2 ted4 = { 126, "Litte", "Princess" };

	// ★ 직접 접근해서 사용
	puts(ted3.first);       // Steve
	puts(ted4.first);       // Litte

	return 0;
}
