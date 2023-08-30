#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int sockfd, port;
  struct sockaddr_in server;
  if (argc != 3) {
    fprintf(stderr, "Usage: %s ip port\n", argv[0]);
    exit(1);
  }
  port = atoi(argv[2]);

  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(argv[1]);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }
  printf("Socket created.\n");
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    exit(1);
  }
  printf("TCP connected.\n");
  /**
   * 如果客户端连接了，但是不发信息且睡眠，服务端就会被阻塞，无法接收别人的信息
  */
  if (send(sockfd, "L3", sizeof("L3"), 0) < 0) {
    perror("send");
    exit(1);
  }
  // sleep(60);

  printf("message sent.\n");
  close(sockfd);

  return 0;
}