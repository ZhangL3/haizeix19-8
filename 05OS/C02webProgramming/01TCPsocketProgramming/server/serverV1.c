#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s port\n", argv[0]);
		exit(1);
	}
	int port, server_listen;
	// convert initial portion of the string to int
	port = atoi(argv[1]);

	// AF_INET: IPv4
	// SOCK_STREAM: 以流的形式传输
	if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		// perror: 解析 errno
		perror("socket");
		exit(1);
	}

	printf("Socket created.\n");
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	// htons: 主机字节序转为网络字节序, s: short
	server.sin_port = htons(port);
	server.sin_addr.s_addr = INADDR_ANY;

	// 强转 sockaddr_in 为 sockaddr, 因为 bind 函数要求的
	// struct sockadd_in 和 sockaddr 的长度是一样的，所以才能强转
	if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
		perror("bind");
		exit(1);
	}

	printf("Socket bund.\n");
	if (listen(server_listen, 20) < 0) {
		perror("listen");
		exit(1);
	}

	printf("Socket listening.\n");
	// 每次只说 1 次话，单线程，就不等待了，去干别的事
	while (1) {
		int sockfd;
		printf("Socket before accept.\n");
		if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
			perror("accept");
			close(sockfd);
			continue;
		}
		char name[20] = {0};
		printf("Socket after accept.\n");
    /**
     * 如果有客户端连接了，但是一直不发信息，程序就会被阻塞在这里，
     * 无法进入下一次循环，接收新的连接
    */
		if (recv(sockfd, name, sizeof(name), 0) <= 0) {
			close(sockfd);
			continue;
		}
		printf("Socket received.\n");
		printf("name: %s\n", name);
		close(sockfd);
	}
}