// stdio.h 是一个文件名
// include 将后面文件的内容拷贝到这里
// 头文件里一般放声明，源文件里放定义
#include <stdio.h>
#include <stdlib.h>

// 调用时，只关心传入参数和传出参数
// 参数名字都不重要
void funcA(int);
// 如果不写 funcA
// 编译阶段报错: use of undeclared identifier 'funcA'
// 编译只要没有语法的问题，就可以通过
// 预处理
// -> 编译阶段（生成多个对象文件，不必须看到函数定义，因为可能在其他文件中）
// -> 链接时找不到，报错未定义
void funcB(int);

// 声明和定义在一起
int add(int a, int b) {
	return a + b;
}

int main() {
	funcA(5);
	return 0;
}

// 声明定义写在一起的话，肯能出现循环调用
void funcB(int x) {
	if (x == 0) return ;
	printf("funcB : %d\n", x);
	funcA(x - 1);
	return ;
}

void funcA(int x) {
	if (x == 0) return ;
	printf("funcA : %d\n", x);
	funcB(x - 1);
	return ;
}

// 如果定义 funcB 或 funcA
// 链接阶段报错：Undefined symbols for architecture x86_64: "funcA(int)" ...
// 在任何源文件中，没有函数的实现