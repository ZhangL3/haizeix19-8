#include <stdio.h>

int main() {
	int n;
	unsigned long long ans = 2;
	scanf("%d", &n);
	if (n == 0) {
		printf("%d\n", 1);
		return 0;
	}
	for (int i = 1; i < n; i++) {
		ans *= 2;
	}
	printf("%lld\n", ans);
	return 0;
}