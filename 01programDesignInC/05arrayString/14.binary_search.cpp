#include <stdio.h>

int binary_search_arr(int *arr, int n, int x) {
  int head = 0, tail = n - 1, mid;
  while (head <= tail) {
    mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    if (arr[mid] < x) head = mid + 1;
    else tail = mid - 1;
  }

  return -1;
}

// x: 0 1 2 3 4  5  6  7  8  9
// y: 0 1 4 9 16 25 36 49 64 81
// y = x ^ 2
int f(int x) {
  return x * x;
}

// 传入一个 y，找到 y 的正整数平方根 x
// 数组是展开了的函数，所有可以给一个函数
int binary_search_func(int (*arr)(int), int y) {
  int head = 0, tail = y, mid;
  while (head <= tail) {
    mid = (head + tail) >> 1;
    if (arr(mid) == y) return mid;
    if (arr(mid) < y) head = mid + 1;
    else tail = mid - 1;
  }

  return -1;
}

int main() {
  // int arr[100], n;
  // scanf("%d", &n);
  // for (int i = 0; i < n; i++) {
  //   scanf("%d", &arr[i]);
  // }
  // int x;
  // scanf("%d", &x);
  // printf("%d\n", binary_search_arr(arr, n, x));

  int n;
  while (~scanf("%d", &n)) {
    int x = binary_search_func(f, n);
    printf("%d * %d = %d\n", x, x, n);
  }
  return 0;
}
