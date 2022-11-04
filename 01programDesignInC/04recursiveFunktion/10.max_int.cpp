#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int max_int(int n, ...) {
	va_list arg;
	// 找到 n 后第一个固定参数，把它和之后的变参放进来
	va_start(arg, n);
	int ans =  INT32_MIN;
	while (n--) {
		int temp = va_arg(arg, int);
		temp > ans && (ans = temp);
	}
	va_end(arg);
	return ans;
}

int main() {
	printf("%d\n", max_int(3, 3, 5, 16));
	// 第一个 3 表示只判断 3 个数字
	printf("%d\n", max_int(3, 3, 5, 16, 21));
	printf("%d\n", max_int(4, 3, 5, 21, -32));
	return 0;
}