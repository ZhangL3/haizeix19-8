#include <stdio.h>

int main() {
	// 打印数字的位数
	int n;
	scanf("%d", &n);
	int digits = 0;
	// n 为 0 时，digits 为 0
	/* while (n) {
		// n 在十进制的表示下去掉一位
		n /= 10;
		// n 在二进制的表示下去掉一位
		// n /= 2;
		digits += 1;
	} */

	do {
		// n 在十进制的表示下去掉一位
		n /= 10;
		// n 在二进制的表示下去掉一位
		// n /= 2;
		digits += 1;
	} while (n);

	printf("%d\n", digits);

	return 0;
}