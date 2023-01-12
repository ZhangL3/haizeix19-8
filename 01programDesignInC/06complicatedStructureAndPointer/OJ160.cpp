#include <stdio.h>
#include <math.h>
#define PI 3.14

double getRoundPerimeter(double r) {
	// printf("getRoundPerimeter = %.2lf\n", 2 * PI * r);
	return 2 * PI * r;
}

double getRoundArea(double r) {
	// printf("getRoundArea = %.2lf\n", PI * pow(r, 2));
	return PI * pow(r, 2);
}

double getTrangleArea(double l) {
	// printf("getTrangleArea = %.2lf\n", l * l / 2);
	return l * l / 2;
}

double getBase(double l) {
	// printf("getBase = %.2lf\n", sqrt(pow(l, 2) + pow(l, 2)));
	return sqrt(pow(l, 2) + pow(l, 2));
}

int main() {
	double r, h, l, area, perimeter, surfaceArea;
	// double ans;
	scanf("%lf %lf", &r, &h);
	l = 2 * r;
	area = getRoundArea(r) / 2 + getTrangleArea(l);
	perimeter = getRoundPerimeter(r) / 2 +  l + getBase(l);
	surfaceArea = 2 * area + perimeter * h;
	printf("%.2lf\n", surfaceArea);

	return 0;
}