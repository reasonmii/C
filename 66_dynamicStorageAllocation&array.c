// 동적 할당 메모리를 배열처럼 사용하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	// 동적 할당 메모리를 변수 하나처럼 사용
	// ※ 이렇게 사용하는 경우 거의 없음

	int* ptr = NULL;

	ptr = (int*)malloc(sizeof(int) * 1);
	if (!ptr) exit(1);

	*ptr = 1024 * 3;
	printf("%d\n", *ptr);  // 3072

	free(ptr);
	ptr = NULL;

	return 0;
}

// ======================================================================
/* 1D array

포인터는 배열처럼 사용 가능
배열과 차이점
1) 포인터 : Heap에 메모리 저장
	 - 프로그래머가 free()하기 전까지 메모리 가지고 있음
2) 배열 : automatic duration, stack에 메모리 저장
	 - 이 block을 나가면 메모리가 자동으로 empty
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	int n = 3;
	int* ptr = (int*)malloc(sizeof(int) * n);
	if (!ptr) exit(1);


	ptr[0] = 123;

	// 위에서 (int*)를 통해 malloc을 void에서 int로
	// 형변환 했기 때문에 포인터 연산 사용 가능
	*(ptr + 1) = 456;
	*(ptr + 2) = 789;

	free(ptr);
	ptr = NULL;

	return 0;
}

// ======================================================================
/* 2D array

결과
0 1
2 3
4 5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	// 2D array

	int row = 3, col = 2;

	// 이렇게 col 개수를 [2]라는 constant value로 대입하면
	// 값이 변경될 수도 있는데, 너무 비효율적임
	int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);

	// 그러나, [col]처럼 변수로 대입하려면, compiler가 VLA 지원해줘야 함
	// but, Visual Studio는 지원하지 않으니, 사용 불가능
	// int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);

	if (!ptr2d) exit(1);

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			ptr2d[r][c] = c + col * r;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++)
			printf("%d ", ptr2d[r][c]);
		printf("\n");
	}

	return 0;
}

// ======================================================================
/*
★ 해결방법 : 1차원 array를 2차원, 3차원... n차원처럼 사용

-------------------------------------------
ex) row = 3, col = 2

(r, c)

2D
(0, 0) (0, 1)
(1, 0) (1, 1)
(2, 0) (2, 1)

1D
(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
 0		1	   2	  3		 4		5
-> ★ index : col * r + c

-------------------------------------------
ex) row = 3, col = 2, depth = 2

(r, c, d)

3D
-------------------
(0, 0, 0) (0, 1, 0)
(1, 0, 0) (1, 1, 0)
(2, 0, 0) (2, 1, 0)
-------------------
(0, 0, 1) (0, 1, 1)
(1, 0, 1) (1, 1, 1)
(2, 0, 1) (2, 1, 1)
-------------------

1D
(0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1) (1, 0, 1) (1, 1, 1) (2, 0, 1) (2, 1, 1)
 0         1         2         3         4         5         6         7         8         9        10        11
-> ★ index : col * r + (col * row) * d
*/

// ======================================================================
/* Using 1D arrays as 2D arrays

결과
0 1
2 3
4 5
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	int row = 3, col = 2;
	int* ptr = (int*)malloc(row * col * sizeof(int));
	if (!ptr) exit(1);

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			ptr[col * r + c] = col * r + c;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++)
			printf("%d ", *(ptr + col * r + c));
		printf("\n");
	}

	return 0;
}

// ======================================================================
/* Using 1D arrays as 3D arrays










