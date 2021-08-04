/*
문자 : 하나의 글자 -> 작은 따옴표 사용
문자열 : 일련의 문자들의 모임 -> 큰 따옴표 사용, NULL 문자로 문자의 끝 표시 ('\0', '0')

문자 처리 library
※ https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
isalpha(c) : c가 영문자인지 (a-z, A-Z)
isupper(c) : 대문자인지
islower(c) : 소문자인지
isdigit(c) : 숫자인지
isalnum(c) : 숫자나 영문자인지 (a-z, A-Z, 0-9)
isxdigit(c) : c가 16진수의 숫자인지 (0-9, A-F, a-f)
isspace(c) : 공백문자인지 ('', '\m', '\t', '\v', '\r')
ispunct(c) : 구두점 문자인지
isprint(c) : 출력 가능한 문자인지
iscntrl(c) : 제어문자인지
isascii(c) : ASCII 코드인지

문자열 처리 library
strlen(s) : 문자열 s의 길이
strcpy(s1, s2) : s2를 s1에 복사
strcat(s1, s2) : s2를 s1 끝에 붙이기
strcmp(s1, s2) : s1과 s2를 비교
strncpy(s1, s2, n) : s2의 최대 n개의 문자를 s1에 복사
strncat(s1, s2, n) : s2의 최대 n개의 문자를 s1 끝에 붙이기
strncmp(s1, s2, n) : 최대 n개의 문자까지 s1과 s2를 비교
strchr(s, c) : 문자열 s안에서 문자 c 찾기
strstr(s1, s2) : 문자열 s1에서 문자열 s2 찾기
char *strtok(s, delimit) : 문자열 s를 delimit을 이용하여 토큰으로 분리

※ strcat() : string concatenation

★ sprintf(array, string) : string을 array에 넣어서 출력
수많은 파일 이름을 순서대로 만들어야 할 때 많이 사용
ex) capture01.png, capture02.png, ...

문자열 수치 변환
int atoi(const char *str); : str을 int형으로 변환
long atoi(const char *str); : str을 long형으로 변환
double atof(const char *str); : str을 double형으로 
*/

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

