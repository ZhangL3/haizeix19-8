// include 里只是声明了函数，可以编译通过当前文件。做链接的时候再去找函数定义
// 直接搜索编译环境的库里
#include <stdio.h>
// "xxx.h" 先搜索当前文件层级，之后向上，直到当前编译环境的 include 库
#include "2.funcB.h"

int funcA(int n) {
	printf("funcA : %d\n", n);
	if (n == 0) return 1;
	funcB(n - 1);
	return n;
}