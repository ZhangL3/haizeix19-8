#include <stdio.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 3) {
		printf("%d\n", 14);
	} else {
		printf("%.1lf\n", 14 + ((n - 3) * 2.3));
	}

	return 0;
}