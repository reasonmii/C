/*
Conversion Specifiers 변환 지정자

%a : 부동 소수점 수, 16진수, p-표기법
%A : 부동 소수점 수, 16진수, P-표기법
%c : 한 글자
%d (또는 %i) : 부호가 있는 10진(decimal) 정수(integer)
%e : 부동 소수점 수, e-표기법
%E : 부동 소수점 수, E-표기법
%f : 부동 소수점 수, 10진수 표기
%g : 값에 따라서 %e나 %f 사용
     지수가 -4보다 작거나 정밀도보다 크거나 같을 경우에는 %e 사용
%G : 값에 따라서 %E나 %f 사용
     지수가 -4보다 작거나 정밀도보다 크거나 같을 경우에는 %E 사용
%o : 부호가 없는 8진(octal) 정소
%p : 포인터
%s : 문자열
%u : 부호가 없는 10진 정수
%x : 부호가 없는 16진 정수, 소문자 알파벳 사용
%X : 부호가 없는 16진 정수, 대문자 알파벳 사용
%% : 퍼센트 기호 출력
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

	double d = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

	// -------------------------------------------

	printf("%c\n", 'A');
	printf("%s", "I love you\n");

	// 문자 너무 긴 경우 '\' 사용
	printf("Even if there's a small chance, \
we owe this to everyone who's not in this room to try.\n");
	
	printf("\n");

	// -------------------------------------------

	// result : 1004 1234 2147483647 -1
	// unsigned integer max가 signed integer max보다 훨씬 큼
	// -> overflow 발생 : -1 출력
	printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX);

	// result : 1024 4294967295 4294967295
	// -1 입력 -> underflow 발생 -> MAX값 출력
	printf("%u %u %u\n", 1024, -1, UINT_MAX);

	// -------------------------------------------

	printf("\n");
	// 이때 lf의 l은 무시됨
	// why? printf 내부에서 float 입력하면 double로 바꿔서 출력되기 때문
	// but, 붙인다고 문제가 되지는 않음
	printf("%f %f %lf\n", 3.141592f, d, d);  // 3.141592 3.141593 3.141593

	// result : 0x1.921fb54442d18p+1 0X1.921FB54442D18P+1
	// a는 소문자 p, A는 대문자 P 출력
	printf("%a %A\n", d, d);

	// 3.141593e+00 3.141593E+00
	// e는 소문자 e, E는 대문자 E 출력
	printf("%e %E\n", d, d);   

	// -------------------------------------------

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89);   // 123457 1.23457e+06
	printf("%G %G\n", 123456.789, 1234567.89);   // 123457 1.23457E+06
	printf("%g %g\n", 0.00012345, 0.000012345);  // 0.00012345 1.2345e-05
	printf("%G %G\n", 0.00012345, 0.000012345);  // 0.00012345 1.2345E-05

	// -------------------------------------------

	printf("\n");
	printf("%o\n", 9);  // 11

	// pointer of operator
	printf("%p\n", &d); // 004FFBBC

	// -------------------------------------------

	printf("\n");
	printf("%x %X\n", 11, 11);  // 16진수 출력 : b B

	// -------------------------------------------

	// %%는 %f를 그대로 인식
	// d는 무시됨
	printf("%%\n", d);         // %

	// -------------------------------------------

	printf("\n");

	// 9칸 만들기, 12345 오른쪽정렬
	printf("%9d\n", 12345);    //     12345

	// 9칸 만들기, 12345 오른쪽 정렬, 남는 부분 0으로 채우기
	printf("%09d\n", 12345);   // 000012345

	printf("%.2f\n", 3.141592);      // 3.14

	// result : 3.14159265358979311600 3.14159265358979311600
	// %f 입력해도 printf는 double로 출력
	// -> double type의 max 값에 맞춰 출력
	printf("%.20f %.20lf\n", d, d);

	// -------------------------------------------

	printf("\n");
	int n_printed = printf("Counting!");

	// result : Counting!9
	// 9 : Counting 글자 개수
	printf("%u\n", n_printed);

	return 0;
}

// ======================================================================

/*
Modifiers 변환 지정자의 수식어들
※ http://www.cplusplus.com/reference/cstdio/printf/

형식 지정자
%[flags][width][.precision][length]specifier
-> specifier 앞에 있어도 되고 없어도 됨

[flags]
-       : 왼쪽정렬 (없으면 오른쪽정렬)
+       : 양수/음수 기호 함께 출력
(space) : 양수인 경우 빈칸, 음수일 때 - 출력 (default)
#       : 8진수, 16진수 등을 출력할 때 앞에 0, 0x 등 출력
0       : 빈칸 0으로 채우기

[width]
(numbers) : 총 글자 자릿수 설정
*

[precision] : 정밀도
.number : 최소 숫자 자릿수만큼 출력하고 빈칸은 0으로 채움
.*

[length] : length of data type / memory
*/

#include <stdio.h>
#include <limits.h>

int main() {

	printf("%10i\n", 1234567);         // 10칸 오른쪽 정렬 :    1234567
	printf("%-10i\n", 1234567);        // 10칸 왼쪽 정렬 : 1234567
	printf("%+i, %+i\n", 123, -123);   // +- 부호표시 : + 123, -123
	printf("% i % i\n", 123, -123);    // +는 빈칸, -는 부호표시 :  123 -123
	printf("%X\n", 17);                // 16진수 : 11
	printf("%#X\n", 17);               // 16진수 : 0X11
	printf("%05i\n", 123);             // 5칸 확보, 남는 자리 0 채우기 : 00123

	// result :     456
	// 이때 *은 7을 의미 -> 7자리 확보
	// 456 오른쪽 정렬
	printf("%*i\n", 7, 456);

	// -------------------------------------------
	// Precision

	printf("%.3d\n", 1024);             // 3자리 확보, 더 크면 그냥 입력 : 1024
	printf("%.5d\n", 1024);             // 5자리 확보, 남는 자리 0 : 01024
	printf("%.3f\n", 123456.1234567);   // 소수점 3자리, 반올림 : 123456.123
	printf("%.3f\n", 123456.1235);      // 소수점 3자리, 반올림 : 123456.124
	printf("%10.3f\n", 123.45678);      // 전체 10자리, 소수점 3자리 :    123.457
	printf("%010.3f\n", 123.45678);     // 전체 10자리, 소수점 3자리, 빈칸 0 : 000123.457
	printf("%.5s\n", "ABCDEFGHIJKLMN"); // ABCDE
	printf("%.s\n", "ABCDEFGHIJKLMN");  // 숫자가 없으면 0이라고 간주 -> 아무 글자도 안 나옴

	// -------------------------------------------
	// Length

	// result : 1 257 257
	// hhd : char -> maximum value of char type : 256 (unsigned) 127 (signed) -> overflow -> 1
	// hd, d : short, decimal -> 257 표현 가능 (no prob.)
	printf("%hhd %hd %d\n", 257, 257, 257);

	// -2147483648 -2147483648 -2147483648
	// %d : INT_MAX+1 -> overflow
	// %lld : long long decimal -> 정상 출력 (no prob.)
	//        but, 상단 Solution Platforms가 'x64'로 설정되어 있어야 원하는 결과 나옴
	//        최근에는 이처럼 'x86'보다 'x64' 더 많이 사용하는 추세
	printf("%d %11d %11d\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL);

	return 0;
}