int main() {

	char c = 'a';
	// 10 : 9 characters + null character
	char str1[10] = "Hello";
	char str2[10] = { 'H', 'i' };

	printf("%c\n", c);     // a
	printf("%s\n", str1);  // Hello
	printf("%s\n", str2);  // Hi

	// result : 72 105 0 0 0
	// ASCII 'H' : 72
	// ASCII 'i' : 105
	printf("%hhi %hhi %hhi %hhi %hhi\n",
		str2[0], str2[1], str2[2], str2[3], str2[4]);

	// array size is not enough
	// char str3[10] = "Hello, World";
	// But, how can we know the size in advance?
	// -> we can use 동적할당 later
	char str3[20] = "Hello, \0World";

	// result : Hello,
	// 중간에 '\0'라는 null character를 만남
	// -> 끝까지 출력 안함
	printf("%s\n", str3);

	// 그렇다고 값이 저장 안된 것은 아님
	printf("%c\n", str3[10]);          // r

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

#include <stdio.h>
#include <string.h>  // strlen and more

int main() {

	char str1[100] = "Hello";
	char str2[] = "Hello";
	char str3[100] = "\0";
	char str4[100] = " \0";
	char str5[100] = "\n";

	// strlen 위에 마우스 놓으면 type이 size_t -> %zu
	// strlen은 '\0'을 제외하고 실제 의미가 있는 문자만 셈
	printf("%zu %zu\n", sizeof(str1), strlen(str1));  // 100 5
	printf("%zu %zu\n", sizeof(str2), strlen(str2));  // 6 5
	printf("%zu %zu\n", sizeof(str3), strlen(str3));  // 100 0
	printf("%zu %zu\n", sizeof(str4), strlen(str4));  // 100 1
	printf("%zu %zu\n", sizeof(str5), strlen(str5));  // 100 1

	// -------------------------------------------
	// 동적할당 예시

	char* str6 = (char*)malloc(sizeof(char) * 100);
	str6[0] = 'H';
	str6[1] = 'e';
	str6[2] = 'l';
	str6[3] = 'l';
	str6[4] = 'o';
	str6[5] = '\0';

	// sizeof(str6) : 4 - point 주소 사이즈
	printf("%zu %zu\n", sizeof(str6), strlen(str6));  // 4 5

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

#define _CRT_SECURE_NO_WARNINGS     // strcat
#include <stdio.h>
#include <string.h>
#include <ctype.h>    // atoi, atof

int main(void) {

	char s1[20] = "world";
	char s2[20] = " world";

	// 결과 : 다른 배열
	if (strcmp(s1, s2) == 0)
		printf("동일한 배열\n\n");
	else
		printf("다른 배열\n\n");

	// -------------------------------------------

	char str1[20] = "100";
	int num1;

	num1 = atoi(str1);

	printf("%d\n\n", num1);

	// -------------------------------------------

	int a;
	// 한 문장 생성
	char menu[5][10] = {
		"init",
		"open",
		"close",
		"read",
		"write"
	};

	for (int i = 0; i < 5; i++)
		printf("%d번째 메뉴 : %s \n", i + 1, menu[i]);

	// -------------------------------------------

	char str2[30] = "The Little Prince";
	char* ptr = strtok(str2, " ");

	while (ptr != NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fit_str(char*, unsigned int);

int main() {

	// Just, do it!
	// Length 12
	char msg[] = "Just,"" do it!";
	puts(msg);
	printf("Length %d\n", strlen(msg));

	// Just
	// Length 4
	fit_str(msg, 4);
	puts(msg);
	printf("Length %d\n", strlen(msg));

	// -------------------------------------------

	char str1[100] = "First string";
	char str2[] = "Second string";
 
	strcat(str1, ", "); // First string,
	strcat(str1, str2); // First stringSecond string

	// Append 2 characters
	// First stringSe
	strncat(str1, str2, 2);
	puts(str1);

	// -------------------------------------------

	printf("%d\n", strcmp("A", "A"));    // 0 : 같다
	printf("%d\n", strcmp("A", "B"));    // -1 : 앞 문자가 뒷 문자보다 ASCII CODE가 더 작은 경우
	printf("%d\n", strcmp("B", "A"));    // 1  : 앞 문자가 뒷 문자보다 ASCII CODE가 더 큰 경우
	printf("%d\n", strcmp("Hello", "Hello"));         // 0 : 같다
	printf("%d\n", strcmp("Banana", "Bananas"));      // -1 : null이 's' 문자보다 더 작음
	printf("%d\n", strcmp("Bananas", "Banana"));      // 1  : 's' 문자가 null보다 더 큼
	printf("%d\n", strncmp("Bananas", "Banana", 6));  // 0  : 6글자 비교해보면 같음

	// -------------------------------------------

	// ★ strcpy : '\0' is not added
	// 딱 정해진 글자만 복사되고 NULL '\0'은 자동으로 복사되지 않음

	// ※ dest : destination
	char dest[100] = ""; 	// make sure memory is enough
	char source[] = "Start programming!";
	// dest = source -> ERROR
	// dest = "Start something"; -> ERROR

	// source를 dest에 복사하는 것
	// Start programming!
	strcpy(dest, source);
	puts(dest);

	// Start
	strncpy(dest, source, 5);
	puts(dest);

	// 시작위치 변경 : source 6번째부터 복사
	// programming!
	strcpy(dest, source + 6);
	puts(dest);

	// dest : programming!
	// dest의 6번째부터 글자에 "coding" overwrite
	// progracoding!
	strcpy(dest + 6, "coding!");  // Start coding!
	puts(dest);

	// -------------------------------------------

	char str[100] = "";
	int i = 123;
	double d = 3.14;

	// 00123.png 3.140000
	sprintf(str, "%05d.png %f", i, d);
	puts(str);

	// -------------------------------------------

	// strchr(string, character)
	// string에서 character로 시작하는 부분의 포인터를 return
	// 마치 그 부분부터 출력되는 것처럼 작동
	printf("%s\n", strchr("Hello, World", 'W'));       // World

	// strpbrk(string1, string2)
	// string1에서 string2 글자 중 하나로 시작되는 글자를 찾음
	printf("%s\n", strpbrk("Hello, World", "ABCDE"));  // (null)
	printf("%s\n", strpbrk("Hello, World", "abcde"));  // ello, World

	// strrchr(string, character)
	// last occurrence
	// string에서 character로 시작하는 가장 마지막 포인터를 return
	// 해당 부분부터 출력
	printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));  // ld

	// strstr(string1, string2)
	// string1에서 string2로 시작하는 부분의 포인터를 return
	// 해당 부분부터 출력
	printf("%s\n", strstr("Hello, World", "wor"));    // (null)
	printf("%s\n", strstr("Hello, World", "Wor"));    // World

	return 0;
}

// 문자열에서 size번째에 '\0' 삽입
void fit_str(char* str, unsigned int size) {

	if (size < strlen(str))
		str[size] = '\0';
}

// ======================================================================
// 문자 함수를 문자열에 사용하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>   // toupper(), ispunct(), ...

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main() {

	char line[NUM_LIMIT];
	char* new_line = NULL;
	fgets(line, NUM_LIMIT, stdin);

	// Find first newline -> NULL로 바꾸기
	// strchr(string, character)
	// string에서 character가 나타나는 첫 번째 포인터 return
	new_line = strchr(line, '\n');
	if (new_line)
		*new_line = '\0';

	// Hello, World!!!! -> HELLO, WORLD!!!!
	ToUpper(line);
	puts(line);

	// Hello, World!!!! -> 5 : one ',' + four '!'
	printf("%d\n", PunctCount(line));

	return 0;
}

void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);
		/*if (islower(*str))
			*str = toupper(*str);*/
		str++;
	}
}

int PunctCount(const char* str) {
	int ct = 0;
	while (*str) {
		// ★ ispunct : 알파벳이 아닌 기호 개수
		if (ispunct(*str))
			ct++;
		str++;
	}
	return ct;
}
