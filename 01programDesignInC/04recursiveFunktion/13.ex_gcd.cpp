#include <stdio.h>

/*
x, y 为传出参数，被一层一层的回溯，所以用地址
*/
int ex_gcd(int a, int b, int *x, int *y) {
	if (!b) {
		*x = 1, *y = 0;
		return a;
	}
	// 上一层的 x, y 分别存入 xx 和 yy
	int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
	// 开始回溯
	// 当前 x 等于上一次的 y
	*x = yy;
	// 当前 y 等于上一次的 x - flow(a / b) * y
	*y = xx - a / b * yy;

	// 简洁版
	// int xx, yy, ret = ex_gcd(b, a % b, y, x);
	// *y -= a / b * (*x);

	return ret;
}

int main() {
	int a, b, x, y;
	// a * x + b * y = ex_gcd(a, b)
	while(~scanf("%d%d", &a, &b)) {
		printf("ex_gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
		printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
	}
	return 0;
}