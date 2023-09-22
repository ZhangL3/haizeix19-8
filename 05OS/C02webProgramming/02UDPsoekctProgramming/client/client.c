#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int sockfd, port;
  struct sockaddr_in server;
  int sendToRes;
  if (argc != 3) {
    fprintf(stderr, "Usage: %s ip port\n", argv[0]);
    exit(1);
  }
  port = atoi(argv[2]);
  printf("ip: %s\n", argv[1]);

  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(argv[1]);

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }
  printf("Socket created.\n");

  char msg[] = "L3";
  sendToRes = sendto(
    sockfd,
    msg,
    sizeof(msg),
    0,
    (struct sockaddr *)&server,
    sizeof(server)
  );
  if (sendToRes < 0) {
    perror("send");
    exit(1);
  }
  printf("sendToRes: %d\n", sendToRes);

  printf("message sent.\n");
  close(sockfd);

  return 0;
}