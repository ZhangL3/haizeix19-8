#include <stdio.h>
#include <inttypes.h>

void markNotPrimeNums(bool *notPrimeNums, int size) {
	for (int i = 2; i * i < size; i++) {
		if (notPrimeNums[i]) continue;
		for (int j = i * i; j <= size; j += i) {
			notPrimeNums[j] = true;
		}
	}
}

int main() {
	int l, r;
	int lFarPrime = 0, rFarPrime = 0, lClosePrime = 0, rClosePrime = 0;
	int closestDist, farstDist;
	int lastPrime = 0, minDist = INT8_MAX, maxDist = INT8_MIN, curDist;
	bool notPrimeNums[8000005];
	scanf("%d %d", &l, &r);
	markNotPrimeNums(notPrimeNums, r + 1);
	for (int i = l; i <= r; i++) {
		// printf("%d: %d\n", i, notPrimeNums[i]);
		// if i is prime
		if (!notPrimeNums[i]) {
			if (lastPrime) {
				curDist = i - lastPrime;
				if (curDist < minDist) {
					minDist = curDist;
					lClosePrime = lastPrime;
					rClosePrime = i;
				}
				if (curDist > maxDist) {
					maxDist = curDist;
					lFarPrime = lastPrime;
					rFarPrime = i;
				}
			}
			lastPrime = i;
		}
	}
	if (minDist != INT8_MAX && maxDist != INT8_MIN) {
		printf("%d,%d are closest, %d,%d are most distant.\n", lClosePrime, rClosePrime, lFarPrime, rFarPrime);
	} else {
		printf("There are no adjacent primes.");
	}

	return 0;
}