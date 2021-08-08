// 구조체 파일 입출력 연습문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SLEN 101

struct book {
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);

// 글을 읽는 방법
// 방법1) n값을 주소로 받고, 반환값으로 포인터 출력
struct book* read_books(const char* filename, int* n);

// 방법2) 인수로 이중포인터를 받음
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main() {

	int temp;
	int n = 3;

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

	if (!my_books) {
		printf("Malloc Failed");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, n);

	printf("\nWriting to a file.\n");

	// books.txt 파일에 my_books의 정보 n개 저장
	write_books("books.txt", my_books, n);

	// 동적할당했던 메모리 반환
	free(my_books);
	n = 0;
	printf("Done\n");

	// 파일 열어서 일부분 수정, 내용 추가해보기

	// 다시 파일을 읽고 싶은 경우 아무 키나 누를 것
	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();    // 아무 키나 받아들임

	// 방법1) 포인터를 받아서 읽기
	my_books = read_books("books.txt", &n);

	// 방법2) 이중 포인터를 받아서 읽기
	// read_books2("books.txt", &my_books, &n);

	// 읽은 내용이 잘 들어왔는지 확인
	print_books(my_books, n);

	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n) {
	for (int i = 0; i < n; i++) {
		printf("Books %d : \"%s\" written by \"%s\"\n",
			i+1, books[i].name, books[i].author);
	}
}

void write_books(const char* filename, const struct book* books, int n) {
	
	FILE* file = fopen(filename, "w");

	// Open a text file for writing
	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	// number of books
	// 책이 몇 권인지 출력
	fprintf(file, "%d\n", n);

	for (int i = 0; i < n; ++i)
		fprintf(file, "%s\n%s\n", books[i].name, books[i].author);

	fclose(file);
}

// ★ void 이중 포인터인 경우 모든 코드 동일한데 마지막 return 부분만 다름
// void read_books2(const char* filename, struct book** books_dptr, int* n) {
struct book* read_books(const char* filename, int* n) {

	FILE* file = fopen(filename, "r");

	// Open a text file for reading
	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	int flag;

	// 책이 몇 개인지 확인
	// %*c : Remove the last '\n'
	flag = fscanf(file, "%d%*c", n);
	if (flag != 1) {
		printf("File read failed");
		exit(1);
	}

	// ★ 책 내용을 읽어드릴 메모리 공간을 동적할당으로 받기
	struct book* books = (struct book*)calloc(sizeof(struct book), *n);

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i) {
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2) {
			printf("File read failed");
			exit(1)
		}
	}

	fclose(file);

	// ★ void 이중 포인터의 경우 return이 아닌 아래 코드 필요
	// inderection에 books의 포인터 저장
	// *books_dptr = books;
	return books;
}
