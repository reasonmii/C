#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc

void test_function() {
	int j;
	printf("Stack high \t%llu\n", (unsigned long long) &j);
}

int main() {

	// Array Versus Pointer
	const char* pt2 = "I am a string!";
	const char* pt3 = "I am a string!";
	const char* pt4 = "I am a string!!!!!!";  // <- different
	const char ar1[] = "I am a string!";
	const char ar2[] = "I am a string!";
	const char ar3[] = "I am a string!!";     // <- different

	// 포인터를 16진수로 보기 불편하니 10진수로 변환해서 보고자 함
	// rodata : read only data
	// ★ compiler가 보기에 1번, 2번, 4번 값이 모두 동일하니, 한 곳에 모두 같이 저장 -> 주소가 같음
	// ★ 즉, 포인터에 저장된 문자열을 인덱싱 [0] 해서 값을 변환시킬 수 없는 이유는
	//    pt2를 변경하려면 사실상 pt3 등 연결된 모든 값을 변경하려 하는 의미이기 때문
	// 6847712 6847712 6848048 6847712
	printf("rodata low \t%llu %llu %llu %llu\n",
		(unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
		(unsigned long long)"I am a string!");

	// 5241404 5241380 5241356 -> 모두 다른 주소
	printf("Stack high \t%llu %llu %llu\n", (unsigned long long)ar1,
		(unsigned long long)ar2, (unsigned long long)ar3);
	
	// -------------------------------------------
	// Local Variables

	// pt2 포인터 자체의 주소
	// 5241452 5241440 5241428
	printf("Stack high \t%llu %llu %llu\n",
		(unsigned long long) & pt2, (unsigned long long) & pt3, (unsigned long long) & pt4);

	int i;
	printf("Stack high \t%llu\n", (unsigned long long) & i); // 5241344

	// -------------------------------------------
	// Local Variables in a function

	test_function();   // 5240968

	// -------------------------------------------
	// Dynamic allocation
	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("Dynamic allocation - Heap middle \t%llu\n", (unsigned long long)p5);  // 9852704

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("Dynamic allocation - Heap middle \t%llu\n", (unsigned long long)p6);  // 9871368

	// -------------------------------------------
	// Array versus Pointer (continued)

	// ar1++; -> Error
	pt2++;      // 포인터는 증감연산자 사용 가능

	// Check the first character
	// 한 칸씩 오른쪽으로 이동하면서 제일 첫 글자 없어짐
	// result : am a string!
	puts(pt2);

	// -------------------------------------------
	// Array and Pointer Differences

	char heart[] = "I love Kelly!";
	const char* head = "I love Helly!";

	// putchar : ASCII code 입력 시 문자 출력
	for (int i = 0; i < 6; i++)
		putchar(heart[i]);          // I love
	putchar('\n');

	for (int i = 0; i < 6; i++)
		putchar(head[i]);          // I love
	putchar('\n');

	// pointer addition : 포인터 연산
	for (int i = 0; i < 6; i++)
		putchar(*(heart + i));    // I love
	putchar('\n');
	
	for (int i = 0; i < 6; i++)
		putchar(*(head + i));     // I love
	putchar('\n');

	// '\0' 만날 때까지 출력
	while (*(head) != '\0')
		putchar(*(head++));      // I love Helly!

	// head : 포인터
	// 포인터에 배열 대입 가능
	// 그러나 배열에 포인터 대입은 불가능
	// heart = head -> Error
	head = heart;

	// -------------------------------------------

	// Cannot change heart
	// Can change the elements of heart
	heart[7] = 'K';      // I love Kelly!
	*(heart + 7) = 'A';  // I love Aelly!

	putchar('\n');

	// 문자열을 포인터로 정의했으면,
	// 어차피 바꾸면 안 되기 때문에 const 앞에 입력하는 것 권장
	// char* word = "Google";
	const char * word = "Google";
	// word[2] = 'o';      -> Run-time error!
	puts(word);            // Google

	// -------------------------------------------

	const char* str1 = "When all the lights are low, ...";
	const char* copy;

	copy = str1;

	// ※ strcpy(), strncpy() : 문자열 배열 자체 복사
	printf("%s %p %p\n", str1, str1, &str1);  // 0068867C 004FF97C
	printf("%s %p %p\n", copy, copy, &copy);  // 0068867C 004FF970

	return 0;
}

