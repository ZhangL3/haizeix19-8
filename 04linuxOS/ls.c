#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

void do_ls(char[]);

int main(int argc, char *argv[]) {
  // 如果只有一个参数，就是没有传參
  if (argc == 1) {
    do_ls(".");
  } else {
    // 减到 0 停止
    while (--argc) {
      // 一次向后挪移个指针，传指针指向的 String 给 do_ls
      printf("%s:\n", *++argv);
      do_ls(*argv);
    }
  }

  return 0;
}

void do_ls(char dirname[]) {
  // 目录指针
  DIR *dirp;
  struct dirent *direntp;

  if ((dirp = opendir(dirname)) == NULL) {
    perror("opendir");
    return ;
  }
  while ((direntp = readdir(dirp)) != NULL) {
    printf("%s ", direntp->d_name);
  }
  closedir(dirp);
  printf("\n");
}