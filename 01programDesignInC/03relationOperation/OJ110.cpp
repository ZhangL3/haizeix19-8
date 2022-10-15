#include <stdio.h>

using namespace std;

int main() {
	double n;
	scanf("%lf", &n);
	printf("%.2lf\n", n <= 15.0 ? 6 * n : 15 * 6 + (n - 15) * 9);
	printf("%.2lf\n", (n > 15 ? 15 : n) * 6 + (n > 15) * (n - 15) * 9);
	return 0;
}