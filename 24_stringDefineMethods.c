// 문자열을 정의하는 방법들

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MESSAGE "A symbolic string constant"
#define MAXLENGTH 81

int main() {

	// Char type의 배열
	// 글자가 얼마나 들어갈지 모르기 때문에 보통 넉넉한 길이 설정
	// ex) MAXLENGTH 81
	char words[MAXLENGTH] = "A string in an array";

	// 문자가 저장된 공간의 첫 번째 주소가 저장됨
	const char* pt1 = "A pointer to a string.";

	/* result
	Puts() adds a newline at the end:
	A symbolic string constant
	A string in an array
	A pointer to a string.
	A spring in an array
	*/

	// ★ puts() add \n at the end
	puts("Puts() adds a newline at the end:");
	puts(MESSAGE);

	// 배열 문자열 출력
	// warning : using uninitialized memory
	// why? words는 81 공간이 있는 배열인데
	//      실제 입력 글자 수는 81보다 작기 때문에
	//      빈 공간들이 초기화 되지 않았다는 의미
	puts(words);

	// 문자열의 포인터 출력
	puts(pt1);

	// 배열이기 때문에 특정 원소 접근해서 변경 가능
	words[3] = 'p';
	puts(words);

	// pt1[8] = 'A';
	// -> Runtime ERROR
	// 이처럼 어차피 ERROR가 발생하기 때문에
	// ★ string을 포인터에 만들 때는 기본적으로 const 붙이는 게 좋음

	// -------------------------------------------

	// 초기화 할 때 "" 여러 번 나누거나 빈칸도 가능
	char greeting[50] = "Hello, and "" How are" "you"
		" today!";

	// warning : using uninitialized memory
	// why? greeting는 50 공간이 있는 배열인데
	//      실제 입력 글자 수는 50보다 작기 때문에
	//      빈 공간들이 초기화 되지 않았다는 의미
	puts(greeting);

	// -------------------------------------------

	// \" : " 자체를 출력
	// "To be, or not to be" Hamlet said.
	printf("\"To be, or not to be\" Hamlet said.\n");

	// -------------------------------------------

	// We, 00EC7BF4, e
	// %s : 문자열 출력
	// %p : 첫 글자가 저장된 주소
	// %c, *"excellent programmers" : 해당 문자열의 첫 번째 공간 주소가 가리키는 값 
	printf("%s, %p, %c\n", "We", "are", *"excellent programmers");

	// -------------------------------------------
	const char m1[15] = "Love you!";	
	const char m3[] = "Love you, too!";   // 빈칸으로 초기화 해도 됨

	// ASCII Code 출력
	// 76 111 118 101 32 121 111 117 33 0 0 0 0 0 0
	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m1[i]);    // ★ Note the null characters
	printf("\n");

	// -------------------------------------------

	// 문자열이 아닌 문자의 배열 초기화
	// 이 때는 수동으로 Null point '\0' 입력해야 함
	const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0'};

	// 76 111 118 101 32 121 111 117 33 0 0 0 0 0 0
	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m2[i]);    // ★ Note the null characters
	printf("\n");

	// -------------------------------------------

	// 여러 가지 가능하지만 [] 안에 실수는 들어갈 수 없음
	int n = 8;
	char cookies[1] = { 'A', };
	char cakes[2 + 5] = { 'A', };
	char pies[2 * sizeof(long double) + 1] = { 'A', };
	
	// Visual Studio는 VLA(가변길이변수) 지원X
	// 아래와 같은 형태는 불가능
	// char crumbs[n];

	// -------------------------------------------

	// result : 전부 true!
	char truth[10] = "Truths is ";
	if (truth == &truth[0]) puts("true!");
	if (*truth == 'T') puts("true!");             // 첫글자
	if (*(truth + 1) == truth[1]) puts("true!");  // 포인터연산
	if (truth[1] == 'r') puts("true!");           // 개별 원소 접근

	return 0;
}
