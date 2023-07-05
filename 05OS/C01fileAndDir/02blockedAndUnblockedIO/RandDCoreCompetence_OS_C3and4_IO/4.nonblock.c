#include "head.h"

int main() {
  int age = 0;
  // 0 号文件：标准输入
  int flag = fcntl(0, F_GETFL);
  flag |= O_NONBLOCK;
  fcntl(0, F_SETFL, flag);
  sleep(2);

  int ret = scanf("%d", &age);
  printf("le is %d years old. ret = %d\n", age, ret);
  return 0;
}

// 正确链接 common/，找到 head.h 文件
// g++ 4.common_nonblock -I common/