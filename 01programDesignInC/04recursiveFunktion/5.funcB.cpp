#include <stdio.h>

int funcB(int n) {
	printf("funcB : %d\n", n);
	if (n == 0) return 1;
	return n * funcB(n - 1);
}