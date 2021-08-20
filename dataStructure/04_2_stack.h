#pragma once

#include "element.h"
#include <stdbool.h>

#define MAX_STACK_SIZE 5

typedef struct stack {
	element item[MAX_STACK_SIZE];
	int top;
} Stack;

void Initialize(Stack* stack);
bool IsFull(const Stack* stack);
bool IsEmpty(const Stack* stack);
void Push(Stack* stack, element iem);
element Pop(Stack* stack);

