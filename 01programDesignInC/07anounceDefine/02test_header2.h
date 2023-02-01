#ifndef _HEADER2_H
#define _HEADER2_H

#include <stdio.h>
// 如果内部引用 header1.h，源文件也有的话，编译阶段报错 redefinition
// 因为 header1.h 里的函数被引用了两次，重复了
#include "02test_header1.h"

void funcC(int a, int b) {
	printf("%d + %d = %d\n", a, b, a + b);
	// 如果没有本地引用 header1.h，也是可以通过编译的
	// 因为在源文件中引用里 header1.h
	// 但有引用顺序的问题，header1.h 必须在前面
	funcA(a);
	return;
}

#endif