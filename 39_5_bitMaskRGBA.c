/*
구글 검색 : RGB color table
-> 그래픽디자인, 웹프로그래밍에서
   많이 사용하는 16진수 color table
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BYTE_MASK 0xff

int main() {

	/*
	0x66CDAAFF : midium aqua marine 색상
	-> 이때, 66 : red, CD : green, AA : blue, FF : alpha 의미

	4 bytes color로 표현하면 아래와 같음
	- red : 102
	- green : 205
	- blue : 170
	- alpha : 255 (투명도)
	*/
	unsigned int rgba_color = 0x66CDAAFF;

	unsigned char red, green, blue, alpha;

	// 4byte color로 바꿔서 표현하기
	// Use right shift >> operator
	// ★ 순서주의
	alpha   = rgba_color & BYTE_MASK;
	blue    = (rgba_color >>  8 & BYTE_MASK);
	green   = (rgba_color >> 16 & BYTE_MASK);
	red     = (rgba_color >> 24 & BYTE_MASK);

	// (R, G, B, A) = (102, 205, 170, 255)
	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha);

	return 0;
}
