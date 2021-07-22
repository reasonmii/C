#include <stdio.h>

int main() {

	char m = '*';
	printf("%c %hhd\n", m, m);   // * 42

	// Bell (Ding-dong)
	// \a = \07 = \x7
	char a = '\a';
	printf("%c", a);
	printf("\07");
	printf("\x7");

	printf("\x23");         // #

	printf("AB\tCDEF\n");
	printf("ABC\tDEF\n");

	// \ 'HA+' "Hello" ?
	printf("\\ \'HA+\' \"Hello\" \?\n");

	return 0;
}
