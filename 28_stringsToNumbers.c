/*
● String to Numbers
int atoi(const char *str); : str을 int형으로 변환
long atoi(const char *str); : str을 long형으로 변환
double atof(const char *str); : str을 double형으로 

strtod()
string to unsinged double 
It converts base 10 only (similar to atoi)

strtol(string, pointer, number) : string to long
strtoul(string, pointer, number) : string to unsinged long
- string에서 한 글자 한 글자 숫자로 변환하다가
	변환할 수 없는 부분을 만나면 그 포인터 값을 pointer 변수에 대입
- number: n진수 ex) 10진수, 16진수
  base로 10진수 외 여러 가지 사용 가능

● Numbers to Strings
sprintf(String Array, base, number)
_itoa(number, String Array, base)
- number를 base진수로 바꿔서 해당 문자열 출력
- ★ Use sprintf() instead of itoa(), ftoa()
  실무에서는 대부분 sprintf() 사용
*/

// ======================================================================

/*
Solution Explorer 창 프로젝트 우클릭 - Properties - Debugging
Command Arguments 부분에 변수 입력
파일 실행
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	if (argc < 3)
		printf("Wrong Usage of %s\n", argv[0]);
	else {

		// 숫자를 문자로 입력 받고 이를 다시 정수로 바꿈
		int times = atoi(argv[1]);
		// atof(), atol()

		// input : 3 hello
		// output : hello hello hello
		for (int i = 0; i < times; i++)
			puts(argv[2]);

		// input : 10 21
		// output : 31
		printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));

	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	char str1[] = "1024Hello";
	char* end;

	// "1024Hello"를 10진수 숫자로 변환하다가 H의 포인터를 &end에 대입
  // number : n진수 base
	long l = strtol(str1, &end, 10);
  // unsigned long l = strtoul(str1, &end, 10);

	// 1024Hello 1024 Hello 72
	// end가 포인터니까 string처럼 end포인터에서부터 끝부분이 출력됨
	// (int)*end : 'H'의 ASCII code 출력 (72)
	printf("%s %ld %s %d\n", str1, l, end, (int)*end);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	// 10FFHello 4351 Hello 72
	// 10FF가 16진수인 경우 10진수로 바꾸면 4351
	// 'H'부터는 숫자로 변경 불가 -> 해당 포인터를 end에 저장
	char str1[] = "10FFHello";
	char* end;
	long l = strtol(str1, &end, 16);
	printf("%s %ld %s %d\n", str1, l, end, (int)*end);
	
	return 0;
}

// ======================================================================
// 10을 16진수로 바꿔서 문자열로 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	char temp[100];

	// result : a
	puts(_itoa(10, temp, 16));
	
	// result : a
  // ★ sprintf가 권장하는 방법
	sprintf(temp, "%x", 10);
	puts(temp);

	return 0;
}

