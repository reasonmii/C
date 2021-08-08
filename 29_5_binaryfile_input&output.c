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

	return 0;
}

// ======================================================================
/*
Reading example
feof(), ferror()

파일을 읽기 위해선 해당 binary file이 어떤 구조인지, 순서가 어떻게 되는지,
어떤 형식으로 작성되었는지 (double, int, etc.)
해당 형식을 몇 개 사용했는지 등을 알고 있어야 해독 가능

★ 실제로는 여러 가지 큰 데이터를 한 번에 쭉 읽어야 하는 경우가 많은데
   그 때는 항상 동적할당 사용할 것
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* fp = fopen("binary_file", "rb");
	double d;
	int n = 0;

	// 우리는 위에서 만든 파일을 읽을 것이기 때문에
	// double 1개, int 1개, int 동적배열로 만들어진 파일이라는 것 알고 있음
	// 해당 형식으로 읽기
	fread(&d, sizeof(d), 1, fp);
	fread(&n, sizeof(n), 1, fp);

	int* parr = (int*)malloc(sizeof(int) * n);
	if (!parr) exit(1);

	fread(parr, sizeof(int), n, fp);

	// ★ feof : End Of File을 만났는지 확인하는 함수
	// 위에서 정확히 만들어진 내용만큼만 읽었기 때문에
	// 아직 EOF를 만나지는 않음 (만나기 직전)
	printf("feof = %d\n", feof(fp));       // 0

	printf("%f\n", d);                     // 0.333333
	printf("%d\n", n);                     // 123
	for (int i = 0; i < n; ++i)
		// 0 2 4 6 8 10 12 ...
		printf("%d ", *(parr + i));
	printf("\n");

	printf("feof = %d\n", feof(fp));       // 0

	// read one more toward EOF
	// 아직 EOF를 만나지 않은 상태에서
	// 4byte만 더 읽어보기
	// ※ n이 int니까 4byte
	fread(&n, sizeof(n), 1, fp);

	// returns non-zero at EOF
	// 이제 EOF를 만났으니 0이 아닌 값 반환
	printf("feof = %d\n", feof(fp));       // 1

	// returns 0 : ok
	// 파일을 읽는동안 문제가 있었는지 확인
	printf("ferror = %d\n", ferror(fp));   // 0

	// try writing to make an error
	// EOF까지 온 상태에서 강제로 writing 시도
	// 그런데 이 파일은 위에서 "rb"로 열었기 때문에 read mode
	// -> writing을 할 수 없음
	fwrite(&n, sizeof(n), 1, fp);

	// 0 is ok, non-zero otherwise
	printf("ferror = %d\n", ferror(fp));   // 1

	fclose(fp);
	free(parr);

	return 0;
}
