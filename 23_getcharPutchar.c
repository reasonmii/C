/*
입출력함수     설명      버퍼사용여부     에코여부    응답성     문자수정여부
getchar()   <stdio.h>       사용          에코      줄단위        가능
_getch()    <conio.h>       사용X         에코X    문자단위      불가능
_getche()   <conio.h>       사용X         에코     문자단위      불가능
*/

// ======================================================================
// 버퍼를 사용하고 에코가 있는 방식
// int getchar(void) : 한 문자 읽어서 반환
// void putchar(int c) : 변수 c에 저장된 문자 출력
//                       (버퍼에 저장된 문자들이 프로그램으로 전달)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char ch;

    ch = getchar();
    putchar(ch);

    return 0;
}

// ======================================================================

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

#include <stdio.h>

int main(void) {

	char ch;

	// Filter a specific character
	// 1) convert f/F -> X
	// 2) convert numbers to asterisks
	while ((ch = getchar()) != '\n') {

		if (ch == 'f' || ch == 'F')
			ch = 'X';
		else if (ch >= '0' && ch <= '9')
			ch = '*';

		putchar(ch);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	char ch;

	// Lower/Upper to upper/Lower characters
	while ((ch = getchar()) != '\n') {

		// ASCII : 'A' = 65, 'a' = 97

		if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';

		putchar(ch);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	char ch;

	// 소문자 → 대문자, 대문자 → 소문자, 숫자 → *
	while ((ch = getchar()) != '\n') {
		if (islower(ch))
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);
		
		if (isdigit(ch) != 0)
			ch = '*';

		putchar(ch);
	}
	
	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int count = 0;

    while (1) {
        printf("Current count is %d. Continue? (y/n)\n", count);

        int c = getchar();

        if (c == 'n')
            break;
        else if (c == 'y')
            count++;
        else
            printf("Please input y or n\n");

        // ※ 여러 문자를 입력했을 때
        // 같은 줄에 있는 첫 글자 외 모든 글자 무시       
        while (getchar() != '\n')
             continue;
    }

    return 0;
}

// ======================================================================
// 버퍼를 사용하지 않고 에코가 없는 방식
// int _getch(int c) : 한 문자 읽어서 반환
// void _putch(int c) : 변수 c에 저장된 문자 출력

// _getch(), _getche() : buffer 미사용
// e : echo의 약자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>   // _getch(), _getche() 

int main() {
    char c;

    // ※ buffer 사용 시 : hello 입력 -> hello 출력
    // buffer 미사용 시 한 글자 입력할 때마다 매번 출력
    // ex) result : hheelllloo
    while ((c = _getche()) != '.')
        putchar(c);

    return 0;
}

// ======================================================================

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
