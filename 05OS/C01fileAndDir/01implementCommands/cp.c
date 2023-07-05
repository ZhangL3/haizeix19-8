#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 512

int main(int argc, char **argv) {
	int fd_in, fd_out;
	ssize_t nread;
	// read 到 buf 里的结果结尾没有 \0，防止刚到到 buf 最后一位结束，整个 string 就没有结束符号了
	char buf[BUFSIZE + 5] = {0};

	if (argc != 3) {
		printf("Usage: %s sourcefile destfile\n", argv[0]);
		exit(1);
	}

	if ((fd_in = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(1);
	}

	if ((fd_out = creat(argv[2], 0644)) == -1) {
		perror(argv[2]);
		exit(1);
	}

	// read: On success, the number of bytes read is returned (zero indicates end of file),
	// and the file position is advanced by this number.
	// write: On success, the number of bytes written is returned.
	while ((nread = read(fd_in, buf, sizeof(buf))) > 0) {
		printf("nread = %ld\n", nread);
		int nwrite;
		if (nwrite = write(fd_out, buf, strlen(buf)) != nread) {
			perror("write");
			exit(1);
		}
		// 如果因为错误，上次读的不够 BUFSIZE，剩余的字节会放在新的开头，所以要清空
		memset(buf, 0, BUFSIZE + 5);
	}
	
	// 普通用会最多能开 1024 个文件
	close(fd_in);
	close(fd_out);
	return 0;
}