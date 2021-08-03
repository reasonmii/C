/*
fgets() and fputs() : 파일입출력

fgets(array's pointer, maximum size, file's pointer)
읽는 데이터가 언제 끝날지 모른다는 가정 하에
(데이터 사이즈를 모른다는 가정 하에) 데이터 받아들임
따라서, 실제 입력한 글자보다 두 번째 maximum size 인수를 작게 해도 Runtime Error 발생X
-> gets보다 안정적

fgets는 항상 반환값이 있음
보통은 입력 받은 포인터 값 반환
문제가 있는 경우 ex) 파일 입력을 받고 EOF를 만난 경우 -> NULL 값 반환

★ 'fgets' does not remove '\n'
파일 입출력에서는 파일 내용을 그대로 받아들여야 하기 때문에 좋은 기능
문자열을 입력 받을 때는 줄바꿈을 제거하지 않으니 번거로워질 수 있음

★ 'fputs' does not add '\n'
파일에서는 불필요한 부분 없이 필요한 데이터만
파일에 저장해야 하기 때문에 '\n' 따로 자동으로 추가하지 않음
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

	char words[STRLEN] = "";

	// does not remove \n
	// stdin : 파일이 아닌 콘솔창에 입력
	fgets(words, STRLEN, stdin);

	// replace '\n' with '\0'
	int i = 0;
	while (words[i] != '\n' && words[i] != '\0')
		i++;
	if (words[i] == '\n')
		words[i] = '\0';
	
	// does not add \n
	// stdout : 파일이 아닌 콘솔창에 출력
	fputs(words, stdout);
	fputs("END", stdout);
	
	return 0;
}

// ======================================================================
// Small array
// 입력 받은 데이터를 저장할 공간이 작은 경우

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 입력 : 1234567890 -> 출력 : 1234
	char small_array[5];
	puts("Enter long strings:");
	fgets(small_array, 5, stdin);   // FILE *_Stream
	fputs(small_array, stdout);

	/* 아래 결과 값은 같음
	printf("%p\n", small_array);
	printf("%p\n", fgets(small_array, 5, stdin));*/
  
	return 0;
}

// ======================================================================
// Repeating short reading -> buffer 사용
// 작은 buffer를 여러 번 재활용하며 큰 내용을 받아들이고 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// 아래 코드에서 fgets가 한 번에 받아들일 수 있는 건 5글자가 최대지만
	// 반복해서 받아들이고 반복해서 출력하면서
	// 긴 문자를 한 번에 받아들여서 출력하는 것처럼 보여질 수 있음

	char small_array[5];
	puts("Enter long strings:");
	while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
		fputs(small_array, stdout);

	
	return 0;
}

// ======================================================================



