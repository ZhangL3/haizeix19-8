#include "head.h"

int main() {
  int age1 = 0;
  int age2 = 0;
  make_nonblock(0);
  // sleep(2);
  // 如果不等 2 秒，或者 2 秒内没有输入
  // 标准输入里没有任何内容可以读取
  // 又因为标准输入被标记位 nonblock, 所以 scanf 会返回 EAGAGIN 错误
  int ret = scanf("%d", &age1);
  if (ret < 0) {
    if (errno == EAGAIN) {
      printf("EAGAIN\n");

    }
    perror("scanf");
  }
  make_block(0);
  scanf("%d", &age2);
  printf("le is %d, %d years old.\n", age1, age2);
  return 0;
}

// 正确链接 common.c，让 common.h 能找到 common.c
// g++ 4.common_nonblock -I common/ common/common.c
