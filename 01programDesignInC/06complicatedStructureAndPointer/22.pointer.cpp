#include <stdio.h>
#define offset2(T, a) (long)(&((T *)(NULL))->a)
#define offset(T, a) ({\
	T tmp;\
	(char *)&tmp.a - (char *)&tmp;\
})

struct Data {
	double a;
	int b;
	char c;
};

int main() {
	/*
	(61)16 = (97)10 => a
	*/
	int num1 = 0x616263;
	int num2 = 0x61626364;
	// 强行转成字符串的首地址
	printf("%s\n", (char *)(&num1)); // cba
	printf("%s\n", (char *)(&num2)); // dcba 老师的是 dcbacba
	// printf("%s\n", (char *)(&num2 + 1));
	// 为什么编译不过？
	printf("%ld\n", offset(struct Data, a));
	// printf("%ld\n", offset(struct Data, b));
	// printf("%ld\n", offset(struct Data, c));
	printf("%ld\n", offset2(struct Data, a));
	printf("%ld\n", offset2(struct Data, b));
	printf("%ld\n", offset2(struct Data, c));
	return 0;
}