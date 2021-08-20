#pragma once

#include <stdbool.h>

#define TSIZE 45
// 대기 줄을 설 수 있는 고객수
#define MAXITEMS 10

struct customer {
	long arrival_time;
	// 주문한 아이스크림을 받기까지 걸리는 시간
	int processtime;
} customer;

typedef struct customer Item;

typedef struct node {
	Item item;
	struct node* next;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
	int n_items;
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* PQ);
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));




