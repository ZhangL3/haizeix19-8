#include <stdio.h>

int main() {
	int n, sum = 0;
	scanf("%d", &n);

	for (int i = 3, j = 2, k = 0; k < n; j += 2, k++) {
		printf("%d\n", i);
		sum += i;
		i += j;
	}
	printf("%d\n", sum);

	return 0;
}