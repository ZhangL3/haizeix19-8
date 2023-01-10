#include <stdio.h>

void printChars(int startChar, int n) {
	int c = startChar;
	if (n == 1) printf("%c", startChar);
	else {
		for (int i = 0; i < n; i++) {
			printf("%c", c);
			if (i < n / 2) {
				c++;
			} else {
				c--;
			}
		}
	}
}

void printSpace(int n) {
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
}

int main() {
	int n, c, l, A = 65;
	scanf("%d", &n);
	l = 2 * n - 1;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (i < n) {
			c = A + i;
			printSpace(i);
			printChars(c, l - i);
			l--;
		} else {
			if (i == n) l++;
			c--;
			l++;
			printSpace(l - (1 + 2 * (i + 1 - n)));
			printChars(c, 1 + 2 * (i + 1 - n));
		}
		printf("\n");
	}

	return 0;
}