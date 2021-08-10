/*
#pragma tokens (ex: once)
- Compiler마다 pragma로 지원되는 내용이 다름
※ Microsoft : https://docs.microsoft.com/vi-vn/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-150

#pragma once
- Header guard로 사용됨
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전처리 단계에 설정
// 1byte로 padding = padding을 하지 않음
// #pragma pack(1)

/*
전처리 연산자
_Pragma("pack(1)")

- Visual Studio에서 지원X
- Pragma 다음에 오는 token을 이렇게 문자열로 넣을 수 있음
  문자열은 VS가 가져오는 과정에서 'destringizing' 함

※ destringizing
remove first and last ", \" -> "
- 문자열에 대한 앞뒤 "" 제거
- \" 인 경우 " 로 표시
*/

/*
#define으로 아래와 같이 macro 만들어서 사용 가능
- Visual Studio에서 지원X

#define PACK1 _Pragma("pack(1)")
PACK1
*/

// warning 끄기
#pragma warning( disable : 4477 )

// warning을 error로 변경
// #pragma warning( error : 4477 )

struct s {
	int i;
	char ch;
	double d;
};

int main() {

	/*
	#pragma pack(1)
	- 적용 전 : 16
	- 적용 후 : 13

	_Pragma("pack(1)")
	- 적용 전 : 16
	- 적용 후 : 13

	*/
	// 
	struct s A;
	printf("Size of A is: %zd", sizeof(A));

	return 0;
}

