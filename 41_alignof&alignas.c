/*
메모리 줄맞춤
Windows Visual Studio는 지원하지 않음
※ 온라인 GCC Compiler
   https://www.onlinegdb.com/online_c_compiler

'_Alignas', '_Alignof' 이렇게 쓰는 게 기본인데
★ #include <stdalign>을 사용해서
c++ style처럼 'alignas', 'alignof'와 같이
간편하게 사용 가능
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdalign.h>

int main() {
    
    // -------------------------------------------
    // 현재 사용하는 compiler가 GCC인지 clang인지 구분하는 코드
    
    #ifdef __clang_major__
    printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
    #endif
    
    #ifdef __GNUC__
    // note that clang 3.7 declares itself as a GCC 4.2"
    printf("GCC detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
    #endif
    
    // result :  GCC detected version 6.5
    
    // -------------------------------------------
    
    // char의 size가 1byte니까, align도 1byte 간격
    printf("Alignment of char = %zu\n", alignof(char));       // 1
    
    // float 10개 배열
    // float가 4 byte니까 각 원소도 4 byte 간격으로 align
    printf("alignof(float[10]) = %zu\n", alignof(float[10])); // 4
    
    // 구조체의 멤버가 1 byte char + 4 byte int
    // 두 개 중 더 큰 4 byte에 맞춰서 align
    printf("alignof(struct{char c; int n;}) = %zu\n",         // 4
            alignof(struct{char c; int n}));
    
    // -------------------------------------------
    
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    char cz;
    
    printf("char alignment : %zd\n", alignof(char));     // _Alignof(char)    // 1
    printf("double alignment : %zd\n", alignof(double)); // _Alignof(double)  // 8
    
    
    // 주소 % 8 -> 나머지 연산
    // 결과가 0인 경우) 줄맞춤이 8글자에 맞춰 된다는 의미
    printf("&dx : %p   %lld\n", &dx, (long long)&dx % 8); // 0 -> double은 8의 배수
    printf("&ca : %p   %lld\n", &ca, (long long)&ca % 8); // 4
    printf("&cx : %p   %lld\n", &cx, (long long)&cx % 8); // 5
    printf("&dz : %p   %lld\n", &dz, (long long)&dz % 8); // 0 -> double은 8의 배수
    printf("&cb : %p   %lld\n", &cb, (long long)&cb % 8); // 6
    printf("&cz : %p   %lld\n", &cz, (long long)&cz % 8); // 7
    
    // -------------------------------------------
    // Align 방법 바꾸기
    // 꼭 객체(object)의 자료형에 맞추지 않고 원하는 값으로 설정하기
    
    // align을 double에 맞춤
    char _Alignas(double) cz2;

    // char인데도 불구하고 주소를 8로 나누면 0이 됨
    printf("&cz : %p   %lld\n", &cz2, (long long)&cz2 % 8); // 0
    
    // align을 16에 맞춤
    char alignas(16) cz3;
    printf("&cz : %p   %lld\n", &cz3, (long long)&cz3 % 8); // 0
    
    // -------------------------------------------
    // 배열을 만들 때 align을 사용하는 방법
    
    unsigned char alignas(long double) c_arr[sizeof(long double)];
    
    return 0;
}
