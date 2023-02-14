#include <stdio.h>

int binarySearch(int target, int *numArr, int l, int r) {
	while (l <= r) {
		int mid = (l + r) / 2;
		// printf("mid = %d\n", mid);
		if (target == numArr[mid]) return mid;
		if (target < mid)  r = mid - 1;
		else l = mid + 1;
		// printf("l = %d, r = %d\n", l, r);
	}
	return -1;
}

int main() {
	int n, k, s, ans;
	int arr[100005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	scanf("%d%d", &k, &s);
	ans = binarySearch(s - k, arr, 0, n - 1);
	if (ans >= 0) printf("Yes\n");
	else printf("No");

	return 0;
}