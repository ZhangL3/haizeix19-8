#include <stdio.h>

// 如果没有这行声明，funcB 里的 funcA 是 undefined
int funcA(int n);
int funcB(int n);

int main() {
	funcA(6);
	funcB(6);
	return 0;
}

// error: duplicate
int funcA(int n) {
	printf("funcA : %d\n", n);
	if (n == 0) return 0;
	funcB(n - 1);
	return n;
}

int funcB(int n) {
	printf("funcB : %d\n", n);
	if (n == 0) return 0;
	funcA(n - 1);
	return n;
}