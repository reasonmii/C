/*
Queue : First In First Out (FIFO)
- 유한한 수의 요소들의 "순서가 있는 목록"
- 함수들 (연산들)
  Initialize(), EnQueue(), DeQueue(), IsFull(), IsEmpty()
- 배열과 Linked List로 모두 구현 가능
  보통 Circular Queue 원형 큐는 배열로 구현할 때 사용

Circular Queue 배열로 구현하기
- ★ 배열 'Size = n'인 경우, 원형 큐의 최대 용량은 'n-1'
  -1 하는 이유 : 완전히 빈 상태와 꽉 찬 상태를 구분하기 위함
  1) IsEmpty : Rear == Front -> 둘 다 0인 상태
  2) IsFull : (Rear + 1) % MAX == Front
- Front, Rear 를 모두 0으로 초기화
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "ArrayQueue.h"

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
	printf("Front: %d, Rear: %d, Size %d\n", pq->front, pq->rear, pq->n_items);

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


/* Result
Result

Front: 0, Rear: 1, Size 1
Queue : Jack

Front: 0, Rear: 2, Size 2
Queue : Jack Henry

Front: 0, Rear: 3, Size 3
Queue : Jack Henry Stan

Queue is full. Cannot EnQueue.
Front: 0, Rear: 3, Size 3
Queue : Jack Henry Stan

Item from queue: Jack
Front: 1, Rear: 3, Size 2
Queue : Henry Stan

Item from queue: Henry
Front: 2, Rear: 3, Size 1
Queue : Stan

Item from queue: Stan
Front: 3, Rear: 3, Size 0
Queue : Empty

Queue is empty. Cannot deque.
Front: 3, Rear: 3, Size 0
Queue : Empty

---------- Circulation Test ----------
Front: 0, Rear: 1, Size 1
Queue : Hello

Item from queue: Hello
Front: 1, Rear: 1, Size 0
Queue : Empty

Front: 1, Rear: 2, Size 1
Queue : Hello

Item from queue: Hello
Front: 2, Rear: 2, Size 0
Queue : Empty

Front: 2, Rear: 3, Size 1
Queue : Hello

Item from queue: Hello
Front: 3, Rear: 3, Size 0
Queue : Empty

Front: 3, Rear: 0, Size 1
Queue : Hello

Item from queue: Hello
Front: 0, Rear: 0, Size 0
Queue : Empty

Front: 0, Rear: 1, Size 1
Queue : Hello

Item from queue: Hello
Front: 1, Rear: 1, Size 0
Queue : Empty

Front: 1, Rear: 2, Size 1
Queue : Hello

Item from queue: Hello
Front: 2, Rear: 2, Size 0
Queue : Empty

Front: 2, Rear: 3, Size 1
Queue : Hello

Item from queue: Hello
Front: 3, Rear: 3, Size 0
Queue : Empty

Front: 3, Rear: 0, Size 1
Queue : Hello

Item from queue: Hello
Front: 0, Rear: 0, Size 0
Queue : Empty

Front: 0, Rear: 1, Size 1
Queue : Hello

Item from queue: Hello
Front: 1, Rear: 1, Size 0
Queue : Empty

Front: 1, Rear: 2, Size 1
Queue : Hello

Item from queue: Hello
Front: 2, Rear: 2, Size 0
Queue : Empty
*/
