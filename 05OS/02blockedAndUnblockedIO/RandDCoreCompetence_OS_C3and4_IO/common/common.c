# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int make_nonblock(int fd) {
  int flag;
  if ((flag = fcntl(fd, F_GETFL)) < 0) {
    return -1;
  }
  flag |= O_NONBLOCK;
  if (fcntl(fd, F_SETFL, flag) < 0) {
    return -1;
  }
  return 0;
}

int make_block(int fd) {
  int flag;
  if ((flag = fcntl(fd, F_GETFL)) < 0) {
    return -1;
  }
  // 要把 NONBLOCK 位设为 0
  // ~: 安位取反
  flag &= ~O_NONBLOCK;
  if (fcntl(fd, F_SETFL, flag) < 0) {
    return -1;
  }
  return 0;
}
