/* 
Visual studio warns using 'scanf'

Method1)
Write this code on the top : #define _CRT_SECURE_NO_WARNINGS 

Method2)
Debug mode
Solution Explorer - Right click 'myFirstPrj' - Properties
C/C++ - Preprocessor
Professor Derinitions : WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)
Change to : WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions);_CRT_SECURE_NO_WARNINGS

★ scanf 한 단어를 입력받음
- 공백을 만나면 더 이상 읽지 않음

★ scanf의 장점 : 여러 가지 자료형이 섞여 있을 때 입력받기 좋음
- 단어, 정수, 실수, etc.
*/

// ======================================================================
// Int and scanf

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int i = 0;
	scanf("%d", &i);   // & : ampersand

	printf("Value is %d\n", i);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	int i = 0, j = 0;
	int sum = 0;

	printf("Input two integers\n");
	scanf("%d%d", &i, &j);

	printf("Your numbers are %d and %d\n", i, j);

	sum = i + j;

	printf("%d + %d = %d\n", i, j, i+j);
	printf("%d + %d = %d\n", i, j, sum);

	return 0;
}

// ======================================================================
// Integer with characters

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 문자를 만나기 전까지 입력받은 숫자들만 i에 넣음
	// ex) 123a456 입력 -> 123 출력
	int i;
	scanf("%i", &i);
	printf("%i\n", i);

}

// ======================================================================
// Regular characters

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a, b;

	// Try blank separator only
	//scanf("%d %d", &a, &b);
	//scanf("%d, %d", &a, &b);
	//scanf("%d ,%d", &a, &b);
	//scanf("%d,%d", &a, &b);
	//scanf("%d-%d", &a, &b);
	scanf("%dA%d", &a, &b);      // ex) 13A45 -> 13 45
	printf("%d %d\n", a, b);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// modifier for scanf))
	int i;
	// 3개의 숫자를 입력하나, 마지막 숫자만 i에 input 됨
	// ex) 123 456 789 -> Your thrid input = 789
	scanf("%*d%*d%d", &i);
	printf("Your thrid input = %d", i);

	return 0;
}

// ======================================================================
// floating point numbers

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// options : %f, %e, %E, %g
	// ★ 주의 : lf로 입력받고 f로 출력해야 함
	// scanf에서 f로 받으면 double은 8 bytes인데 size가 안 맞아서 에러 발생
	double d = 0.0;
	scanf("%lf", &d);    // lf : 8 bytes
	printf("%f\n", d);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	float won = 0;
	float dollar = 0;

	printf("Input Won\n");
	scanf("%f", &won);

	// 0.00089f : float형임을 선언
	dollar = won * 0.00089f;
	printf("Dollar = %f\n", dollar);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	// 맨 앞부터 6글자 입력
	float salary;
	printf("$______\b\b\b\b\b\b"); // $ _____
	scanf("%f", &salary);

	return 0;
}

// ======================================================================
// Signed and Unsigned

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// unsigned로 선언했으나
	// 입출력 모두 signed 형식으로 하면 signed 형식으로 변함
	// ex) -123 입력하면 -123 출력
	// 그러나 이런 방식 권장하지 않음 (나중에 코드 볼 때 헷갈림)
	unsigned i;
	scanf("%i", &i);
	printf("%i\n", i);

	// unsigned 선언, unsigned 형태로 입출력
	// ex) -123 입력 -> 4294967173 출력 (에러 발생)
	unsigned ui;
	scanf("%u", &ui);
	printf("%u\n", ui);

	return 0;
}

// ======================================================================
// Char and scanf

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// char : stores only 1 character
	char fruit_name;

	printf("What is your favorite fruit?\n");
	scanf("%c", &fruit_name);

	printf("You like %c!\n", fruit_name);

	return 0;
}

