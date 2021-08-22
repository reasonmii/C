#include "LinkedQueue.h"
#include <assert.h>
#include <stdio.h>

// ★ static 선언 -> main.c에서는 사용 불가능
// ★ main.c는 자료구조가 어떻게 구현되었는지 최대한 적게 아는 게 좋음
// 주요 함수만 알면 됨
static void CopyToNode(Item item, Node* pn) {
	pn->item = item;
}

static void CopyToItem(Node* pn, Item* pi) {
	*pi = pn->item;
}

void InitializeQueue(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
	pq->n_items = 0;
}

bool QueueIsFull(const Queue* pq) {
	return pq->n_items == MAXITEMS;
}

bool QueueIsEmpty(const Queue* pq) {
	return pq->n_items == 0;
}

/*
배열은 메모리가 일렬로 나열되어 있고
이 경우 CPU의 캐시 메모리를 사용해서 매우 빠르고 효율적으로 개수를 셀 수 있는 반면
Heap에 저장된 데이터들은 pointer, link를 타고 건너 건너 탐색해야 함
-> 따라서 모든 아이템을 세려고 하면 효율이 떨어지고 배열에 비해 느림
   즉 n_items를 통해 데이터가 증가할 때마다 개수를 세고, 이를 return 하는 것이 효율적
*/
int QueueItemCount(const Queue* pq) {
	return pq->n_items;
}

// Item item : 새로운 customer
// Queue* pq : 현재 Queue
bool EnQueue(Item item, Queue* pq) {

	if (QueueIsFull(pq)) {
		printf("Queue is full. Cannot EnQueue.\n");
		return false;
	}

	// Make a new node
	Node* pnew;
	pnew = (Node*)malloc(sizeof(Node));

	if (pnew == NULL) {
		printf("Malloc() failed.\n");
		return false;
	}

	CopyToNode(item, pnew);
	pnew->next = NULL;

	// Add new node at the end
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;

	pq->rear = pnew;
	pq->n_items++;

	return true;
}

bool DeQueue(Item* pitem, Queue* pq) {

	if (QueueIsEmpty(pq)) {
		printf("Queue is empty. Cannot deque.\n");
		return false;
	}

	Node* pn;

	// 따로 Copy 하는 이유
	// 이후 main.c에서 pitem으로 손님이 아이스크림을 받는데
	// 몇 분 걸렸는지 printf를 통해 출력하기 위함
	CopyToItem(pq->front, pitem);

	pn = pq->front;
	pq->front = pq->front->next;

	free(pn);
	pq->n_items--;

	// Queue에 아이템이 하나도 남아 있지 않은 경우
	if (pq->n_items == 0)
		pq->rear = NULL;

	return true;
}

// 배열은 초기화 하면 끝이지만
// ★ Linkedlist는 하나하나 원소를 지워야 함
void EmptyTheQueue(Queue* pq) {
	Item temp;
	while (!QueueIsEmpty(pq))
		DeQueue(&temp, pq);
}

void TraverseQueue(Queue* pq, void(*func)(Item item)) {

	Node* temp = pq->front;
	while (temp != NULL) {
		(*func)(temp->item);
		temp = temp->next;
	}
}
