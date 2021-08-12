// 표준 Utility Library
// rankd(), srand(), malloc(), free(), qsort() 등

#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>   // utility library

void goodbye(void) {
	printf("Goodbye\n");
}

void thankyou(void) {
	printf("Thankyou\n");
}

int main() {

	/*
	★ atexit(function)
	프로그램이 종료될 때 해당 함수 호출
  - 함수 포인터의 목록을 가지고 있음
  - runtime에 user가 입력한 결과 저장

	result
	Purchased?
	y
	Goodbye message?
	y
	Goodbye
	Thankyou
	*/ 
	printf("Purchased?\n");
	if (getchar() == 'y')
		atexit(thankyou);

	while (getchar() != '\n') {};

	printf("Goodbye message?\n");
	if (getchar() == 'y')
		atexit(goodbye);

	return 0;
}

// ======================================================================
/*
exit(0);
debugging, 문제 확인 할 때 많이 사용
주로 C++에서 사용

Visual Studio에서 지원하지 않음
Online Compiler 사용하기
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdnoreturn.h>

/*
_Noreturn Function Specifier
- 이 함수가 끝나고 어떤 또 다른 프로그램 실행으로
  돌아가지 않는다는 것 명시
- 여기서 프로그램이 끝난다는 의미

causes undefined behavior if i <= 0
exits if i > 0
*/
_Noreturn void stop_now(int i) {
    if (i > 0) exit(i);
}

/*
실행결과 warning 발생
- 'noreturn' function does return
- 프로그램이 진행되는 흐름으로
  돌아가지 않고 바로 끝나야 하는데,
  조건에 따르면 i가 0일 경우에는 exit(0)을 통해
  원래 프로그램으로 돌아갈 수도 있기 때문
*/
int main(void) {
    puts("Preparing to stop...");
    stop_now(2);
    puts("This code is never executed");
}
