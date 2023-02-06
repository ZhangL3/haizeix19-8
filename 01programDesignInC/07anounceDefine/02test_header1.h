// 为了避免一次编译过程中的重复包含，增加一个条件判断
#ifndef _HEADER1_H
#define _HEADER1_H

#include <stdio.h>

void funcA(int);
void funcB(int);

void funcA(int x) {
	if (!x) return ;
	printf("funcA : %d\n", x);
	funcB(x - 1);
	return ;
}

void funcB(int x) {
	if (!x) return ;
	printf("funcB : %d\n", x);
	funcA(x - 1);
	return ;
}

#endif