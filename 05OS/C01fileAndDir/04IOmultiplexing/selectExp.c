#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval;

	/* Watch stdin (fd 0) to see when it has input. */

	// clear rfds
	FD_ZERO(&rfds);
	// add df: 0 to rfds
	// 0: stdin
	FD_SET(0, &rfds);

	/* Wait up to five seconds. */

	tv.tv_sec = 2;
	tv.tv_usec = 0;

	// 1: 最大文件描述符 + 1
	retval = select(1, &rfds, NULL, NULL, &tv);
	/* Don't rely on the value of tv now! */
	printf("tv finished\n");

	if (retval == -1)
		perror("select()");
	else if (retval) {
		char buff[512] = {0};
		printf("Data is available now.\n");
		/* FD_ISSET(0, &rfds) will be true. */
		printf("FD_ISSET(0, &rfds) after getting data: %d\n", FD_ISSET(0, &rfds));
		// 标准输出被读入 buff 后，就不会被之后的 bash 接收了
		// scanf("%s", buff);
	}
	else {
		printf("FD_ISSET(0, &rfds) after expiring: %d\n", FD_ISSET(0, &rfds));
		printf("No data within five seconds.\n");
	}

	exit(EXIT_SUCCESS);
}