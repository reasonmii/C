// 추가 수정 필요

#include <stdio.h>
#include <stdlib.h>
#define DSIZE 5

// 데크 원소의 자료형을 int로 정의
typedef int element;

typedef struct {
	int front;
	int rear;
	element deque[DSIZE];  // 1차원 배열 데크 선언
}dequeType;


void error(char* message) {
	printf(stderr, "%s\n", message);
	exit(1);
}

void createDeque(dequeType* D) {
	D->front = -1;    // front 초기값 설정
	D->rear = -1;     // rear 초기값 설정
}

// 데크가 공백상태인지 검사
// 공백상태 : front == rear
int isEmpty(dequeType* D) {
	if (D->front == D->rear) {
		printf("데크 공백상태입니다\n");
		return 1;
	}
	else return 0;
}

// 데크가 포화상태인지 검사
// 포화상태 : rear 값 = DSIZE - 1
int isFull(dequeType* D) {
	if (D->rear == DSIZE - 1) {
		printf("데크가 포화상태입니다!\n");
		return 1;
	}
	else return 0;
}

// 데크 front에 원소 삽입하기
void insertFront(dequeType* D, element item) {
	if (isFull(D)) return;
	else {
		D->front--;
		D->deque[D->front] = item;
	}
}

// 데크 rear에 원소 삽입하기
void insertRear(dequeType* D, element item) {
	if (isFull(D)) return;     	// 포화 상태이면 삽입 중단
	else {
		D->rear++;              // 포화 상태가 아니면 현재 rear보다 하나 뒤 위치에 원소 삽입
		D->deque[D->rear] = item;
	}
}

// 데크 front에서 원소 삭제하기
element deleteFront(dequeType* D) {
	if (isEmpty(D)) return -1;      // 공백 상태이면 삭제 연산 중단
	else {
		D->front++;
		return D->deque[D->front];  // 공백 상태가 아니면 현재 front 위치 원소 삭제
	}
}
// 데크 rear에서 원소 삭제하기
element deleteRear(dequeType* D) {
	if (isEmpty(D)) return -1;      // 공백 상태이면 삭제 연산 중단
	else {
		D->rear--;
		return D->deque[D->rear];  // 공백 상태가 아니면 현재 front 위치 원소 삭제
	}
}

// 데크 프린트하기
void printDeque(dequeType* D) {
	int i;
	for (i = 0; i < DSIZE; i++) {
		if (i <= D->front || i > D->rear) printf("");
		else printf("%d ", D->deque[i]);
	}
	printf("\n");
}

// 데크 front에서 원소 검색
element getFront(dequeType* D) {
	if (isEmpty(D)) exit(1);    // 공백상태이면 연산 중단
	else return D->deque[D->front + 1];
}

// 데크 rear에서 원소 검색
element getRear(dequeType* D) {
	if (isEmpty(D)) exit(1);    // 공백상태이면 연산 중단
	else return D->deque[D->rear - 1];
}





int main(void) {

	int item;
	dequeType d;

	createDeque(&d);

	// 원소 삽입하기
	printf("\n데크에 20을 삽입합니다 (Front)\n");
	insertFront(&d, 20);
	printDeque(&d);

	printf("\n데크에 37을 삽입합니다 (Front)\n");
	insertFront(&d, 37);
	printDeque(&d);

	printf("\n데크에 52을 삽입합니다 (Front)\n");
	insertFront(&d, 52);
	printDeque(&d);

	printf("\n데크에 11을 삽입합니다 (Rear)\n");
	insertRear(&d, 11);
	printDeque(&d);

	printf("\n데크에 69을 삽입합니다 (Rear)\n");
	insertRear(&d, 69);
	printDeque(&d);

	printf("\n데크에 74을 삽입합니다 (Front)\n");
	insertFront(&d, 74);
	printDeque(&d);

	// 원소 삭제하기
	//printf("");

	return 0;

}
