#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: fn_call file_name");
    exit(0);
  }

  printf("file name: %s\n", argv[1]);

  
  return 0;
}