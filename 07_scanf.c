/* 
 * Visual studio warns using 'scanf'
 *
 * Method1)
 * Write this code on the top : #define _CRT_SECURE_NO_WARNINGS 
 *
 * Method2)
 * Debug mode
 * Solution Explorer - Right click 'myFirstPrj' - Properties
 * C/C++ - Preprocessor
 * Professor Derinitions : WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions)
 * Change to : WIN32;_DEBUG;_CONSOLE;%(PreprocessorDefinitions);_CRT_SECURE_NO_WARNINGS
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int i = 0;
	scanf("%d", &i);   // & : ampersand

	printf("Value is %d\n", i);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	int i = 0, j = 0;
	int sum = 0;

	printf("Input two integers\n");
	scanf("%d%d", &i, &j);

	printf("Your numbers are %d and %d\n", i, j);

	sum = i + j;

	printf("%d + %d = %d\n", i, j, i+j);
	printf("%d + %d = %d\n", i, j, sum);

	return 0;
}

// ======================================================================

#include <stdio.h>

int main() {

	float won = 0;
	float dollar = 0;

	printf("Input Won\n");
	scanf("%f", &won);

	// 0.00089f : float형임을 선언
	dollar = won * 0.00089f;
	printf("Dollar = %f\n", dollar);

	return 0;
}
