#include <stdio.h>
#include <math.h>

int main() {
	double x, n, principals, ans;
	scanf("%lf %lf", &x, &n);
	// principals = x;

	// for (int i = 0; i < n; i++) {
	// 	principals = principals * (1 + 0.06);
	// 	ans = principals;
	// }
	
	ans = x * pow(1.06, n);

	printf("%.6f\n", ans);
	return 0;
}