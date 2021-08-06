/*
모든 텍스트 파일은 사실 binary로 저장됨
이렇게 이진수로 저장된 파일을 사람이 알 수 있게 읽도록 출력하려면 규칙이 있음
- decoding 표 사용 : 특정 이진수와 글자를 matching

한글인 경우
console창에 출력하면 다 깨지는데
해당 파일을 새로운 파일에 복사 후, 새로운 파일 열어보면 안 깨져있음

encoding 방식을 제대로 하면 글자 안 깨짐

방법1)
한글이 들어간 파일의 경우 기존에 메모장을 저장할 때
인코딩 설정을 'UTF-8'이 아닌 'ANSI'로 하기
-> 콘솔 창 돌려도 글자가 깨지지 않음
   C-program의 decoding 방식과 잘 맞기 때문

방법2)
파일 읽기 전 부분에 UTF-8 표를 보고 decoding 할 수 있도록 코딩
SetConsoleOutputCP(CP_UTF8);
but, 파일 내 한글은 안 깨지는데
     콘솔창에서 마지막에 기본으로 출력하는 한글 말들이 깨짐
-> 해결방법
   파일 내용을 읽은 후에는 프로그램 자체에서 사용하는
   기본 encoding 모드로 돌아가야 함
   SetConsoleOutputCP(default_cp);
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// CP : Code Page
// encoding을 위해 어떤 decoding 표를 사용할 지 결정
#include <windows.h>  // SetConsoleOutputCP()

int main(int argc, char* argv[]) {

	// GetConsoleOutputCP() : 현재 사용 중인 CP 확인
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);

	int ch;
	FILE* fr, * fw;

	const char* in_filename = "원본.txt";
	const char* out_filename = "사본.txt";

	unsigned long count = 0;

	// Open a text file for reading
	if ((fr = fopen(in_filename, "r")) == NULL) {
		printf("Can't open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	// Open a text file for writing
	if ((fw = fopen(out_filename, "w")) == NULL) {
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}

	// UTF-8 mode
	// "원본.txt" 파일이 UTF-8 형식인 경우
	SetConsoleOutputCP(CP_UTF8);

	while ((ch = fgetc(fr)) != EOF) {
		fputc(ch, stdout);   // same as putchar(ch);
		fputc(ch, fw);
		count++;
	}

	fclose(fr);
	fclose(fw);

	// ISO 2022 Korean
	// 프로그램 자체에서 사용하는 기본모드로 돌아가기
	SetConsoleOutputCP(default_cp);

	printf("File %s has %lu characters\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인");

	return 0;
}
 
