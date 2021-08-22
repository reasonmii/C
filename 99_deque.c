// 추가 수정 필요

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DSIZE 5

struct element {
	char name[DSIZE];
} element;

typedef struct element Item;

typedef struct node {
	Item item;
	struct node* prev;
	struct node* next;
} Node;

typedef struct dequeue {
	Node* front;
	Node* rear;
	int n_items;
} DeQueue;

void CopyToNode(Item item, Node* pn) {
	pn->item = item;
}

void CopyToItem(Node* pn, Item* pi) {
	*pi = pn->item;
}

Item get_item(const char* name) {
	Item new_item;
	strcpy(new_item.name, name);
	return new_item;
}

void InitializeQueue(DeQueue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
	pq->n_items = 0;
}

bool QueueIsFull(const DeQueue* pq) {
	return pq->n_items == DSIZE;
}

bool QueueIsEmpty(const DeQueue* pq) {
	return pq->n_items == 0;
}

bool insertFront(Item item, DeQueue* pq) {

	if (QueueIsFull(pq)) {
		printf("Queue is full. Cannot EnQueue.\n");
		return false;
	}

	Node* pnew;
	pnew = (Node*)malloc(sizeof(Node));

	if (pnew == NULL) {
		printf("Malloc() failed.\n");
		return false;
	}

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (QueueIsEmpty(pq)) {
		pq->front = pnew;
		pq->rear = pnew;
	}
	else {
		Node* temp = pq->front;
		pq->front = pnew;
		pq->front->next = temp;
		free(temp);
	}

	pq->n_items++;
	return true;
}

bool insertRear(Item item, DeQueue* pq) {

	if (QueueIsFull(pq)) {
		printf("Queue is full. Cannot EnQueue.\n");
		return false;
	}

	Node* pnew;
	pnew = (Node*)malloc(sizeof(Node));

	if (pnew == NULL) {
		printf("Malloc() failed.\n");
		return false;
	}

	CopyToNode(item, pnew);
	pnew->next = NULL;

	if (QueueIsEmpty(pq)) {
		pq->front = pnew;
		pq->rear = pnew;
	}
	else {
		pq->rear->next = pnew;
		pq->rear = pnew;
	}

	pq->n_items++;
	return true;
}

bool deleteFront(Item* pitem, DeQueue* pq) {

	if (QueueIsEmpty(pq)) {
		printf("Queue is empty. Cannot deque.\n");
		return false;
	}

	Node* pn;
	CopyToItem(pq->front, pitem);
	pn = pq->front;
	pq->front = pq->front->next;

	free(pn);
	pq->n_items--;

	if (pq->n_items == 0)
		pq->rear = NULL;

	return true;
}


bool deleteRear(Item* pitem, DeQueue* pq) {

	if (QueueIsEmpty(pq)) {
		printf("Queue is empty. Cannot deque.\n");
		return false;
	}

	Node* pn;
	CopyToItem(pq->rear, pitem);
	pn = pq->rear;

	Node* temp = pq->front;
	while (temp->next != pn->next)
		temp = temp->next;

	pq->rear = temp;

	free(pn);
	pq->n_items--;

	if (pq->n_items == 0)
		pq->front = NULL;

	return true;
}

void print_item(Item item) {
	printf("%s ", item.name);
}

void Traverse(DeQueue* pq, void(*func)(Item item)) {
	Node* temp = pq->front;
	while (temp != NULL) {
		(*func)(temp->item);
		temp = temp->next;
	}
}

void printDeque(DeQueue* pq) {

	printf("DeQueue: ");
	if (QueueIsEmpty(pq))
		printf("Empty");
	else
		Traverse(pq, &print_item);
	printf("\n\n");
}

int main() {

	DeQueue dequeue;
	Item temp;

	InitializeQueue(&dequeue);

	insertFront(get_item("Jack"), &dequeue);
	printDeque(&dequeue);

	insertFront(get_item("Harry"), &dequeue);
	printDeque(&dequeue);

	insertFront(get_item("Tom"), &dequeue);
	printDeque(&dequeue);

	insertRear(get_item("Coco"), &dequeue);
	printDeque(&dequeue);

	insertRear(get_item("Buzz"), &dequeue);
	printDeque(&dequeue);

	deleteFront(&temp, &dequeue);
	printDeque(&dequeue);

	deleteRear(&temp, &dequeue);
	printDeque(&dequeue);

	deleteRear(&temp, &dequeue);
	printDeque(&dequeue);

	return 0;

}
