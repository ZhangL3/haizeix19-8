#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int flag_a = 0;
int flag_l = 0;

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

  return 0;
}