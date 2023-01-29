#include <cstdio>
#include <cmath>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
	double l = -20, r = 20;
	while (fabs(l - r) > EPSILON) {
		double m = (l + r) / 2;
		if (f(p, q, l) * f(p, q, m) > 0) {
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

double f(int p, int q, double x) {
    return p * x + q;
}
