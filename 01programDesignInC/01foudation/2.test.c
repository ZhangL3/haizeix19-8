#include <stdio.h>

int main() {
	// str: 100 位长的字符串
	char str[100];
	// [^\n] 读入字符集，直到 \n 停止
	//  ^ (XOR -Operator ) which gives true until both characters are different
	scanf("%[^\n]s", str);
	printf(" has %d chars\n", printf("%s", str));
	
	return 0;
}