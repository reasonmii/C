/*
#define

● Preprocessor directives 전처리 지시자
It begins with # symbol at the beginning of a line

● Macro
It's an instruction that represents
a sequence of instructions in abbreviated form
- 여러 명령어가 나열되어 있는 것을 하나의 명령어로 축약한 것
- 똑같은 일을 여러 번 해야 할 때 축약하는 것

#define           SAY_HELLO          printf("Hello, World!");
Preprocessor      Macro (name)       body (or replacement list)
directive         매크로 이름        매크로가 실제 하는 역할

● Macro expansion :
실제로는 printf("Hello, World!"); 로 macro가 실행되는 현상

● define의 범위
- 파일 단위
- ★ 한 파일에서 define을 같은 이름으로 쓰는 것 -> 가능
- 만약 어떤 헤더파일에 define이 되어 있고
  그 헤더파일을 main 파일에서 include하면,
  마치 main 파일에도 해당 define이 있는 것처럼 작동
- 그런데, 사실 header 파일에 어떤 define이 있는지
  하나하나 알기 어려움
  -> 그런 경우 보통 redefine 사용
     or 의도치 않게 redefine 발생

● Object-like macros vs Function-like macros
1) Object-like macros
   기호적 상수 선언할 때 사용하는 macro
   ex) #define ONE 1
   전처리기가 ONE을 볼 때마다 모두 1로 바꿈
   ★ 즉, 컴파일러는 ONE의 존재를 볼 수 없음
2) Function-like macro
   ex) #define SQUARE(X) X*X
   전처리기는 SQUARE(X)를 볼 때마다 모두 X*X로 교체함
   ★ 즉, 컴파일러는 SQUARE(X)의 존재를 볼 수 없음

● Tokens
컴파일러에 따라 아래 코드 해석 모두 다름
- 3*2를 문자로 인식
- 3과 2는 숫자, *는 연산자로 인식
- 빈칸까지 모두 인식
- 3*2를 계산해서 6으로 인식

#define SIX 3*2
#define SIX 3  *  2
#define SIX 3    *    2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Symbolic, or manifest constants
#define PI 3.141592
#define GRAVITY 9.8
#define THREE 3

#define MESSAGE "The greatest glory in living lies not in never falling, \
but in rising every time we fall."

// macro를 이용해 macro 선언 가능
// 그러나 macro 사용은 가급적 사용하지 않는 게 좋기 때문에
// 권장하지 않음
#define NINE     THREE*THREE

#define SAY_HELLO printf("Hello, World!\n");
#define SAY_HELLO for(int i = 0; i < 10; i++) printf("Hello, World!\n");

// printf를 위한 formatting 문자열을
// 미리 macro로 지정 가능
#define FORMAT "Number is %d.\n"

// 아주 예전에는 안 됐지만
// 이렇게 앞에 빈칸 써도 문제 없이 실행은 됨
// 절대 권장하지 않음
 #define WITH_BLANK 1

#define MY_CH 'Z'
#define MY_ST "Z"    // Z\0 -> 문자열이니 보이지 않는 null character 포함됨

// 배열 크기 선언할 때 macro 많이 사용함
#define LIMIT 20
const int LIM = 50;
static int arr1[LIMIT];
const int LIM2 = 2 * LIMIT;

/*
변수를 이용한 선언 -> 컴파일러에 따라 ERROR 발생
※ clang, C++에서는 사용 가능
static int arr2[LIM];
const int LIM3 = 2 * LIM;
*/

// Redefining Constants
// 한 파일에서 define을 같은 이름으로 쓰는 것 -> 가능
#define SIX 2*3
#define SIX 2*3
#define SIX 2 * 3 // Warning -> 컴파일러가 2*3 과 2 * 3을 다르게 인식하기 때문

// ★ #undef : define 없애기
#undef SIX
#define SIX 2*3

int main() {

	int n = THREE;

	// SAY_HELLO 안에서 이미 ;를 썼으니
	// ; 안 써도 됨
	// 여기에서는 써도 되지만,
	// 일부 프로그램에서는 쓰면 난리가 나는 경우 있음
	SAY_HELLO
	/*Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!
	Hello, World!*/

	n = NINE;
	printf(FORMAT, n);  // Number is 9

	// result : The greatest glory in living lies not in never falling, but in rising every time we fall.
	printf("%s\n", MESSAGE);     // replaced

	// result : SAY_HELLO NINE
	printf("SAY_HELLO NINE\n");  // Not replaced (macro로 바뀌지 않고 그대로 출력)

	return 0;
}
