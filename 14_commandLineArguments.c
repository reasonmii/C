/*
Command-Line Arguments 명령줄 인수
main함수 변수 : 운영체제가 값을 넣는 방식
How? 프로그래머, 사용자가 이 프로그램을 실행시킬 때 argument 입력
Rule : 변수가 아예 없거나, 변수를 넣고 싶으면 두 개를 무조건 넣어야 함
1) 현재 파일 Build하기 : ctrl + shift + B
2)
방법1 : 상단 Tools - Command Line - Developer Command Prompt
   	실행파일의 위치 입력
   	C:\Users\User\Desktop\C_inflearn\myFirstSolution\Debug\myFirstPrj.exe
방법2 : Solution Explorer 창 프로젝트 우클릭 - Properties - Debugging
	Command Arguments 부분에 변수 입력 ex) 3 Hello

※ 파일 저장 위치 원리
Solution Explorer 창 프로젝트 우클릭 - Properties - General
1) Output Directory : Solution Directory : Visual Studio가 만드는 .snl 파일
					  Configuration : debug, release 파일 등
2) Intermediate Directory : Build할 때 중간에  사용하는 파일 저장 위치
3) Target Name : 실행파일 이름 (프로젝트이름과 동일)
4) Configuration Type : Application (.exe)

※ 실행파일 위치를 탐색기로 찾기
상단 파일명 우클릭 : myFirstPrj.c - Open Containing Folder
한 단계 위 폴더 클릭 - Debug - myFirstPrj.exe
*/

/*
Result
Input : C:\Users\User\Desktop\C_inflearn\myFirstSolution\Debug\myFirstPrj.exe
Output : The command line has 1 arguments:
		 Arg 0 : C : \Users\User\Desktop\C_inflearn\myFirstSolution\Debug\myFirstPrj.exe

Input : C:\Users\User\Desktop\C_inflearn\myFirstSolution\Debug\myFirstPrj.exe hello world 1234 3.14
Output
The command line has 5 arguments:
Arg 0 : C : \Users\User\Desktop\C_inflearn\myFirstSolution\Debug\myFirstPrj.exe
Arg 1 : hello
Arg 2 : world
Arg 3 : 1234
Arg 4 : 3.14
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// argc: 문자열 개수, argv : 문자열
int main(int argc, char * argv[]) {

	int count;
	printf("The command line has %d arguments:\n", argc);

	for (count = 0; count < argc; count++)
		printf("Arg %d : %s\n", count, argv[count]);
	printf("\n");

	return 0;
}

