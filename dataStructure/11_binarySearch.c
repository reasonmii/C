/*
Binary Search 이진탐색
- 아이템을 찾을 때 사용할 열쇠(key)와 데이터 아이템의 쌍(pair) 여러 개
- 함수들 (연산들)
  Create(), IsEmpty(), Search(), Delete(), Insert()

- 범위를 반으로 나눠 탐색하니 Sequential 탐색보다 시간 소요가 크게 감소
- Sorting에 시간 소요 필요
  -> 탐색을 여러 차례 해야 할 때 유리
     처음에 한 번 sorting 해 놓으면 됨

1) Sorting 정렬
2) 배열의 가운데 찾기
   (First + Last) / 2
3) 가운데 값과 찾는 값을 비교
4) 비교 결과에 따라 탐색 구간 변경
   - 찾는 값이 가운데 값보다 앞에 있는 경우
     Last = Middle - 1
   - 찾는 값이 가운데 값보다 뒤에 있는 경우
     First = Middle + 1
5) 찾을 때까지 반복
   First = Middle = Last 가 되는 순간 그 값이 찾는 값
6) 만약 First > Last 라면 탐색 실패
   찾는 값이 없는 것
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TMAX 40

typedef struct {
	char character[TMAX]; // the name of avengers
	char name[TMAX];      // actor's real name
} Item;

void print_items_array(Item items[], int size);
int compare_items(const void* first, const void* second);

const Item* sequential_search(const Item items[], const int size, const char key[TMAX]);
const Item* binary_search(const Item items[], const int size, const char key[TMAX]);

int main() {
	
	// Assume that there is no duplicated items
	// 키가 중복되는 아이템은 없다고 가정

	Item items[] = {
		{"Iron Man", "Tony Stark"},
		{"Thor", "Thor Odinson"},
		{"Ant-Man", "Hank Pym"},
		{"Wasp", "Janet van Dyne"},
		{"Hulk", "Bruce Banner"},
		{"Captain America", "Steve Rogers"},
		{"Scarlet Witch", "Wanda Maximoff"},
		{"Black Widow", "Natasha Romanoff"},
		{"Dr. Strange", "Stephen Strange"},
		{"Daredevil", "Metthew Murdock"},
		{"Punisher", "Frank Castle"},
		{"Batman", "Bruce Wayne"}
	};

	int n = sizeof(items) / sizeof(items[0]);

	print_items_array(items, n);

	// sorting 순서 : avengers 이름 -> 본명
	qsort(items, n, sizeof(Item), compare_items);

	print_items_array(items, n);

	// key : the name of the avengers
	// -> print : their real name
	while (1) {
		char key[TMAX] = "";
		
		printf("Input key >> ");
		// fgets
		// - save the input in 'key' (size : TMAX)
		// - stdin : fgets는 파일에서 문자열을 가져오는 함수지만,
		//           stdin을 사용하면 표준 입력을 받도록 함
		// - 줄바꿈 문자를 마지막에 포함 ('\n')
		fgets(key, TMAX, stdin);
		
		// key값이 잘 입력된 경우
		// 마지막 줄바꿈 문자를 null 값으로 대체
		if ((strlen(key) > 0) && (key[strlen(key) - 1] == '\n'))
			key[strlen(key) - 1] = '\0';

		// exit을 입력한 경우 종료
		if (strcmp(key, "exit") == 0)
			break;

		//const Item* found = sequential_search(items, n, key);
		const Item* found = binary_search(items, n, key);

		if (found == NULL)
			printf("Not in the List\n\n");
		else
			printf("%s is %s\n\n", found->character, found->name);
	}

	return 0;
}

void print_items_array(Item items[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%s (%s)\n", items[i].character, items[i].name);
	printf("\n");
}

int compare_items(const void* first, const void* second) {

	Item* first_item = (Item*)first;
	Item* second_item = (Item*)second;

	return strcmp(first_item->character, second_item->character);
}

// ※ compare_items 함수의 포인터를 받아와서 strcmp 대신 사용할 수도 있음
// -> 객체지향 프로그램에서 유용
const Item* sequential_search(const Item items[], const int size, const char key[TMAX]) {
	
	for (int i = 0; i < size; ++i)
		if (strcmp(items[i].character, key) == 0)
			return &items[i];
	return NULL;
}

const Item* binary_search(const Item items[], const int size, const char key[TMAX]) {

	int first = 0;
	int last = size - 1;
	int middle = (first + last) / 2;

	while (first <= last) {

		// ★ strcmp : 1, 0, -1 반환
		int comp = strcmp(items[middle].character, key);

		if (comp < 0)
			first = middle + 1;
		else if (comp == 0) {
			return &items[middle];
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	return NULL;
}
