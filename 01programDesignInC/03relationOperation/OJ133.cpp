#include <stdio.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			j - i && printf("\t");
			printf("%d*%d=%d", i, j, i * j);
		}
		printf("\n");
	}

	return 0;
}