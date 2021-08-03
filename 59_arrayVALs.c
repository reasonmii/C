/*
Variable - Length Arrays(VLAs)
변수로 길이를 정할 수있는 배열

★ Visual Studio에서 지원하지 않음
C online compiler 사용하기 : https://replit.com/languages/c
*/

#include <stdio.h>

#define ROWS 3
#define COLS 4

// 매개변수에서 배열을 선언 할 때도
// 이처럼 row, col 값을 배열에 지정하는 가변 길이 배열 활용 가능
int sum2d_4(int row, int col, int ar[row][col]){
	int r, c, tot = 0;
	for (r = 0; r < row; r++)
		for (c = 0; c < col; c++)
			tot += ar[r][c];
	return tot;
}

int main() {
    int n;

	printf("Input array length : ");
	scanf("%d", &n);

	// 가변 길이 배열에서는 변수를 넣을 수 있음
	// 그러나 한 번 선언되면 길이 변경 불가
	// ★ Cannot change length after declaration
	float my_arr[n];

	for(int i = 0; i < n; ++i)
		my_arr[i] = (float)i;

	for(int i = 0; i < n; ++i)
		printf("%f\n", my_arr[i]);

	int data[ROWS][COLS] = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 0, 1, 2}
	};

	printf("%d\n", sum2d_4(ROWS, COLS, data));

	return 0;
	
}
  
