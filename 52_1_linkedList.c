/*
결과
-----------------
Head address = 18902168
18902168 "Avatar" 9.500000 0
-----------------
Head address = 18896856
18896856 "Aladdin" 8.000000 18902168
18902168 "Avatar" 9.500000 0
-----------------
Head address = 18896856
18896856 "Aladdin" 8.000000 18902168
18902168 "Avatar" 9.500000 18915000
18915000 "Wonder Woman" 8.500000 0
-----------------
Head address = 18902168
18902168 "Avatar" 9.500000 18915000
18915000 "Wonder Woman" 8.500000 0
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TSIZE 45

struct movie {
	char title[TSIZE];
	float rating;
	struct movie* next;
};

// 이중포인터가 필요할 때 편리하게 사용하기 위해 선언
typedef struct movie* p_movie;

// Linked List에 담긴 데이터 모두 출력
void print_all(struct movie* head) {
	printf("-----------------\n");
	printf("Head address = %zd\n", (size_t)head);
	// search : 각 노드를 돌면서 출력
	struct movie* search = head;
	while (search != NULL) {
		// (size_t)search : 현재 출력 노드의 주소
		printf("%zd \"%s\" %f %zd\n", (size_t)search, search->title,
			search->rating, (size_t)search->next);
		search = search->next;
	}
}

int main() {

	// 아직 노드가 없는 상태
	p_movie head = NULL;

	// -------------------------------------------
	// First Node

	p_movie new_node = malloc(sizeof(struct movie));
	// if 조건 없으면 warning 발생
	// -> 꼼꼼한 코딩을 위해 조건 입력
	if (new_node == NULL) {
		printf("ERROR: malloc failed.");
		exit(1);
	}

	// 초기화
	strcpy(new_node->title, "Avatar");
	new_node->rating = 9.5f;
	new_node->next = NULL;

	// head에 First node 삽입
	if (head == NULL)
		head = new_node;

	print_all(head);

	// -------------------------------------------
	// Second Node

	new_node = malloc(sizeof(struct movie));
	if (new_node == NULL) {
		printf("ERROR: malloc failed.");
		exit(1);
	}

	strcpy(new_node->title, "Aladdin");
	new_node->rating = 8.0f;
	new_node->next = NULL;

	// Add front : 맨 앞에 삽입
	p_movie temp = head;    // temp에 기존 head를 잠깐 넣기
	head = new_node;        // head에 새로 만든 node 넣기
	new_node->next = temp;  // next에 temp 넣기

	print_all(head);

	// -------------------------------------------
	// Third node

	new_node = malloc(sizeof(struct movie));
	if (new_node == NULL) {
		printf("ERROR: malloc failed.");
		exit(1);
	}

	strcpy(new_node->title, "Wonder Woman");
	new_node->rating = 8.5f;
	new_node->next = NULL;

	// Add back : 맨 뒤에 삽입
	// 1) Find the last node
	p_movie search = head;
	while (search->next != NULL) {
		search = search->next;
	}
	// 2) link
	search->next = new_node;

	print_all(head);

	// -------------------------------------------
	// Find and delete an item

	search = head;
	p_movie prev = NULL;

	// Find "Aladdin"
	int count = 0;
	while (search != NULL) {

		if (strcmp(search->title, "Aladdin") == 0) break;

		// prev : delete을 위해 이전 node의 포인터 저장 해야 함
		prev = search;
		search = search->next;
		count++;
	}
	
	// Delete "Aladdin"
	if (search == NULL) {
		printf("Wrong title\n");
		return;
	}
	if (prev == NULL)         // prev가 HEAD라는 의미
		head = search->next;  // head에 search 다음 노드 넣기
	else
		prev->next = search->next;
	free(search);

	print_all(head);

	return 0;
}
