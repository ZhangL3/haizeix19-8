#include <stdio.h>
using namespace std;

int main() {
	double r1, r2;
	scanf("%lf%lf", &r1, &r2);

	printf("%.2lf\n", 3.14 * r1 * r1 - 3.14 * r2 * r2);

	return 0;
}