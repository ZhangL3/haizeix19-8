# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# "common.h"

int main() {
  int age1 = 0;
  int age2 = 0;
  make_nonblock(0);
  scanf("%d", &age1);
  make_block(0);
  scanf("%d", &age2);
  printf("le is %d, %d years old.\n", age1, age2);
  return 0;
}
