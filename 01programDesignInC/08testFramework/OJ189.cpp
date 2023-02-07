#include <stdio.h>

int binarSearch(int target, int *nums, int size) {
	int startInd = 0, endInd = size - 1, midInd = (startInd + endInd) / 2;
	while (
		nums[midInd] != target
	) {
		if (target < nums[midInd]) {
			endInd = midInd - 1;
		} else {
			startInd = midInd + 1;
		}
		if (startInd > endInd) return 0;
		midInd = (startInd + endInd) / 2;
	}
	return midInd + 1;
}

int main() {
	int size, searchSize;
	int nums[1000005];
	int targetNum;

	scanf("%d %d", &size, &searchSize);
	for (int i = 0; i < size; i++) {
		scanf("%d", nums + i);
	}

	for (int i = 0; i < searchSize; i++) {
		scanf("%d", &targetNum);
		if (i < searchSize - 1) printf("%d ", binarSearch(targetNum, nums, size));
		else printf("%d\n", binarSearch(targetNum, nums, size));
	}
}