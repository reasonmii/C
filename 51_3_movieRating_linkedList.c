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
	struct movie* next;
};

// 이중포인터가 필요할 때 편리하게 사용하기 위해 선언
typedef struct movie* p_movie;

void read_file(p_movie* p_head);
unsigned int count_items(const p_movie head);
void write_file(p_movie head);
int input_int();
int input_menu();

void print_all(p_movie head);
void print_an_item(p_movie head);
void edit_an_item(p_movie head);
void add_an_item(p_movie* p_head);
void insert_an_item(p_movie* p_head);
void delete_an_item(p_movie* p_head);
void delete_all_items(p_movie* p_head);
void search_by_name(p_movie head);

int main() {

	p_movie head = NULL;

	read_file(&head);

	while (1) {

		printf("\n");

		int s = input_menu();

		switch (s) {
		case 1:
			print_all(head);
			break;
		case 2:
			print_an_item(head);
			break;
		case 3:
			edit_an_item(head);
			break;
		case 4:
			// item이 하나 추가가 되니, n_items 값 수정 필요
			// -> 주소를 입력해야 함
			add_an_item(&head);
			break;
		case 5:
			// item이 추가, n_items 값 수정 필요
			// -> 주소를 입력해야 함
			insert_an_item(&head);
			break;
		case 6:
			// item이 삭제, n_items 값 수정 필요
			// -> 주소를 입력해야 함
			delete_an_item(&head);
			break;
		case 7:
			delete_all_items(&head);
			break;
		case 8:
			write_file(head);
			break;
		case 9:
			search_by_name(head);
			break;
		case 10:
			printf("Good bye\n");
			delete_all_items(&head);
			return 0;
		default:
			printf("%d is not implemented.\n", s);
		}
	}

	// 프로그램 구조상 이 부분을 지나가지는 않음
	// delete_all_items(&head)

	return 0;
}

// p_movie* == movie**
void read_file(p_movie* p_head) {

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
	if (fscanf(file, "%d%*c", &num) != 1) {
		printf("ERROR: Wrong file format.");
		exit(1);
	}

	p_movie prev = *p_head;

	for (int n = 0; n < num; ++n) {

		p_movie new_movie = (p_movie)malloc(sizeof(struct movie));

		if (new_movie == NULL) {
			printf("ERROR: malloc failed.\n");
			exit(1);
		}

		new_movie->next = NULL;

		if (fscanf(file, "%[^\n]%*c", new_movie->title) != 1 ||
			fscanf(file, "%f%*c", &new_movie->rating) != 1) {
			printf("ERROR: Wrong file format.\n");
			exit(1);
		}

		if (prev == NULL) {
			*p_head = new_movie;
			prev = new_movie;
		}
		else {

			// Insert front
			/*p_movie temp = (*head)->next;
			(*head)->next = new_movie;
			new_movie->next = temp;*/

			// Add at the end
			prev->next = new_movie;
			prev = new_movie;
		}
	}

	fclose(file);
	printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const p_movie head) {
	
	unsigned int count = 0;
	p_movie pnode = head;     // set to start of list

	while (pnode != NULL) {
		count += 1;
		pnode = pnode->next;
	}
	return count;
}

void write_file(p_movie head) {

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

	int count = 0;
	fprintf(file, "%d\n", (int)count_items(head));

	// set to start of the list
	p_movie pnode = head;

	while (pnode != NULL) {
		fprintf(file, "%s\n", pnode->title);
		fprintf(file, "%.1f\n", pnode->rating);
		
		pnode = pnode->next;
		count++;
	}

	fclose(file);

	assert(count == (int)count_items(head));
	printf("%d items have been saved to the file.\n", count);
}

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

void print_all(p_movie head) {

	// set to start of the list
	p_movie pnode = head;

	int count = 0;
	while (pnode != NULL) {
		printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rating);
		pnode = pnode->next;
		count++;
	}
}

void print_an_item(p_movie head) {
	printf("Input an index of item to print.\n");
	int index = input_int();

	// set to start of the list
	p_movie pnode = head;

	int count = 0;

	while (pnode != NULL) {
		
		if (count == index) break;

		pnode = pnode->next;
		count++;
	}

	if (pnode != NULL)
		printf("%d : \"%s\", %.1f\n", index, pnode->title, pnode->rating);
	else
		printf("Invalid item.\n");
}

