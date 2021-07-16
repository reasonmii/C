// 문자 : 하나의 글자 -> 작은 따옴표 사용
// 문자열 : 일련의 문자들의 모임 -> 큰 따옴표 사용, NULL 문자로 문자의 끝 표시 ('\0', '0')

// EOF (End of File)
// 파일의 끝을 표현하기 위해 정의된 상수
// 더 이상 읽을 수 있는 데이터가 없음을 의미함
// 보통 -1 로 정의된 상수
// 콘솔 창에서 ctrl + z 입력
// 함수 호출이 실패했을 때 발생

// 입출력함수     설명      버퍼사용여부     에코여부    응답성     문자수정여부
// getchar()   <stdio.h>       사용          에코      줄단위        가능
// _getch()    <conio.h>       사용X         에코X    문자단위      불가능
// _getche()   <conio.h>       사용X         에코     문자단위      불가능

// 문자 처리 library
// isalpha(c) : c가 영문자인지 (a-z, A-Z)
// isupper(c) : 대문자인지
// islower(c) : 소문자인지
// isdigit(c) : 숫자인지
// isalnum(c) : 숫자나 영문자인지 (a-z, A-Z, 0-9)
// isxdigit(c) : c가 16진수의 숫자인지 (0-9, A-F, a-f)
// isspace(c) : 공백문자인지 ('', '\m', '\t', '\v', '\r')
// ispunct(c) : 구두점 문자인지
// isprint(c) : 출력 가능한 문자인지
// iscntrl(c) : 제어문자인지
// isascii(c) : ASCII 코드인지

// 문자열 처리 library
// strlen(s) : 문자열 s의 길이
// strcpy(s1, s2) : s2를 s1에 복사
// strcat(s1, s2) : s2를 s1 끝에 붙이기
// strcmp(s1, s2) : s1과 s2를 비교
// strncpy(s1, s2, n) : s2의 최대 n개의 문자를 s1에 복사
// strncat(s1, s2, n) : s2의 최대 n개의 문자를 s1 끝에 붙이기
// strncmp(s1, s2, n) : 최대 n개의 문자까지 s1과 s2를 비교
// strchr(s, c) : 문자열 s안에서 문자 c 찾기
// strstr(s1, s2) : 문자열 s1에서 문자열 s2 찾기
// char *strtok(s, delimit) : 문자열 s를 delimit을 이용하여 토큰으로 분리

// 문자열 수치 변환
// int atoi(const char *str); : str을 int형으로 변환
// long atoi(const char *str); : str을 long형으로 변환
// double atof(const char *str); : str을 double형으로 

// ======================================================================
#include <stdio.h>

int main(void) {
	char ch = 'a';                        // 문자형 변수 초기화
	char a[4] = { 'a', 'b', 'c', '\0' };  // 문자 배열 초기화
	char b[4] = "abc";
	char c[4] = "abcdefg";
	char d[6] = "abc";
	char e[4] = "";

	// 원래 배열 안에 아무 것도 안 넣으면 안 되지만
	// 이처럼 바로 초기값 주면 가능
	char f[] = "abcdefg";

	printf("a의 크기 = %d, 내용 = %s\n", sizeof(a), a);   // 4, abc
	printf("b의 크기 = %d, 내용 = %s\n", sizeof(b), b);   // 4, abc
	printf("c의 크기 = %d, 내용 = %s\n", sizeof(c), c);   // 4, abcd儆儆儆儆abc
	printf("d의 크기 = %d, 내용 = %s\n", sizeof(d), d);   // 6, abc
	printf("e의 크기 = %d, 내용 = %s\n", sizeof(e), e);   // 4, 공백
	printf("f의 크기 = %d, 내용 = %s\n", sizeof(f), f);   // 8, abcdefg

	// -------------------------------------------

	char str1[4] = "You";
	char str2[4] = { 'a', 'r', 'e' };
	char str3[] = "the best";

	// You are the best
	printf("%s %s %s \n", str1, str2, str3);

	return 0;

}

// ======================================================================

#include <stdio.h>

