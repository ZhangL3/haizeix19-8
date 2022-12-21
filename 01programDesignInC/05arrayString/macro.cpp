#include <stdio.h>

// #define MAX(a, b) (a) > (b) ? (a) : (b)
#define int MAX(a, b) { return a > b ? a : b}

int main() {
  int a = 2, b = 3;
  printf("MAX(2, 3) = %d\n", MAX(a, b));
  printf("5 + MAX(2, 3) = %d\n", (5 + MAX(a, b)));
  return 0;
}
