#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int flag_a = 0;
int flag_l = 0;

void do_stat(char *filename) {
  printf("Doing with %s status.\n", filename);
  return;
}

void do_ls(char *dirname) {
  DIR *dirp = NULL;
  struct dirent *direntp;

  // NULL: 目录无法打开, 不是目录
  if ((dirp = opendir(dirname)) == NULL) {
    // 可能是个文件
    // access 对某个文件是否可达
    if (access(dirname, R_OK) == 0) {
      // 如果不是列表形式，直接打印
      if (flag_l == 0) {
        printf("%s\n", dirname);
        return;
      } else {
        do_stat(dirname);
        return;
      }
    } else {
      // 既不是目录也不是文件
      // This is the C string containing a custom message to be printed before the error message itself.
      perror(dirname);
      return;
    }
  } else {
    // 目录可打开
    printf("%s:\n", dirname);
  }
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