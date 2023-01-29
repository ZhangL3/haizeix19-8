#include <stdio.h>
#include <string.h>

int convertChar(int c) {
	if (c >= 65 && c <= 90) return c + 32;
	if (c >= 97 && c <= 122) return c - 32;
	return c;
}

int main() {
	char s[1000];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		printf("%c", convertChar(s[i]));
	}
	printf("\n");
}