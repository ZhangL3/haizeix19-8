#include <stdio.h>

int funcA(int n);
int funcB(int n);

int funcB(int n) {
	printf("funcB : %d\n", n);
	if (n == 0) return 0;
		funcA(n - 1);
	return n;
}

int funcA(int n) {
	printf("funcA : %d\n", n);
	if (n == 0) return 0;
	funcB(n - 1);
	return n;
}
