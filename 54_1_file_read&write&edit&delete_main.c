/*
1) SimpleList.h
- C언어로 작성된 인터페이스
- 자료형
- 함수들의 프로토타입

2) main.c
- SimpleList 자료 구조를 사용하는 프로그램

3) SimpleList.cpp
- 실제 기능 (function) 구현

4) another.c
- SimpleList 자료 구조를 사용하는 또 다른 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS

#include "SimpleList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <assert.h>

void read_file(List* plist);
unsigned int count_items(const List* const plist);
void write_an_item(FILE* const file, const Item item);
void write_file(const List* const plist);
int input_int();
int input_menu();
void print_all(const List* plist);
void print_an_item(Item item);
void find_and_print_an_item(const List* const plist);
void edit_an_item(List* plist);
void add_an_item(List* plist);
void insert_an_item(List* plist);
void delete_an_item(List* plist);
void delete_all_items(List* plist);
bool compare_items(Item a, Item b);
void search_by_name(const List* plist);

int main() {

	List movie_list;

	InitializeList(&movie_list);

	read_file(&movie_list);

	while (1) {

		printf("\n");

		int s = input_menu();

		switch (s) {
		case 1:
			print_all(&movie_list);
			break;
		case 2:
			find_and_print_an_item(&movie_list);
			break;
		case 3:
			edit_an_item(&movie_list);
			break;
		case 4:
			add_an_item(& movie_list);
			break;
		case 5:
			insert_an_item(& movie_list);
			break;
		case 6:
			delete_an_item(&movie_list);
			break;
		case 7:
			delete_all_items(&movie_list);
			break;
		case 8:
			write_file(&movie_list);
			break;
		case 9:
			search_by_name(&movie_list);
			break;
		case 10:
			printf("Good bye\n");
			delete_all_items(&movie_list);
			exit(0);
		default:
			printf("%d is not implemented.\n", s);
		}
	}

	return 0;
}

// p_movie* == movie**
void read_file(List* plist) {

	char filename[TSIZE] = { 0, };

	printf("Please input filename to read and press Enter.\n");
	printf(">> ");

	if (scanf("%[^\n]%*c", filename) != 1) {
		printf("Wrong input. Terminating.\n");
		exit(1);
	}

	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		printf("ERROR: Cannot open file.\n");
		exit(1);
	}

	int num;
	// %d%*c : 파일을 열면 제일 먼저 나오는 숫자 값만 &num에 저장하고 이후 글자는 모두 무시
	if (fscanf(file, "%d%*c", &num) != 1) {
		printf("ERROR: Wrong file format.");
		exit(1);
	}

	for (int n = 0; n < num; ++n) {

		Item new_item;

		if (fscanf(file, "%[^\n]%*c", new_item.title) != 1 ||
			fscanf(file, "%f%*c", &new_item.rating) != 1) {
			printf("ERROR: Wrong file format.\n");
			exit(1);
		}

		AddItem(new_item, plist);
	}

	fclose(file);
	printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const List *const plist) {
	return CountItems(plist);
}

/*
Write file을 할 때 SimpleList로 일반화 된 것을 쓰기 어려움
만들고 싶은 자료에 따라 입력해야 하는 정보가 다르기 때문
ex) 학생들의 성적, 영화 평점, 책 리뷰

-> 해결방법
1) main.c 파일에 write_an_item 이라는 함수를 따로 생성
2) SimpleList.c 파일에는 WriteAllItems 함수 생성
3) main.c 파일의 write_file 함수에서 WriteAllItems 쓸 때
   main.c 파일의 write_an_item 함수 이용
*/

void write_an_item(FILE* const file, const Item item) {
	fprintf(file, "%s\n", item.title);
	fprintf(file, "%.1f\n", item.rating);
}

void write_file(const List * const plist) {

	char filename[TSIZE] = { 0, };
	printf("Please input filename to write and press Enter.\n");
	printf(">> ");

	if (scanf("%[^\n]%*c", filename) != 1) {
		printf("Wrong input. Terminating.\n");
		exit(1);
	}

	FILE* file = fopen(filename, "w");

	if (file == NULL) {
		printf("ERROR: Cannot open file.\n");
		exit(1);
	}

	unsigned int num = CountItems(plist);
	fprintf(file, "%d\n", num);

	// ★ main.c 파일의 write_an_item 함수 포인터 input
	// WriteAllItems : 추가 입력 후 총 개수를 return
	unsigned int count = WriteAllItems(plist, file, &write_an_item);

	assert(count == num);
	fclose(file);
	printf("%d items have been saved to the file.\n", count);
}

// 입력한 정수값 return
int input_int() {

	int input;
	while (1) {
		printf(">> ");
		// %d%*c : 정수 뒤에 여러 글자 입력해도 첫 정수 값만 받음
		if (scanf("%d%*c", &input) == 1) return input;
		else {
			printf("Please input an integer and press enter. Try again.\n");
			while (getchar() != '\n') continue;
		}
	}
}

