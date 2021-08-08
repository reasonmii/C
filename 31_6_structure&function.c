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
//    const : 값을 바꾸면 안 되는 경우
double sum(const struct fortune *my_fortune) {
	return my_fortune->bank_saving + my_fortune->fund_invest;
}

// ======================================================================

