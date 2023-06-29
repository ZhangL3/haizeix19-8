# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int main() {
  int age = 0;
  // 0 号文件：标准输入
  int flag = fcntl(0, F_GETFL);
  flag |= O_NONBLOCK;
  fcntl(0, F_SETFL, flag);
  sleep(2);

  scanf("%d", &age);
  printf("le is %d years old.\n", age);
  return 0;
}
