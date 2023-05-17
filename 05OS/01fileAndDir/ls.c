#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ioctl.h>

#define FILEMAX 1024
// 定义 name 长度和 direntp->d_name 一样
#define NAMEMAX 256

int flag_a = 0;
int flag_l = 0;

void size_window(char filename[][NAMEMAX], int cnt, int *row, int *col) {
  /* 
  struct winsize {
               unsigned short ws_row;
               unsigned short ws_col;
           };
  */
  struct winsize size;
  // len: 各个文件名的长度
  // 动态数组不会被初始化，所以用 memset 初始化
  // int len[cnt] = {0};
  // max: 最长名字的长度, 判断是不是一个名字就超出的宽度
  // total: 所有名字加起来的长度
  int len[cnt], max = 0, total = 0;
  // memeset(内存首地址, 初始化的值, 整个的长度)
  memset(len, 0, sizeof(int) * cnt);

  // 判断是不是终端
  // STDOUT_FILENO: open 函数打开终端返回的文件标识符
  if (isatty(STDOUT_FILENO) == 0) {
    exit(1);
  }

  // The  ioctl()  system  call manipulates the underlying device parameters of special files.
  // fd: STDOUT_FILENO: open 函数打开终端返回的文件标识符
  // cmd: TIOCGWINSZ: 获取窗口大小
  /*
    TIOCGWINSZ
              Argument: struct winsize *argp

              Get window size.
  */
  // &size: cmd 的参数,传出参数
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
    perror("ioctl");
    exit(1);
  }
  printf("window size row = %d, col = %d\n", size.ws_row, size.ws_col);

  // 所有文件都显示，且长度不超出宽度的时候，显示在一行
  // 超出宽度，显示成列
  for (int i = 0; i < cnt; i++) {
    len[i] = strlen(filename[i]);
    if (max < len[i]) max = len[i];
    // +1: 名字后要有一个空格
    total += len[i] + 1;
  }
  // 如果最长的名字超过了宽度，就打印一列
  if (max + 1 >= size.ws_col) {
    *row = cnt;
    *col = 1;
    return ;
  }
  // 如果总长度没超过宽度，就打印一行
  if (total <= size.ws_col) {
    *row = 1;
    *col = cnt;
    return;
  }
  // 打印多行多列, 到底几行几列, 怎么算？
  // 先看一行最多能放几个（从头向后），放不下了再把列数向下减
  // 本次尝试时，共有几列
  int try_begin = 0;
  for (int i = 0, tmp = 0; i < cnt; i++) {
    // tmp: 当前行的宽度
    tmp += (len[i] + 1);
    if (tmp >= size.ws_col) {
      try_begin = i; 
      break;
    }
  }

  // 宽度不够的话，向下减
  for (int i = try_begin; ;i--) {
    // 找到每列最宽的那个，能知道下一列在什么位置输出
    // wide[i] 里的 i 是动态的，无法初始化，所以手动申请内存
    int *wide = (int *)malloc(sizeof(int) * i);
    memset(wide, 0, sizeof(int) * i);
    // ceil: 上取整，最后一列不一定要摆满，ceil 返回 double，强转
    *row = (int)ceil(cnt / i);
    // 遍历过的所有列的宽度的总和
    int try_sum = 0;   
    // 求每一列的初始位置，第一个 name 是哪一个
    for (int x = 0; x < i; x++) {
      for (int y = x * *row; y < (x + 1) * *row && y < cnt; y++) {
        // 如果当前遍历的 name 的长度大于当前列宽度，更新当前列的宽度 wide[x]
        if (wide[x] < len[y]) wide[x] = len[y];
      }
      try_sum += (wide[x] + 1);
    }

    // 如果宽度总和超过了终端的宽度，减少一列试试
    if (try_sum > size.ws_col) continue;
    // 第一个小于屏幕宽度的列宽度总和出现时，就定好了总共有多少列
    if (try_sum <= size.ws_col) {
      *col = i;
      break;
    }
  }
}

void do_stat(char *filename) {
  printf("Doing with %s status.\n", filename);
  return;
}

// A void pointer is a pointer that has no associated data type with it.
// A void pointer can hold address of any type and can be typecasted to any type. 
// void* 相当于 any
int cmp_name(const void* _a, const void* _b) {
  // 强转
  char *a = (char *)_a;
  char *b = (char *)_b;
  return strcmp(a, b);
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
  // 目录下的文件个数
  int cnt = 0;

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
    // readdir 读到目录末尾时返回 NULL
    while((direntp = readdir(dirp)) != NULL) {
      // 处理是否显示隐藏文件
      if (direntp->d_name[0] == '.' && (flag_a == 0)) continue;
      strcpy(names[cnt++], direntp->d_name);
    }
    // sort
    qsort(names, cnt, NAMEMAX, cmp_name);
    if (flag_l == 1) {
      for (int i = 0; i < cnt; i++) {
        do_stat(names[i]);
      }
    } else {
      printf("Print all files\n");
    }
  }
  printf("Doing with dir %s.\n", dirname);
  // 输出 names 数组里所有内容
  // 规划窗口: 要输出几行几列
  int row, col;
  // 输出参数，传地址
  size_window(names, cnt, &row, &col);
  printf("row = %d, col = %d\n", row, col);
}

int main(int argc, char **argv) {
  char currentDirChar = '.';
  char currentDirStr[2];
  currentDirStr[0] = currentDirChar;
  currentDirStr[1] = '\0';

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
    do_ls(currentDirStr);
  } else {
    while(--argc) {
      do_ls(*(++argv));
    }
  }

  return 0;
}