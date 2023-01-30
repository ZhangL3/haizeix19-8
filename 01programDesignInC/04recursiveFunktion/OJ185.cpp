#include <stdio.h>

int f(int n, int *val) {
	if (n == 1 || n == 2) return 1;
	*val = f(n - 1, val) + f(n - 2, val);
	return *val;
}

int main() {
	int n, val = 0;
	scanf("%d", &n);
	printf("%d\n", f(n, &val));
}