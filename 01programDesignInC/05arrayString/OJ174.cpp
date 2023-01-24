#include <stdio.h>
#include <string.h>

int main() {
	char str[1000005];
	char ch;
	int i = 0;
	scanf("%[^\n]s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			printf("%%20");
		}
		else printf("%c", str[i]);
	}

	return 0;
}