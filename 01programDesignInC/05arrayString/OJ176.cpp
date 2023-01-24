#include <stdio.h>
#include <string.h>

int main() {
	int cnt = 0;
	char str[1005];
	char pattern[1005];
	scanf("%[^\n]s", str);
	// printf("str = %s\n", str);
	scanf("%s", pattern);
	// printf("pattern = %s\n", pattern);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == pattern[0]) {
			bool flag = true;
			for (int j = 1; j < strlen(pattern); j++) {
				if (str[i + j] != pattern[j]) {
					flag = false;
					break;
				}
			}
			flag && cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}