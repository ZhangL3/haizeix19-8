#include <stdio.h>
#include <string.h>

void markPrimeNumbers(int *prime, int size) {
	// i = 5 时，5 * [2, 3, 4] 都被标记过了
	// 所以最开始标记的是 5 * 5, 得小于 size
	for (int i = 2; i * i < size; i++) {
		if (prime[i]) continue;
		for (int j = i * i; j <= size; j += i) {
			prime[j] = 1;
		}
	}
}

int main() {
	int min, max;
	int prime[100005] = {0};
	scanf("%d %d", &max, &min);
	// printf("max = %d, min = %d\n", max, min);
	markPrimeNumbers(prime, max + 5);
	for (int i = min; i <= max; i++) {
		if (prime[i] == 0) {
			printf("%d\n", i);
		}
	}



	return 0;
}