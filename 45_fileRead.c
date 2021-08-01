/*
파일 내용 출력하기
1) 상단 현재 파일명 'myFirstPrj.c' 우클릭 - Open Containing Folder
   ex) C:\Users\User\Desktop\C_inflearn\myFirstSolution\myFirstPrj
2) 해당 경로에 text 파일 만들기
   ex) my_file.txt
*/ 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   // exit()

int main() {

	int c;
	FILE* file = NULL;
	char file_name[] = "my_file.txt";

	// fopen : file open
	// "r" : read, "w" : write
	// default format : text file
	file = fopen(file_name, "r");

	// 해당 이름을 가진 파일이 없는 경우
	if (file == NULL) {
		printf("Failed to open file.\n");
		// exit(1)
		// 실행이 잘못되었을 때, 이를 개발자에게 알려주기 위해 '1' 숫자를 날림
		// 보통 1, -1 사용
		exit(1);
	}

	while ((c = getc(file)) != EOF)
		putchar(c);

	// fclose : file close
	fclose(file);

	return 0;
}
