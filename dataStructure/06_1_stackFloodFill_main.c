/*
Stack 연습문제 : Flood Fill Algorithm

Cell : (0, 0)
Stack : (0, 1) (1, 0)
1 0 0 0 0 0 0
0 1 1 1 1 1 0
0 1 0 0 0 1 0
0 1 0 0 0 1 0
0 1 0 0 0 1 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0

Result:
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 0 0 0 1 1
1 1 0 0 0 1 1
1 1 0 0 0 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

#define WIDTH 7
#define HEIGHT 7

// 0: empty, 1: full
static int map[HEIGHT][WIDTH] = {
	0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0
};

// 현재 결과 출력 함수
// 일종의 Debugging 도구로 사용 가능
void print_map() {
	for (int j = 0; j < HEIGHT; ++j) {
		for (int i = 0; i < WIDTH; ++i)
			printf("%d ", map[j][i]);
		printf("\n");
	}
	printf("\n");
}

// main 코드를 더 간편하게 작성하기 위해
// 이 부분은 함수를 생성하여 따로 작성
element get_element(const int i, const int j) {
	element new_element;
	new_element.i = i;
	new_element.j = j;
	return new_element;
}

print_stack(const Stack* stack) {
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i <= stack->top; ++i)
			printf("(%d, %d) ", stack->items[i].i, stack->items[i].j);
	printf("\n");
}

int main() {

	print_map();

	Stack to_visit;
	Initialize(&to_visit);

	// 바깥 네모를 채우는 경우 : start cell - (0, 0)
	Push(&to_visit, get_element(0, 0)); // 

	// 가운데 네모를 채우는 경우 : start cell - (3, 3)
	// Push(&to_visit, get_element(3, 3));

	while (IsEmpty(&to_visit) != true) {
		element cell = Pop(&to_visit);

		// skip if this cell is visited already
		if (map[cell.j][cell.i] == 1)
			continue;

		map[cell.j][cell.i] = 1; // tag full

		// ※ (3), (4)을 먼저 하도록 순서 변경 가능
		// Push (1), (2) : 오른쪽부터 채움
		// Push (3), (4) : 아래쪽부터 채움

		// Push (1)
		if (cell.j - 1 >= 0 && map[cell.j - 1][cell.i] == 0)
			Push(&to_visit, get_element(cell.i, cell.j - 1));

		// Push (2)
		if (cell.j + 1 < HEIGHT && map[cell.j + 1][cell.i] == 0)
			Push(&to_visit, get_element(cell.i, cell.j + 1));

		// Push (3)
		if (cell.i - 1 >= 0 && map[cell.j][cell.i - 1] == 0)
			Push(&to_visit, get_element(cell.i - 1, cell.j));

		// Push (4)
		if (cell.i + 1 < WIDTH && map[cell.j][cell.i + 1] == 0)
			Push(&to_visit, get_element(cell.i + 1, cell.j));

		// ★ Debugging
		system("cls"); // system("clear"); in linux
		// -> 이 부분 때문에 결과가 밑으로 이어서 출력되지 않고
		//    계속 전체 화면 reset 후 새로 출력됨
		printf("Cell : (%d, %d)\n", cell.i, cell.j);
		print_stack(&to_visit);
		print_map();
		int dummy = _getch();
	}

	printf("Result:\n");
	print_map();

	return 0;
}
