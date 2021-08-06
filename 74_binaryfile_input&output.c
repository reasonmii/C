/*
text 파일을 제외한
우리가 아는 거의 모든 파일은 binary file
ex) 한글, MS워드 등

fopen() mode string for binary IO
- "rb", "wb", "ab"
- "ab+", "a+b"
- "wb+", "w+b"
※ 'b' is for binary

C11 'x' mode fails if the file exists,
instead of overwriting it
- "wx", "wbx", "w+x", "wb+x", "w+bx"
*/

// ======================================================================
/*
Writing example
실행해보면 경로에 binary_file 생김
- 우클릭 - 속성 - 크기 확인 : 정확히 '504바이트'라고 써 있음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	{
		// Open new file
		FILE* fp = fopen("binary_file", "wb");

		double d = 1.0 / 3.0;
		int n = 123;

		// 동적배열
		int* parr = (int*)malloc(sizeof(int) * n);

		if (!parr) exit(1);

		// 동적배열 데이터 초기화
		for (int n = 0; n < 123; ++n)
			*(parr + n) = n * 2;

		// fwrite(주소, size, 개수, 파일 포인터);
		fwrite(&d, sizeof(d), 1, fp);
		fwrite(&n, sizeof(n), 1, fp);
		fwrite(parr, sizeof(int), n, fp);

		fclose(fp);
		free(parr);

		/*
		Total size is 504bytes
		- double : 8byte * 1
		- int : 4byte * 1
		- int array : 4byte * 123
		*/
	}

  return 0;
}

// ======================================================================













