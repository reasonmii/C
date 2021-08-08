// 구조체와 동적 할당 메모리 & 포인터

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // strlen(), strcmp()
#include <stdlib.h>  // malloc(), free()

#define SLEN 81

struct namect {
	char* fname;  // use malloc()
	char* lname;  // use malloc()
	int letters;
};

void getinfo(struct namect*);        // allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);        // free memory when done
char* s_gets(char* st, int n);

int main() {

	/*
	★ Dangerous Usage
	namect는 문자열을 가리키는 "포인터"를 저장하는 구조체
	즉, 입력하는 문자열이 저장된 첫 주소를 저장함
	- p.fname = "Do-Re"의 첫 주소
	- p.lname = "Mi"의 첫 주소
	그런데, 이러한 문자열은 프로그램과 함께 text segment에 저장됨
	text segment란?
	- read only 영역 (읽기만 가능)
	- 해당 주소를 활용해서 메모리 공간에 저장된 값을 바꿀 수 없음
	
	struct namect p = { "Do-Re", "Mi" };
	printf("%s %s\n", p.fname, p.lname);

	즉 이렇게 코딩한 경우
	아래와 같이 새로 값을 입력받아서 바꾸려고 하면 ERROR 발생
	int f1 = scanf("%[^\n]%*c", p.lname);
	printf("%s %s\n", p.lname, p.fname);

	-> ★ Recommended Usage : malloc 사용
	*/

	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, "\n");
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void getinfo(struct namect* nc) {

	int flag;
	char buffer[SLEN] = { 0, };           // 임시 데이터 저장 공간 생성

	printf("Please enter your first name.\n");
	// s_gets(nc->fname, SLEN);
	flag = scanf("%[^\n]%*c", buffer);  // 입력 받아서 임시 공간에 저장
	if (flag != 1)
		printf("Wrong input");          // receive input again
	else {
		// ★ 포인터 값 저장
		// ★ 동적할당 : 입력 받은 문자 길이 + null character 저장할 공간
		// ★ 이때 malloc에서 sizeof(char)을 곱할 필요 없음
		//    sizeof(char)은 어차피 1byte이기 때문
		nc->fname = (char*)malloc(strlen(buffer) + 1);

		if (nc->fname != NULL)
			strcpy(nc->fname, buffer);  // copy
		else
			printf("Malloc() FAILED");
	}

	printf("Please enter  your last name.\n");
	// s_gets(nc->lname, SLEN);
	flag = scanf("%[^\n]%*c", buffer);
	if (flag != 1)
		printf("Wrong input");
	else {
		nc->lname = (char*)malloc(strlen(buffer) + 1);

		if (nc->lname != NULL)
			strcpy(nc->lname, buffer);
		else
			printf("Malloc() FAILED");
	}
}

void makeinfo(struct namect* nc) {
	nc->letters = strlen(nc->fname) + strlen(nc->lname);
}

void cleanup(struct namect* nc) {
	free(nc->fname);
	free(nc->lname);
}

void showinfo(const struct namect* nc) {
	printf("%s %s. your name contains %d letters", nc->fname, nc->lname, nc->letters);
}
