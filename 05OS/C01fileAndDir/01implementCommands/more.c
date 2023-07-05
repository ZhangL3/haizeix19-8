#include <stdio.h>
#include <stdlib.h>

#define PAGELINE 15
#define LENLINE 512

void do_more(FILE *fp);

int main(int argc, char **argv) {
	// 文件指针，文件流
	FILE *fp;
	if (argc == 1) {
		// printf("Usage: %s [filename | stdin]\n", argv[0]);
		do_more(stdin);
	} else {
		while (--argc) {
			if ((fp = fopen(*++argv, "r")) != NULL ) {
				do_more(fp);
			}
		}
	}

	return 0;
}

void do_more(FILE *fp) {
	char line[LENLINE] = {0};
	// 从终端中打开流
	FILE *cmd = fopen("/dev/tty", "r");
	int num_line = 0, reply, get_cmd(FILE*);
	// 一行一行的读入流里的字符串到 line 中
	while (fgets(line, LENLINE, fp)) {
		// 如果到了一页末尾，等待用户输入
		if (num_line == PAGELINE) {
			reply = get_cmd(cmd);
			if (reply == 0) break;
			// 执行完输入命令减掉对应行数，可时间继续打印
			num_line -= reply;
		}
		// 打印 line 到 stdout
		// 如果到文件结尾了，退出
		if (fputs(line, stdout) == EOF) {
			perror("fputs");
			exit(1);
		}

		num_line++;
	}
}

// 如果没有明确输入设备，./a.lout < 1.log 时， 1.log 里的字符也会作为输入控制传给 get_cmd
int get_cmd(FILE *fp) {
	printf("more:");
	int c;
	// getchar: 读取输入
	while ((c = fgetc(fp)) != EOF) {
		// 退出
		if (c == 'q') return 0;
		// 输出下一页
		if (c == ' ') return PAGELINE;
		// 输出一行
		if (c == '\n') return 1;
	}
	return -1;
}