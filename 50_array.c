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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// symbolic constant, macro
#define MONTHS 12

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };
	
	// 평균 계산하기
	float avg = 0.0;
	for (int i = 0; i < MONTHS; ++i)
		avg += high[i];
	printf("Average = %f\n", avg / (float)MONTHS);

	// 한 번 초기화된 배열은 아래와 같이 변경 불가능
	//high = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	//high[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// symbolic constant, macro
#define MONTHS 12

int main() {

	// 배열은 0번부터 시작
	// ★ ERROR : high[12], high[-1]
	// -> 주의 : Compiler가 이 오류를 안 잡아주고 경고만 함
	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	// 평균 계산하기
	float avg = 0.0;
	for (int i = 0; i < MONTHS; ++i)
		avg += high[i];
	printf("Average = %f\n", avg / (float)MONTHS);

	// -------------------------------------------

	// 한 번 초기화된 배열은 아래와 같이 변경 불가능
	//high = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	//high[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	// -------------------------------------------

	// 주소 같음
	// 012FFB10 012FFB10
	printf("%p %p\n", high, &high[0]);

	/* 숫자가 4씩 증가
	15726608
	15726612
	15726616
	15726620
	15726624
	15726628
	15726632
	15726636
	15726640
	15726644
	15726648
	15726652*/

	for (int i = 0; i < MONTHS; ++i)
		printf("%lld\n", (long long)&high[i]);
	printf("\n");

	// -------------------------------------------

	// const and array
	// 해당 배열의 원소 값 변경 불가
	const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };

	// -------------------------------------------

	// When array is not initialized
	// result : -858993460 -858993460 -858993460 -858993460
	// ※ static int not_init[4] -> result : 0 0 0 0
	int not_init[4];
	for (int i = 0; i < 4; ++i)
		printf("%d ", not_init[i]);
	printf("\n");

	// -------------------------------------------

	// Partially initialized
	// result : 2 4 0 0
	// 개발자가 일부 초기화를 시도하면, 알아서 나머지는 0으로 초기화 함
	int insuff[4] = { 2, 4 };
	for (int i = 0; i < 4; ++i)
		printf("%d ", insuff[i]);
	printf("\n");

	// -------------------------------------------

	// Omitting size
	const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };
	printf("%d\n", sizeof(power_of_twos));     // 28 (4 * 7)
	printf("%d\n", sizeof(int));               // 4
	printf("%d\n", sizeof(power_of_twos[0]));  // 4

	// 1 2 4 8 16 32 64
	for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)
		printf("%d ", power_of_twos[i]);
	printf("\n");

	// -------------------------------------------

	// Designated initializers
	// [1] = 29 : index 1 값을 29로 하라고 덮어 썼으니 두 번째 값이 29가 됨
	// [4] 자리는 31
	// 31 29 0 0 31 30 31 0 0 0 0 0
	int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	for (int i = 0; i < MONTHS; ++i)
		printf("%d ", days[i]);

	// -------------------------------------------

	// Specifying Array sizes
	int arr1[MONTHS];   // Symbolic integer constant
	double arr2[123];   // Literal integer constant
	float arr3[3 * 4 + 1];
	float arr4[sizeof(int) + 1];
	// float arr5[-10];   -> Error
	// float arr6[0];     -> Error
	// float arr7[1.5];   -> Error
	float arr8[(int)1.5];  // arr8[1] 과 같음

	// Variable-Length Array is optional from C11
	// Visual Studio에서는 ERROR
	// int n = 8;
	// float arr9[n];

	return 0;
}

// ======================================================================
// ★ 큰 데이터 처리할 때는 for loop 안에 여러 가지를 넣는 것보다
//    최대한 나눠서 여러 for loop 사용해서 처리하는 게 효율적 ex) Prepare, Print

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main() {

	int my_arr[SIZE];

	// Prepare for array data
	for (int i = 0; i < SIZE; ++i)
		my_arr[i] = i;

	// Print array data
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", my_arr[i]);     // 0 1 2 3 4

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main() {

	int numbers[SIZE];
	int sum = 0;
	int i;

	printf("Enter %d numbers :", SIZE);

	for (i = 0; i < SIZE; ++i)
		scanf("%d", &numbers[i]);

	for (i = 0; i < SIZE; ++i)
		sum += numbers[i];

	printf("sum = %d\n", sum);

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
// ERROR

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int my_numbers[5];

	// Runtime Error
	// out of bound : array[5]는 0~4까지만 가능
	my_numbers[5] = 123;
	printf("%d\n", my_numbers[5]);

	// Compile Error
	my_numbers = 7;

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

