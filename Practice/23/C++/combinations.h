#include "factorials.h"

#ifndef compp
#define compp

int comb(int k, int n) {
	return fact(n) / fact(k) / fact(n-k);
}

#endif