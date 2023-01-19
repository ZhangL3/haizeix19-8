#include <stdio.h>
#include <string.h>

int main() {
	int n, tmp, sum = 0;
	int t[26] = {0};
	char c;
	char str[35];
	scanf("%d", &n);
	// printf("n = %d\n", n);
	for (int i = 0; i < n; i++) {
		scanf("\n%c", &c);
		// printf("c = %c\n", c);
		scanf("%d", t + ((int)c - 65));
	}
	// for (int i = 0; i < 26; i++) {
	// 	printf("%d: %d\n", i, t[i]);
	// }

	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		int s = (int)str[i] - 65;
		if (s >= 0 && s <= 26) {
			sum += t[s];
		}
	}
	printf("%d\n", sum);


	return 0;
}