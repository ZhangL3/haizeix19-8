#include <stdio.h>

// n: 形式参数，作用域在 func 内，无法影响外面的 n
int func(int n) {
  return 0;
}

// 如果要影响外面的 n，就要定义为传出参数，用指针变量
int funcP(int *n) {
  // 在 n 所在的地址上存入 123
  *n = 123;
  return 0;
}

// 指向整型的指针变量 a
int funcPa(int *a, int n) {
  printf("funcPa : a[3] = %d\n", a[3]);
  // *a = 8, 它是指针变量，指针变量是用 8 Byte 储存的
  printf("*a = %lu\n", sizeof(a));
  printf("*a = %p, a + 1 = %p\n", a, a + 1);
  return 0;
}

int funcN(int *a) {
  // *(arr + 0) = &arr[0]
  *a = 123;
  // *(a + 0)
  // 传进来的地址不偏移，直接存上 123
  a[0] = 123;
  return 0;
}

// 不能这么用，**a 并不是定义了一个二维数组的头指针
// (int *)(* a) 定义了一个指向整型指针类型的一个指针
// a 里存的是一个整型指针的一个地址
int funcA2(int **a) {
  // + 1 是加的一个指针类型的偏移量 8 Byte
  printf("a = %p, a + 1 = %p\n", a , a + 1);
  return 0;
}

int funcA2d(int (*a)[200]) {
  // + 1 的偏移量是 200 个 int, 800 Byte
  printf("a = %p, a + 1 = %p\n", a , a + 1);
  return 0;
}

int funcA3d(int (*a)[200][300]) {
  // + 1 的偏移量是 60000 个 int, 240000 Byte
  printf("a = %p, a + 1 = %p\n", a , a + 1);
  return 0;
}

int main() {
  int arr[100];
  int arr2d[100][200];
  int arr3d[100][200][300];
  // arr: 数组名, 首地址, 第一个整型的地址
  // arr 于 &arr[0] 是一样的
  // arr = 0x7ffdcdf00720, &arr[0] = 0x7ffdcdf00720
  printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);
  // 指针向后偏移了一个类型的大小, int 是 4 Byte
  // arr + 1 = 0x7ffdcdf00724, arr + 2 = 0x7ffdcdf00728
  printf("arr + 1 = %p, arr + 2 = %p\n", arr + 1, arr + 2);
  // arr 本身是个整型，强转成字符指针
  char *p = (char *)arr;
  // p + 1 = 0x7ffe7c732d61, p + 2 = 0x7ffe7c732d62
  printf("p + 1 = %p, p + 2 = %p\n", p + 1, p + 2);
  int n = 0;
  // 传 n 的时候为什么要加取址符？
  // 储存到所指向地址的位置
  // scanf("%d", &n);
  // n: 实际参数
  // func(n);
  // funcP(&n);
  // p = 123
  // printf("n = %d\n", n);

  // for (int i = 0; i < n; i++) {
  //   // scanf("%d", &arr[i]);
  //   scanf("%d", arr + i);
  // }
  funcPa(arr, n);
  // arr = 400
  // 每个 int 占用 4 Byte，100 个就是 400 Byte
  printf("arr = %lu\n", sizeof(arr));
  funcN(&n);
  funcA2d(arr2d);
  return 0;
}
