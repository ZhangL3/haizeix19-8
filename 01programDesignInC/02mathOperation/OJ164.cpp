#include <stdio.h>
#include <math.h>

int main() {
	double n, m;
	scanf("%lf %lf", &n, &m);
	printf("%.0lf\n", ceil(n / m));
}