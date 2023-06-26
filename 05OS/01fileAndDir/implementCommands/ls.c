#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define FILEMAX 1024
// 定义 name 长度和 direntp->d_name 一样
#define NAMEMAX 256

int flag_a = 0;
int flag_l = 0;
int fg_c, bg_c;

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

void update_color(mode_t mode) {
  // 0: 黑色
  bg_c = 0;
  // 37: 白色
  fg_c = 37;
  // 可执行文件
  if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
    // 32: 绿色
    fg_c = 32;
  }

  switch (mode & S_IFMT) {
    case S_IFDIR:
      // 34: 蓝色
      fg_c = 34;
      break;
    case S_IFLNK:
      // 36: 青色
      fg_c = 36;
      break;
  }

}


void show_files(char filename[][NAMEMAX], int cnt, int row, int col) {
  int wide_file[cnt];
  struct stat tmp_st;
  memset(wide_file, 0, sizeof(int) * cnt);
  // 求每一列的宽度
  for (int i = 0; i < col; i++) {
    for (int j = (i * row); j < (i + 1) * row && j < cnt; j ++) {
      if (wide_file[i] < strlen(filename[j])) wide_file[i] = strlen(filename[j]);
    }
  }

  for (int i = 0; i < row; i++) {
    // 这里有两个问题有待修改
    // 第一：输出不是完全的
    // 第二：改成完全的和屏幕不符
    for (int j = i; j < i + (row * col) && j < cnt; j = j + row) {
      int tmp = j / row;
      lstat(filename[j], &tmp_st);
      update_color(tmp_st.st_mode);
      // -: Left-justify within the given field width; Right justification is the default.
      // *: The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.
      // 输出颜色
      // printf(“\033[0;31m”); //Set the text to the color red
      // printf(“Hello\n”); //Display Hello in red
      // printf(“\033[0m”); //Resets the text to default color
      // Escape is: \033
      // Color code is: [0;31m
      printf("\033[%d;%dm%-*s\033[0m", bg_c, fg_c, wide_file[tmp] + 1, filename[j]);
    }
    printf("\n");
  }
}

void mode_to_str(mode_t mode, char *str) {
  // struct stat {
  //     mode_t    st_mode;        /* File type and mode */
  // };

  /**
   * The following mask values are defined for the file type:
     以 0 开头，八进制，每个数字为 3 bit，最大为 7(111)
      S_IFMT     0170000   bit mask for the file type bit field
                 001111000000000000

      S_IFSOCK   0140000   socket
                 001100000000000000
      S_IFLNK    0120000   symbolic link
                 001010...
      S_IFREG    0100000   regular file
                 001000...
      S_IFBLK    0060000   block device
                 000110...
      S_IFDIR    0040000   directory
                 000100...
      S_IFCHR    0020000   character device
                 000010
      S_IFIFO    0010000   FIFO
                 000001

      // stat: 链接的话显示链接到的文件
      stat(pathname, %sb);
      // lstat: 链接的话显示链接的文件本身
      lstat(pathname, &sb);
      if ((sb.st_mode & S_IFMT) == S_IFREG) {
        // Handle regular file
      }
  */

  if (S_ISREG(mode)) str[0] = '-';
  if (S_ISDIR(mode)) str[0] = 'd';
  if (S_ISCHR(mode)) str[0] = 'c';
  if (S_ISBLK(mode)) str[0] = 'b';
  if (S_ISSOCK(mode)) str[0] = 's';
  if (S_ISLNK(mode)) str[0] = 'l';
  if (S_ISFIFO(mode)) str[0] = 'p';

  /**
   *  The following mask values are defined for the file mode component
      of the st_mode field:

      S_ISUID     04000   set-user-ID bit (see execve(2))
                  100000000000
      S_ISGID     02000   set-group-ID bit (see below)
                  010000...
      S_ISVTX     01000   sticky bit (see below)
                  001000...

      S_IRWXU     00700   owner has read, write, and execute
                          permission
                  000111...
      S_IRUSR     00400   owner has read permission
      S_IWUSR     00200   owner has write permission
      S_IXUSR     00100   owner has execute permission

      S_IRWXG     00070   group has read, write, and execute
                          permission
      S_IRGRP     00040   group has read permission
      S_IWGRP     00020   group has write permission
      S_IXGRP     00010   group has execute permission

      S_IRWXO     00007   others (not in group) have read, write,
                          and execute permission
      S_IROTH     00004   others have read permission
      S_IWOTH     00002   others have write permission
      S_IXOTH     00001   others have execute permission

      if (sb.st_mode & S_IRWXU) {
        // Handle user hat read, write, execute permissions
      }
  */

  if (mode & S_IRUSR) str[1] = 'r';
  if (mode & S_IWUSR) str[2] = 'w';
  if (mode & S_IXUSR) str[3] = 'x';

  if (mode & S_IRGRP) str[4] = 'r';
  if (mode & S_IWGRP) str[5] = 'w';
  if (mode & S_IXGRP) str[6] = 'x';

  if (mode & S_IROTH) str[7] = 'r';
  if (mode & S_IWOTH) str[8] = 'w';
  if (mode & S_IXOTH) str[9] = 'x';

  if ((mode & S_IXUSR) && (mode & S_ISUID)) str[3] = 's';
  if (!(mode & S_IXUSR) && (mode & S_ISUID)) str[3] = 'S';
  if ((mode & S_IXGRP) && (mode & S_ISGID)) str[6] = 's';
  if (!(mode & S_IXGRP) && (mode & S_ISGID)) str[6] = 'S';
  if ((mode & S_IXOTH) && (mode & S_ISVTX)) str[9] = 's';
  if (!(mode & S_IXOTH) && (mode & S_ISVTX)) str[9] = 'S';

  update_color(mode);
}

