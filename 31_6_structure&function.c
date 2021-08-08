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

/*★ 변수 대입 함수를 포인터 대입 함수로 바꾸기
double sum(double x, double y); -> double sum(double* x, double* y);
1) sum부분 우클릭 - Quick Actions and Refactorings - Change Signature
2) x부분 클릭 - Modify - double -> double*
   y부분 클릭 - Modify - double -> double*
3) Apply
*/
// double sum(double* x, double* y);

// ★ 코드를 더 간단하게 하는 방법 : 구조체를 아예 함수에 대입
double sum(struct fortune my_fortune);

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

		// 더 간단하게 쓰는 방법
		sum(my_fortune)
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
double sum(struct fortune my_fortune) {
	return my_fortune.bank_saving + my_fortune.fund_invest;
}
