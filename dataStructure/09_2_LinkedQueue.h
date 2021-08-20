#pragma once

#include <stdbool.h>

#define TSIZE 45

// ★ 배열과 달리 Linked List는 컴퓨터의 메모리가 허용해 주는 한
// 얼마든지 Queue의 capacity를 증가시킬 수 있음
// 따라서 아래 코드는 Optional!
// 아주 큰 숫자로 설정도 가능
#define MAXSIZE 3

struct element {
	char name[TSIZE];
} element;

typedef struct element Item;

typedef struct node {
	Item item;
	// Singly Linked List
	// 한 쪽 방향으로만 next를 가지고 있음
	struct node* next;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
	//int front;
	//int rear;
	int n_items;  // number of items
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* PQ);
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));
