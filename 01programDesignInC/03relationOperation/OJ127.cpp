#include <stdio.h>
using namespace std;

int main() {
	double x;
	int n;
	scanf("%lf%d", &x, &n);

	for (int i = 0; i < n; i++) {
		x = x * (1 + 0.06);
	}

	printf("%d\n", (int)x);
	return 0;
}