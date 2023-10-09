#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int pid;
  // printf("before fork()...");
  
  // 1.fork_n.c
  // printf("before fork()...\n");

  // 1.fork_fflush.c
  printf("before fork()...");
  fflush(stdout);

  // 从 fork 开始，文件是两份, 报扩执行到哪了
  if ((pid = fork()) < 0) {
    perror("fork");
  }
  // 父子进程谁先执行是由内核的调度器决定的，自己无法直接控制
  if (pid == 0) {
    printf("\nin Child!\n");
  } else {
    sleep(1);
    printf("\n Parent!\n");
  }
  // 不在子进程中，必然会被执行两次
  printf("End Fork!\n");

  return 0;
}