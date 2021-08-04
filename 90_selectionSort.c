/*
Selection Sort Algorithm
https://www.geeksforgeeks.org/selection-sort/

64 25 12 22 11 (min_idx = 0)
   64          (min_idx = 0)
   25          (min_idx = 1)
      25       (min_idx = 1)
	  12       (min_idx = 2)
	     12    (min_idx = 2)
		    12 (min_idx = 2)
			11 (min_idx = 4)
11 25 12 22 64 (swap arr[0] and arr[4])
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* xp, int* yp);
void printArray(int arrp[], int size);
void selectionSort(int arr[], int n);

int main() {

	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// ascending order
	selectionSort(arr, n);

	printArray(arr, n);

	return 0;
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printArray(int arrp[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arrp[i]);
	printf("\n");
}

void selectionSort(int arr[], int n) {

	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	// ★ Note : n - 1
	for (i = 0; i < n - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		// ★ Note : n
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

// ======================================================================
/*
문자열의 포인터 정렬하기
Cherry
AppleBee
Pineapple
Apple
Orange

Apple
AppleBee
Cherry
Orange
Pineapple
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   // strcmp()

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);

	// ascending order
	selectionSort(arr, n);

	printStringArray(arr, n);

	return 0;
}

void swap(char** xp, char** yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printStringArray(char* arr[], int size) {
	for (int i = 0; i < size; i++)
		puts(arr[i]);
	printf("\n");
}

void selectionSort(char* arr[], int n) {

	int i, j, min_idx;

	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (strcmp(arr[j], arr[min_idx]) < 0)
				min_idx = j;
		}
		swap(&arr[min_idx], &arr[i]);
	}
}
