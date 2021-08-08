/*
구조체의 배열을 사용하는 함수
*/

/*
Books 1 : "The Great Gatsby" written by "F. Scott Fitzgerald"
Books 2 : "Hamlet" written by "William Shakespeare"
Books 3 : "The Odyssey" written by "Homer"
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SLEN 101

struct book {
	char name[SLEN];
	char author[SLEN];
};

// void print_books(const struct book *books, int n); // ★ 동적할당메모리
void print_books(const struct book books[], int n);

int main() {

  // 초기화 방법1) 직접 초기화
	// struct book my_books[3] = { { "The Great Gatsby", "F. Scott Fitzgerald" }, ...};
  
  // 초기화 방법2) Compound Literal
  // 보통 가장 많이 사용
	struct book my_books[3];
	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };	
	
  // 초기화 방법3) 동적할당메모리 사용
  /*
  struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
  
  // malloc이 실패해서 my_books가 그냥 NULL 포인터인 경우 -> 종료
  if (!my_books) {
		printf("Malloc Failed");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };
  */
  
	print_books(my_books, 3);

	return 0;
}

// void print_books(const struct book *books, int n) {  // ★ 동적할당메모리
void print_books(const struct book books[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Books %d : \"%s\" written by \"%s\"\n",
			i+1, books[i].name, books[i].author);
	}
}

