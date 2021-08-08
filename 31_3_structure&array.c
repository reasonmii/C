#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3

// 문자열을 입력받는 함수
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	// ★ scanf() 사용 불가
	// 책 이름 같은 거 입력할 때 중간에 빈칸이 있기 때문
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');        // look for new line
		if (find)                       // if the address is not NULL
			*find = '\0';           // place a null character there
		else
			while (getchar() != '\n')   // dispose of rest of line
				continue;
	}
	return ret_val;
}

struct book {
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

int main() {

	// ★ array of book structures
	// struct book library[MAX_BOOKS]
	struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, };  // 초기화
	int count = 0;

	while(1)
	{
		printf("Input a book title or press [Enter] to stop.\n>>");
		if (s_gets(library[count].title, MAX_TITLE) == NULL) break;
		// ★ title 첫 글자가 null character인 경우
		if (library[count].title[0] == '\0') break;
				
		printf("Input the author.\n>>");
		s_gets(library[count].author, MAX_AUTHOR);
		
		printf("Input the price.\n>>");
		int flag = scanf("%f", &library[count].price);

		// clear input line
 		// ※ 여러 문자를 입력했을 때
		// 같은 줄에 있는 첫 글자 외 모든 글자 무시       
		while (getchar() != '\n')
			continue;

		count++;

		if (count == MAX_BOOKS) {
			printf("No more books.\n");
			break;
		}
	}

	if (count > 0) {
		printf("\nThe list of books:\n");
		for (int index = 0; index < count; index++)
			printf("\"%s\" written by %s: $%.1f\n",
				library[index].title, library[index].author, library[index].price);
	}
	else
		printf("No books to show.\n");

	return 0;
}
