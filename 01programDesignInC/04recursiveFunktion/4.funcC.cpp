#include <stdio.h>
#include "2.funcB.h"

int funcC(int n) {
	printf("funcC : %d\n", n);
	if (n == 0) return 1;
	funcB(n - 1);
	return n;
}