#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

void test_sscanf() {
	char str1[] = "123 456 789 987";
	char str2[100];
	int a, b, c, d;
	// sscanf(str1, "%d%d%d%d", &a, &b, &c, &d);

	// sscanf(str1, "%d", &a);
	// sscanf(str1 + 4, "%d", &b);
	// sscanf(str1 + 8, "%d", &c);
	// sscanf(str1 + 12, "%d", &d);

	// []: 字符匹配及
	// ^：异或。之前学过 [^\n]: 除了换行其他都读入
	// $: 字符串的末尾 \0
	// 读入一次之后，他之后的字符串再赋值给 str1
	sscanf(str1, "%d%[^$]s", &a, str1);
	sscanf(str1, "%d%[^$]s", &b, str1);
	sscanf(str1, "%d%[^$]s", &c, str1);
	sscanf(str1, "%d%[^$]s", &d, str1);
	// sprintf(str2, "a = %d, b = %d, c = %d d = %d", a, b, c, d);
	int offset = 0; offset += sprintf(str2 + offset, "a = %d", a);
	offset += sprintf(str2 + offset, " b = %d", b);
	offset += sprintf(str2 + offset, " c = %d", c);
	offset += sprintf(str2 + offset, " d = %d", d);
	offset += printf("%s\n", str2);
	// printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
}

// int 最多能返回 2 GB 的 string 长度
// char 是可变的，不能用 strlen1("hello world")
int strlen1(char *str) {
	int i = 0;
	while (str[i]) i++;
	return i;
}

uint64_t strlen2(const char *str) {
	uint64_t i = 0;
	while (str[i]) i++;
	return i;
}

int strcmp1(const char *str1, const char *str2) {
	uint64_t i = 0;
	for (; str1[i] && str2[i]; i++) {
		if (str1[i] - str2[i]) return str1[i] - str2[i];
	}
	return str1[i] - str2[i];
}

int main() {
	int n;
	char str[100];
	char str1[100] = "hello haizei";
	/* while(~scanf("%d", &n)) {
		// 把 n 的值以 16 进制字符的形式存入 str
		sprintf(str, "%x", n);
		printf("%s has %lu digit\n", str, strlen(str));
	} */

	// test_sscanf();

	printf("%d\n", strlen1(str1));
	// 传的是字符串的字面量，定义的是指针
	// 传的是常量的地址，定义的是变量的地址
	// printf("%d\n", strlen1("hello haizei"));
	printf("%" PRIu64"\n", strlen2("hello haizei"));
	printf("%d\n", strcmp1("hello world", "hello haizei"));

	return 0;
}