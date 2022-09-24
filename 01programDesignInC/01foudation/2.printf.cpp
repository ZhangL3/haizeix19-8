#include <stdio.h>

int main() {
	char str[100], str2[100];
	int ret;
	// str 是数组名和首地址，所以不用特意标明 &str
	// case 1:
	// input: hello heizei'\n'
	/* output: 以空格作为分隔符，读入了两次变量
	hello 
	heizei
	 */
	/* while(scanf("%s", str) != EOF) {
		printf("%s\n", str);
	} */

	// case 2:
	// input: hello heizei'\n'
	/* output: 带空格，但死循环
	hello heizei ret = 1
	hello heizei ret = 0
	hello heizei ret = 0
	hello heizei ret = 0
	...
	 */
	// []: 字符匹配集，只读入输出匹配集里面能匹配到的字符
	// ^: 取反，非
	// [^\n]: 除了 \n 都匹配
	/* 
	读入第一行后，\n 没有被存到 str 里面，
	下次读入的时候还是这个 \n，但是又被排除了，
	所以返回值一直是 0，且不等于 EOF(-1)
	 */
	/* while((ret = scanf("%[^\n]s", str)) != EOF) {
		printf("%s ret = %d\n", str, ret);
	} */

	// case 3:
	// input: hello heizei'\n'
	/* output: 正确输出
	input: hello heizei'\n'
	...
	 */
	// getchar(): 从标准输入 stdin 中获取一个字符
	// 这样就把 \n 释放了出来
	/* while((ret = scanf("%[^\n]s", str)) != EOF) {
		getchar();
		printf("%s ret = %d\n", str, ret);
	} */

	/* scanf("%[^\n]s", str);
	getchar();
	// str2: 要存入的字符集的首地址
	// str: 可以是字符集首地址或变量
	sprintf(str2, "(%s)", str);
	printf("str2 = %s\n", str2); */

	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	sprintf(str2, "%d.%d.%d.%d", a, b, c, d);
	// file print
	// *fd 文件地址指针
	// wb 二进制写入
	// FILE *fd = fopen("out", "wb");
	// 把 str2 里的内容写入到文件 out 中
	// fprintf(fd, "%s", str2);
	// stdin: 终端的输入内容
	// stdout: 输出到终端上
	// stderr: 标准错误
	fprintf(stdout, "stdout = %s\n", str2);
	fprintf(stderr, "stderr = %s\n", str2);
	printf("str2 = %s\n", str2);
	// >: 标准输出重定向，只重定向输出，其他的输出到终端
	// 2>: 标准错误重定向, ...
	// ./a.out > stdout
	// ./a.out 2> stderr

	return 0;
}