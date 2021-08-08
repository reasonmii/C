/*
기타 입출력 함수들

● ungetc()
- 읽은 글자를 다시 buffer에 넣음

● setvbuf()
- buffer의 설정 변경
- 파일에서 buffer로 올리고 읽는 과정은 느림
  따라서, 프로그램이 파일 내용을 계속 읽을 것으로 예상되는 경우,
  미리 buffer에 buffer size만큼 파일 내 글자들을 올려놓으면,
  이후 fgetc를 통해 파일을 읽는 속도가 더 빨라짐
- 파일을 읽는 것보다도 파일에 여러 글자를 한 번에 다 저장할 때 많이 사용됨
  이때 여러 옵션이 있음
  _IOLBF : Line을 하나씩 buffer에서 꺼내서 저장
  _IOFBF : Full - 통째로 buffer에서 꺼내서 저장
  _IONBF : No - buffer를 사용하지 않음

● fflush()
- buffer에 쌓여있던 데이터를 모두 내려보내라는 의미
- Writing a large amount of data
- Writing 할 데이터가 엄청 많은 상황
  buffer에 아직 데이터가 남아 있는데,
  파일, 디스크 등으로 완벽하게 출력을 못한 경우
  -> buffer가 빌 때까지 반드시 다 출력하라는 의미로 사용
- ex) fflush(fp);
*/

// ======================================================================
// ungetc()

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE* fp;
	int ch;

	// -------------------------------------------

	fp = fopen("input.txt", "r");

	ch = fgetc(fp);     // 첫 글자 읽고
	fputc(ch, stdout);  // 출력

	// ungetc() : 읽은 글자를 다시 buffer에 넣음
	ungetc(ch, fp);

	// 위에서 읽은 글자가 buffer에 다시 들어갔으니
	// 똑같은 첫 번째 글자가 또 출력됨
	ch = fgetc(fp);
	fputc(ch, stdout);

	// 두 번째 글자 출력됨
	ch = fgetc(fp);
	fputc(ch, stdout);

	fclose(fp);

	// -------------------------------------------

	fp = fopen("input.txt", "r");

	ch = fgetc(fp);     // 첫 글자 읽고
	fputc(ch, stdout);  // 출력

	// 첫 글자 있던 buffer 자리에 'A'를 넣음
	ungetc((int)'A', fp);

	// buffer에 제일 위에 'A'가 저장되어 있으니
	// 'A'가 출력됨
	ch = fgetc(fp);
	fputc(ch, stdout);

	fclose(fp);

	return 0;
}

// ======================================================================
// setvbuf()

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE* fp;
	int ch;

	fp = fopen("input.txt", "r");

	char buffer[50] = { '\0', };

	// 위에서 정의한 buffer[32]를 buffer로 사용
	// ★ _IONBF 사용하면 buffer를 쓰지 않겠다는 의미이기 때문에
	//   두 번째 dump buffer 출력해보면 빈공간 출력
	setbuf(fp, buffer, _IOFBF, sizeof(buffer));

	// dump buffer
	// 현재 buffer는 비어있기 때문에 '0' 50개 출력
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%hhd", buffer[i]);
	printf("\n");

	// Read just only a single character!
	ch = fgetc(fp);

	// dump buffer
	// 파일 내 글자를 위에서 딱 한 글자만 읽었는데
	// buffer 크기만큼 파일 내용이 다 담김
	// buffer를 출력해 보면 파일 첫 부분 50글자가 모두 들어 있음
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	fclose(fp);

	return 0;
}

