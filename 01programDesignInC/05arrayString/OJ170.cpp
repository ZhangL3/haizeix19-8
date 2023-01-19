#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char str[100000];
	const char pattern[] = "Ban_smoking";
	const char target[] = "No_smoking";

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int j = 0, k; j < strlen(str); j++) {
			bool isMatched = false;
			if (str[j] == 'B') {
				isMatched = true;
				for (k = 0; k < strlen(pattern); k++) {
					if (str[j + k] != pattern[k]) {
						isMatched = false;
						break;
					}
				}
				if (isMatched) {
					printf("%s", target);
					j = j + k - 1;
				}
			}
			if (isMatched == false) {
				printf("%c", str[j]);
			}
		}
		printf("\n");
	}


	return 0;
}