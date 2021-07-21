#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top;

// stack이 처음 만들어졌을 때는 공석상태
// 따라서, 제일 위 top 위치를 -1 로 설정
void createStack() {
	top = -1;
}

// stack 원소 삽입하기
void push(unsigned int val) {
	// top의 위치가 SIZE-1 값이면 stack이 포화 상태
	if (top >= SIZE - 1) {
		printf("\nError : Stack Overflow!\n");
		return -1;
	}
	// 현재 top 위치 보다 하나 위에 새로운 값 삽입
	stack[++top] = val;
}

// stack 원소 삭제하기
int pop(void) {
	// top의 위치가 0보다 작으면 stack이 공석 상태
	if (top < 0) {
		printf("\nError : Stack underflow\n");
		return -1;
	}
	// 현재 top 위치의 원소를 return 하고,
	// top의 위치를 한 단계 아래로 내리기
	return stack[top--];
}

void printStack() {
	int i;
	printf("\nStack : ");
	for (i = top; i >= 0; i--)
		printf("%-6d", stack[i]);
}

void main(void) {
	int i;
	createStack();

	// 원소 삽입하기
	printf("\nPush 1");
	push(1);
	printf("\nPush 7");
	push(7);
	printf("\nPush 4");
	push(4);
	printf("\nPush 6");
	push(6);
	printf("\nPush 3");
	push(3);

	// stack에 이미 5개 원소가 채워졌으니
	// overflow 에러 발생
	printf("\nPush 9");
	push(9);

	// 현재 stack 확인하기
	printStack();

	// 제일 위 원소 삭제하기
	i = pop();
	printf("\nPOP   : %d", i);
	// 현재 stack 확인하기
	printStack();

	// 제일 위 원소 삭제하기
	i = pop();
	printf("\nPOP   : %d", i);
	// 현재 stack 확인하기
	printStack();

	// 제일 위 원소 삭제하기
	i = pop();
	printf("\nPOP   : %d", i);
	// 현재 stack 확인하기
	printStack();

	// 원소 삽입하기
	printf("\n\nPush 3");
	push(3);
	printf("\nPush 2");
	push(2);

	// 현재 stack 확인하기
	printStack();

}
