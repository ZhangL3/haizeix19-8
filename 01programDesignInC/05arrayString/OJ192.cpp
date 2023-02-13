#include <stdio.h>
#include <math.h>

double f(double x) {
	return x * exp(x);
}

double binarySearch(int target, double l, double r) {
	int i = 0;
	while(r - l > 0.000001) {
		double mid = (l + r) / 2;
		// printf("r = %lf, l = %lf, mid = %lf\n", r, l, mid);
		if (f(mid) > target) {
			r = mid;
		} else {
			l = mid;
		}
		i++;
	}
	return l;

}

int main() {
	int a;
	scanf("%d", &a);
	printf("%.4f\n", binarySearch(a, 0, 30));
	return 0;
}