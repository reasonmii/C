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

// ======================================================================
/*
Text file mode string & 다양한 입출력 함수들
fprintf(), fscanf(), fgets(), fputs()

-------------------------------------------

★ fscanf와 fgets 차이점
입력 : Happy Friday Smile

fscanf 출력 :
Happy
Friday
Smile

fgets 출력 :
Happy Friday Smile
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

int main(void) {

	FILE* fp;

	// 문자의 배열에 입력받기
	char words[MAX] = { '\0', };

	// 확장자를 꼭 .txt로 쓰지 않더라도
	// 문자 파일로 저장하면 문자 파일로 읽음 
	const char* filename = "record";
	//const char* filename = "record.txt";

	/*
	Try r+ , w+ , a+

	"r+"
	1) 해당 경로에 파일이 없는 경우
	result : Can't open "record" file.
	2) 파일이 있는 경우
	맨 앞부터 overwriting

	"w+" : 파일이 없으면 새로 만들고, 있으면 전체 파일 overwriting
	result : 글자 입력 -> 해당 경로에 record 파일 생김
	그런데, filename을 "record"로 지정했기 때문에,
	확장명 없이 'record'로 저장되어 있음
	방법1) Visual Studio에 drag 해서 가져오면 열림
	방법2) 메모장 열고 해당 파일 drag 하기
	방법3) 이름 뒤에 .txt 붙이고 열기

	"a+" : 파일을 열고 새로운 내용을 덧붙임
	*/
	if ((fp = fopen(filename, "a+")) == NULL) {
		// stdout에 출력하면 console 입력
		// stderr도 비슷하게 사용됨
		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	/*
	fscanf(stdin, "%30s", words) == 1
	stdin 사용한 경우 : scanf와 동일하게 작동
	words에 입력받은 내용 받아들임
	== 1 : 입력 받은 것이 하나인지 (입력을 잘 받았는지) 확인

	words[0] != '.'
	입력 받은 첫 글자가 마침표면 종료

	fprintf(fp, "%s\n", words)
	fp에 프린트하고, 문자열 words를 "%s\n" 형태로 출력함
	*/ 
	while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
		fprintf(fp, "%s\n", words);

	// ★ fgets는 EOF 파일을 만나면 NULL 값 반환함
	/*while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
		fputs(words, fp);*/

	/*
	rewind : go back to beginning of file
	fprint하면 계속 출력하면서,
	커서가 파일의 마지막 부분으로 가는데
	rewind를 하면 커서를 파일의 제일 첫 부분으로 옮김

	이후 while문을 보면 파일 첫 번째 글자부터
	fscanf로 한 단어씩 다시 읽어서 배열 words로 저장
	*/
	rewind(fp);

	while (fscanf(fp, "%s", words) == 1)  // != EOF
		fprintf(stdout, "%s\n", words);

	/*while (fgets(words, MAX, fp) != NULL)
		fputs(words, stdout);*/

	// 파일이 닫히지 않는 경우
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");	

	return 0;
}
 
// ======================================================================
/*
텍스트 파일을 바이너리처럼 읽어보기
file 글자가 하나도 깨지지 않고 정상적으로 잘 출력됨

1) test.txt 파일 생성
2) test.txt 파일 내용
   ABC
   DE
   123
   C언어

3) ASCII CODE 출력값 :
65 A
66 B
67 C
13
10

68 D
69 E
13
10

49 1
50 2
51 3
13
10

67 C
236
150
184
236
150
180
-> ASCII CODE가 3개 씩 묶여서 한글 한 개를 나타낸다는 것 알 수 있음
   13 10 : 줄바꿈
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>   // SetConsoleOutputCP()

int main() {

	// binary로 파일 open
	FILE* fp = fopen("test.txt", "rb");

	unsigned char ch;

	// UTF-8 mode
	SetConsoleOutputCP(CP_UTF8);

	// fread(&ch, sizeof(unsigned char), 1, fp)
	// - 1byte 씩 파일 읽기
	// fread 함수의 반환값 : 읽은 데이터 양
	// - 따라서, 반환값이 0이면 EOF라는 의미
	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0) {
		
		// binary 파일로 open해서 열어도
		// file 글자가 하나도 깨지지 않고 정상적으로 잘 출력됨
		printf("%c", ch);

		// ASCII code, 원래  글자 출력
		// printf("%hhu %c\n", ch, ch);
	}

	fclose(fp);

	return 0;
}
