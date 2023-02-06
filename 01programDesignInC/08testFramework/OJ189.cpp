#include <stdio.h>

int binarSearch(int target, int *nums, int size) {
	int startInd = 0, endInd = size - 1, midInd = (startInd + endInd) / 2;
	while (
		nums[midInd] != target
	) {
		if (target < nums[(startInd + endInd) / 2]) {
			startInd = midInd;
		} else {
			endInd = midInd;
		}
		if (startInd >= endInd) return 0;
		midInd = (startInd + endInd) / 2;
	}
	return midInd + 1;
}

int main() {
	int size, searchSize;
	int nums[1000005];
	int searchNums[1000005];

	scanf("%d %d", &size, &searchSize);
	printf("size = %d, searchSize = %d\n", size, searchSize);
	for (int i = 0; i < size; i++) {
		scanf("%d", nums + i);
	}
	// test
	for (int i = 0; i < size; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	// test end
	// fflush(stdin);
	for (int i = 0; i < searchSize; i++) {
		printf("i = %d\n", i);
		scanf("%d", searchNums + i);
		printf("%d", searchNums[i]);
	}
	fflush(stdout);

	// for (int i = 0; i < searchSize; i++) {
	// 	printf("%d", searchNums[i]);
	// }
	// printf("\n");

	printf("%d\n", binarSearch(searchNums[0], nums, size));


}