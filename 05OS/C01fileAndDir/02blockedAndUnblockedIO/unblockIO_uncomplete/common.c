#include "head.h"

void make_nonblock_ioctl(int fd) {
  // 1 为非阻塞
  unsigned long ul = 1;
  ioctl(fd, FIONBIO, &ul);
}

void make_block_ioctl(int fd) {
  // 0 为阻塞
  unsigned long ul = 0;
  ioctl(fd, FIONBIO, &ul);
}

void make_nonblock(int fd) {
  fcntl(fd, F_SETFL, O_NONBLOCK);
}

void make_block(int fd) {
  fcntl(fd, F_SETFL, O_BLOCK);
}