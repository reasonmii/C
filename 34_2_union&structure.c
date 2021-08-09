/*
공용체와 구조체를 같이 사용하면,
★ 어떠한 하나의 구조체를 조건에 따라 다르게,
두 가지의 구조체인 것처럼 사용 가능

나중에 객체지향 프로그래밍 공부할 때 아주 유용하게 쓸 수 있음
*/

// ======================================================================

#include <stdio.h>

// 구조체 선언
struct exStruct {
	char c;
	int i;
	int j;
	int k;
};

// 공용체 선언
union example {
	char c;
	int i;
	int j;
	int k;
};

int main(void) {	

	struct exStruct est;          // 구조체
	union  example e = { 'a' };  // 공용체

	// 구조체 크기 : 16
	// -> padding으로 한 개당 4byte 처리
	printf("%d\n", sizeof(est));

	// 공용체 크기 : 4
	// 한 개의 사이즈만 잡음
	printf("%d\n", sizeof(e));

	// 공용체 출력
	// a  97  97  97
	printf("%c  %d  %d  %d\n", e.c, e.i, e.j, e.k);

	e.i = 500;
	// ? 500  500  500
	printf("%c  %d  %d  %d\n", e.c, e.i, e.j, e.k);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct personal_owner {
	char rrn1[7];    // Resident Registration Number
	char rrn2[8];    // ex) 둘리 주민번호 830422-1185600
};

struct company_owner {
	// ★ 마지막 null character 고려해서
	// 3자리 - 2자리 - 5자리이면
	// 4자리 - 3자리 - 6자리 배열로 만들어야 함
	char crn1[4];    // Company Registration Number
	char crn2[3];    // ex) 법인번호 111-22-33333
	char crn3[6];
};

// 개인소유이면서 동시에 회사소유일 수 없음
// 둘 중 하나만 가능 -> union
union data {
	struct personal_owner po;
	struct company_owner  co;
};

struct car_data {
	char model[15];
	int status;     // 0 = personal, 1 = company
	union data ownerinfo;
};

void print_car(struct car_data car) {
	printf("-----------------------------------\n");
	printf("Car model : %s\n", car.model);

	if (car.status == 0)
		printf("Personal owner : %s-%s\n",
			car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);

	else
		printf("Comapny owner : %s-%s-%s\n",
			car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
	printf("-----------------------------------\n");
}

int main() {

	struct car_data my_car = { .model = "Avante", .status = 0, .ownerinfo.po = {"830422", "1185600"} };
	struct car_data company_car = { .model = "Sonata", .status = 1, .ownerinfo.co = {"111", "22", "33333"} };

	print_car(my_car);
	print_car(company_car);

	return 0;
}