// ======================================================================


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// ★ scanf는 한 단어를 입력받음 (공백을 만나면 더이상 읽지 않음)
	char input[100] = "";
	int ret = scanf("%10s", input);   // Just do it, do it!
	printf("%s\n", input);            // Just

	// 이 상태에서 다시 scanf를 호출하면
	// 위에서 읽지 않고 남아있던 문자를 받아들임
	// 공백을 만나기 전까지만 받음
	ret = scanf("%10s", input);
	printf("%s\n", input);            // do

	return 0;
}

// ======================================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a, b;
	char c;

	// ex) 123 456 -> 123| |456
	scanf("%d%c%d", &a, &c, &b);
	printf("%d|%c|%d", a, c, b);	// | is separator

	return 0;
}

// ======================================================================
// h modifier

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// hhd : signed char type이니, 127 입력하면 잘 나오지만
	// 256 등 큰 숫자 입력하면 에러 발생
	char i;
	scanf("%hhd", &i);
	printf("%i\n", i);

	return 0;
}

// ======================================================================
// Character

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char c;
	scanf("%c", &c);    // try blank
	printf("%i\n", c);  // ASCII code : blank is 32

	return 0;
}

// ======================================================================
// Array and scanf

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 1byte 40개 확보
	char fruit_name[40];

	printf("What is your favorite fruit?\n");
	// ★ & 없어짐
	// fruit_name 자체가 40개 공간에 대한 주소이기 때문
	scanf("%s", fruit_name);

	printf("You like %s!\n", fruit_name);

	return 0;
}

// ======================================================================
// width : 글자 입력 수 지정

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char str[30];

	// 입력으로 5글자만 허용
	scanf("%5s", str);   // width
	printf("%s\n", str);

	return 0;
}

// ======================================================================
// width 유연하게 사용하기 : modifier for printf()
// 아래 예제에서는 scanf에서 읽어 왔는데,
// 그 외에도 script file, GUI 등에서 읽어오며 width를 유연하게 사용 가능

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int i = 123;
	int width = 5;   // 일단 초기화

	// ex1) 1입력 -> 123 출력
	//      123보다 크기가 작으니 123 다 출력
	// ex2) 7입력 ->     123 출력
	//      7칸 빈칸 확보, 123 오른쪽 정렬
	printf("Input width : ");
	scanf("%d", &width);
	printf("%*d\n", width, i);

	return 0;
}

// ======================================================================
// multiple inputs with blank separators

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int i;
	float f;
	char str[30];
	
	// Note & is absent in front of str
	// 만약 네 개 입력하면 네 번째 값은 buffer에만 저장되고 출력되지는 않음
	scanf("%d %f %s", &i, &f, str);
	printf("%d %f %s\n", i, f, str);

	return 0;
}

// ======================================================================
// j modifier
// portable type이라는 것만 차이점이고, 그 외에는 다른 자료형과 일치

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <inttypes.h>  // intmax_t

int main() {

	// 
	intmax_t i;     // 가장 큰 정수형 타입

	// %ji, %jd : intmax_t를 받아들인다는 의미
	scanf("%ji", &i);
	printf("%ji", i);

	return 0;
}

// ======================================================================
// return value of scanf() : the number of input items

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a, b;

	// ex) 45 65 -> 2
	int i = scanf("%d%d", &a, &b);
	printf("%d", i);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// scanf()로 string 입력받을 때 글자 개수 제한 가능
	// str[6] -> 끝은 '\0'니까 총 5글자 받을 수 있음
	// %5s : 5개로 입력 제한
	// 입력 : 123456789012345 -> 출력 : 12345 | 67890
	char str1[6], str2[6];
	int count = scanf("%5s %5s", str1, str2);

	// scanf_s : Visual Studio에서 권장하는 방식
	// 6 : 가장 크게 받을 사이즈
	// int count = scanf_s("%5s %5s", str1, 6, str2, 6);

	// int count = scanf("%6s %6s", str1, str2); -> Runtime ERROR!

	printf("%s|%s \n", str1, str2);

	return 0;
}
