#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // memcpy(), memmove()

#define LEN 6

void prt(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {

	/*
	- overlapping region
	- pointer-to-void (datatype is unknown)
	*/

	int arr1[LEN] = { 1, 3, 5, 7, 9, 11 };
	//int arr2[LEN] = { 0, };
	int* arr2 = (int*)malloc(LEN * sizeof(int));
	if (arr2 == NULL) exit(1);

	// memcpy와 memmove를 사용하지 않으면
	// for문으로 하나하나 작업해야 함
	for (int i = 0; i < LEN; ++i)
		arr2[i] = arr1[i];

	/*
	memcpy는 메모리를 통으로 복사
	★ memcpy(destination, source, memory byte)
	   destination과 source를 모두 void pointer로 받기 때문에
	   크기를 알 수 없음
	   memory byte 부분에서 정해준 크기만큼만 복사함
	   memcpy(arr2, arr1, sizeof(int) * LEN);
	*/
	prt(arr2, LEN);

	/*
	{ 1, 3, 5, 7, 9, 11 }
	-> 뒤 네 개 원소를 복사해서 앞에 붙여넣기
	-> 5, 7 부분이 복사하는 부분과 겹침
	   - memcpy는 이러한 경우 ERROR 발생 : undefined behavior
	   - memmove는 5 ~ 11 부분을 buffer를 거쳐
	     옮기는 방식이라 겹치는 부분이 있어도 ERROR 발생X
	-> ★ 즉, 복사할 때 겹치는 부분이 있으면 memcpy가 아닌 memmove 사용
	{ 5, 7, 9, 11, 9, 11 }

	*/
	memmove(arr1, &arr1[2], sizeof(int) * 4);
	// return 값 : destination -> arr1
	prt(arr1, LEN);

	return 0;
}
