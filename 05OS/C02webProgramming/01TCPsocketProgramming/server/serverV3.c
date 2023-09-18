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

	// 延迟关闭
	struct linger m_linger;
	// 是否打开延迟
	m_linger.l_onoff = 1;
	// 延迟时间
	m_linger.l_linger = 0;
	if (
		setsockopt(
			server_listen,
			SOL_SOCKET,
			SO_LINGER,
			&m_linger,
			(socklen_t)sizeof(m_linger)
		) < 0
	) {
		perror("setsockopt");
		exit(1);
	}

	// 设置地址重用
	int flag = 1;
	if (
		setsockopt(
			server_listen,
			SOL_SOCKET,
			SO_REUSEADDR,
			&flag,
			sizeof(int)
		) < 0
	) {
		perror("setsockopt");
		exit(1);
	}

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
		// 在执行下一次 accept 之前，其他链接都处于 pending 状态

		pid_t pid;

		if ((pid = fork()) < 0) {
			perror("fork");
			continue;
		}

		/**
		 * fork 结束后，下面的代码在两个进程中都有
		 * 如果不想做同样的事情，就要判断逻辑了
		*/
		/**
		char name[20] = {0};
		printf("Socket after accept.\n");
		if (recv(sockfd, name, sizeof(name), 0) <= 0) {
			close(sockfd);
			continue;
		}
		printf("Socket received.\n");
		printf("name: %s\n", name);
		close(sockfd);
		*/

		// 子进程
		if (pid == 0) {
			close(server_listen);
			char name[20] = {0};
			if (recv(sockfd, name, sizeof(name), 0) <= 0) {
				perror("recv");
				close(sockfd);
				continue;
			}
			printf("Socket received in process %d.\n", pid);
			printf("name: %s\n", name);
			// 父进程不管退出的子进程，子进程就会变成 zombie 进程
			exit(0);
		}
		// 父进程什么也不做，只负责生出子进程
	}

	return 0;
}