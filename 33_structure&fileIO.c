/*
구조체 파일 입출력 연습문제
- Text File 보다 Binary File 구현 방법이 훨씬 간단하고 효율적임
- 데이터의 양이 많고, 입출력 속도가 중요하고, 편리성이 중요할 땐
  Binary File 사용할 것
*/

// ======================================================================

/*
text File 구현

1) 파일 실행
   Books 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
   Books 2 : "Hamlet" written by "William Shakespeare"
   Books 3 : "The Odyssey" written by "Homer"

   Writing to a file.
   Done

   Press any key to read data from a file.

2) Console 창 닫지 말고 editor에서 파일명 우클릭
   - Open Containing Folder
   - books.txt 파일 생성되어 있음
     파일 열어서 제일 위 숫자 3을 4로 변경
     name, author 추가 후 닫기

3) 다시 Console 창에서 Enter 클릭
   -> 방금 추가한 name, author가 Books 4로 출력됨

   Books 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
   Books 2 : "Hamlet" written by "William Shakespeare"
   Books 3 : "The Odyssey" written by "Homer"
   Books 4 : "Chirstmas" written by "Merry"

   
※ binary file을 사용하는 경우 2번 과정 불가능
*/

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
// n : 몇 개를 출력할지
void write_books(const char* filename, const struct book* books, int n);

// 글을 읽는 방법
// 방법1) n값을 주소로 받고, 반환값으로 포인터 출력
//        n : 몇 개를 읽어 들일지
struct book* read_books(const char* filename, int* n);

// 방법2) 인수로 이중포인터를 받음
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main() {

	int temp;
	int n = 3;

	// 동적할당
	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

	if (!my_books) {
		printf("Malloc Failed");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	// 책 정보 출력
	print_books(my_books, n);

	printf("\nWriting to a file.\n");

	// books.txt 파일에 my_books의 정보 n개 저장 -> 현재 : 3개
	write_books("books.txt", my_books, n);
	// cf. binary file인 경우)
	// write_books("books.dat", my_books, n);

	// 동적할당했던 메모리 반환
	free(my_books);
	n = 0;
	printf("Done\n");

	// 다시 파일을 읽고 싶은 경우 아무 키나 누를 것
	printf("\nPress any key to read data from a file.\n\n");
	// ★ 키 누르기 전에 파일 열어서 일부분 수정, 내용 추가해보기
	temp = _getch();    // 아무 키나 받아들임

	// 방법1) 포인터를 받아서 읽기
	// 현재 책이 몇 개인지 읽고 n 주소값에 자동 입력됨
	my_books = read_books("books.txt", &n);

	// 방법2) 이중 포인터를 받아서 읽기
	// 방법1과 달리 반환값이 없음
	// 마치 parameter가 함수의 결과를 담아주는 변수인 것처럼 사용
	// read_books2("books.txt", &my_books, &n);
	// cf. binary file인 경우)
	// read_books2("books.dat", &my_books, &n);

	// 읽은 내용이 잘 들어왔는지 확인
	print_books(my_books, n);

	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n) {
	for (int i = 0; i < n; i++) {
		printf("Books %d : \"%s\" written by \"%s\"\n",
			i + 1, books[i].name, books[i].author);
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

	// ★ 책이 몇 개인지 읽음 -> 이렇게 읽은 값이 n에 저장됨
	// %*c : Remove the last '\n' - 마지막 줄바꿈 문자 삭제
	flag = fscanf(file, "%d%*c", n);
	if (flag != 1) {
		printf("File read failed");
		exit(1);
	}

	// ★ 책 내용을 읽어드릴 메모리 공간을 동적할당으로 받기
	// Note : calloc()
	struct book* books = (struct book*)calloc(sizeof(struct book), *n);

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i) {
		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2) {
			printf("File read failed");
			exit(1);
		}
	}

	fclose(file);

	// ★ void 이중 포인터의 경우 return books;가 아닌 아래 코드 필요
	// *books_dptr = books;
	// -> inderection에 books의 포인터 저장
	return books;
}

// ======================================================================
// ★ Binary File인 경우 훨씬 구현이 간단해짐 -> 추천

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

	// cf. binary file인 경우)
	write_books("books.dat", my_books, n);

	free(my_books);
	n = 0;
	printf("Done\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	// cf. binary file인 경우)
	read_books2("books.dat", &my_books, &n);

	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n) {
	for (int i = 0; i < n; i++) {
		printf("Books %d : \"%s\" written by \"%s\"\n",
			i + 1, books[i].name, books[i].author);
	}
}

void write_books(const char* filename, const struct book* books, int n) {

	FILE* file = fopen(filename, "w");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	// cf. binary file인 경우)
	fwrite(&n, sizeof(n), 1, file);   // number of books
	// binary file은 멤버를 하나하나 파일에 저장하지 않고
	// 메모리를 통째로 저장함
	fwrite(books, sizeof(struct book), n, file);

	fclose(file);
}

void read_books2(const char* filename, struct book** books_dptr, int* n) {

	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		fputs("Can't open file.", stderr);
		exit(1);
	}

	// cf. binary file인 경우)
	fread(n, sizeof(*n), 1, file);

	struct book* books = (struct book*)calloc(sizeof(struct book), *n);

	if (!books) {
		printf("Malloc() failed.");
		exit(1);
	}

	// cf. binary file인 경우)
	// 읽을 때 하나하나 읽지 않고
	// sizeof(struct book)이 *n 개수만큼 있다고
	// 한 번에 읽어드림
	fread(books, sizeof(struct book), *n, file);

	fclose(file);

	*books_dptr = books;
}
