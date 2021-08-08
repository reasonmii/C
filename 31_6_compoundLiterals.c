/*
Compound Literals 복합 리터럴
구조체의 값을 임시로 잠깐 사용할 때 편하게 활용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	// char* title;  -> not recommended
	// char* author; -> not recommended
	float price;
};

struct rectangle {
	double width;
	double height;
};

double rect_area(struct rectangle r) {
	return r.width * r.height;
}

double rect_area_ptr(struct rectangle* r) {
	return r->width * r->height;
}

int main() {

	// 구조체 초기화
	struct book book_to_read = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.5f };

	// 한 번 초기화 한 후에는 
	// 아래와 같이 값을 변경하려 하면 ERROR 발생
	// book_to_read = { Alice in Wonderland", "Lewis Carroll", 20.3f }

	// 해결방법1
	strcpy(book_to_read.title, "Alice in Wonderland");
	strcpy(book_to_read.author, "Lewis Carroll");
	book_to_read.price = 20.3f;

	// 해결방법2
	struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	book_to_read = book2;

	/*
	★ 해결방법3 : compound literal 사용하기
	"Alice in Wonderland", "Lewis Carroll", 20.3f와 같이
	다양한 literal 자료형을 묶어서 대입

	이때, (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f }는
	R-value가 아닌 L-value임

	*/
	book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };

	printf("%s %s\n", book_to_read.title, book_to_read.author);

	// -------------------------------------------

	// 만약 아래의 경우에서 rec1의 용도가
	// area를 계산하는 것 외에 아무것도 없다면,
	// 굳이 변수로 처음에 초기화하며 선언하는 것이 낭비일 수도 있음
	struct rectangle rec1 = { 1.0, 2.0 };
	double area = rect_area(rec1);

	// 이러한 경우 아래처럼 처음부터 복합 리터럴 area값만 계산하는 게 효율적
	area = rect_area((struct rectangle) { 1.0, 2.0 });
	printf("%f\n", area);

	// &(struct rectangle) : 주소값 활용하기
	// { .height = 3.0, .width = 2.0 }
	// - Designated Initializers 사용해서 값 결정하는 방법도 가능
	area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 });
	printf("%f\n", area);

	return 0;
}

