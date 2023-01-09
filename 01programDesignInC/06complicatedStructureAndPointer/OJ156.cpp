#include <stdio.h>

void getPrime(int *prime, int l) {
	// printf("l = %d\n", l);
	// 质数从 2 开始，为什么是乘方
	for (int i = 2, j; i * i < l; i++) {
		// printf("i = %d\n", i);
		if (prime[i] == 0) {
			// 初始为 i 的 2 倍
			j = 2 * i;
			// printf("prime[%d] == %d\n", i, prime[i]);
			while (j < l) {
				// 标记 i 的倍数为合数
				prime[j] = 1;
				// printf("%d = 1\n", j);
				j = j + i;
			}
		}
	}
}

void getPerfectSquareNumber() {

} 

int main() {
	int m, n;
	int p[10000] = {1};
	int s[100];
	scanf("%d %d", &m, &n);
	getPrime(p, (sizeof(p) / 4));
	// for (int i = 0; i < sizeof(p) / 4; i++) {
	// 	if (p[i] == 1) {
	// 		printf("%d\n", p[i]);
	// 	}
	// }

	return 0;
}