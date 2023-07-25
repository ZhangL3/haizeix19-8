#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int
main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval;

	/* Watch stdin (fd 0) to see when it has input. */

	// clear rfds
	FD_ZERO(&rfds);
	// add df: 0 to rfds
	FD_SET(0, &rfds);

	/* Wait up to five seconds. */

	tv.tv_sec = 2;
	tv.tv_usec = 0;

	retval = select(1, &rfds, NULL, NULL, &tv);
	/* Don't rely on the value of tv now! */
	printf("FD_ISSET(0, &rfds) before getting anything: %d\n", FD_ISSET(0, &rfds));

	if (retval == -1)
		perror("select()");
	else if (retval) {
		printf("Data is available now.\n");
		/* FD_ISSET(0, &rfds) will be true. */
		printf("FD_ISSET(0, &rfds) after getting data: %d\n", FD_ISSET(0, &rfds));
	}
	else {
		printf("FD_ISSET(0, &rfds) after expiring: %d\n", FD_ISSET(0, &rfds));
		printf("No data within five seconds.\n");
	}

	exit(EXIT_SUCCESS);
}