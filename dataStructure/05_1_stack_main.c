/*
Stack : Last In First Out (LIFO)
- 유한한 수의 요소들의 "순서가 있는 목록"
- Stack은 보통 배열으로 많이 구현함 (속도↑)
  linked list 잘 사용x
- 함수들 (연산들)
  Initialize(), Push(), Pop(), IsFull(), IsEmpty()

※ element : 배열에 저장된 각 요소를 지칭
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"

print_stack(const Stack* stack) {
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i <= stack->top; ++i)
			printf("%d ", stack->items[i].key);
	printf("%\n");
}

// 입력한 key 값을 가지고 있는 element를 만들어서 return
// 코드를 간결화 하기 위해 따로 함수 만든 것
element get_element(const int key) {
	element new_element;
	new_element.key = key;
	return new_element;
}

int main() {

	Stack my_stack;

	Initialize(&my_stack);
	print_stack(&my_stack);

	Push(&my_stack, get_element(1));
	print_stack(&my_stack);

	Push(&my_stack, get_element(3));
	print_stack(&my_stack);

	Push(&my_stack, get_element(4));
	print_stack(&my_stack);

	Push(&my_stack, get_element(2));
	print_stack(&my_stack);

	Push(&my_stack, get_element(5));
	print_stack(&my_stack);

	Push(&my_stack, get_element(6));
	print_stack(&my_stack);

	Pop(&my_stack);
	print_stack(&my_stack);

	Push(&my_stack, get_element(7));
	print_stack(&my_stack);

	for (int i = 0; i < MAX_STACK_SIZE + 1; ++i) {
		printf("Pop : %d\n", Pop(&my_stack).key);
		print_stack(&my_stack);
	}
	return 0;
}
