#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int flag_a = 0;
int flag_l = 0;

void do_ls(char *dirname) {
  printf("Doing with dir %s.\n", dirname);
}

int main(int argc, char **argv) {
  int opt;
  while((opt = getopt(argc, argv, "al")) != -1) {
    switch (opt) {
      case 'a':
        flag_a = 1;
        break;
      case 'l':
        flag_l = 1;
        break;
      default:
        fprintf(stderr, "Usage: %s -[al] [filename]\n", argv[0]);
        exit(1);
    }
  }

  printf("flag_a = %d, flag_l = %d\n", flag_a, flag_l);

  // argc 更新为 getopt 解析完后，剩下参数的个数
  // optind 指向下一个要解析的位置，是处理完选项后的下一个位置，所以得 -1
  printf("optind = %d\n", optind);
  argc -= (optind - 1);
  // 指针向后移动到最后一个选项的位置
  argv += (optind - 1);

  // argv + 1 是第一个参数的位置
  // argc 是 函数调用(1)和参数个数的和, 对应的参数是 *(argv + 1)
  printf("argc = %d, argv=%s\n", argc, *(argv + 1));

  // 1 表示只有函数调用，没有参数
  if (argc == 1){
    do_ls(".");
  } else {
    while(--argc) {
      do_ls(*(++argv));
    }
  }

  return 0;
}