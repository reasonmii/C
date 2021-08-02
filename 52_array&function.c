/*
함수에 배열을 전달하면 배열의 첫 번째 값의 주소가 전달됨
★ 즉, 배열은 자동으로 포인터로 인식됨
따라서, 배열 내 개수에 대한 인자는 따로 받아야 함

함수 선언 시 네 가지 경우 모두 가능
※ 어차피 배열은 포인터로 인식되기 때문
double average(double arr[], int n);
double average(double [], int n);
double average(double * arr, int n);
double average(double *, int n);
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double average(double arr[], int num) {

	double avg = 0.0;
	for (int i = 0; i < num; ++i)
		avg += arr[i];

	avg /= (double)num;
	return avg;
}

int main() {

	double arr1[5] = { 10, 13, 12, 7, 8 };
	double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	double arr3[3] = { 1.8, -0.2, 6.3 };

	printf("Address = %p\n", arr1);       // 0135FEA4
	printf("Size = %zd\n", sizeof(arr1)); // 40

	printf("Address = %p\n", arr3);       // 0135FE54
	printf("Size = %zd\n", sizeof(arr3)); // 24
	
	printf("Avg = %f\n", average(arr1, 5));   // 10.000000
	printf("Avg = %f\n", average(arr2, 5));   // 8.460000
	printf("Avg = %f\n", average(arr3, 3));   // 2.633333

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void) {
	int key, i, data[SIZE];   // 배열선언

	inArr(data, SIZE);        // 배열 초기화 함수 호출

	printf("정렬 전 \n");
	prtArr(data, SIZE);       // 배열 출력 함수 호출

	selectSort(data, SIZE);
	printf("정렬 후 \n");
	prtArr(data, SIZE);       // 배열 출력 함수 호출

	printf("찾을 숫자는? ");  // 배열 내 숫자 검색
	scanf("%d", &key);
	int n = biSearch(data, SIZE, key);
	if (n == -1)
		printf("찾는 숫자 %d는 없음", key);
	else
		printf("찾는 숫자 %d는 배열의 %d번째에 있음\n", key, n);

	return 0;
}


// 함수 정의
void inArr(int a[], int size) {
	// 배열 초기화
	for (int i = 0; i < SIZE; i++) {
		printf("%d번째 정수 : ", i + 1);
		scanf("%d", &a[i]);
	}
}

void prtArr(int a[], int size) {
	printf("==============================");
	for (int i = 0; i < SIZE; i++) {
		printf("data[%2d] = %3d \n", i, a[i]);
	}
}

// 선택 정렬 함수 정의
void selectSort(int a[], int size) {
	int i, j, minIndex, temp;
	for (i = 0; i < size - 1; i++)  // 세로이동
	{
		minIndex = i;
		for (j = i + 1; j < size; j++) // 가로이동
		{
			if (a[minIndex] > a[j])
				minIndex = j;
		}
		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}
}

// 검색 함수 정의
int biSearch(int a[], int size, int key) {
	int low = 0, high = size - 1, middle;
	while (low <= high) {
		printf("[%d - %d]", low, high);
		middle = (low + high) / 2;
		if (key == a[middle]) return middle;
		else if (key > a[middle]) low = middle + 1;  // 오른쪽으로 이동
		else                      high = middle - 1;
	}
	return -1;
}

