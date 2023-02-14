#include <stdio.h>

int binarySearch(int target, int *arr, int l, int r) {
	int mid;

	while (l <= r) {
		if (l == r && arr[l] < target) return l;
		if (l == r && arr[l] > target) return 0;

		mid = (l + r) / 2;

		if (arr[mid] <= target && arr[mid + 1] > target) return mid;
		if (arr[mid] <= target && (arr[mid + 1] == 0 || arr[mid + 1] <= target)) l = mid + 1;
		else r = mid - 1;
	}
	return 0;
}

int b10Search1(int target, int *arr, int l, int r) {
	int mid;
	while (l != r) {
		mid = (l + r + 1) / 2;
		// 如果 mid 没超过，就向右二分
		if (arr[mid] <= target) l = mid;
		// 如果 mid 超过了 target, 就向回减回来一点儿
		else r = mid - 1;
	}
	return l;
}

int b01Search1(int target, int *arr, int l, int r) {
	int mid;
	while (l != r) {
		mid = (l + r + 1) / 2;
		if (arr[mid] <= target) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main() {
	int n, m;
	int nums[100005];
	int num, ind;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", nums + i);
	}

	for (int j = 0; j < m; j++) {
		scanf("%d", &num);
		// ind = binarySearch(num, nums, 0, n - 1);
		ind = b10Search1(num, nums, 0, n - 1);
		if (j < m - 1) {
			printf("%d ", nums[ind]);
		} else {
			printf("%d\n", nums[ind]);
		}
	}

	return 0;
}