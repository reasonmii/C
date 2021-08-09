/*
Namespace
이름 공간 공유하기
- Identify parts of a program in which a name is recognized
- You can use the same name for one variable and one tag
  변수와 tag는 category가 다르기 때문
- C++ : use 'namespace' to use the same identifiers in the duplicated scopes

Namespace Pollution (KNK p.465)
- Names in different files accidentally conflicting with each other
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int iamfunction() {
	return 0;
}

// ======================================================================

/*
Namespace Pollution
★ 어느 다른 프로그램에서 a라는 변수를 이미 사용한 경우, 같은 이름 사용 불가
Solution Explorer에서 같은 프로젝트 내 파일 하나 더 생성 ex) other.c
- 파일 내에 변수 'a' 사용해서 선언
*/
// int a = 123;
// -> ERROR : _a already defined in myFirstPrj.obj

int a;   // other.c 에서 가져옴

int main() {

	{
		int myname = 345;
		// double myname = 3.14; -> ERROR : same name
	}
	
	struct rect { double x; double y; };

	// 'struct rect' and 'variable' are in different categories
	// but, now recommended
	// int rect = 123;   // OK in C (Not OK in C++)

	// 'struct rect' and 'rect' are in different categories
	struct rect rect = { 1.1, 2.2 };  // OK

	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 };     // Not OK
	*/

	// 함수의 이름과 동일한 변수를 선언하려고 하면 충돌
	// int iamfunction = iamfunction();   // ERROR

	// Namespace Pollution
	printf("%d\n", a);     // other.c에서 가져옴

	return 0;
}

// -------------------------------------------
// other.c

int a = 1;
int b = 2;
int c = 3;
int i = 4;
int j = 5;
int health = 100;
// more usefulnames

