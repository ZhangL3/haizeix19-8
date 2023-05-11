#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	int flags, opt;
	int nsecs, tfnd;

	nsecs = 0;
	tfnd = 0;
	flags = 0;

	// optstring: "nt:", n 选项没有选项参数, t 选项有选项参数
	while ((opt = getopt(argc, argv, "nt:")) != -1) {
		// optind shows the index of next element to be processed in argv array
		printf("opt = %d\n", opt);
		// optopt 储存第一个错误选项字符,并返回给stderr
		printf("optopt = %d\n", optopt);
		// 全局变量 opterr 可用来禁止显示由 getopt() 打印出的错误消息。默认情况下,这个变量被设为1。如果我们将它设为0,那么 getopt() 将不再打印错误消息,而是表现的如同 上一条所描述的那样。程序可以通过检查函数返回值是否为?字符来判断是否出错, 并打印出用户自定义的错误消息。
		printf("opterr = %d\n", opterr);
		printf("optind = %d in while\n", optind);
		printf("optarg = %s in while\n", optarg);
		switch (opt) {
		case 'n':
			flags = 1;
			printf("optind = %d by n\n", optind);
			printf("optarg = %s by n\n", optarg);
			break;
		case 't':
			// atoi: 字符串专成整形
			printf("optind = %d by t\n", optind);
			printf("optarg = %s by t\n", optarg);
			nsecs = atoi(optarg);
			tfnd = 1;
			break;
		default: /* '?' */
			// fprintf: 打印到一个文件 (stderr)
			printf("optind = %d by default\n", optind);
			printf("optarg = %s by default\n", optarg);
			fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
					// argv[0]: 程序自己
					argv[0]);
			// 宏定义，错误推出状态
			exit(EXIT_FAILURE);
		}
	}

	printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
			flags, tfnd, nsecs, optind);

	// 索引值大于参数数量，就是没跟参数
	printf("optind = %d after while loop\n", optind);
	if (optind >= argc) {
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}

	// 如果 getopt() 返回了-1,表示目前没有更多的选项可解析了,且 optind 的值比argc要小,那么 argv[optind]就表示命令行中下一个非选项单词
	printf("name argument = %s\n", argv[optind]);

	/* Other code omitted */

	exit(EXIT_SUCCESS);
}