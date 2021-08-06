/*
fopen mode string for text file
- r : reading
- w : creating-and-writing or over-writing
- a : appending or creating-and-writing
- r+ : both reading and writing
- w+ : reading and writing, over-writing or creating
- a+ : reading and writing, appending or creating
*/

// ======================================================================

/*
Read File

1) 파일 생성
상단 파일명 우클릭 - Open Containing Folder
text파일 생성 : 메모장 ex) input.txt
내용입력

2) 파일 실행하기
※ 여기에서 그냥 실행하면 main함수에 인수를 넣지 못하기 때문에 ERROR
Solution Explorer에서 project 파일 우클릭
- Properties - Configuration Properties - Debugging
- Command Arguemnts : 'input.txt' 입력
- 실행하기

결과 : text파일 내용과 글자수 출력됨
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	// ★ int type으로 한 글자 한 글자 받아오기
	int ch;

	// file pointer to write
	// file에 필요한 여러 가지 data의 묶음에 대한 pointer
	// file 자체에 대한 포인터처럼 사용 가능
	FILE* fr;

	/*
	typedef struct _iobuf
	{
		char* _ptr;
		int _cnt;
		char* _base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char* _tmpfname;
	} FILE;
	*/

	unsigned long count = 0;

	// 명령줄 인수가 비어있으면
	// 파일 이름을 입력하라고 경고문 뜨게 함
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Open a text file for reading
	if ((fr = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// ★ fgetc, fputc 사용하는 방법이 더 안정적
	while ((ch = fgetc(fr)) != EOF)   // getc(fr)
	{

		// ch에 입력하는 내용을 stdout에 저장
		// stdout을 다른 string으로 바꿀 수 있음
		// putc(ch, stdout);   // same as putchar(ch);
		fputc(ch, stdout);

		// 글자수 세기
		count++;
	}

	// ★ 반드시 닫아줘야 함
	// 만약 buffer에 뭔가 남아있는데 close 안 하면
	// buffer 내용이 잘못 처리될 수 있음
	fclose(fr);

	printf("File %s has %lu characters\n", argv[1], count);

	return 0;
}
 
// ======================================================================
/*
Write File

text 파일 복사해서 신규 파일로 만들기
1) 새로운 파일을 열고
2) 같은 경로에 있는 특정 text 파일 읽어서
3) 해당 내용을 새로운 파일에 쓰기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int ch;
	FILE* fr, * fw;   // read and write file

	// 출력파일명
	const char* out_filename = "copy.txt";

	unsigned long count = 0;

	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Open a text file for reading
	if ((fr = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Open a text file for writing
	// if ((fr = fopen(argv[2], "w")) == NULL) {
	if ((fw = fopen(out_filename, "w")) == NULL) {
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fr)) != EOF)   // getc(fr)
	{
		// 화면에 출력
		fputc(ch, stdout);

		// write a file stream
		// 파일에 출력
		fputc(ch, fw);

		// 글자수
		count++;
	}

	fclose(fr);
	fclose(fw);

	printf("File %s has %lu characters\n", argv[1], count);
	printf("Copied to %s\n", out_filename);

	return 0;
}
 
