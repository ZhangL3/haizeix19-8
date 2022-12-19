#include <stdio.h>

// a: 形参
int func(int a) {
  a = 234;
  return 0;
}

int func2(int *a) {
  *a = 123;
  *(a + 0) = 123;
  // a[0] 就代表当前传进来的元素，可以看作是单一元素的数组
  a[0] = 123;
  return 0;
}

// 接收的是数组的首地址, 存到一个指针变量中
// 64 位系统地址是 8 Byte 长
// 32 位系统中，一个指针占 4 个 Byte, 最大 4GB
int func_1(int *a) {
  // a 是指针变量，所以是 8 Byte 长
  printf("sizeof(*a) = %lu\n", sizeof(a));
  return 0;
}

// 方便进行校验
// n 是 a 数组的大小
int func_2(int n, int a[n]) {
  // printf("sizeof(a[]) = %lu\n", sizeof(a));
  return 0;
}

// 二维数组 arr[100][200]
// arr[0] 有 200 个元素, 应该是这 200 个元素的首地址
// arr[1] 也有 200 个元素, 应该是这第二个 200 个元素的首地址
// 所以 arr[1] 要比 arr[0] 向后跳 800 Byte
// int *a 情况下
// a + 1 向后挪 4 Byte，因为一个 int 是 4 Byte
// int **a 情况下 (指向指针的指针)
// a + 1 向后挪 8 Byte，因为一个指针是 8 Byte
// 也就是说 a[0], a[1], ... 存的都是 int *, 而不是 200 个 int
// int * 指向一篇连续的存储区
// 所以也可以看作是一个二维数组
// 但 arr 不能传给 **a
// 是因为 a[1] != arr[1]
int func_3(int **a) {
  a[0][1] = 123;
  return 0;
}

// a 是一个指针，指向大小为 200 的整型数组
int func_4(int (*a)[200]) {
  a[0][1] = 12322;
  return 0;
}

int func_5(int (*a)[200][300]) {
  a[0][1][1] = 12333;
  return 0;
}

// 第 i 个元素的地址
// arr + i
// 等价于
// arr[i]
// 第 i 个元素的值, * 表示取反
// *(arr + i)


int main() {
  // 存储 100 个整型变量的数组
  int arr[100];
  int arr_2[100][200];
  int arr_3[100][200][300];
  // 整型的第一个元素
  // arr[0];
  // arr 的首地址
  // arr
  printf("&arr[0] = %p arr = %p\n", &arr[0], arr);
  // 向后移动一个元素的位置
  // arr + 1
  printf("arr + 1 = %p arr + 2 = %p\n", arr + 1, arr + 2);
  char *p = (char *)arr;
  // p + 1 挪动一个 char 的位置
  printf("p + 1 = %p p + 2 = %p\n", p + 1, p + 2);
  int n = 0;
  // 等价于
  // int n[1] = {0};
  // n: 实参, 与形参互不影响, 改变形参的值，并不会改变实参的值
  func(n);
  printf("func: %d\n", n);
  func2(&n);
  // &n: 传出参数 (取 n 的地址传给函数)
  printf("func2: %d\n", n);
  // scanf("%d", &n);
  // for (int i = 0; i < 10; i++) {
  //   scanf("%d", arr + i);
  //   scanf("%d", &arr[i]);
  // }
  printf("sizeof(arr) = %lu\n", sizeof(arr));
  func_1(arr);
  func_2(100, arr);
  // 也是可以通过编译的
  func_2(200, arr);
  char str[1000];
  // str 就代表了数组的首地址
  // scanf("%s", str);
  // 不能通过编译
  // func_3(arr_2);
  func_4(arr_2);
  func_5(arr_3);

  return 0;
}
