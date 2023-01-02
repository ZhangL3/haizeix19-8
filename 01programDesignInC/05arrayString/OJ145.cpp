#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	unsigned long maxLen = 0;
	int n;
	char str[105] = "";
	char strMax[105] = "";
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (strlen(str) > strlen(strMax)) strcpy(strMax, str);
	}
	printf("%s\n", strMax);

	return 0;
}