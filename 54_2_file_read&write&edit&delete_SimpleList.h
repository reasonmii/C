#pragma once

#include <stdbool.h>
#include <stdio.h>

#define TSIZE 45

struct movie {
	char title[TSIZE];
	float rating;
};

/* 이렇게 따로 분리하면, 다른 데이터가 필요한 경우(ex.학생, 책 등)
movie 부분만 변경하면 되니, 아주 간단해짐
이름도 movie가 아닌 Item으로 받고 있으니,
경우에 따라 다른 이름으로 모든 코드를 변경할 필요도 없어짐 */
typedef struct movie Item;

typedef struct node {
	Item item;          // 어떤 형태의 아이템이 들어와도 상관없음
	struct node* next;  // 다음 노드의 포인터를 받음
} Node;

typedef struct list {
	Node* head;    // head pointer
	int size;      // number of items : 매번 개수 세지 않아도 되니 간단
	// 그 외에 필요한 것들도 여기 추가 가능
} List;

void InitializeList(List* plist);
bool IsEmpty(const List* plist);   // Not used in this example
bool IsFull(const List* plist);     // Not used in this example
void InsertbyIndex(Item item, List* plist, int index);
void RemoveByIndex(List* plist, int index);
bool InsertItemFront(Item item, List* plist);
bool Find(const List* plist, Item item_to_find, int* index, Item* item_found, bool (*compare_func)(Item a, Item b));

unsigned int CountItems(const List* plist);
unsigned int PrintAllItems(const List* plist, void(*print_an_item_func)(Item item));
unsigned int WriteAllItems(const List* plist, FILE* file, void(*write_an_item_func)(FILE* file, Item item));

// Traverse : 모든 node들을 다 한 번씩 방문하면서 무언가 작업을 하는 함수
void Traverse(const List* plist, void (*pfun)(Item item));   // Not used in this example
void ClearList(List* plist);

bool FindItemByIndex(const List* plist, const int index, Item** item);
void RemoveFirstItem(List* plist);
