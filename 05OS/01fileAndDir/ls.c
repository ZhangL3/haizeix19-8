#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

#define FILEMAX 1024
// 定义 name 长度和 direntp->d_name 一样
#define NAMEMAX 256

int flag_a = 0;
int flag_l = 0;

void do_stat(char *filename) {
  printf("Doing with %s status.\n", filename);
  return;
}

void do_ls(char *dirname) {
  // DIR: pointer to a directory stream
  // opendir return in this type
  DIR *dirp = NULL;
  // readdir return in this type, man readdir
  // struct dirent {
  //   ino_t          d_ino;       /* Inode number */
  //   off_t          d_off;       /* Not an offset; see below */
  //   unsigned short d_reclen;    /* Length of this record */
  //   unsigned char  d_type;      /* Type of file; not supported
  //                                 by all filesystem types */
  //   char           d_name[256]; /* Null-terminated filename */
  // };
  struct dirent *direntp;
  // 储存文件夹下文件的名字
  char names[FILEMAX][NAMEMAX] = {0};

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
    int cnt = 0;
    // readdir 读到目录末尾时返回 NULL
    while((direntp = readdir(dirp)) != NULL) {
      // 处理是否显示隐藏文件
      if (direntp->d_name[0] == '.' && (flag_a == 0)) continue;
      strcpy(names[cnt++], direntp->d_name);
    }
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