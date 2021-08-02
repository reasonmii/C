// 2차원 배열과 메모리

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int arr[2][3] = { {1, 2, 3}, {4, 5,6} };
	
	printf("%d\n\n", arr[1][1]);    // 5

	// result
	// 1 2 3
	// 4 5 6
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < 3; ++i)
			printf("%d ", arr[j][i]);
		printf("\n");
	}
	printf("\n");

	// -------------------------------------------

	// 배열의 첫 주소를 포인터로 바꾸고
	// 1차원 배열인 것처럼 사용 가능
	// result : 1 2 3 4 5 6
	int* ptr = &arr[0][0];
	for (int k = 0; k < 6; ++k)
		printf("%d ", ptr[k]);
	printf("\n\n");

	// -------------------------------------------

	// result : 24 12
	// sizeof(arr) : 2행 * 3열 * 4byte = 24
	// sizeof(arr[0]) : 3열 * 4 byte = 12
	printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));

	return 0;
}

// ======================================================================
// 3차원 배열 입출력

#include <stdio.h>

void main() {
	int array[2][3][4];
	int i, j, k, value = 1;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				array[i][j][k] = value;
				printf("\narray[%d][%d][%d] = %d", i, j, k, array[i][j][k]);
				value++;
			}
		}
	}
}
