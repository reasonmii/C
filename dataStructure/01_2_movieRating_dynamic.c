#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <assert.h>

#define TSIZE 45

struct movie {
	char title[TSIZE];
	float rating;
};

void read_file(struct movie movie_list[], int* prt_n_items);
void write_file(struct movie movie_list[], int n_items);

int input_int();
int input_menu();

void print_all(struct movie movie_list[], int n_items);
void print_an_item(struct movie movie_list[], int n_items);
void edit_an_item(struct movie movie_list[], int n_items);
void add_an_item(struct movie movie_list[], int* ptr_n_items);
void insert_an_item(struct movie movie_list[], int* ptr_n_items);
void delete_an_item(struct movie movie_list[], int* ptr_n_items);
void search_by_name(struct movie movie_list[], int n_items);

int main() {

	struct movie* movie_list = NULL;

	size_t n_items = 0;

	// movie_list의 주소 사용 -> 이중포인터
	read_file(&movie_list, &n_items);

	while (1) {

		printf("\n");

		int s = input_menu();

		switch (s) {
		case 1:
			print_all(movie_list, n_items);
			break;
		case 2:
			print_an_item(movie_list, n_items);
			break;
		case 3:
			edit_an_item(movie_list, n_items);
			break;
		case 4:
			// item이 하나 추가가 되니, n_items 값 수정 필요
			// -> 주소를 입력해야 함
			add_an_item(&movie_list, &n_items);
			break;
		case 5:
			// item이 추가, n_items 값 수정 필요
			// -> 주소를 입력해야 함
			insert_an_item(&movie_list, &n_items);
			break;
		case 6:
			// item이 삭제, n_items 값 수정 필요
			// -> 주소를 입력해야 함
			delete_an_item(movie_list, &n_items);
			break;
		case 7:
			n_items = 0;
			break;
		case 8:
			write_file(movie_list, n_items);
			break;
		case 9:
			search_by_name(movie_list, n_items);
			break;
		case 10:
			printf("Good bye\n");
			// 메모리 지우기
			// 밖에서 지우는데도 여기서 중복으로 지우는 이유
			// 프로그램의 확장성을 고려하는 것
			// 나중에 수정이 있더라도 안전하게 작동
			free(movie_list);
			n_items = 0;
			exit(0);
		default:
			printf("%d is not implemented.\n", s);
		}
	}

	free(movie_list);
	n_items = 0;

	return 0;
}

// **ptr_movie_list : 이중포인터 사용
void read_file(struct movie **ptr_movie_list, int* ptr_n_items) {

	// filename을 문자의 배열로 받아옴
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

	// 파일 맨 처음 정수 하나 읽기
	int num;
	if (fscanf(file, "%d%*c", &num) != 1) {
		printf("ERROR: Wrong file format.");
		exit(1);
	}

	// 동적할당으로 메모리 할당 받음
	*ptr_movie_list = (struct movie*)malloc(sizeof(struct movie) * num);
	if (*ptr_movie_list == NULL) {
		printf("Malloc failed.\n");
		exit(1);
	}

	for (int n = 0; n < num; ++n) {
		if (fscanf(file, "%[^\n]%*c", (*ptr_movie_list)[*ptr_n_items].title) != 1 ||
			fscanf(file, "%f%*c", &(*ptr_movie_list)[*ptr_n_items].rating) != 1)
		{
			printf("ERROR: Wrong file format.\n");
			exit(1);
		}

		*ptr_n_items += 1;
	}

	// 당연히 두 개가 같을 수밖에 없음
	assert(*ptr_n_items == num);

	fclose(file);
	printf("%d items have been read from the file.\n", *ptr_n_items);

}

void write_file(struct movie movie_list[], int n_items) {

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

	fprintf(file, "%d\n", n_items);
	for (int n = 0; n < n_items; ++n) {
		fprintf(file, "%s\n", movie_list[n].title);
		fprintf(file, "%s\n", movie_list[n].rating);
	}

	fclose(file);
	printf("%d items have been saved to the file.\n", n_items);
}