int input_menu() {
	while (1) {

		printf("\nPlease select an option and press enter.\n");
		printf("1. Print all items        2. Print an item\n");
		printf("3. Edit an item           4. Add an item\n");
		printf("5. Insert an item         6. Delete an item\n");
		printf("7. Delete all items       8. Save file\n");
		printf("9. Search by name         10. Quit\n");

		int input = input_int();

		if (input >= 0 && input <= 10) return input;
		else
			printf("%d is invalid. Please try again.\n", input);
	}
}

/*
print_all 부분도 데이터 내용에 따라 다르게 다르게 출력해야 함
-> 개별 데이터에 맞게 main.c에서 print_an_item 함수 생성
   print_an_item 함수의 포인터를 인수로 받음
*/
void print_an_item(Item item) {
	printf("\"%s\", %.1f\n", item.title, item.rating);
}

void print_all(const List* plist) {
	PrintAllItems(plist, print_an_item);
}

/*
Note : We defined this function as 'print_an_item'
       in the previous lecture, but we'll rename it
위에서 print_an_item 함수가 다른 기능을 하는 함수로 바꼈기 때문에
기존의 print_an_item 함수 역할을 했던 함수 이름 변경
*/
void find_and_print_an_item(const List* const plist) {
	printf("Input the index of item to print.\n");
	int index = input_int();

	Item* pitem;
	const flag = FindItemByIndex(plist, index, &pitem);

	if (flag == true) {
		printf("%d : ", index);
		print_an_item(*pitem);
	}
	else
		printf("Invalid item.\n");
}

void edit_an_item(List* plist) {
	printf("Input the index of item to edit.\n");
	int index = input_int();

	Item* pitem;
	const bool flag = FindItemByIndex(plist, index, &pitem);

	if (flag == true) {

		printf("%d : ", index);
		print_an_item(*pitem);

		Item new_item;
		printf("Input new title and press enter.\n");
		printf(">> ");
		int f = scanf("%[^\n]%*c", new_item.title);    // 줄바꿈 전까지 글자 받음
		printf("Input new rating and press enter.\n");
		printf(">> ");
		f = scanf("%f%*c", &new_item.rating);          // 앞부분 float만 받고 뒤에 글자 써도 모두 무시

		*pitem = new_item;

		printf("%d : ", index);
		print_an_item(*pitem);
	}
	else
		printf("Invalid item.\n");
}

void add_an_item(List* plist) {

	printf("Input title and press enter.\n");
	printf(">> ");

	Item new_item;

	int f = scanf("%[^\n]%*c", new_item.title);  // f = 1
	printf("Input rating and press enter.\n");
	printf(">> ");
	f = scanf("%f%*c", &new_item.rating);        // f = 1

	// 왼쪽 값을 오른쪽 plist 마지막에 추가
	AddItem(new_item, plist);

	printf("%d : \"%s\", %.1f\n", CountItems(plist) - 1, new_item.title, new_item.rating);
}

void insert_an_item(List* plist) {

	printf("Input the index of item to insert.\n");
	int index = input_int();

	Item* pitem;  // Not actually used
	const bool flag = FindItemByIndex(plist, index, &pitem);

	if (flag == false) {
		printf("Wrong index\n");
		return;
	}

	Item new_item;

	printf("Input title and press enter.\n");
	printf(">> ");
	int f = scanf("%[^\n]%*c", new_item.title);
	printf("Input rating and press enter.\n");
	printf(">> ");
	f = scanf("%f%*c", &new_item.rating);

	printf("%d : \"%s\", %.1f\n", index, new_item.title, new_item.rating);

	InsertbyIndex(new_item, plist, index);
}

void delete_an_item(List* plist) {

	printf("Input the index of item to delete.\n");
	int index = input_int();

	Item* pitem;  // Not actually used
	const bool flag = FindItemByIndex(plist, index, &pitem);

	if (flag == false) {
		printf("Wrong index\n");
		return;
	}

	RemoveByIndex(plist, index);
}

void delete_all_items(List* plist) {
	ClearList(plist);
}

// 프로그래머가 이 프로그램에서는 제목만 같으면 같다고 하는 것으로 정의함
bool compare_items(Item a, Item b) {
	if (strcmp(a.title, b.title) == 0)  // Note: compare titles only
		return true;
	else
		return false;
}

void search_by_name(const List* plist) {

	printf("Input title to search and press enter.\n");
	printf(">> ");

	Item item_to_find;
	char title[TSIZE] = { 0, };

	if (scanf("%[^\n]%*c", item_to_find.title) != 1) {  // input title
		printf("Wrong input.\n");
		return;
	}

	Item item_found;
	int index;
	// 어떤 아이템을 찾는데, 그 기준은 이름이 같은 것을 찾는 것 : compare_items
	if (Find(plist, item_to_find, &index, &item_found, compare_items) == false) {
		printf("No movie found : %s\n", item_to_find.title);
		return;
	}
	else
		printf("%d : \"%s\", %.1f\n", index, item_found.title, item_found.rating);
}

