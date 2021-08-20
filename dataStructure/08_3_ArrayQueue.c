#include "ArrayQueue.h"
#include <assert.h>
#include <stdio.h>

void InitializeQueue(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
	pq->n_items = 0;
}

bool QueueIsFull(const Queue* pq) {
	return (pq->rear + 1) % MAXSIZE == pq->front;
}

bool QueueIsEmpty(const Queue* pq) {
	return pq->front == pq->rear;
}

int QueueItemCount(const Queue* pq) {
	return pq->n_items;
}

bool EnQueue(Item item, Queue* pq) {

	if (QueueIsFull(pq)) {
		printf("Queue is full. Cannot EnQueue.\n");
		return false;
	}

	// ★ Use % for circular queue
	pq->rear = (pq->rear + 1) % MAXSIZE;
	pq->items[pq->rear] = item;
	pq->n_items++;

	return true;
}

bool DeQueue(Item* pitem, Queue* pq) {

	if (QueueIsEmpty(pq)) {
		printf("Queue is empty. Cannot deque.\n");
		return false;
	}

	// ★ Use % for circular queue
	pq->front = (pq->front + 1) % MAXSIZE;
	*pitem = pq->items[pq->front];
	pq->n_items--;

	return true;
}

// Linkedlist는 하나하나 원소를 지워야 하지만
// ★ 배열은 초기화 하면 끝
void EmptyTheQueue(Queue* pq) {
	InitializeQueue(pq);
}

void TraverseQueue(Queue* pq, void(*func)(Item item)) {
	// ★ Note: be careful with conditions
	// 원형 큐가 꽉 차면 front의 값이 rear의 값보다 커질 수 있기 때문에
	// 부등호가 아닌 != 를 사용해서 for 문에 입력해야 함
	for (int i = pq->front; i != pq->rear; i = (i + 1) % MAXSIZE)
		(*func)(pq->items[(i + 1) % MAXSIZE]);
}
