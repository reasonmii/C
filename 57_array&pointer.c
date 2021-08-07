#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// Two of 1D arrays

	int arr0[3] = { 1, 2, 3 };
	int arr1[3] = { 4, 5, 6 };

	// an array of pointers
	int* parr[2] = { arr0, arr1 };

	// 1(== 1, 1, 1) 2(== 2, 2, 2) 3(== 3, 3, 3)
	// 4(== 4, 4, 4) 5(== 5, 5, 5) 6(== 6, 6, 6)
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < 3; ++i)
			// ★ *(parr + j) -> 주소값 반환
			printf("%d(==%d, %d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i), (*(parr + j))[i]);
		printf("\n");
	}
	printf("\n");

	// -------------------------------------------
	// 2D arrays are arrays of 1D arrays

	int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

	int* parr0 = arr[0];
	int* parr1 = arr[1];

	// 1 2 3
	// 4 5 6
	for (int i = 0; i < 3; ++i)
		printf("%d ", parr0[i]);
	printf("\n");

	for (int i = 0; i < 3; ++i)
		printf("%d ", parr1[i]);
	printf("\n\n");

	// -------------------------------------------
	// arrays of pointers works like a 2D array

	int arr3[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int* parr3[2];
	parr3[0] = arr3[0];
	parr3[1] = arr3[1];

	/*1 1 1 1
	  2 2 2 2
	  3 3 3 3

	  4 4 4 4
	  5 5 5 5
	  6 6 6 6*/
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < 3; ++i)
			printf("%d %d %d %d\n",
				arr3[j][i], parr3[j][i], *(parr3[j] + i), *(*(parr3 + j) + i));
		printf("\n");
	}
	printf("\n");

	// -------------------------------------------
	// 배열과 포인터의 배열의 차이

	printf("%p\n", &parr3[0]);   // 0098F990 : 포인터 자체의 주소
	printf("%p\n", parr3[0]);    // 0098F9A0 : 가리키고 있는 주소
	printf("%p\n", arr3);        // 0098F9A0
	printf("%p\n", &arr3[0]);    // 0098F9A0
	printf("%p\n", arr3[0]);     // 0098F9A0
	printf("%p\n", &arr3[0][0]); // 0098F9A0

	// -------------------------------------------
	// Array of string of diverse lengths example

	char* name[] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie" };

	// n : 4
	const int n = sizeof(name) / sizeof(char*);

	// ×64인 경우, unsinged가 아닌 unsinged long long 사용해야 함
	// Aladdin at 1473508
	// Jasmine at 1473780
	// Magic Carpet at 1473788
	// Genie at 1474096
	for (int i = 0; i < n; ++i)
		printf("%s at %u\n", name[i], (unsigned)name[i]);
	printf("\n");

	char aname[][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar" };
	const int an = sizeof(aname) / sizeof(char[15]);

	// 위와 달리 정확히 주소가 15씩 차이남
	// 15라는 공간을 만들고 단어를 각각 하나씩 채우는 방식
	// Aladdin at 14350260
	// Jasmine at 14350275
	// Magic Carpet at 14350290
	// Genie at 14350305
	// Jafar at 14350320
	for (int i = 0; i < an; ++i)
		printf("%s at %u\n", aname[i], (unsigned)&aname[i]);
	printf("\n");

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f }, {5.0f, 6.0f, 7.0f, 8.0f} };

	// ※ ×64 : use unsinged long long
	printf("%u\n", (unsigned)arr2d);    // 5242504
	printf("%u\n", (unsigned)arr2d[0]); // 5242504
	printf("\n");

	// arr2d points to arr2d[0] (not arr2d[0][0]) - KNK Ch. 12.4
	// 개념상 arr2d가 가리키는 주소는 arr2d[0]임
	// arr2d[0][0]은 메모리 공간에 있는 값을 의미
	printf("%u\n", (unsigned)* arr2d);         // 5242504
	printf("%u\n", (unsigned)& arr2d[0]);      // 5242504 : C language allows this
	printf("%u\n", (unsigned)& arr2d[0][0]);   // 5242504
	printf("%f %f\n", arr2d[0][0], **arr2d);   // 1.000000 1.000000 : 값 출력
	printf("\n");

	// float 4byte * 4 = 16byte를 건너뛴다는 의미
	printf("%u\n", (unsigned)arr2d + 1);        // 5242505
	printf("%u\n", (unsigned)&arr2d[1]);        // 5242520
	printf("%u\n", (unsigned)arr2d[1]);         // 5242520
	printf("%u\n", (unsigned)(*(arr2d + 1)));   // 5242520
	printf("%u\n", (unsigned)&arr2d[0] + 1);    // 5242505
	printf("%u\n", (unsigned)&arr2d[1][0]);     // 5242520
	printf("\n");

	// 값 출력
	printf("%f\n", *(*(arr2d + 1) + 2));        // 7.000000
	printf("\n");

	// [0] = 5242504, 5242504
	// [0][0] = 1.000000, 1.000000
	// [0][1] = 2.000000, 2.000000
	// [0][2] = 3.000000, 3.000000
	// [0][3] = 4.000000, 4.000000
	// [1] = 5242520, 5242520
	// [1][0] = 5.000000, 5.000000
	// [1][1] = 6.000000, 6.000000
	// [1][2] = 7.000000, 7.000000
	// [1][3] = 8.000000, 8.000000
	for (int j = 0; j < 2; ++j) {
		printf("[%d] = %u, %u\n", j, (unsigned)(arr2d[j]), (unsigned)*(arr2d + j));
		for (int i = 0; i < 4; ++i) {
			printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));
			*(*(arr2d + j) + i) += 1.0f;    // arr2d[j][i] += 1.0f;
		}
	}
	printf("\n");

	return 0;
}

