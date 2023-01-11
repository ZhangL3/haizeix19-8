#include <stdio.h>

void printSpace(int n) {
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
}

int main() {
	// l: total length of a row
	int n, l;
	scanf("%d", &n);
	l = 2 * n + 1;
	// first helf
	for (int i = 0; i < n; i++) {
		l -= 1;
		printSpace(i);
		printf("%d", n - i);
		printSpace(l - i - 1);
		printf("%d", n - i);
		printf("\n");
	}
	// middle: 0
	printSpace(n);
	printf("0\n");
	// second helf
	for (int i = n - 1; i >= 0; i--) {
		l += 1;
		printSpace(i);
		printf("%d", n - i);
		printSpace(l - i - 2);
		printf("%d", n - i);
		printf("\n");
	}
}