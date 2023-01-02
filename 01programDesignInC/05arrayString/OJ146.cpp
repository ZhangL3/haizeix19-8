#include <stdio.h>

// a: 97, z: 122, A: 65, Z: 90
// 0: 48, 1:29, 9: 57
int plusOne(int n) {
	if (n == 122) return 97;
	if (n == 90) return 65;
	if (
		(n >= 97 && n < 122)
		|| (n >= 65 && n < 90)
	) return n + 1;
	return n;
}

int main() {
	char str[55];
	char c;
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		printf("%c", (char)plusOne((int)str[i]));
		// str[i] = (char)plusOne((int)str[i]);
	}
	// printf("%s", str);
	printf("\n");
	return 0;
}