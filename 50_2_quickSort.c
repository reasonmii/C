// 함수 포인터 사용
// int 오름차순 정렬하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// TODO: try increasing/decreasing order
int compare(const void* first, const void* second) {

	if (*(int*)first > *(int*)second)
	// if (*(int*)first < *(int*)second)      // DESC
		return 1;
	else if (*(int*)first < *(int*)second)
	// else if (*(int*)first > *(int*)second) // DESC
		return -1;
	else
		return 0;

}

int main() {

	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// C언어에서 자체적으로 qsort 제공 중
	// 단, compare 함수는 직접 만들어야 함
	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}

// ======================================================================
// float 오름차순 정렬하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second) {

	if (*(float*)first > *(float*)second)
	// if (*(float*)first < *(float*)second)      // DESC
		return 1;
	else if (*(float*)first < *(float*)second)
	// else if (*(float*)first > *(float*)second) // DESC
		return -1;
	else
		return 0;

}

int main() {

	float arr[] = { 8.1f, 2.4f, 3.6f, 6.7f, 11.5f };
	int n = sizeof(arr) / sizeof(arr[0]);

	// C언어에서 자체적으로 qsort 제공 중
	// 단, compare 함수는 직접 만들어야 함
	qsort(arr, n, sizeof(float), compare);

	// result : 2.400000 3.600000 6.700000 8.100000 11.500000
	for (int i = 0; i < n; i++)
		printf("%f ", arr[i]);

	return 0;
}

// ======================================================================

/*
구조체 member 값에 따라 정렬하기

키에 따라 정렬하기
Jack Jack       40
Piona           150
Aladdin         170
Genie           300
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct kid {
	char name[100];
	int height;
};

// Try increasing/decreasing order
int compare(const void* first, const void* second);

int main() {

	struct kid my_friends[] = {
		"Jack Jack", 40, "Genie", 300, "Aladdin", 170, "Piona", 150
	};

	const int n = sizeof(my_friends) / sizeof(struct kid);

	qsort(my_friends, n, sizeof(struct kid), compare);

	for (int i = 0; i < n; i++)
		printf("%s    \t%d\n", my_friends[i].name, my_friends[i].height);

	return 0;
}

int compare(const void* first, const void* second) {

	if (((struct kid*)first)->height > ((struct kid*)second)->height)
		return 1;
	else if (((struct kid*)first)->height < ((struct kid*)second)->height)
		return -1;
	else
		return 0;
}
