#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedQueue.h"

/*
Icecream Store Simulation
- 아이스크림을 만드는 시간은 제외
- 시뮬레이션이 끝나기 직전에 주문을 받은 경우에도
  아이스크림을 만들어드리는 것으로 가정
  즉, 'DeQueue'가 된 손님은 'customers served'에 포함됨

Wait : 손님이 아이스크림을 주문하기 위해 줄에서 기다린 시간
Lost : Queue가 꽉 차서 더 이상 손님을 받지 못하는데 손님이 온 경우
*/

// 새로운 손님이 올지 안 올지를 시간 당 오는 손님에 비례하여 확률로 결정
// x = min_per_cust = 60.0f / average_n_customers_per_hour;
// It's a probabilistic number of n_queued_customers per an hour
bool newcustomer_visit(double x) {

	// ★ 시뮬레이션, 게임 만들기에서 많이 사용하는 방법
	// rand() / RAND_MAX : 0 이상 1 이하의 숫자
	// x 값에 비례해서 true를 return 할 확률이 증가함
	if (rand() * x / RAND_MAX < 1.0)
		return true;
	else
		return false;
}

Item get_customer(long arrival_time) {

	Item cust;

	// 1, 2, 3 중 한 가지를 랜덤하게 받음
	cust.processtime = rand() % 3 + 1; // 1 - 3
	cust.arrival_time = arrival_time;

	return cust;
}

int main() {

	Queue waiting_queue;

	int simulation_length_in_hours;
	int average_n_customers_per_hour;
	double min_per_cust;
	long cycle, cyclelimit;

	// Statistics
	long n_lost_customers = 0;    // came when queue is full : 못 받는 손님 수
	long n_queued_customers = 0;  // 줄 선 손님 수
	long n_served_customers = 0;  // 아이스크림 받은 손님 수

	// Accumulated queue sizes of all time
	// Used to calculate average
	// 평균적으로 큐에 몇 명의 손님이 있었는지 보기 위함
	long sum_line = 0;

	// time left: 아이스크림 만드는 시간
	int wait_time = 0; // 

	// cumulative time in line: 누적 시간
	int line_wait = 0;

	InitializeQueue(&waiting_queue);

	// random initializing of rand()
	srand((unsigned int)time(0));

	// for deterministic debugging
	// time을 사용하면 완전한 random number지만
	// debugging을 위해 고정된 random number를 사용하고 싶은 경우 코드
	// -> random number지만 매번 같은 number 출력
	// srand(0);

	printf("How many hours do you want to simulate? \n>> ");
	int flag;
	flag = scanf("%d", &simulation_length_in_hours);

	printf("How many customers per hour do you expect? \n>> ");
	flag = scanf("%d", &average_n_customers_per_hour);

	// ★ simulation 코딩에서 cycle이라는 용어 많이 사용함
	// for로 돌릴 때, "한 사이클 돌았다"고 표현
	cyclelimit = simulation_length_in_hours * 60;

	// 매 cycle마다 이번 cycle에 손님이 올지 안 올지 결정
	min_per_cust = 60.0f / average_n_customers_per_hour;

	for (cycle = 1; cycle <= cyclelimit; cycle++) {
		if (newcustomer_visit(min_per_cust)) {
			if (QueueIsFull(&waiting_queue)) {
				n_lost_customers++;
				printf("%3ld: Customer lost\n", cycle);
			}
			else {
				n_queued_customers++;
				Item customer_ready = get_customer(cycle);
				EnQueue(customer_ready, &waiting_queue);
				printf("%3ld: a new customer enqueue.\n", cycle);
			}
		}

		if (wait_time <= 0 && !QueueIsEmpty(&waiting_queue)) {
			Item customer_ready;
			DeQueue(&customer_ready, &waiting_queue);
			printf("%3ld: start serving a customer for %d minutes.\n", cycle, customer_ready.processtime);

			// 손님이 주문한 아이스크림을 만드는 시간
			wait_time = customer_ready.processtime;

			// 지금 막 큐에서 나온 손님이 큐에서 얼마나 기다렸었는지
			// -> 평균적으로 손님이 큐에서 기다리는 시간을 계산하기 위함
			line_wait += cycle - customer_ready.arrival_time;
			n_served_customers++;
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += QueueItemCount(&waiting_queue);
	}

	printf("\n");

	if (n_queued_customers > 0) {
		printf("customers accepted: %ld\n", n_queued_customers);
		printf("  customers served: %ld\n", n_served_customers);
		printf("              lost: %ld\n", n_lost_customers);
		printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
		printf(" average wait time: %.2f minutes\n", (double)line_wait / n_served_customers);
	}
	else
		puts("No customers!");

	EmptyTheQueue(&waiting_queue);

	return 0;
}

