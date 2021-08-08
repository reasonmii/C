#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
	char   bank_name[FUNDLEN];
	double bank_saving;
	char   fund_name[FUNDLEN];
	double fund_invest;
};

/*
★ 변수 대입 함수를 포인터 대입 함수로 바꾸기
double sum(double x, double y); -> double sum(double* x, double* y);
1) sum부분 우클릭 - Quick Actions and Refactorings - Change Signature
2) x부분 클릭 - Modify - double -> double*
   y부분 클릭 - Modify - double -> double*
3) Apply
*/
// double sum(double* x, double* y);

/*
★ 구조체를 함수에 대입 : call by value
- 코드를 더 간단하게 구현 가능
- 단점
  구조체의 값을 복사해서 다른 메모리에 사본을 저장하고
  함수에 넣는 방식이기 때문에
  데이터 양이 많은 경우, 사본 만드는데 시간도 오래 걸리고,
  '원본 + 사본'으로 메모리도 너무 차지함
*/
// double sum(struct fortune my_fortune);

/*
★ 구조체를 함수에 포인터로 대입
- 보통 가장 많이 사용하는 방법
- 메모리를 많이 차지하거나 프로그램이 느려지는 것 방지
*/
double sum(struct fortune *my_fortune);

int main() {

	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	// Total : $12576.21.
	printf("Total : $%.2f.\n",

		// ★ 포인터 함수인 경우 수정 필요
		// sum(&y_fortune.bank_saving, my_fortune.fund_invest) ->
		// sum(&my_fortune.bank_saving, &my_fortune.fund_invest)

		// ★ 구조체를 함수에 대입
		// sum(my_fortune)

		// ★ 구조체를 함수에 포인터로 대입
		sum(&my_fortune)
	);

	return 0;
}

// ★ const 사용 : x와 y값을 함부로 바꾸는 실수 방지
/*double sum(const double* x, const double* y) {
	// ★ 포인터 함수인 경우 수정 필요
	// x + y ->
	return *x + *y;
}*/

// ★ 구조체를 아예 함수에 대입
/*double sum(struct fortune my_fortune) {
	return my_fortune.bank_saving + my_fortune.fund_invest;
}*/

// ★ 구조체를 함수에 포인터로 대입
//    const : 값을 바꾸면 안 되는 경우 -> 경우에 따라 알맞게 사용할 것
double sum(const struct fortune *my_fortune) {
	return my_fortune->bank_saving + my_fortune->fund_invest;
}

// ======================================================================
/*
Input your first name:
>>lolly-polly
Input your last name:
>>grace
Hi, lolly-polly grace. Your name has 16 characters.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main() {

	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, "\n");      // look for newline
		if (find)                      // if the address is not null
			*find = '\0';              // place a null character there
		else                           // if the address is null = no newline
			while (getchar() != '\n')  // dispose of rest of line
				continue;
	}
	return ret_val;
}

// ★ 여기서는 const struct 이렇게 대입하면 안 됨
//    first, last, num 등의 값을 바꿔야 하기 때문
void receive_input(struct name_count* ptr_nc) {

	int flag;

	printf("Input your first name:\n>>");

	// s_gets(ptr_nc->first, NLEN);	
	// ★ scanf로 줄바꿈 전까지 사용자가 입력한 글자 받는 방법
	// ★ [^\n] : 줄바꿈이 나타날 때까지 문자열 입력받기
	// ★ *c : c를 하나 무시해라 = 줄바꿈 기호를 무시해라
	// ^ : cap operator
	flag = scanf("%[^\n]%*c", ptr_nc->first);
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>>");
	
	// s_gets(ptr_nc->last, NLEN);
	flag = scanf("%[^\n]%*c", ptr_nc->last);
	if (flag != 1)
		printf("Wrong input");
}

void count_characters(struct name_count* ptr_nc) {
	ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);
}

void show_result(const struct name_count* ptr_nc) {
	printf("Hi, %s %s. Your name has %d characters.",
		ptr_nc->first, ptr_nc->last, ptr_nc->num);
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main() {

	struct name_count user_name;

	user_name = receive_input();
	user_name = count_characters(user_name);
	show_result(user_name);

	return 0;
}

char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, "\n");       // look for newline
		if (find)                      // if the address is not null
			*find = '\0';              // place a null character there
		else                           // if the address is null = no newline
			while (getchar() != '\n')  // dispose of rest of line
				continue;
	}
	return ret_val;
}

struct name_count receive_input() {
	struct name_count nc;
	int flag;

	printf("Input your first name:\n>>");
	s_gets(nc.first, NLEN);

	printf("Input your last name:\n>>");
	s_gets(nc.last, NLEN);

	return nc;
}

struct name_count count_characters(struct name_count nc) {
	nc.num = strlen(nc.first) + strlen(nc.last);
	return nc;
}

void show_result(const struct name_count nc) {
	printf("Hi, %s %s. Your name has %d characters.",
		nc.first, nc.last, nc.num);
}