int main(void) {
	
	// 복사하기 : 잘못된 예
	char str1[4] = "You";
	char str2[4];

	// \0 : null
	for (int i = 0; i < str1[i] != '\0'; i++)
		str2[i] = str1[i];

	printf("원본 = %s\n", str1);   // You
	printf("사본 = %s\n", str2);   // You儆儆儆儆?ou

	// -------------------------------------------

	// 복사하기 : 바른 예
	char str3[4] = "You";
	char str4[4];

	int i;

	for (i = 0; i < str3[i] != '\0'; i++)
		str4[i] = str3[i];

	str4[i] = '\0';

	printf("원본 = %s\n", str3);   // You
	printf("사본 = %s\n", str4);   // You

	// -------------------------------------------

	// 복사하기 : 간단한 예
	char str5[4] = "You";
	char str6[4];

	// 오른쪽 값을 왼쪽에 
	strcpy(str6, str5);

	printf("원본 = %s\n", str5);   // You
	printf("사본 = %s\n", str6);   // You

	return 0;

}

// ======================================================================

#include <stdio.h>

int main(void) {
	
	// 개별 문자 
	char str1[4] = "Yoo";
	str1[2] = 'u';

	printf("%s\n", str1);  // You
  
  return 0;
  
}

// ======================================================================
// 버퍼를 사용하고 에코가 있는 방식
// int getchar(void) : 한 문자 읽어서 반환
// void putchar(int c) : 변수 c에 저장된 문자 출력
//                       (버퍼에 저장된 문자들이 프로그램으로 전달)

#include <stdio.h>

int main(void) {
	
	int ch;

	// 문자열 입출력
	printf("한 문자씩 입력하세요 (종료 : q)\n");
	while ((ch = getchar()) != 'q')
		putchar(ch);

	return 0;

}

// ======================================================================
// 버퍼를 사용하지 않고 에코가 없는 방식
// int _getch(int c) : 한 문자 읽어서 반환
// void _putch(int c) : 변수 c에 저장된 문자 출력

#include <stdio.h>
#include <conio.h>

int main(void) {
	
	int ch;

	// 문자열 입출력
	printf("한 문자씩 입력하세요 (종료 : q)\n");
	while ((ch = _getch()) != 'q')
		_putch(ch);

	return 0;

}

// ======================================================================
// char * gets_s(char *s, int size) : 한 줄의 문자열을 읽어서 문자 배열 s[]에 저장
// int puts(const char *s) : 배열 s[]에 저장되어 있는 한 줄의 문자열을 추력

#include <stdio.h>

int main(void) {

	char name[20];

	printf("이름 : ");

	// scanf("%s", name);
	gets_s(name, sizeof(name));

	// printf(name);
	puts(name);

	return 0;

}

// ======================================================================

#include <stdio.h>

int main(void) {

	int c;

	// 소문자인지 대문자인지 파악하기
	printf("문자를 입력하세요 : \n");
	while ((c = getchar()) != EOF) {
		if (islower(c))
			printf("%c : 소문자 \n", c);
		else if (isupper(c))
			printf("%c : 대문자 \n", c);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	// 소문자 입력 시 대문자로 바꾸기
	int c;

	printf("문자를 입력하세요 : \n");
	while ((c = getchar()) != EOF) {
		if (islower(c))
			c = toupper(c);
		putchar(c);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	// 배열로 하면 더 간단하고
	// 포인터로 하면 더 유용함 -> C에서는 포인터 많이 사용함
	char s1[10] = "hello";
	char* s2 = "hello";

	printf("%d \n", strlen(s1));      // 5
	printf("%d \n", strlen(s2));      // 5
	printf("%d \n", strlen("hello")); // 5

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS     // strcat
#include <stdio.h>
#include <string.h>

int main(void) {

	char s1[20] = "world";
	char s2[20] = "hello";

	// 왼쪽 값에 오른쪽 값 붙이기
	// 이때 최소한 s2는 s1을 모두 넣을 수 있도록 크기가 20 이상이어야 함
	strcat(s2, s1);

	printf("%s \n", s1);      // world
	printf("%s \n", s2);      // helloworld

	return 0;
}

// ======================================================================



// ======================================================================



