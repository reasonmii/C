/*
전처리를 준비하는 번역 단계

● Program written in C
1) Translating
   컴파일러가 이해할 수 있는 언어로
   바꿔주는 과정이 가장 먼저 필요
2) Preprocessing
3) Compiling
4) Linking
5) Executable

※ Translating 단계는 전처리기 이전 단계일 수도 있고
   Preprocessing과 함께 처리하는 단계일 수도 있고
   컴파일러가 Translating과 Preprocessing을 모두 할 수도 있음

● Trigraph Sequences
- Some keyboards don't provide all the symbols used in C
  예전에 어떤 keyboard들은 Replacement 기호들이 없었음
- Three-character sequences
  세글자 규칙을 이용해서 해당 기호를 입력했음
- 전처리기가 이를 인지함

Trigraph  Replacement
??=       #
??/       \
??'       ^
??(       [
??)       ]
??!       |
??<       {
??>       }
??-       ~

● Digraphs
- Two-character sequences
  두글자 규칙을 이용해서 원하는 기호 입력

Digraph  Equivalent
<:       [
:>       ]
<%       {
%>       }
%:       #

★ Trigraph와 Digraph 차이
- printf에서 trigraph 기호 쓰면 자동으로 바뀜
- printf에서 Digraph 기호 쓰면 안 바뀌고 입력 그대로 출력

● Tokens
- ★ Compile의 기본 단위
  작성한 코드를 token 단위로 쪼갬
- Groups separated from each other by spaces, tabs, or line breaks
- Whitespace characters -> a single space
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// International characters

	puts("안녕하세요? 좋은 아침입니다.\n");

	// -------------------------------------------
	/*
	Trigraph Sequences

	현재 Visual Studio에서는 호환되지 않음
	이를 사용하기 위해서 설정 변경

	Solution Explorer 프로젝트 우클릭 - Properties
	Configuration Properties - C/C++ - Command Line
	- Additional Options
	- 입력 : /Zc:trigraphs
	- OK
	*/
	
	int arr[3] = { 1, 2, 3 };
	// 예전에는 이렇게 코딩했었음
	printf("arr??(0??) == %d\n", arr??(0??));  // arr[0] == 1
	printf("arr[0] == %d\n", arr[0]);          // arr[0] == 1

	// -------------------------------------------
	// Digraphs

	// ★ printf가 digraphs를 인지하지 못하고 그대로 출력
	printf("arr<:1:> == %d\n", arr<:1:>);     // arr<:1:> == 2
	printf("arr[1] == %d\n", arr[1]);         // arr[1] == 2

	// -------------------------------------------
	// Two physical lines vs One logical line

	printf("This is a very very very very very very very very very very very very long long long long long long long long long long long long long long long long line.\n");

	// Pysical line은 4줄이지만 Logical line(실제 출력)은 1줄
	printf("This is a very very very very very very \
very very very very very very long long long long \
long long long long long long long long long long \
long long line.\n");

	// -------------------------------------------
	// Tokens

	// 이런 식으로 주석을 달면 이 주석이 빈칸 한 칸으로 인식됨
	// -> 따라서 이렇게 주석 달아도 정상적으로 실행됨
	int/*a variable to count a nubmer*/n = 1;
	//int n = 1;

	return 0;
}
