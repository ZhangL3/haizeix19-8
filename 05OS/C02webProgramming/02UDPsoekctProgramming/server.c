#include <stdio.h>
#include <string.h>
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
	int port, server_listen, sockfd;
	struct sockaddr_in client;
	socklen_t addr_len = sizeof(client);
	// convert initial portion of the string to int
	port = atoi(argv[1]);

	// AF_INET: IPv4
	// SOCK_DGRAM: 以报的形式传输 (UDP)
	if ((server_listen = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
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
	if (sockfd = bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
		perror("bind");
		exit(1);
	}

	printf("Socket bund.\n");

	// 置 client 空间为 0，接收所有 ip 的数据
	memset(&client, 0, sizeof(struct sockaddr_in));
	// 每次只说 1 次话，单线程，就不等待了，去干别的事
	while (1) {
		char buff[512] = {0};
		// 从 sockfd 收到 buff,
		// flag 为 0
		if ((recvfrom(
				sockfd,
				buff,
				sizeof(buff),
				0,
				((struct sockaddr *)&client),
				&addr_len)
		) > 0) {
			printf("[%s]: %s\n", inet_ntoa(client.sin_addr), buff);
		}
	}
}