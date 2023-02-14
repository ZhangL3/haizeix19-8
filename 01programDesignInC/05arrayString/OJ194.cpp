#include <stdio.h>

int binarySearch(int target, int *arr, int l, int r) {
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (target == arr[mid]) return mid;
		if (target < mid) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int main() {
	int n, s, ans;
	int a[100005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	scanf("%d", &s);
	for (int i = 0; i < n; i++) {
		ans = binarySearch(s - a[i], a, 0, n - 1);
		printf("ans = %d\n", ans);
		if (ans >= 0) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}