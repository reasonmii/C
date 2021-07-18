#include <stdio.h>
#include <stdlib.h>
#define QSIZE 5

// 큐 원소의 자료형을 int로 정의
typedef int element;

typedef struct {
	int front;
	int rear;
	element queue[QSIZE]; // 1차원 배열 큐 선언
}QueueType;

void error(char* message) {
	printf(stderr, "%s\n", message);
	exit(1);
}

void createQueue(QueueType* Q) {
	Q->front = -1;   // front 초기값 설정
	Q->rear = -1;    // rear 초기값 설정
}

// 순차 큐가 공백상태인지 검사
// 만약 front 값과 rear 값이 같으면 공백상태
int isEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("큐가 공백상태입니다!\n");
		return 1;
	}
	else return 0;
}

// 순차 큐가 포화상태인지 검사
// 만약 rear 값이 큐 사이즈 - 1이면 포화상태
int isFull(QueueType* Q) {
	if (Q->rear == QSIZE - 1) {
		printf("큐가 포화상태입니다!\n");
		return 1;
	}
	else return 0;
}

// 순차 큐 rear에 원소 삽입하기
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;  // 포화 상태이면, 삽입 중단
	else {
		Q->rear++;          // 포화 상태가 아니면 현재 rear 보다 하나 뒤 위치에 원소 삽입
		Q->queue[Q->rear] = item;
	}
}

// 순차 큐 front에서 원소 삭제하기
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return -1;       // 공백 상태이면, 삭제 연산 중단
	else {
		Q->front++;
		return Q->queue[Q->front];  // 공백 상태가 아니면 현재 front 위치 원소 삭제
	}
}

// 큐 프린트하기
void printQueue(QueueType* Q) {
	int i;
	for (i = 0; i < QSIZE; i++) {
		if (i <= Q->front || i > Q->rear)
			printf("");
		else
			printf("%d ", Q->queue[i]);
	}
	printf("\n");
}

// 순차 큐 원소 검색
element peek(QueueType* Q) {
	if (isEmpty(Q)) exit(1);   // 공백 상태이면 연산 중단
	else return Q->queue[Q->front + 1];
}

int main(void) {

	int item;
	QueueType q;

	createQueue(&q);

	// 원소 삽입하기
	printf("\n큐에 20을 삽입합니다\n");
	enQueue(&q, 20);
	printQueue(&q);
	printf("\n큐에 37을 삽입합니다\n");
	enQueue(&q, 37);
	printQueue(&q);
	printf("\n큐에 52을 삽입합니다\n");
	enQueue(&q, 52);
	printQueue(&q);
	printf("\n큐에 11을 삽입합니다\n");
	enQueue(&q, 11);
	printQueue(&q);

	// 원소 삭제하기
	printf("\n큐의 원소를 삭제합니다\n");
	deQueue(&q);
	printQueue(&q);
	printf("\n큐의 원소를 삭제합니다\n");
	deQueue(&q);
	printQueue(&q);

	return 0;

}
