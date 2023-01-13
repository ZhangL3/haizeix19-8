// c ^ 2 = a ^ 2 + b ^ 2 - 2 * a * b * cosO
#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main() {
	double a, b, c, O;
	scanf("%lf %lf %lf", &a, &b, &O);
	c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos((O * PI) / 180));
	printf("%.6lf\n", c);
	return 0;
}