/*
● calloc : contiguous allocation
ex) calloc(5, sizeof(int))
    4byte인수 5개 = 20byte -> 20byte의 연속된 메모리 공간 받기

★ malloc과 큰 차이
- malloc은 메모리를 할당만 받고 값을 초기화하진 않음
- calloc은 0으로 초기화된 메모리를 받음

● realloc(ptr, n) (KNK p.422)
- ptr : 이미 동적할당으로 받아서 가지고 있는 메모리의 포인터
- n : 새로 할당받고 싶은 메모리 크기

1) doesn't initialize the bytes added
   새로 요청한 메모리 크기가 이전보다 큰 경우,
   기존 값은 자동으로 복사해주지만,
   새로 추가된 부분을 초기화해주진 않음 (쓰레기값)
2) returns NULL if can't enlarge the memory block
   메모리를 더 키울 수 없는 경우 return NULL
3) if first argument is NULL, it behaves like malloc()
4) if second argument is 0, it frees the memory block

ex) 100개 메모리 받아서 값 넣었는데 200개 메모리가 필요한 상황
    200개 메모리를 새로 받고
    이전의 100개 메모리에 있던 값을 복사해서 200개 메모리에 넣고
    100개 메모리는 반납
    -> realloc : 이 과정을 한 번에 하게 해 줌
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 10;

	int* ptr = NULL;

	ptr = (int*)calloc(n, sizeof(int));
	if (!ptr) exit(1);

	// result : 0 0 0 0 0 0 0 0 0 0
	// malloc과 달리 자동으로 초기화 됨
	// 쓰레기 값이 아닌 0 출력
	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]);
	printf("\n");
	

	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));

	// ※ 실무에서는 같은 포인터로 받기도 함
	// ptr = (int*)realloc(ptr, n * sizeof(int));

	// 00A26D48 00A26D48
	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);   // 1

	if (!ptr2) exit(1);
	else
		// 원래 포인터는 NULL값으로 비우기
		ptr = NULL;

	// result : 1 2 3 4 5 6 7 8 9 10
	//			-842150451 -842150451 -842150451
	//			-842150451 -842150451 -842150451
	//			-842150451 -842150451 -842150451 -842150451
	// 앞부분은 기존 값 자동으로 복사
	// ★ 새로 추가된 메모리 부분은 쓰레기 값 출력
	for (int i = 0; i < n; ++i)
		printf("%d ", ptr2[i]);
	printf("\n");

	free(ptr2);

	return 0;
}
