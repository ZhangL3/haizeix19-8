# include <stdio.h>

int main() {
	char str[100];
	// input: haizei123nihao
	// output: haizei
	// 在遇到不匹配的时候自动加了个 '\0' 结束
	scanf("%[a-z]s", str);
	printf("%ss\n", str);
	return 0;
}