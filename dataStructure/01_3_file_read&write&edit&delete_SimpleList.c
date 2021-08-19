/*
Hint
SimpleList.c 안에 정의되는 도구 함수들
※ main.c 입장에서는 node를 몰라도 됨
  main.c는 WriteAllItems 함수만 사용하면,
  SimpleList.h와 SimpleList.c 내부적으로 노드를 사용해서 알아서 모두 구현
*/
//Node* FindNodeByIndex(const List* plist, const int index);
//bool AppendItem(Item item, Node* pnode);
//void RemoveNextItem(Node* pnode);

#include "SimpleList.h"

#include <stdio.h>
#include <stdlib.h>

// 오른쪽 값에 왼쪽 값을 복사
static void CopyToNode(Item item, Node* pnode) {
	pnode->item = item;
}

void InitializeList(List* plist) {
	plist->head = NULL;
}

bool IsEmpty(const List* plist) {
	if (plist->head == NULL)
		return true;
	else
		return false;
}

// Linked list가 아니고 배열을 사용해서 만들었을 때도
// 배열은 최대 사이즈가 결정되어 있기 때문에 배열이 꽉 찼는지 확인하기에 유용
bool IsFull(const List* plist) {

	// true when malloc fails

	Node* pt;
	bool full;

	// 메모리 할당을 운영체제에 요청했을 때, 실패하면 꽉 찬 것
	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

unsigned int CountItems(const List* plist) {

	unsigned int count = 0;
	Node* pnode = plist->head;

	while (pnode != NULL) {
		++count;
		pnode = pnode->next;		
	}
	return count;
}

bool InsertItemFront(Item item, List* plist) {

	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Malloc failed.\n");
		return false;
	}

	CopyToNode(item, new_node);

	Node* temp = plist->head;
	plist->head = new_node;
	new_node->next = temp;
	return true;
}

bool AppendItem(Item item, Node* prev) {

	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("Malloc failed.\n");
		return false;
	}

	CopyToNode(item, new_node);

	Node* temp = prev->next;
	prev->next = new_node;
	new_node->next = temp;

	return true;
}

bool AddItem(Item item, List* plist) {
	
	Node* new_node;
	Node* search = plist->head;

	new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL) {
		printf("Malloc failed.\n");
		return false;
	}

	// 1) 오른쪽 값에 왼쪽 값을 복사
	CopyToNode(item, new_node);

	new_node->next = NULL;

	// 2) 복사된 값을 기존 plist 마지막에 추가
	if (search == NULL)
		plist->head = new_node;
	else {
		while (search->next != NULL)
			search = search->next;
		search->next = new_node;
	}
	return true;   // return new_node pointer
}

/*
입력 예시 : WriteAllItems(plist, file, &write_an_item);

void write_an_item(FILE* const file, const Item item) {
	fprintf(file, "%s\n", item.title);
	fprintf(file, "%.1f\n", item.rating);
}
*/
unsigned int WriteAllItems(const List* plist, FILE* file, void (*write_an_item_func)(FILE* file, Item item)) {
	Node* pnode = plist->head;

	unsigned int count = 0;
	while (pnode != NULL) {
		// 어떤 item이든지 작동할 수 있도록
		// ★ 함수 포인터를 받음
		(*write_an_item_func)(file, pnode->item);
		pnode = pnode->next;
		count++;
	}
	return count;
}

/*
입력 예시 : PrintAllItems(plist, print_an_item);

void print_an_item(Item item) {
	printf("\"%s\", %.1f\n", item.title, item.rating);
}
*/
unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item)) {

	Node* pnode = plist->head;

	unsigned int count = 0;
	while (pnode != NULL) {
		printf("%d : ", count);
		(*print_an_item_func)(pnode->item);
		pnode = pnode->next;
		count++;
	}
	return count;
}

// ★ 보통 PrintAllItems 대신 traverse 사용
void Traverse(const List* plist, void (*pfun)(Item item)) {
	Node* pnode = plist->head;
	while (pnode != NULL) {
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

bool Find(const List* plist, Item item_to_find, int* index, Item* item_found, bool (*compare_func)(Item a, Item b)) {

	Node* pnode = plist->head;
	
	*index = 0;
	while (pnode != NULL) {
		if ((*compare_func)(pnode->item, item_to_find) == true) {
			*item_found = pnode->item;
			return true;
		}
		pnode = pnode->next;
		*index += 1;
	}
	return false;
}

void ClearList(List* plist) {
	Node* iterator = plist->head;
	Node* temp = NULL;

	while (iterator != NULL) {
		temp = iterator->next;
		free(iterator);
		iterator = temp;
	}
	plist->head = NULL;
}

bool FindItemByIndex(const List* plist, const int index, Item** item) {

	// set to start of list
	Node* pnode = plist->head;

	int count = 0;

	while (pnode != NULL) {
		if (count == index) break;
		pnode = pnode->next;
		count++;
	}

	if (pnode == NULL)
		return false;
	else {
		*item = &pnode->item;
		return true;
	}	
}

Node* FindNodebyIndex(const List* plist, const int index) {
	Node* pnode = plist->head;
	int count = 0;
	while (pnode != NULL) {
		if (count == index) break;
		pnode = pnode->next;
		count++;
	}
	return pnode;
}

// ex) InsertbyIndex(new_item, &movie_list, index);
void InsertbyIndex(Item item, List* plist, int index) {

	Node* prev = FindNodebyIndex(plist, index - 1); // 직전 index의 node 반환

	if (prev == NULL)  // when index is 0
		InsertItemFront(item, plist);
	else
		AppendItem(item, prev);
}

void RemoveFirstItem(List* plist) {
	Node* temp = NULL;
	if (plist->head != NULL)
		temp = plist->head->next;
	free(plist->head);
	plist->head = temp;
}

void RemoveNextItem(Node* prev) {
	Node* temp = NULL;
	if (prev->next == NULL)
		temp = NULL;
	else
		temp = prev->next->next;
	free(prev->next);
	prev->next = temp;
}

void RemoveByIndex(List* plist, int index) {
	Node* prev = FindNodebyIndex(plist, index - 1);

	// prev == NULL
	// -> previous Node가 가장 첫 노드인 경우
	if (prev == NULL)  // when index is 0
		RemoveFirstItem(plist);
	else
		RemoveNextItem(prev);
}

