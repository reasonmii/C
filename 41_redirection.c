/*
Redirection
myFirstPrj.exe의 출력 방향은 원래 콘솔창인데,
output.txt 파일로 방향을 재지정하기

명령 프롬프트 실행

1. 파일로 저장하기
1) 현재 파일 실행 경로 붙여넣기
   ex) cd C:\Users\User\Desktop\C_inflearn\myFirstSolution\Debug
2) dir 입력
3) 현재 파일 입력해서 실행하기 : myFirstPrj.exe
   - apple 입력
   - 결과 : I love apple.
4) 해당 text를 text 파일에 저장하기 : myFirstPrj.exe > output.txt
5) 생성된 파일 열기 : output.txt
   ※ 해당 탐색창 열기 : explorer .

2. 이미 있는 파일 활용해서 프로그램에 넣기
1) 해당 경로에 txt 파일 생성 : 'Melon' 입력
2) myFirstPrj.exe < input.txt
   - 결과 : I love Melon 출력

3. 이미 있는 파일 활용해서 프로그램에 넣고 새파일 생성하기
myFirstPrj.exe < input.txt > output.txt
- 결과 : 'I love Melon'이 써 있는 output.txt 파일 생성됨

4. 파일에 글 덧붙이기
1) output.txt 파일 열기
   ★ 주의 : >>
   myFirstPrj.exe >> output.txt
2) 'banana' 입력
3) output.txt 파일 확인
   - 결과 : I love Melon
           I love Banana
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    char str[100];

    scanf("%s", str);
    printf("I love %s.\n", str);

    return 0;
}

// ======================================================================

/*
5. 파일 두 개 연결하기

1) 코드 작성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    printf("Programming");
    return 0;
}

2) 명령 프롬프트: 현재 파일 다른 파일로 저장하기
   copy myFirstPrj.exe test.exe
   -> 결과 : test.exe 파일로 저장됨

3) 아래 코드 재작성 후 컴파일

4) 명령 프롬프트 : test.exe 파일 결과를 myFirstPrj.exe 파일에 대입하기
   test.exe | myFirstPrj.exe
   -> 결과 : I love Programming.
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    
    //printf("Programming");

    char str[100];
    scanf("%s", str);
    printf("I love %s\n", str);

    return 0;
}
