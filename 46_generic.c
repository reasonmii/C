/*
Generic selection expression
- Generic programming
  code is not specific to a particular type
  특정한 자료형에 대해서만 작동하는 것이 아님
  여러 가지 자료형 각각에 대해 모두 작동

_Generic : C11에서 추가된 keyword

※ Visual Studio에서 제공X
   Online Compiler 이용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 입력한 X의 자료형에 따라
// switch case 처럼 작동
#define MYTYPE(X) _Generic((X), \
    int : "int", \
    float : "float", \
    double : "double", \
    long : "long", \
    int* : "int*", \
    default : "other" \
)

int main() {

    int d = 5;
    
    printf("%s\n", MYTYPE(d));     // int
    printf("%s\n", MYTYPE(2.0*d)); // double
    printf("%s\n", MYTYPE(3L));    // long
    printf("%s\n", MYTYPE(&d));    // int*
    
    return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MYTYPE(X) _Generic((X), \
    int : (X + 123), \
    default : "other" \
)

int main() {
    int d = 5;
    printf("%d\n", MYTYPE(d));     // 128    
    return 0;
}
