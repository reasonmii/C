// ※ https://en.cppreference.com/w/

#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>

#include <math.h>
// #include <tgmath.h>   // type generic macros

int main() {

	printf("%f\n", cos(3.141592));

	// -------------------------------------------
	// Pythagorean theorem

	// ★ 정밀도 : double > float
	// -> 비슷해 보이지만 내부적으로 의외로 차이 많이 남
	double c = 5.0, b = 4.0, a;
	a = sqrt(c * c - b * b);
	printf("a = %f\n", a);

	// ★ sqrtf : sqrt 결과를 float로 반환
	float cf = 5.0f, bf = 4.0f, af;
	af = sqrtf(cf * cf - bf * bf);
	printf("af = %f\n", af);

	return 0;
}

// ======================================================================
/*
Visual Studio에서 지원하지 않는 math library
Online Compiler 사용하기
*/

#include <stdio.h>
#include <math.h>
#include <tgmath.h>

// Generic Selection Expression
// long double인 경우 sqrtl -> 정밀도↑
#define SQRT(X) _Generic((X), \
    long double: sqrtl, \
    default: sqrt, \
    float: sqrtf)(X)

int main() {
    
    // Type Variants
    
    double t1 = SQRT(2.0f);
    double t2 = SQRT(2.0);
    
    // result : ★ Not Identical
    if(t1 == t2)
        printf("Identical\n");
    else
        printf("Not Identical\n");
    
    // -------------------------------------------
    // Tgmath.h Library
    
    /*
    sqrt : 입력, 출력 모두 double로 받음
    -> float를 입력해도 double로 자동 변환
    
    그런데 Tgmath.h library를 include하면
    ★ float를 float로 계산함
    */
    double a1 = sqrt(2.0f);
    double a2 = sqrt(2.0);

    /*
    1) Tgmath.h library를 쓰지 않은 경우
       result : ★ Identical 
    2) 포함한 경우
       result : ★ Not Identical
    */
    if(a1 == a2)
        printf("Identical\n");
    else
        printf("Not Identical\n");
    
    return 0;
    
}
