#include <stdio.h>

int main() {
	int mt[205][205];
	int m, n;
	scanf("%d %d", &n, &m);
	// printf("m = %d, n = %d\n", m, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mt[i][j]);
			// printf("%d ", mt[i][j]);
		}
		// printf("\n");
	}

	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (j == n - 1) printf("%d", mt[j][i]);
			else printf(" %d", mt[j][i]);
		}
		printf("\n");
	}
	return 0;
}