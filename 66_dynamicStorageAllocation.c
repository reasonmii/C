/*
Dynamic Storage Allocation 동적 메모리 할당
1) Compile time이 아닌 Run time에 결정
2) 필요한 메모리의 크기를 미리 알 수 없을 경우
3) Heap에 저장 (Stack X)
4) 메모리를 할당받기만 하고 초기화하지 않으면 쓰레기값 출력
   ★ 동적 할당 메모리는 자동으로 0 값 초기화 해주지 않음

malloc()
- memory allocation
- It returns a void type pointer

void*
- generic pointer
- 특별한 자료형을 갖는 것이 아닌, 순수한 주소 자체 값
- 즉, 자료형의 크기를 모르기 때문에 포인터 연산 사용 불가능

free()
- deallocates the memory
- 다 쓴 메모리는 반드시 다른 용도로도 사용할 수 있게 반납해줘야 함
- 반납 없이 malloc으로 계속 받아오기만 하면
  보이지 않는 공간에 메모리가 꽉 차서 나중에 더이상 할당을 해 줄 메모리가 없게 됨
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	float x;
	char str[] = "Dancing with a Star";

	int arr[100];

	double* ptr = NULL;

	/*
	malloc(30 * sizeof(double))
	- double 30개를 저장할 수 있는 메모리 공간이 필요한 경우
	- 30 * 8byte = 240byte
	- 운영체제에 남은 공간 중 240byte를 Heap에 allocate
	- malloc 결과값 : 해당 240byte 공간에 대한 첫 번째 주소값 반환

	(double*)
	- double type으로 형 변환 (casting)
	- void가 아닌 특정한 자료형의 자료인 것처럼 사용하기 위함
	- void*는 포인터 연산이 불가능하기 때문

	결국 배열처럼 사용
	*/
	ptr = (double*)malloc(30 * sizeof(double));

	/*
	프로그래머가 요청한 240byte를 줄 수 없는 경우 NULL 반환

	발생원인
	1) 어마어마하게 큰 공간을 요청하는 경우
	2) 너무 많은 프로그램을 띄워 놓은 경우
	
	이 정도로 메모리 할당이 안 되면
	아주 심각해서 더 이상 프로그램을 진행할 수 없는 경우일 때가 많음
	
	해결방법
	★ exit() 함수로 강제 종료
	★ 메모리 할당 값을 240byte보다 줄여볼 수도 있음
	*/
	if (ptr == NULL) {
		puts("Memory allocation failed.");

		/*
		★ exit() 함수
		어떤 위치에서든 강제로 프로그램 종료
		보통 이럴 때보다 debugging에서 많이 사용됨
		내가 잘 코드한 부분 뒤에 exit() 함수 써서,
		실제로 해당 부분까지는 프로그램이 잘 실행되는지 확인 가능
		
		exit(EXIT_FAILURE)
		- It is similar to return 1 IN main()

		exit(EXIT_FAILURE)
		- It is similar to return 0 IN main()
		*/

		exit(EXIT_FAILURE);
	}
	
	printf("Before free %p\n", ptr);

	// ★ no action occurs when ptr is NULL
	free(ptr);

	// 더이상 해당 pointer에 실제 값이 존재하지는 않지만,
	// 주소값은 가지고 있음
	printf("After free % p\n", ptr);

	// optional
	// 주소값 자체도 없애기
  // ★ 이 메모리는 어떠한 동적할당메모리도 가리키고 있지 않음을 명확히 함
	ptr = NULL;

	return 0;
}

// ======================================================================
/*
Dynamically Allocated Array
동적 할당 메모리를 길이가 변할 수 있는 배열처럼 사용가능
- supported by Visual Studio compiler
- free를 하기 전까지 Heap에 계속 있음, int n 값으로 size 조절 가능
- Heap은 stack보다 크기가 훨씬 큼
  대신 Heap에서 해당 값이 어디에 있는지 찾기가 어려움

VLA : Variable Length Arrays
- not supported by Visual Studio compiler
- automatic duration, cannot be resized
- limited by stack size (when compiler places VLA in stack segment)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()

int main() {

	int n = 5;
	double* ptr = NULL;

	ptr = (double*)malloc(n * sizeof(double));

	// if(!ptr)
	if (ptr != NULL) {

		// 메모리를 할당받기만 하고 초기화하지 않아 쓰레기값 출력
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n\n");

		// i값을 double로 바꿔서 값 입력
		for (int i = 0; i < n; ++i)
			*(ptr + i) = (double)i;

		// 다시 출력
		// result : 0.000000 1.000000 2.000000 3.000000 4.000000
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n\n");
	
	}

	free(ptr);
	ptr = NULL;

	return 0;
}
