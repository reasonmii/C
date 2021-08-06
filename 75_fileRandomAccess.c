/*
File Random Access 파일 임의 접근

test.txt 파일 생성
내용 : ABCDEFGHIJKLMNOPQRSTUVWXYZ

작동원리
처음에 파일을 열면 커서가 0번째 있음
한 글자를 읽으면 커서가 1번째에 있음 = 1byte만큼 이동
두 글자를 읽으면 커서가 2번째에 있음 = 2byte만큼 이동
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	// ★ ftell()
	// 어디서부터 읽을 준비가 되어 있는지 위치 알려줌
	cur = ftell(fp);

	// result : 0
	// -> 시작점으로부터 0byte 떨어져 있다는 의미
	printf("ftell() = %ld\n", cur);

	// ★ fseek(filePointer, number, flag)
	// 2L : 2byte
	// SEEK_SET : 시작점
	// -> 시작점으로부터 2byte 떨어진 곳으로 이동한다
	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	
	// 파일 읽기
	printf("ftell() = %ld\n", cur);   // 2
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);        // 67 C

	cur = ftell(fp);
	printf("ftel;() = %ld\n", cur);   // 3

	// ★ SEEK_CUR : 현재 위치에서 -2L만큼 이동
	// -2L : -2byte
	// -> 양수, 음수 모두 가능
	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);   // 1

	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);        // 66 B

	// ★ SEEK_END : 맨 끝으로 커서 이동
	// 0L만큼 이동하고 읽기
	// = 제일 끝에 커서 있음 = EOF = -1
	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);  // -1

	// -1L만큼 이동해서 읽기
	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);  // 90 Z
	
	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);  // 89 Y

	// -------------------------------------------
	/*
	파일이 어마어마하게 큰 경우)
	Visual Studio의 compiler에서는 fpos_t 사용하면 됨
	fpos_t 위에 커서 두면 long long으로 type define되어 있는 것 확인 가능

	※ fpos_t에 대한 형식 지정자가 존재하지 않음
	long long type으로 아주 큰 숫자인데
	여러 숫자들의 조합일 수도 있고 다양한 경우를 모두 받아들이기 위해
	일부러 %lld로 규정하지 않음
	*/

	fpos_t pt;
	pt = 10;

	// ★ fsetpos = fseek
	// 10위치로 이동 -> "K"
	fsetpos(fp, &pt);    // return 0 ok
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);   // 75 K

	// ★ fgetpos = ftell
	fgetpos(fp, &pt);
	printf("%lld\n", pt);        // 11

	return 0;
}

// ======================================================================
// Binary File Random Access

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// make a test binary file
	{
		FILE* fp = fopen("binary", "wb");
		for (int i = 0; i < 100; ++i) {
			double d = i * 1.11;
			fwrite(&d, sizeof(double), 1, fp);
		}
		fclose(fp);
	}
	
	// read

	FILE* fp = fopen("binary", "rb");
	long cur;
	double d;

	cur = ftell(fp);
	printf("Before reading %ld\n", cur); // 0

	// double을 저장한 파일이니,
	// 한 글자씩 읽으려면 double size로 읽어야 함
	// = 8 byte씩 이동
	fread(&d, sizeof(double), 1, fp);

	cur = ftell(fp);
	printf("After reading %ld\n", cur);  // 8 -> double : 8byte

	printf("%f\n", d);                   // 0.000000

	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d);                   // 1.110000

	cur = ftell(fp);
	printf("After reading %ld\n", cur);  // 16

	// 32 = 8 byte * 4개
	// -> double 4개만큼 앞으로 가서 이후 글자 읽기 (0, 1, 2, 3)
	// -> 4.440000 읽을 차례
	fseek(fp, 32L, SEEK_SET);
	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d);                   // 4.440000

	fclose(fp);

	return 0;
}
