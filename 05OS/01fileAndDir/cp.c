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
	char buf[BUFSIZE];

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

	while ((nread = read(fd_in, buf, sizeof(buf))) > 0) {
		if (write(fd_out, buf, strlen(buf)) != nread) {
			perror("write");
			exit(1);
		}
	}
	return 0;
}