// ======================================================================
// Pointers to Multidimensional Arrays

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f }, {5.0f, 6.0f, 7.0f, 8.0f} };

	// a SINGLE pointer to an array of 4 float
	// 4개의 float를 가진 배열에 대한 단일 포인터
	float(*pa)[4];

	// an array of TWO pointers-to-float
	// 원소가 2개인 포인터의 배열
	float* ap[2];

	printf("%zu\n", sizeof(pa));    // 4 : 포인터 1개니까 4byte
	printf("%zu\n", sizeof(ap));    // 8 : 포인터 2개니까 4byte * 2 = 8byte
	printf("\n");

	// 단일포인터이기 때문에 배열처럼 사용 불가
	// 첫 번째 주소를 대입할 수는 있음
	pa = arr2d;
	// pa[0] = arr2d[0];  -> ERROR
	// pa[1] = arr2d[1];  -> ERROR

	// ap = arr2d;        -> ERROR
	// 포인터의 배열이기 때문에 아래와 같이 초기화 해야 함
	ap[0] = arr2d[0];
	ap[1] = arr2d[1];

	printf("%u %u\n", (unsigned)pa, (unsigned)(pa + 1));       // 10746488 10746504
	printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]); // 10746488 10746504
	printf("%u %u\n", (unsigned)pa[0], (unsigned)(pa[0] + 1)); // 10746488 10746492
	printf("%f\n", pa[0][0]);          // 1.000000
	printf("%f\n", *pa[0]);            // 1.000000
	printf("%f\n", **pa);              // 1.000000
	printf("%f\n", pa[1][3]);          // 8.000000
	printf("%f\n", *(*(pa + 1) + 3));  // 8.000000
	printf("\n");

	// ap에 arr2d를 그대로 담은 것이 아닌,
	// 포인터를 담는 배열이 새로 생겨났기 때문에 주소가 다름
	printf("%u %u\n", (unsigned)ap, (unsigned)(ap + 1));        // 10746460 10746464

	printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);  // 10746488 10746504
	printf("%u %u\n", (unsigned)ap[0], (unsigned)(ap[0] + 1));  // 10746488 10746492
	printf("%f\n", ap[0][0]);          // 1.000000
	printf("%f\n", *ap[0]);            // 1.000000
	printf("%f\n", **ap);              // 1.000000
	printf("%f\n", ap[1][3]);          // 8.000000
	printf("%f\n", *(*(ap + 1) + 3));  // 8.000000
	printf("\n");

	return 0;
}

// ======================================================================
/*
In higher dimensions,
you may omit the value in the left-most bracket
고차원 배열에서 보통 가장 왼쪽 값은 생략 []
다른 값은 입력해야 함

예시)
int my_function(int ar[][3][5][8], int rows);
int my_function(int (*ar)[][3][5][8], int rows);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ROWS 3
#define COLS 4

// 배열의 가장 왼쪽 [] ROWS자리는 Compiler가 빈칸으로 인식함
// 따라서 생략해도 상관 없음
int sum2d_1(int ar[ROWS][COLS]);

int sum2d_2(int ar[][COLS], int row);
// 방법2)
// int sum2d_2(int [][COLS], int row);
// 방법3)
// ar is a SINGLE pointer to the array of COLS ints
// COLS 개수만큼의 배열을 갖는 배열에 대한 단일 포인터
// int sum2d_2(int (*ar)[COLS], int row);

// 동적할당에서 사용하는 방법
// 실제 다차원 배열에서 많이 사용
int sum2d_3(int *ar, int row, int col);
// 방법2) 변수 이름 생략 가능
// int sum2d_3(int*, int, int);

int main() {

	int data[ROWS][COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 0, 1, 2}
	};

	// 배열의 원소 접근하기
	printf("%d\n", data[2][3]);

	// data[2][3]
	// 배열의 첫 번째 원소 포인터를 활용해
	// 포인터 연산으로 배열 접근하기
	int* ptr = &data[0][0];
	printf("%d\n", *(ptr + 3 + COLS * 2));

	printf("Sum of all elements = %d\n", sum2d_1(data));
	printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
	printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));


	return 0;
}

int sum2d_1(int ar[ROWS][COLS]) {
	int r, c, tot = 0;
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
	return tot;
}

int sum2d_2(int ar[][COLS], int row) {
	int r, c, tot = 0;
	for (r = 0; r < row; r++)
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
	return tot;
}

int sum2d_3(int* ar, int row, int col) {
	int r, c, tot = 0;
	for (r = 0; r < row; r++)
		for (c = 0; c < col; c++)
			tot += *(ar + c + col * r);  // ar[c + col * r]
	return tot;
}
