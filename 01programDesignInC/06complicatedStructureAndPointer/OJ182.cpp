#include <stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int n, maxNum = 0, tmp = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		// printf("%d\n", tmp);
		maxNum = max(tmp, maxNum);
	}
	printf("%d\n", maxNum);
	return 0;
}