char *uid_to_name(uid_t uid) {
  // struct passwd {
  //     char   *pw_name;       /* username */
  //     char   *pw_passwd;     /* user password */
  //     uid_t   pw_uid;        /* user ID */
  //     gid_t   pw_gid;        /* group ID */
  //     char   *pw_gecos;      /* user information */
  //     char   *pw_dir;        /* home directory */
  //     char   *pw_shell;      /* shell program */
  // };
  struct passwd *pw_ptr;
  // 如果不是全局的静态变量（static）返回的时候会被销毁
  static char tmpstr[10] = {0};
  if ((pw_ptr = getpwuid(uid)) == NULL) {
    sprintf(tmpstr, "%d", uid);
    return tmpstr;
  } else {
    return pw_ptr->pw_name;
  }
}

char *gid_to_name(gid_t gid) {
  // struct group {
  //     char   *gr_name;        /* group name */
  //     char   *gr_passwd;      /* group password */
  //     gid_t   gr_gid;         /* group ID */
  //     char  **gr_mem;         /* NULL-terminated array of pointers
  //                               to names of group members */
  // };
  struct group *gr_ptr;
  // 和 uid_to_name 里的 tmpstr 不会同时使用，所以重名没问题
  static char tmpstr[10] = {0};
  if ((gr_ptr = getgrgid(gid)) == NULL) {
    sprintf(tmpstr, "%d", gid);
    return tmpstr;
  } else {
    return gr_ptr->gr_name;
  }
}

