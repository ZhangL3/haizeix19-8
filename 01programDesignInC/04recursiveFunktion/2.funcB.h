// 定义头文件是不能有 .
#ifndef _2FUNCB_H
#define _2FUNCB_H

int funcB(int);

// 多次声明错误愿意
/* int funcB(int n) {
	printf("funcB : %d\n", n);
	if (n == 0) return 1;
	return n * funcB(n - 1);
} */

#endif