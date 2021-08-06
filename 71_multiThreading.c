/*
Multi-Threading 멀티 쓰레딩

하나의 전역 변수를 여러 개의 Thread가 모두 동시에 접근하려 하면 경쟁 발생
특히, 첫 번째 Thread가 해당 값을 사용하는 동안
두 번째 Thread도 해당 값을 가져와서 중간에 값을 변경해 버리면 문제 발생
-> ★ 이를 방지하기 위해 atomic type qualifier 사용

★ atomic type qualifier
1) 사용방법
   - #include <stdatomic.h>
   - 전역 변수 자료형 앞에 '_Atomic' 입력
2) 단점 : 해당 변수를 사용하는 연산이 느려지게 됨

C언어 표준에서는 Multi-Threading 제공X
운영체제에서 제공하는 것 가져와서 써야 함
- 운영체제에 따라 코딩이 달라짐

● Windows에서 Multi-Threading 사용법
1) #include <windows.h>
2) 단점
   - atomic type 사용 불가능
   - #include <pthread.h>를 사용하려면 따로 설치해야 함
3) atomic을 사용하지 않고 전역변수 충돌을 방지하는 법
   나중에 심화학습에서 알게 될 수 있음

Windows보다는 보통 Linux 환경에서 많이 사용
구글 검색 : online c compiler gcc
※ https://www.onlinegdb.com/online_c_compiler

#include <pthread.h>
★ windows에서도 사용 가능하지만, 코드 매우 복잡
나중에 C++에서 배우고 다시 돌아오면 매우 쉽게 사용 가능

※ Visual Studio에서 작업 후 gcc에서 compile 하고 싶은 경우
1) compile
$ gcc <file-name.c> -o <output-file-name> -lpthread
2) run
$ ./<output-file-name>
*/

// ======================================================================
/* online c compiler gcc code

결과
Before Thread
Printing from Thread 1 14041967...
Printing from Thread 2 14041967...
Printing from Thread 3 14041967...
Printing from Thread 4 14041967...
Printing from Thread 5 14041967...
Printing from Thread 6 14041967...
Printing from Thread 7 14041967...
Printing from Thread 8 14041967...
Printing from Thread 9 14041967...
Printing from Thread 10 14041967...
Printing from Thread 11 14041967...
Printing from Thread 12 14041967...
Printing from Thread 13 14041967...
Printing from Thread 14 14041967...
Printing from Thread 15 14041967...
Printing from Thread 16 14041967...
Printing from Thread 17 14041967...
Printing from Thread 18 14041967...
Printing from Thread 19 14041967...
Printing from Thread 20 14041967...
After Thread
Atomic 20
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // sleep()
#include <pthread.h>  // ★ windows에서도 사용 가능 (but ,코드 매우 복잡)
#include <stdatomic.h>

// atomic type qualifier (C11)
_Atomic int acnt = 0;

/*
A normal C function that is executed as a thread
when its name is specified in pthread_create()
*/
void *myThreadFun(void *vargp) {
    
    // thread storage duration
    // 이 block이 빠져나가면 없어짐
    int n = 1;
    
    for (int j = 0; j < 10; ++j) {
        sleep(1);
        // 한 thread 안에서 빈번하게 하는 연산에 대해서는
        // 이처럼 atomic 변수를 사용하지 않는 게 좋음
        // 전체 프로그래밍이 느려지게 됨
        acnt += n;
        printf("Printing from Thread %d %llu\n", acnt, (unsigned long long)&n);
    }
    return NULL;
}

int main() {
    
    // Identification
    // pointer처럼 thread를 식별하기 위해 사용
    pthread_t thread_id1, thread_id2;
    
    printf("Before Thread\n");
    
    // myThreadFun을 실행하고
    // 그 식별자를 thread_id에 포인터 주소로 넣어줌
    pthread_create(&thread_id1, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);
    /*
    -> 일시적으로 메모리에서 두 개의 myThreadFun copy가 작동하게 됨
    
    myThreadFun 안에는 지역 변수 n이 있음
    n은 각 myThreadFun 안에서 따로 따로 메모리를 차지하고 있음
    
    각 myThreadFun은 동시에 전역변수 acnt에 접근할 수 없게
    atomic 변수로 선언함
    따라서, acnt += n; 연산은 조금 느려지게 됨
    
    */
    
    // ★ 동시에 진행 중인 여러 thread가
    // 모두 끝날 때까지 기다려주는 것
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    
    printf("After Thread\n");
    printf("Atomic %d\n", acnt);
    
    return 0;
}

// ======================================================================
// Visual Studio에서 사용하는 법 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(void* data) {
	int n = 1;
	Sleep(1000);
	// acnt += n;    // NA
	printf("Printing from Thread \n");
	return 0;
}

int main() {

	HANDLE thread = CreateThread(NULL, 0 ThreadFunc, NULL, 0, NULL);
	
	if (thread)
		WaitForSingleObject(thread, INFINITE);

	return 0;
}
 