void edit_an_item(p_movie head) {
	printf("Input the index of item to edit.\n");
	int index = input_int();

	// set to start of the list
	p_movie pnode = head;

	int count = 0;

	while (pnode != NULL) {

		if (count == index) break;

		pnode = pnode->next;
		count++;
	}

	if (pnode != NULL) {

		printf("%d : \"%s\", %.1f\n", index, pnode->title, pnode->rating);

		printf("Input new title and press enter.\n");
		printf(">> ");
		int f = scanf("%[^\n]%*c", pnode->title);
		printf("Input new rating and press enter.\n");
		printf(">> ");
		f = scanf("%f%*c", &pnode->rating);

		printf("%d : \"%s\", %.1f\n", index, pnode->title, pnode->rating);
	}
	else
		printf("Invalid item.\n");
}

/*
Linked list는 공간이 부족해서 ERROR가 발생할 일이
없기 때문에 이와 관련된 조건문 필요 없음
*/
void add_an_item(p_movie* p_head) {

	printf("Input title and press enter.\n");
	printf(">> ");

	p_movie new_movie = (p_movie)malloc(sizeof(struct movie));
	if (new_movie == NULL) {
		printf("ERROR: malloc() failed.");
		exit(1);
	}
	new_movie->next = NULL;


	int f = scanf("%[^\n]%*c", new_movie->title);
	printf("Input rating and press enter.\n");
	printf(">> ");
	f = scanf("%f%*c", &new_movie->rating);

	int count = 0;
	p_movie pnode = *p_head;

	if (pnode == NULL)
		*p_head = new_movie;
	else {
		while (pnode->next != NULL) {
			pnode = pnode->next;
			count++;
		}
		pnode->next = new_movie;
		count++;
	}

	printf("%d : \"%s\", %.1f\n", count, new_movie->title, new_movie->rating);
}

void insert_an_item(p_movie* p_head) {

	printf("Input the index of item to insert.\n");
	int index = input_int();

	p_movie pnode = *p_head;
	p_movie prev = NULL;

	int count = 0;
	while (pnode != NULL) {

		if (count == index) break;

		prev = pnode;
		pnode = pnode->next;
		count++;
	}

	if (pnode == NULL) {
		printf("Wrong index\n");
		return;
	}

	p_movie new_movie = (p_movie)malloc(sizeof(struct movie));
	if (new_movie == NULL) {
		printf("ERROR: malloc() failed.");
		exit(1);
	}
	new_movie->next = NULL;

	printf("Input title and press enter.\n");
	printf(">> ");
	int f = scanf("%[^\n]%*c", new_movie->title);
	printf("Input rating and press enter.\n");
	printf(">> ");
	f = scanf("%f%*c", &new_movie->rating);

	printf("%d : \"%s\", %.1f\n", index, new_movie->title, new_movie->rating);

	// p_movie temp = pnode->next;
	if (prev == NULL)
		*p_head = new_movie;
	else
		prev->next = new_movie;
	new_movie->next = pnode;
}

void delete_an_item(p_movie* p_head) {

	printf("Input the index of item to delete.\n");
	int index = input_int();

	p_movie pnode = *p_head;
	p_movie prev = NULL;

	int count = 0;
	while (pnode != NULL) {
		if (count == index) break;

		prev = pnode;
		pnode = pnode->next;
		count++;
	}

	if (pnode == NULL) {
		printf("Wrong index\n");
		return;
	}

	if (prev == NULL)
		*p_head = pnode->next;
	else
		prev->next = pnode->next;
	free(pnode);
}

void delete_all_items(p_movie* p_head) {

	int count = 0;
	p_movie search = *p_head;

	if (search == NULL) {
		printf("Nothing to delete.\n");
		return;
	}

	p_movie temp = NULL;

	while (search != NULL) {
		printf("%s is deleted.\n", search->title);
		temp = search->next;
		free(search);
		search = temp;
		count++;
	}

	*p_head = NULL;
	printf("%d items deleted.\n", count);
}

void search_by_name(p_movie head) {

	printf("Input title to search and press enter.\n");
	printf(">> ");

	char title[TSIZE] = { 0, };
	if (scanf("%[^\n]%*c", title) != 1) {
		printf("Wrong input.\n");
		return;
	}

	p_movie pnode = head;

	int count = 0;
	while (pnode != NULL) {
		if (strcmp(pnode->title, title) == 0) break;
		pnode = pnode->next;
		count++;
	}

	if (pnode == NULL) {
		printf("No movie found : %s\n", title);
		return;
	}

	printf("%d : \"%s\", %.1f\n", count, pnode->title, pnode->rating);
}
