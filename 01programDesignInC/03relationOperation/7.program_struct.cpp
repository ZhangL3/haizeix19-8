#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	// 随机化
	srand(time(0));
	// srand(666);

	// 100 以内随机
	// printf("%d\n", rand() % 100);
	// printf("%d\n", rand() % 100);
	// printf("%d\n", rand() % 100);

	int a, b;
	scanf("%d%d", &a, &b);
	// if (a != b) {
	if (a - b) {
		printf("not equal\n");
	} else {
		printf("equal\n");
	}

	// 短路运算
	// a 为假，b++ 得执行
	if ((a++) && (b++)) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	// a 为真，b++ 没有执行
	if ((a++) || (b++)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	printf("a = %d, b = %d\n", a, b);

	/*
	input:
		0 0
	output:
		equal
		false
		true
		a = 2, b = 0
	 */

	// 循环输出 0 - 9，但最后不能右空格
	for (int i = 0; i < 10; i++) {
		// if (i) printf(" ");
		// 比 if 更高效
		i && printf(" ");
		printf("%d ", i);
	}
	printf("\n");

	// 随机生成 10 个数字，判断奇偶性
	int cnt_odd = 0;
	int cnt_even = 0;
	for (int i = 0; i < 10; i++) {
		int val = rand() % 100;
		// if (val % 2 == 1) cnt += 1;
		// cnt += val % 2;
		// 求奇数个数，判断最后一位是不是 1
		cnt_odd += val & 1;
		// 求偶数个数
		cnt_even += !(val & 1);

		// i && printf(" ");
		// 等价于
		i == 0 || printf(" ");
		printf("%d", val);
	}
	printf("\n");
	printf ("odd numbers : %d\n", cnt_odd);
	printf ("even numbers : %d\n", cnt_even);

	return 0;
}