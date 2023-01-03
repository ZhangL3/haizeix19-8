#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define offset(T, a) ({\
	T tmp;\
	(char *)&tmp.a - (char *)&tmp;\
})
#define offset2(T, a) (long)(&((T *)(NULL))->a)
#define pchar char *

typedef char * ppchar;

struct Data {
	double a;
	int b;
	char c;
};

void output_main(int argc, char *argv[], char *env[]) {
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	for (int i = 0; env[i]; i++) {
		printf("env[%d] = %s\n", i, env[i]);
		if (strncmp(env[i], "USER=", 5) == 0) {
			printf("check USER!\n");
			if (strncmp(env[i] + 5, "zhangs", 6)) {
				printf("you are not user!\n");
				exit(0);
			}
		}
	}
	return ;
}

int main(int argc, char *argv[], char *env[]) {
	/*
	(61)16 = (97)10 => a
	*/
	int num1 = 0x616263;
	int num2 = 0x61626364;
	// char *p;
	pchar p1, p2;
	ppchar p3, p4;
	// 8, 1, 指针是 8 bytes，为什么这里是 1 个 byte
	// 展开后 char * p1, p2，p1 是个 char 指针，但 p2 只是 char
	printf("sizeof(p1) = %lu, sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
	// 8, 8
	printf("sizeof(p3) = %lu, sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
	// 强行转成字符串的首地址
	printf("%s\n", (char *)(&num1)); // cba
	printf("%s\n", (char *)(&num2)); // dcba 老师的是 dcbacba
	// 为什么编译不过？
	// g++ 会对代码进行优化，如果只有 %s，printf 会被优化为 puts，但 puts 无法找到 &num + 1 的内存
	// 所以会报错
    // printf("%s\n", (char *)(&num2 + 1));
	printf("%s", (char *)(&num2 + 1));
	// 为什么编译不过？
	// printf("%ld\n", offset(struct Data, a));
	// printf("%ld\n", offset(struct Data, b));
	// printf("%ld\n", offset(struct Data, c));
	printf("%ld\n", offset2(struct Data, a));
	printf("%ld\n", offset2(struct Data, b));
	printf("%ld\n", offset2(struct Data, c));

	/*
	$ ./a.out -al
	argv[0] = ./a.out
	argv[1] = -al
	env[0] = SHELL=/bin/bash
	env[1] = NVM_INC=/home/zhangl/.nvm/versions/node/v19.1.0/include/node
	env[2] = WSL_DISTRO_NAME=Ubuntu-22.04
	...
	$ ./a.out "hello world"
	argv[0] = ./a.out
	argv[1] = hello world
	env[0] = SHELL=/bin/bash
	env[1] = NVM_INC=/home/zhangl/.nvm/versions/node/v19.1.0/include/node
	env[2] = WSL_DISTRO_NAME=Ubuntu-22.04
	...
	*/
	output_main(argc, argv, env);
	printf("hello haizei!!!");
	return 0;
}