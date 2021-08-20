#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// top은 보통 배열의 index로 사용됨 
void Initialize(Stack* stack) {
	stack->top = -1;
	// allocate memory if dynamic array is used
}

bool IsFull(const Stack* stack) {
	if (stack->top >= MAX_STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty(const Stack* stack) {
	if (stack->top == -1)
		return true;
	else
		return false;
}

void Push(Stack* stack, element item) {

	if (IsFull(stack) == true)
		printf("Stack is full. Cannot add.\n");
	else {
		//memcpy(&stack->items[++stack->top], &item, sizeof(item));
		stack->items[++stack->top] = item;
	}

}

element Pop(Stack* stack) {

	if (IsEmpty(stack) == true) {
		printf("Stack is empty. Cannot remove.\n");

		// -1을 가지고 있는 element를 반환
		element temp = { -1 }; // Place holder, dummy : fake data  
		return temp;
	}
	return stack->items[stack->top--];
}
