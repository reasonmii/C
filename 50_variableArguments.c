/*
Variable Arguments 가변인수
- 함수가 받아들일 수 있는 인수의 개수가 상황에 따라 달라지는 것
- 대표적인 예 : printf, scanf
  ex) int printf(char const* const _Format, ...);

1. Provide a function prototype using an ellipsis (...)
1) 말줄임표 ... 은 항상 맨 뒤에 와야 함
   void   vaf1(int n, ...);
2) 말줄임표 ... 앞에는 한 개 이상의 여러 parameter를 받을 수 있음
   int    vaf2(const char *s, int k, ...);
3) 말줄임표 뒤에 또 다른 것을 받을 수는 없음
   char   vaf3(char c1, ..., char c2);
   -> Not OK, ellipsis should be the last
4) 말줄임표 앞에 parameter가 무조건 있어야 함
   그 parameter를 기준으로 말줄임표에 들어오는 인수들의 주소를 체크할 수 있기 때문
   double vaf4(...);
   -> Not OK, no parameter

2. Create a va_list type variable in the function definition
3. Use a macro to initialize the variable to an argument list
4. Use a macro to access the argument list

※ 실무에서 직접 사용할 일이 없고 권장하지 않음
   - Debugging이 힘들어지기 때문
   보통 저수준 Level에서 운영체제, 프로그래밍 언어 만들 때 사용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdarg.h>   // Variable Arguments

double average(int, ...);
double average2(char* format_string, ...);

int main() {

	double a, b;

	a = average(3, 1.1, 2.2, 3.3);
	b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

	printf("%lf\n", a);   // 3개로 average 계산 : 2.200000
	printf("%lf\n", b);   // 6개로 average 계산 : 3.850000

	a = average(1, 1.1, 2.2, 3.3);
	b = average(3, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

	printf("%lf\n", a);   // 3개로 average 계산 : 1.100000
	printf("%lf\n", b);   // 6개로 average 계산 : 2.200000

	// -------------------------------------------
	// 첫 번째 parameter의 글자 수를 세어서
	// 그만큼의 글자만 사용해 계산

	a = average2("dd", 1.1, 2.2, 3.3);
	b = average2("ddd", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

	printf("%lf\n", a);   // 2개로 average 계산 : 1.650000
	printf("%lf\n", b);   // 3개로 average 계산 : 2.200000

	return 0;
}

double average(int num, ...) {

	// va_list 라는 type으로 ap 정의
	va_list ap;
	double sum = 0.0;
	int i;

	// va_start : macro
	// num : 말 줄임표 앞에 있는 가장 parameter를 대입
	va_start(ap, num);
	for (i = 0; i < num; i++)
		// ...에 들어오는 것들이 double type인 경우 
		// -> ★ type은 미리 정해져 있어야 함
		sum += va_arg(ap, double);
	va_end(ap);

	return sum / (double)num;

}

// format_string을 분석해서
// 말줄임표 부분에 들어올 argument들이 몇 개인지,
// 어떤 자료형인지 알아냄
double average2(char* format_string, ...) {
	
	int num = strlen(format_string);

	va_list ap;
	double sum = 0.0;
	int i;

	// va_start(ap, format_string);
	// format_string 다음부터가
	// ... 부분이라는 걸 알려주기 위함
	va_start(ap, format_string);
	for (i = 0; i < num; i++)
		sum += va_arg(ap, double);
	va_end(ap);

	return sum / (double)num;
}

