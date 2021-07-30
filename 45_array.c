#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_DAYS 365

int main() {

	char my_chars[] = "Hello, World!";

	int daily_temperature[NUM_DAYS];
	double stock_prices_history[NUM_DAYS];

	printf("%d\n", sizeof(stock_prices_history));      // 2920 : 8 * 365
	printf("%d\n", sizeof(double) * NUM_DAYS);         // 2920
	printf("%d\n", sizeof(stock_prices_history[0]));   // 8 : double 1개

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {
	int i = 0;
	int a[5];

	// 배열 초기화
	for (i = 0; i < 5; i++) {
		a[i] = i + 1;
	}

	// 배열 출력
	for (i = 0; i < 5; i++) {
		// a[0] ~ a[4] -> 1 ~ 5
		printf("a[%d] = %3d \n", i, a[i]);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	int a = 1;
	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

	// 10개 배열인데 그보다 더 뒤 메모리 접근하려는 경우
	// 에러 : exited with code -1073741819
	printf("%i\n", int_arr[10000]);

	return 0;
}

// ======================================================================

#include <stdio.h>

void main() {
	// 3차원 배열 입출력
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

// ======================================================================

#include <stdio.h>
#define SIZE 5

int main(void) {
	int i = 0;
	int a[SIZE];

	// 배열 초기화
	for (i = 0; i < SIZE; i++) {
		a[i] = 0;
	}

	// 배열 출력
	for (i = 0; i < SIZE; i++) {
		// a[0] ~ a[SIZE] -> 1 ~ SIZE
		printf("a[%d] = %3d \n", i, a[i]);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>
#define SIZE 5

int main(void) {
	int i = 0;
	int a[SIZE];

	// 배열 초기화
	for (i = 0; i < SIZE; i++) {
		a[i] = i + 1;
	}

	// 배열 출력
	for (i = 0; i < SIZE; i++) {
		// a[0] ~ a[SIZE] -> 1 ~ SIZE
		printf("a[%d] = %3d \n", i, a[i]);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>
#define SIZE 20

int main(void) {
	int i = 0;
	int a[SIZE];

	// 배열 초기화
	for (i = 0; i < SIZE; i++) {
		// 1 ~ 99까지 숫자
		a[i] = rand() % 100 + 1;
	}

	// 배열 출력
	for (i = 0; i < SIZE; i++) {
		// a[0] ~ a[SIZE] -> 1 ~ SIZE
		printf("a[%d] = %3d \n", i, a[i]);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void) {
	int i = 0;
	int score[SIZE];

	// 배열 초기화
	// ★ 반드시 & 붙여야 함
	// ★ scanf("%d", score); -> score array의 [0]번째 값으로 입력됨
	for (i = 0; i < SIZE; i++) {
		printf("%d번째 학생의 점수는? ", i + 1);  // 점수 입력
		scanf("%d", &score[i]);
	}

	// 배열 출력
	for (i = 0; i < SIZE; i++) {
		printf("score[%2d] = %3d \n", i, score[i]);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void) {
	int i = 0;
	int score[] = { 1, 2, 3 };

	int size = sizeof(score) / sizeof(score[1]);

	// 배열 출력
	// SIZE가 5라도 SCORE에 3까지만 값이 있으면 SCORE SIZE에 맞춰서 3까지만 출력
	for (i = 0; i < size; i++) {
		printf("score[%2d] = %3d \n", i, score[i]);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>
#define SIZE 5

int main(void) {
	int i = 0;

	// 배열 a는 초기화 시키고 b는 초기화하지 않음
	int a[SIZE] = { 1, 2, 3, 4, 5 }, b[5];

	// 배열 복사하기
	for (i = 0; i < SIZE; i++)
		b[i] = a[i];

	// 배열 출력
	for (i = 0; i < SIZE; i++) {
		printf("a[%2d] = %3d \t", i, a[i]);
		printf("b[%2d] = %3d \n", i, b[i]);
	}

	// 배열로 확인 -> 결과 : 달라요
	if (a == b)
		printf("같아요 \n");
	else
		printf("달라요 \n");

	// 원소 별 확인 -> 결과 : 같아요
	for (i = 0; i < SIZE; i++) {
		if (a[i] != b[i]) {
			printf("달라요 \n");
			return 0;
		}
	}
	printf("같아요\n");

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

