#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct personal_owner {
	char rrn1[7];
	char rrn2[8];
};

struct company_owner {
	char crn1[4];
	char crn2[3];
	char crn3[6];
};

// ★ Anonymous Unions
// 공용체를 따로 만드는 것이 아닌 아예 구조체 안에 익명으로 대입
struct car_data {
	char model[15];
	int status;     // 0 = personal, 1 = company
	union data {
		struct personal_owner po;
		struct company_owner  co;
	};
};

void print_car(struct car_data car) {
	printf("-----------------------------------\n");
	printf("Car model : %s\n", car.model);

	if (car.status == 0)
		printf("Personal owner : %s-%s\n",
			car.po.rrn1, car.po.rrn2);

	else
		printf("Comapny owner : %s-%s-%s\n",
			car.co.crn1, car.co.crn2, car.co.crn3);
	printf("-----------------------------------\n");
}

int main() {

	struct car_data my_car = { .model = "Avante", .status = 0, .po = {"830422", "1185600"} };
	struct car_data company_car = { .model = "Sonata", .status = 1, .co = {"111", "22", "33333"} };

	print_car(my_car);
	print_car(company_car);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

  /*
  익명 union을 통해 세 개의 구조체를 묶음
  ★ 세 개는 전부 같은 메모리를 사용
  
  장점)
  같은 구조인데, x/y, i/j 등
  개인에 따라 원하는 주소를 사용할 수 있고
  배열을 사용할 수도 있음
  */
	struct Vector2D {
		union {
			struct { double x, y; };
			struct { double i, j; };
			struct { double arr[2]; };
		};
	};

	// Vector2D가 너무 기니까 ver2로 rename
	typedef struct Vector2D ver2;

	ver2 v = { 3.14, 2.99 };

	printf("%.2f %.2f\n", v.x, v.y);
	printf("%.2f %.2f\n", v.i, v.j);
	printf("%.2f %.2f\n", v.arr[0], v.arr[1]);

	for (int d = 0; d < 2; d++)
		printf("%.2f ", v.arr[d]);

	return 0;
}
