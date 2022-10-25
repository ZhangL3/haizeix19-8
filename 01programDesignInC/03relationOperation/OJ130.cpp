#include <stdio.h>
using namespace std;

int main() {
	double m = 0.0, sum = 0.0;
	int n;
	scanf("%lf%d", &m, &n);
	for (int i = 0; i < n; i++) {
		sum = (m + sum) * (1 + 0.00417);
	}
	
	printf("$%.2lf\n", sum);

	return 0;
}