// ★ 사용자로부터 정수 입력 받아야 하는 경우
// 정수를 입력할 때까지 계속 입력 받음
// -> 자주 사용하는 함수
int input_int() {

	int input;
	while (1) {
		printf(">> ");
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

void print_all(struct movie movie_list[], int n_items) {
	for (int n = 0; n < n_items; ++n)
		printf("%d : \"%s\", %.1f\n", n, movie_list[n].title, movie_list[n].rating);
}

void print_an_item(struct movie movie_list[], int n_items) {
	printf("Input an index of item to print.\n");
	int index = input_int();
	if (index < n_items)
		printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
	else
		printf("Invalid item.\n");
}

void edit_an_item(struct movie movie_list[], int n_items) {
	printf("Input the index of item to edit.\n");
	int index = input_int();
	if (index < n_items) {

		printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);

		printf("Input new title and press enter.\n");
		printf(">> ");
		int f = scanf("%[^\n]%*c", movie_list[index].title);
		printf("Input new rating and press enter.\n");
		printf(">> ");
		f = scanf("%f%*c", &movie_list[index].rating);

		printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
	}
	else
		printf("Invalid item.\n");
}

// n_items is a pointer
void add_an_item(struct movie **ptr_movie_list, int* ptr_n_items) {

	// Resizing allocated memory
	struct movie* temp = *ptr_movie_list;
	*ptr_movie_list = malloc(sizeof(struct movie) * (*ptr_n_items + 1));
	if (*ptr_movie_list == NULL) {
		printf("malloc() failed.\n");
		exit(1);
	}
	// 새로운 메모리에 기존의 데이터를 모두 복사
	memcpy(*ptr_movie_list, temp, sizeof(struct movie) * *ptr_n_items);
	free(temp);

	const int index = *ptr_n_items;

	printf("Input title and press enter.\n");
	printf(">> ");
	int f = scanf("%[^\n]%*c", (*ptr_movie_list)[index].title);
	printf("Input rating and press enter.\n");
	printf(">> ");
	f = scanf("%f%*c", &(*ptr_movie_list)[index].rating);

	printf("%d : \"%s\", %.1f\n", index, (*ptr_movie_list)[index].title, (*ptr_movie_list)[index].rating);

	*ptr_n_items += 1;
}

void insert_an_item(struct movie **ptr_movie_list, int* ptr_n_items) {

	// Resizing allocated memory
	struct movie* temp = *ptr_movie_list;
	*ptr_movie_list = (struct movie*)malloc(sizeof(struct movie) * ((size_t)(*ptr_n_items) + 1));
	if (*ptr_movie_list == NULL) {
		printf("malloc() failed.\n");
		exit(1);
	}
	memcpy(*ptr_movie_list, temp, sizeof(struct movie) * *ptr_n_items);
	free(temp);

	printf("Input the index of item to insert.\n");
	int index = input_int();

	memmove(&(*ptr_movie_list)[index + 1], &(*ptr_movie_list)[index],
		sizeof(struct movie) * (*ptr_n_items - index));

	printf("Input title and press enter.\n");
	printf(">> ");
	int f = scanf("%[^\n]%*c", (*ptr_movie_list)[index].title);
	printf("Input rating and press enter.\n");
	printf(">> ");
	f = scanf("%f%*c", &(*ptr_movie_list)[index].rating);

	printf("%d : \"%s\", %.1f\n", index, (*ptr_movie_list)[index].title, (*ptr_movie_list)[index].rating);

	*ptr_n_items += 1;
}

void delete_an_item(struct movie * movie_list, int* ptr_n_items) {
	
	printf("Input the index of item to delete.\n");
	int index = input_int();

	/*memmove(&movie_list[index + 1], &movie_list[index],
		sizeof(struct movie) * (*ptr_n_items - index));*/

	// For loop implementation
	for (int i = index; i < *ptr_n_items; i++) {
		strcpy(movie_list[i].title, movie_list[i + 1].title);
		movie_list[i].rating = movie_list[i + 1].rating;
	}

	*ptr_n_items -= 1;
}

void search_by_name(struct movie movie_list[], int n_items) {

	printf("Input title to search and press enter.\n");
	printf(">> ");

	char title[TSIZE] = { 0, };
	if (scanf("%[^\n]%*c", title) != 1) {
		printf("Wrong input.\n");
		return;
	}

	int index = 0;
	for (; index < n_items; ++index) {
		if (strcmp(movie_list[index].title, title) == 0)
			break;
	}

	if (index == n_items)
		printf("No movie found : %s\n", title);
	else
		printf("%d : \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
}
