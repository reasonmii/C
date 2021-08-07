/*
Compound Literals 복합 리터럴
- 같은 자료형 or 다른 자료형을 묶는 것
- Literals are constants that aren't symbolic : 이름이 없는 자료 묶음
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define COLS 4

int sum_1d(int ar[], int n);
int sum_2d(int ar[][COLS], int row);

int main() {

	int a = 1;
	3;                     // Literal
	3.14f;
	int b[2] = { 3, 4 };

	// 배열을 Compound Literal로 표현
	// ※ literal : 이름이 없는 상수
	(int[2]) {3, 4};

	// ERROR
	// int c[2] = (int[2]){ 3, 4 };

	int arr1[2] = { 1, 2 };
	int arr2[2][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	
	printf("%d\n", sum_1d(arr1, 2));  // 3
	printf("%d\n", sum_2d(arr2, 2));  // 36
	printf("\n");

	// Compound Literal를 함수에 argument로 직접 보내기 가능
	printf("%d\n", sum_1d((int[2]) { 1, 2 }, 2));                               // 3
	printf("%d\n", sum_2d((int[2][COLS]){ { 1, 2, 3, 4 }, {5, 6, 7, 8} }, 2));  // 36
	printf("\n");

	int* ptr1;
	int(*ptr2)[COLS];   // COLS만큼 원소를 갖는 배열에 대한 포인터

	// Compound Literal 직접 포인터에 대입 가능
	ptr1 = (int[2]){ 1, 2 };
	ptr2 = (int[2][COLS]){ {1, 2, 3, 4}, {5, 6, 7, 8} };

	printf("%d\n", sum_1d(ptr1, 2));  // 3
	printf("%d\n", sum_2d(ptr2, 2));  // 36
	printf("\n");

	return 0;
}

int sum_1d(int ar[], int n) {
	int tot = 0;
	for (int i = 0; i < n; ++i)
		tot += ar[i];
	return tot;
}

int sum_2d(int ar[][COLS], int row) {
	int tot = 0;
	for (int r = 0; r < row; r++)
		for (int c = 0; c < COLS; c++)
			tot += ar[r][c];
	return tot;
}
