// 이중포인터 **
// 일반변수의 주소가 아닌, 포인터의 주소를 가진 포인터를 의미

#include <stdio.h>

void main() {

	char* ptrArray[2];
	char** ptrptr;
	int i;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Seoul";
	ptrptr = ptrArray;

	// %s : 주소값을 받고 그 주소값에 저장된 문자를 시작으로 '\0'이 나올 때까지 문자열 출력
	// %c : 실제 문자를 받아서 해당 문자 출력
	printf("\n ptrArray[0]의 주소       (&ptrArray[0]) = %u", &ptrArray[0]);  // 3537264
	printf("\n ptrArray[0]의 값         (ptrArray[0])  = %u", ptrArray[0]);   // 4160304
	printf("\n ptrArray[0]의 참조값     (*ptrArray[0]) = %c", *ptrArray[0]);  // K
	printf("\n ptrArray[0]의 참조문자열 (*ptrArray[0]) = %s", *ptrArray);     // Korea 

	printf("\n ptrArray[1]의 주소       (&ptrArray[1]) = %u", &ptrArray[1]);     // 3537268
	printf("\n ptrArray[1]의 값         (ptrArray[1])  = %u", ptrArray[1]);      // 4160312
	printf("\n ptrArray[1]의 참조값     (*ptrArray[1]) = %c", *ptrArray[1]);     // S
	printf("\n ptrArray[1]의 참조문자열 (*ptrArray[1]) = %s", *(ptrArray + 1));  // Seoul

	printf("\n ptrptr의 주소           (&ptrptr) = %u", &ptrptr);   // 3537252
	printf("\n ptrptr의 값             (ptrptr)  = %u", ptrptr);    // 3537264
	printf("\n ptrptr의 1차 참조값     (*ptrptr) = %c", *ptrptr);   // 0
	printf("\n ptrptr의 2차 참조값     (**ptrptr) = %c", **ptrptr); // K
	printf("\n ptrptr의 2차 참조문자열 (**ptrptr) = %s", *ptrptr);  // Korea

	// *ptrArray[0] : Korea
	printf("\n\n *ptrArray[0] : ");
	for (i = 0; i < 5; i++) printf("%c", *(ptrArray[0] + i));

	// **ptrptr : Korea
	printf("\n\n **ptrptr : ");
	for (i = 0; i < 5; i++) printf("%c", *(*ptrptr + i));

	// *ptrArray[1] : Seoul
	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++) printf("%c", *(ptrArray[1] + i));

	// **(ptrptr + 1) : Seoul
	printf("\n\n **(ptrptr + 1) : ");
	for (i = 0; i < 5; i++) printf("%c", *(*(ptrptr + 1) + i));

	getchar();
}
