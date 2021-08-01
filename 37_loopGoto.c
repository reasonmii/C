/*
goto문
옛날 loop 방식인데, 코드가 꼬이고,
에러가 발생할 확률이 많아서 요즘은 사용X -> 단종된 기술
*/

// ======================================================================

#include <stdio.h>

int main() {

	int n = 1;

label:
	printf("%d\n", n);
	n = n + 1;

	if (n == 10) goto out;
	goto label;

out:

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int size = 15, cost;

    if (size < 10)
        goto a;
    goto b;

a: cost = 50 * size;
b: cost = 100 * size;

    return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char c;

read: c = getchar();
    putchar(c);
    if (c == '.') goto quit;
    goto read;
quit:
    while (1) {
        c = getchar();
        putchar(c);
        if (c == '.') break;
    }

    return 0;
}

