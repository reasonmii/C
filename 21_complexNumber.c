// visual studio보다 gcc에서 복소수 더 잘 지원함 (visual studio code)
// visual studio 사용자들은 주로 직접 만들어서 복소수 사용

#include <stdio.h>
#include <complex.h>

int main() {

	// Dcomplex : double type
	_Dcomplex z;
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;

	return 0;
}
