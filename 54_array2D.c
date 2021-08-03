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

// ======================================================================
/*
기상청 데이터를 활용해서 아래와 같이 2차원 배열 프로그래밍하기

[Temperature Data]
Year Index :    1       2       3       4       5       6       7       8       9       10      11      12
Year 0     :    -3.2    0.2     7.0     14.1    19.6    23.6    26.2    28.0    23.1    16.1    6.8     1.2
Year 1     :    -1.8    -0.2    6.3     13.9    19.5    23.3    26.9    25.9    22.1    16.4    5.6     -1.9
Year 2     :    -4.0    -1.6    8.1     13.0    18.2    23.1    27.8    28.8    21.5    13.1    7.8     -0.6

[Yearly average temperatures of 3 years]
Year 0 : average temperature = 13.6
Year 1 : average temperature = 13.0
Year 2 : average temperature = 12.9

[Monthly average temperature for 3 years]
Year Index :    1       2       3       4       5       6       7       8       9       10      11      12
Avg temps :     -3.0    -0.5    7.1     13.7    19.1    23.3    27.0    27.6    22.2    15.2    6.7     -0.4
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main() {

	// 기상청 홈페이지
	// https://www.weather.go.kr/w/obs-climate/land/past-obs/obs-by-element.do?stn=108&yy=2018&obs=07
	double year2016[MONTHS] = { -3.2,  0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8,  1.2 };
	double year2017[MONTHS] = { -1.8, -0.2,	6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6,	8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

	double year[YEARS][MONTHS];

	for(int i = 0; i < YEARS; ++i)
		for (int j = 0; j < MONTHS; ++j) {
			if (i == 0)
				year[i][j] = year2016[j];
			else if (i == 1)
				year[i][j] = year2017[j];
			else
				year[i][j] = year2018[j];
		}

	printf("[Temperature Data]\n");

	printf("Year Index :");
	for (int i = 0; i < MONTHS; ++i)
		printf("\t%d", i+1);

	printf("\n");

	for (int i = 0; i < YEARS; ++i) {
		printf("Year %d\t   :", i);
		for (int j = 0; j < MONTHS; ++j) {
			printf("\t%.1f", year[i][j]);
		}
		printf("\n");
	}

	printf("\n[Yearly average temperatures of 3 years]\n");

	for (int i = 0; i < YEARS; ++i) {
		double avg = 0.0;
		for (int j = 0; j < MONTHS; ++j) {
			avg += year[i][j];
		}
		avg /= (double)MONTHS;
		printf("Year %d : average temperature = %.1f\n", i, avg);
	}

	printf("\n[Monthly average temperature for 3 years]\n");

	printf("Year Index :");
	for (int i = 0; i < MONTHS; ++i)
		printf("\t%d", i + 1);

	printf("\nAvg temps :");

	for (int j = 0; j < MONTHS; ++j) {
		double avg = 0.0;
		for (int i = 0; i < YEARS; ++i) {
			avg += year[i][j];
		}
		avg /= (double)YEARS;
		printf("\t%.1f", avg);
	}
	
	printf("\n");

	return 0;
}
