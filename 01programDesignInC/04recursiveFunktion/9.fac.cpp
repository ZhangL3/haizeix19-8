#include <stdio.h>

// 语义信息: fac(n) 代表 n 的阶乘是多少
int fac1(int n) {
	if (n == 0) return 1;
	return n * fac1(n - 1);
}

int fac2(int n) {
	return (1 + n) * n / 2;
}

int g(int (*func)(int), int (*func2)(int), int x) {
	if (x < 5) return func(x);
	else return func2(x);
}

int main() {
	int n;
	// ~: 按位取反
	// scanf 读入的第一个不符合条件的情况返回的是 -1 (111...)
	// ~ => 000...
	/* while (~scanf("%d", &n)) {
		printf("fac(%d) = %d\n", n, fac1(n));
	} */

	while(~scanf("%d", &n)) {
		printf("f(%d) = %d\n", n, g(fac1, fac2, n));
	}

	return 0;
}

/* 
每次调用自身的时候，开辟的空间是多少？
fac(int n): int n 变量的值 (4 byte)
函数指针的空间
 */