#include <stdio.h>

int main() {
	char str[105];
	int cnt = 0;
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		if (str[i] != 'A') continue;
		cnt++;
	};
	printf("%d\n", cnt);

	return 0;
}