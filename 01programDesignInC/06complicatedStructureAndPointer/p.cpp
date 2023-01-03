#include <stdio.h>

int main() {
	int num2 = 0x61626364;
	printf("test: \n");
	// g++ 会对代码进行优化，如果只有 %s，printf 会被优化为 puts，但 puts 无法找到 &num + 1 的内存
	// 所以会报错
    // printf("%s\n", (char *)(&num2 + 1));
    printf("%s", (char *)(&num2 + 1));
}