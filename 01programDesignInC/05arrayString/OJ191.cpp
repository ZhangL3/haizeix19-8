#include <stdio.h>

void markNotPrimeNums(bool *notPrimeNums, int size) {
	for (int i = 2; i * i < size; i++) {
		if (notPrimeNums[i]) continue;
		for (int j = i * i; j <= size; j += i) {
			notPrimeNums[j] = true;
		}
	}
}

int main() {
	int l, r, n, maxDist = 0, lastPrime = 2;
	bool notPrimeNums[8000005];
	scanf("%d", &n);
	markNotPrimeNums(notPrimeNums, n);
	for (int i = 0; i < 20; i++) {
		printf("%d: %d\n", i, notPrimeNums[i]);
		if (!notPrimeNums[i]) {
			maxDist = i - lastPrime > maxDist ? (i - lastPrime) : maxDist;
			lastPrime = i;
		}
	}
	printf("%d\n", maxDist);

	return 0;
}