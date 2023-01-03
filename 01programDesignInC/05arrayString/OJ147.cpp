#include <stdio.h>
#include <string.h>

int main() {
	char n[10005];

	scanf("%s", n);
	(int)n[strlen(n) - 1] % 2 ? printf("NO\n") : printf("YES\n");
	return 0;
}