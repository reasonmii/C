/*
EOF (End of File)
파일의 끝을 표현하기 위해 정의된 상수
더 이상 읽을 수 있는 데이터가 없음을 의미함 (stream 종료 시기)
보통 -1 로 정의된 상수
콘솔 창에서 ctrl + z 입력
함수 호출이 실패했을 때 발생
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int c;

    // ctrl + z + Enter : -1 출력 후 종료
    // 운영체제 강제 종료 : ctrl + c
    while ((c = getchar()) != EOF)  // End Of File
        putchar(c);

    return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int c;

    // 각 입력 문자에 대한 ASCII CODE 출력
    while (1) {
        c = getchar();
        printf("%d\n", c);
        if (c == EOF)
            break;
    }

    return 0;
}

