#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");

	// 정수를 입력하지 않으면 status는 0이 됨
	// status = scanf("%d", &num);

	while (scanf("%d", &num) == 1) {
		sum += num;
		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d", sum);
	return 0;
}

/*
※ Pseudo Code
Initialize sum to 0
Prompt user
Read input
While the input is an integer
  Add the input to sum,
  Prompt user,
  Then read next input
After input complete, print sum
*/

while (scanf("%d", &num) == 1) {
	// do something with num
}

/*
※ Pseudo Code
while getting and testing the value succeeds
  Process the value
*/

