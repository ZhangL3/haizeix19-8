#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int pid, x;
  for (int i = 1; i <= 10; i++) {
    if ((pid = fork()) < 0) {
      perror("fork");
      continue;
    }
    // 如果子进程不从循环里退出，创建的进程数是 1 变 2, 2 变 4 ...
    // 因为子进程也 fork 自己
    if (pid == 0) {
      x = i;
      break;
    }
  }
  // 父进程中，x 并没有被赋值，打印出来是 0
  printf("I'm %dth child, pid: %d\n", x, getpid());
  // 总过是 1 个父进程，10 个子进程

  sleep(60);

  return 0;
}
