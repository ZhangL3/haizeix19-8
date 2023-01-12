#include <stdio.h>

void printChars(int a) {
	// A: 65
	int l = a - 65 + 1;
	int i;
	for (i = 0; i < l; i++) {
		printf("%c", a - i);
	}
	for (; i < 2 * l - 1; i++) {
		printf("%c", 65 + (i - l));
	}
	printf("\n");
}

void printSpaces(int n) {
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
}

int main() {
	char ch;
	int c, n;
	scanf("%c", &ch);
	c = (int) ch;
	n = c - 64;
	for (int i = 0; i < n; i++) {
		printSpaces(i);
		printChars(c - i);
	}
	return 0;
}