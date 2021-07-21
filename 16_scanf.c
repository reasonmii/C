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


