#include <stdio.h>

void markNotPrime(bool *notPrimeArr, int size) {
	for (int i = 2; i * i < size; i++) {
		// printf("i = %d\n", i);
		if (notPrimeArr[i]) continue;
		for (int j = i * i; j <= size; j += i) {
			notPrimeArr[j] = 1;
		}
	}
}

int binarySearch(int targetNum, int startNum, int endNum, bool *notPrimeArr) {
	int midNum = (startNum + endNum) / 2;
	while (notPrimeArr[midNum] || midNum != targetNum) {
		// printf("midNum = %d\n", midNum);
		if (midNum < targetNum) startNum = midNum + 1;
		if (midNum > targetNum) endNum = midNum - 1;
		// printf("startNum = %d", startNum);
		// printf("endNum = %d", endNum);
		if (startNum >= endNum) return 0;
		midNum = (startNum + endNum) / 2;
	}

	return midNum;
}

int main() {
	bool notPrimeNums[8000005];
	int n, cnt = 0;
	scanf("%d", &n);
	markNotPrime(notPrimeNums, n);
	for (int i = 2; i < n / 2 + 1; i++) {
		if (notPrimeNums[i] || notPrimeNums[n - i]) continue;
		cnt++;
		// if (binarySearch(n - i, n / 2, n, notPrimeNums)) cnt++;
		// printf("i = %d: %d\n", i, binarySearch(n - i, n / 2, n, notPrimeNums));
	}
	printf("%d\n", cnt);

	return 0;
}