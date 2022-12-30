#include <stdio.h>

#define print(func) {\
	printf("%s = %d\n", #func, func);\
}

struct Data {
	int x, y;
};

int main() {

	// p 指针指向 array a 的首地址
	struct Data a[2], *p = a;
	a[0].x = 0, a[0].y = 1;
	a[1].x = 2, a[1].y = 3;

	// 尽可能多的形式表示 a[1].x --> 2
	print(a[1].x);
	print((&(a[1]))->x);
	// 对 array 的地址加 1，就是向后挪几位，不用考虑具体是几个 bytes，数组自己可以处理
	// printf("%lu\n", sizeof(Data));
	print((a + 1)->x);
	print((&a[0] + 1) -> x);
	print((*(&a[1])).x);
	print((*(a + 1)).x);
	print((*(&a[0] + 1)).x);

	print(p[1].x);
	print((&p[1])->x);
	print((p + 1)->x);
	print((&p[0] + 1) -> x);
	print((*(&p[1])).x);
	print((*(p + 1)).x);
	print((*(&p[0] + 1)).x);
	return 0;
}