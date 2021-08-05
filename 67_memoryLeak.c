/*
메모리 누수 Leak 확인하기
★ 상단 x86->x64 변경 : Heap 메모리 공간을 더 크게 사용 가능

아래 printf("Dummy Output\n") 줄에 debug 포인트 찍기
Debug 하면 오른쪽에 Diagnostic Tools 나타남
- 하단 Memory Usage
- 한 줄 실행할 때마다 'Take Snapshot'으로
  Heap Size 내 메모리가 차지하는 크기 확인할 것

int* ptr = (int*)malloc(n * sizeof(int));
이 부분 지나면 메모리가 39만 Kbyte로 급증함

마지막 printf("Dummy Output\n"); 줄 우클릭
- ★ Run to Cursor : 해당 부분으로 debugging 점프

free(ptr); 을 쓰지 않은 경우
Diagnostic Tools - Memory Usage - Take Snapshot
Block 나가면 더이상 ptr 변수가 존재하지 않는데도
메모리 공간 그대로 차지하고 있음
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	printf("Dummy Output\n");  	// debug 포인트 찍기

	{
		// 4억 byte / (1024 * 1024)
		// -> 381 megabyte 정도 크기임
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		// if(ptr == NULL)
		if (!ptr) {
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		// 메모리를 동적할당배열처럼 사용
		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		free(ptr);
		ptr = NULL;
	}

	printf("Dummy Output\n");  // debug 포인트 찍기

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	printf("Dummy Output\n");  	// debug 포인트 찍기

	// ★ block을 나와도 free()를 하지 않았으면
	// block에서 정의한 ptr 내 값에 접근할 수 있음
	// backup pointer에 block을 내 ptr 포인터를 옮겨놓으면 됨
	// 권장하지 않는 방법임
	int* ptr_backup = NULL; // ★
	{

		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr) {
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		printf("%d %d\n", ptr[0], ptr[1]); // 1 2

		ptr_backup = ptr; // ★ 이때는 절대 free(ptr); 하면 안 됨

	}

	printf("%d %d\n", ptr_backup[0], ptr_backup[1]); // 1 2
	printf("Dummy Output\n");  // debug 포인트 찍기

	return 0;
}

// ======================================================================
/*
메모리 누수 일부러 만들어보기
★ 위험하니 반드시 Debug 포인트 찍고 Debug로 확인할 것

1) F10 클릭 : Debugging 시작
   Diagnostic Tools - Memory Usage - Take Snapshot
2) F5 클릭 : continue
   Diagnostic Tools - Memory Usage - Take Snapshot
3) F5 클릭 : continue
   Diagnostic Tools - Memory Usage - Take Snapshot
-> 계속 반복하면 Memory가 무한히 증가하는 것 볼 수 있음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	printf("Dummy Output\n");  	// debug 포인트 찍기

	for(int k = 0; k < 1000000; ++k)
	{

		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr) {
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		printf("%d %d\n", ptr[0], ptr[1]); // 1 2

	}

	printf("Dummy Output\n");  // debug 포인트 찍기

	return 0;
}

