// 연결 리스트로 큐 구현하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "LinkedQueue.h"

Item get_item(const char* name) {
	Item new_item;
	strcpy(new_item.name, name);
	return new_item;
}

void print_item(Item item) {
	printf("%s ", item.name);
}

void print_queue(Queue* pq) {

	// Debugging code
	// ★ Linked List에서 front와 rear는 pointer
	printf("Front: %s at %p, Rear: %s at %p, Size %d\n",
		pq->front == NULL ? "NULL" : pq->front->item.name, pq->front,
		pq->rear == NULL ? "NULL" : pq->rear->item.name, pq->rear, pq->n_items);

	printf("Queue : ");
	if (QueueIsEmpty(pq))
		printf("Empty");
	else
		TraverseQueue(pq, &print_item);
	printf("\n\n");
}

int main() {

	Queue queue;
	Item temp;

	InitializeQueue(&queue);

	EnQueue(get_item("Jack"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Henry"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Stan"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Butters"), &queue);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue: %s\n", temp.name);
	print_queue(&queue);

	printf("---------- Circulation Test ----------\n");

	InitializeQueue(&queue);

	for (int i = 0; i < 10; ++i) {
		EnQueue(get_item("Hello"), &queue);
		print_queue(&queue);

		if (DeQueue(&temp, &queue))
			printf("Item from queue: %s\n", temp.name);
		print_queue(&queue);
	}
	return 0;
}

/*
Front: Jack at 013F6C98, Rear: Jack at 013F6C98, Size 1
Queue : Jack

Front: Jack at 013F6C98, Rear: Henry at 013F57D8, Size 2
Queue : Jack Henry

Front: Jack at 013F6C98, Rear: Stan at 013F9EB8, Size 3
Queue : Jack Henry Stan

Queue is full. Cannot EnQueue.
Front: Jack at 013F6C98, Rear: Stan at 013F9EB8, Size 3
Queue : Jack Henry Stan

Item from queue: Jack
Front: Henry at 013F57D8, Rear: Stan at 013F9EB8, Size 2
Queue : Henry Stan

Item from queue: Henry
Front: Stan at 013F9EB8, Rear: Stan at 013F9EB8, Size 1
Queue : Stan

Item from queue: Stan
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Queue is empty. Cannot deque.
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

---------- Circulation Test ----------
Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty

Front: Hello at 013F9EB8, Rear: Hello at 013F9EB8, Size 1
Queue : Hello

Item from queue: Hello
Front: NULL at 00000000, Rear: NULL at 00000000, Size 0
Queue : Empty
*/
