#include <stdio.h>

void markPrime(int *prime, int l) {
	// printf("l = %d\n", l);
	// 质数从 2 开始，为什么是乘方更好
	// 因为 2 * i 其实是被 2 标记过了，所有初始值最小可以是这两个质数的乘积
	// for (int i = 2, j; 2 * i < l; i++) {
	for (int i = 2, j; i * i < l; i++) {
		// printf("i = %d\n", i);
		if (prime[i] == 0) {
			// 初始为 i 的 2 倍
			// 为什么是乘方更好
			// j = 2 * i;
			j = i * i;
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

void markPerfectSquareNumber(int *pf, int l) {
	for (int i = 2; i * i < l; i++) {
		pf[i * i] = 1;
	}
} 

int getFirstTwoNumber(int n) {
	return n / 100;
}

int getLastTwoNumber(int n) {
	return n % 100;
}

int main() {
	int m, n, cnt = 0;
	scanf("%d %d", &m, &n);
	int p[10005] = {0};
	int s[105] = {0};
	s[1] = 1;
	markPrime(p, (sizeof(p) / 4));
	markPerfectSquareNumber(s, (sizeof(s) / 4));
	for (int i = m; i <= n; i++) {
		// if (i == 1601) {
		// 	printf("p[%d] = %d\n", i, p[i]);
		// 	printf("s[%d] = %d\n", getFirstTwoNumber(i), s[getFirstTwoNumber(i)]);
		// 	printf("s[%d] = %d\n", getLastTwoNumber(i), s[getLastTwoNumber(i)]);
		// }
		if (p[i] == 1) continue;
		if (s[getFirstTwoNumber(i)] == 0 || s[getLastTwoNumber(i)] == 0) continue;
		if (cnt == 0) {
			printf("%d", i);
		} else {
			printf(" %d", i);
		}
		cnt++;
	}
	printf("\n%d\n", cnt);

	return 0;
}