// stdio.h 是一个文件名
// include 将后面文件的内容拷贝到这里
// 头文件里一般放声明，源文件里放定义
#include <stdio.h>
#include <stdlib.h>
#include "02test_header1.h"
#include "02test_header2.h"

int main() {
	funcA(5);
	funcC(6, 7);
	return 0;
}