void show_info(char *filename, struct stat *info) {
  char modestr[11] = "----------";
  mode_to_str(info->st_mode, modestr);
  printf("%s ", modestr);
  printf("%4d ", (int)info->st_nlink);
  printf("%10s ", uid_to_name(info->st_uid));
  printf("%10s ", gid_to_name(info->st_gid));
  printf("%10ld ", info->st_size);
  // man 2 stat 中 struct stat 里有关于时间的结构体和红定义
  // struct timespec st_atim;  /* Time of last access */
  // struct timespec st_mtim;  /* Time of last modification */
  // struct timespec st_ctim;  /* Time of last status change */

  // #define st_atime st_atim.tv_sec      /* Backward compatibility */
  // #define st_mtime st_mtim.tv_sec
  // #define st_ctime st_ctim.tv_sec

  // head 文件存在 /usr/include 文件下，可以通过 grep 找到 timespec 结构体的头文件
  // grep -n "struct timespec" /usr/include/* 2> /dev/null
  // 或者直接 man timespec

  // struct timespec {
  //     // The number of whole seconds elapsed since the epoch (for a simple calendar time) or since some other starting point (for an elapsed time).
  //     time_t  tv_sec;  /* Seconds 相对时间 */
  //     long    tv_nsec; /* Nanoseconds */
  // };

  // 相对时间要转成绝对时间 localtime，用到 struct tm
  // struct tm {
  //     int tm_sec;    /* Seconds (0-60) */
  //     int tm_min;    /* Minutes (0-59) */
  //     int tm_hour;   /* Hours (0-23) */
  //     int tm_mday;   /* Day of the month (1-31) */
  //     int tm_mon;    /* Month (0-11) */
  //     int tm_year;   /* Year - 1900 */
  //     int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
  //     int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
  //     int tm_isdst;  /* Daylight saving time */
  // };
  // ?? 为什么这里要用 &infor->st_mtime 而不是 info->st_mtime
  // !! 因为 info 自己就是个首地址
  // &... 是字符串的首地址， 4 + & 是从第四个字符开始打印
  printf("%.15s ", 4 + ctime(&info->st_mtime));
  printf("\033[%d;%dm%s\033[0m ", bg_c, fg_c, filename);
  if(modestr[0] == 'l') {
    int cnt;
    // readlink 填写 buffer 是不加 \0, 所有这里要初始化为 0
    char buf[NAMEMAX] = {0};
    // readlind(path_of_file, buffer_to_store_linked_path, size_of_buffer)
    if ((cnt == readlink(filename, buf, NAMEMAX)) < 0) {
      perror("readlin");
    } else {
      printf("-> %s", buf);
    }
  }
  printf("\n");
}

void do_stat(char *filename) {
  struct stat st;
  // stat: These  functions  return  information about a file, in the buffer pointed to by statbuf.
  if (lstat(filename, &st) < 0) {
    perror(filename);
  } else {
    show_info(filename, &st);
  }
  // printf("Doing with %s status.\n", filename);
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

  // NULL: 目录无法打开, 不是目录
  if ((dirp = opendir(dirname)) == NULL) {
    // 可能是个文件
    // access 对某个文件是否可达
    if (access(dirname, R_OK) == 0) {
      // 如果不是列表形式，直接打印
      if (flag_l == 0) {
        struct stat tmp_st;
        lstat(dirname, &tmp_st);
        update_color(tmp_st.st_mode);
        printf("\033[%d;%dm%s\033[0m\n", bg_c, fg_c, dirname);
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
    // 当前程序的运行的位置为默认 dir,要找到特定文件夹下的文件，先进入那个文件夹
    chdir(dirname);
    // 目录下的文件个数
    int cnt = 0;
    // readdir 读到目录末尾时返回 NULL
    while((direntp = readdir(dirp)) != NULL) {
      // 处理是否显示隐藏文件
      if (direntp->d_name[0] == '.' && (flag_a == 0)) continue;
      strcpy(names[cnt++], direntp->d_name);
    }
    printf("cnt: %d\n", cnt);
    // sort
    qsort(names, cnt, NAMEMAX, cmp_name);
    if (flag_l == 1) {
      for (int i = 0; i < cnt; i++) {
        do_stat(names[i]);
      }
    } else {
      printf("Print all files\n");
      int row, col;
      // 输出参数，传地址
      size_window(names, cnt, &row, &col);
      printf("row = %d, col = %d\n", row, col);
      show_files(names, cnt, row, col);
    }
  }
  printf("Doing with dir %s.\n", dirname);
  // 输出 names 数组里所有内容
  // 规划窗口: 要输出几行几列
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