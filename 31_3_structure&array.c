#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3

// 문자열을 입력받는 함수
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;

	// ★ scanf() 사용 불가
	// 책 이름 같은 거 입력할 때 중간에 빈칸이 있기 때문
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');        // look for new line
		if (find)                       // if the address is not NULL
			*find = '\0';           // place a null character there
		else
			while (getchar() != '\n')   // dispose of rest of line
				continue;
	}
	return ret_val;
}

struct book {
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

int main() {

	// ★ array of book structures
	// struct book library[MAX_BOOKS]
	struct book library[MAX_BOOKS] = { {"Empty", "Empty", 0.0f}, };  // 초기화
	int count = 0;

	while(1)
	{
		printf("Input a book title or press [Enter] to stop.\n>>");
		if (s_gets(library[count].title, MAX_TITLE) == NULL) break;
		// ★ title 첫 글자가 null character인 경우
		if (library[count].title[0] == '\0') break;
				
		printf("Input the author.\n>>");
		s_gets(library[count].author, MAX_AUTHOR);
		
		printf("Input the price.\n>>");
		int flag = scanf("%f", &library[count].price);

		// clear input line
 		// ※ 여러 문자를 입력했을 때
		// 같은 줄에 있는 첫 글자 외 모든 글자 무시       
		while (getchar() != '\n')
			continue;

		count++;

		if (count == MAX_BOOKS) {
			printf("No more books.\n");
			break;
		}
	}

	if (count > 0) {
		printf("\nThe list of books:\n");
		for (int index = 0; index < count; index++)
			printf("\"%s\" written by %s: $%.1f\n",
				library[index].title, library[index].author, library[index].price);
	}
	else
		printf("No books to show.\n");

	return 0;
}

// ======================================================================
/*
Flexible Array Members
신축성 있는 배열 멤버
- 배열이 flexible하다 = 길이가 변한다
- 예전에는 GCC에서 'struct hack'이라는 걸 이용해,
  일종의 편법으로 사용하기도 했음

★ 사용방법
1) 구조체에서 "마지막" 멤버를 배열로 선언하되,
   길이가 없는 빈 배열 []로 선언해야 함
2) 내가 배열로 사용하고 싶은 크기에 대해 "추가로" 동적할당을 받아야 함
   즉, 동적할당 = 원래 구조체의 크기 + 배열로 사용하고 싶은 크기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	struct flex {
		size_t count;      // unsinged int : 4byte
		double average;    // double : 8byte
		// flexible array member - ★ Last member!
		double values[];
	};

	// ★ 마지막 멤버인 배열의 크기 조절
	const size_t n = 3;

	// 동적할당 : 구조체 크기 + 배열에 들어갈 double 개수 * double 1개 당 크기 
	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL) exit(1);

	printf("\n===Flexible array member===\n");

	/*
	★ 구조체 크기가 16byte인 이유? Padding
	count는 4byte, average는 double이라 8byte인데,
	CPU는 기본적으로 8byte씩 데이터를 묶어 보냄
	따라서, count 4 byte + 빈공간 4 byte로 먼저 보내고
	그 다음에 average 8 byte 보냄
	-> 총 16byte 필요
	*/
	printf("Sizeof struct flex : %zd\n", sizeof(struct flex));  // 16
	printf("Sizeof *pf         : %zd\n", sizeof(*pf));          // 16
	printf("Sizeof malloc      : %zd\n", sizeof(struct flex) + n * sizeof(double));  // 40

	printf("%lld\n", (long long)pf);                                // 15687056
	printf("%lld\n", (long long)&pf->count);                        // 첫 번째 멤버 주소 : 15687056
	printf("%zd\n", sizeof(pf->count));                             // 첫 번째 멤버 사이즈 : 4
	printf("%lld\n", (long long)&pf->average);                      // 15687064 : count주소 + 8byte -> ★ why? Padding
	printf("Address of pf->value %lld\n", (long long)&pf->values);  // 15687072 : average주소 + 8byte
	printf("Value of pf->value %lld\n", (long long)&pf->values);    // 15687072
	printf("Sizeof pf->values %zd\n", sizeof(pf->values));          // 0

	pf->count = n;

	// value 초기화
	pf->values[0] = 1.1;
	pf->values[1] = 2.1;
	pf->values[2] = 3.1;

	// 평균 구하기
	pf->average = 0.0;
	for (unsigned i = 0; i < pf->count; ++i)
		pf->average += pf->values[i];
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average);    // 2.100000

	// -------------------------------------------

	/*
	★ 마지막 멤버를 배열 대신 포인터로 사용하는 경우
	1) 배열은 구조체 내에서 아무 메모리도 차지하지 않지만,
	   포인터는 구조체 내에서 4byte 차지함
	2) '동적할당'을 할 때, 구조체 사이즈에 더하는 방식이 아니기 때문에
	   해당 메모리가 어디에 위치해야 할 지 알 수 없음
	   구조체가 차지하는 메모리와 마지막 멤버가 가리키는 메모리가
	   전혀 엉뚱하게 멀리 떨어져 있을 수 있음

	struct flex {
		size_t count;      // unsinged int : 4byte
		double average;    // double : 8byte
		double *values;    // pointer : 4byte
	};

	// 구조체 내 value의 크기 조절
	const size_t n = 3;
	struct flex pf;

	// 구조체 사이즈에 더하는 방식이 아니라,
	// 단순히 포인터 자리에 들어갈 double 개수에 대한 메모리만 할당
	pf.values = (double*)malloc(sizeof(double) * n);
	*/

	// -------------------------------------------

	struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf2 == NULL) exit(1);

	/*
	Don't copy flexible members, use memcpy() instead

	*pf2 = *pf;
	복사가 잘 되지 않음
	why? struct flex의 size는 사실 16
		 *pf2에 *pf의 16byte만 복사가 됨
		 ★ 추가로 요청한 배열 24byte는 compiler가 알지 못해 복사 못함

	반면, memcpy()를 사용하면,
	pf2에 대해 선언한 메모리 전체에 대해 pf에서 가져와서 복사해줌
	*/
	memcpy(pf2, pf, n * sizeof(double));

	// 11313600  11313600  11313608  11313616
	printf("\n===Flexible array member===\n");
	printf("%lld  %lld  %lld  %lld\n",
		(long long)pf2, (long long)&pf2->count, (long long)&pf2->average, (long long)&pf2->values);

	free(pf);
	free(pf2);

	return 0;
}
