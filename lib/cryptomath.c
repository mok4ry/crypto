#include <stdlib.h>
#include "cryptomath.h"

bool are_coprime(int a, int b) {
	return gcd(a, b) == 1;
}

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}