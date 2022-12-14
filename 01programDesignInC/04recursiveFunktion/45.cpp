#include <stdio.h>
#include <inttypes.h>

typedef int64_t int1;

int1 Triangle(int1 n) {
	return n * (n + 1) / 2;
}

int1 Pentagonal(int1 n) {
	return n * (3 * n - 1) / 2;
}

int1 Hexagonal(int1 n) {
	return n * (2 * n - 1);
}

// 不用函数指针的方法
/* int binary_search(int x) {
	int head = 1, tail = x, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (Pentagonal(mid) == x) return mid;
		if (Pentagonal(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return -1;
} */

int1 binary_search(int1 (*func)(int1), int x) {
	int1 head = 1, tail = x, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (func(mid) == x) return mid;
		if (func(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return -1;
}

int main() {
	int n = 286;
	for (;; n++) {
		if (binary_search(Hexagonal, Triangle(n)) == -1) continue;
		if (binary_search(Pentagonal, Triangle(n)) == -1) continue;
		printf("%" PRId64 "\n", Triangle(n));
		break;
	}

	return 0;
}