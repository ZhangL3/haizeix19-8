#include <stdio.h>

// #define MAX(a, b) a > b ? a : b
// #define MAX(a, b) (a > b ? a : b)
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// ({}) 这个括号必须写，因为替代到调用里，没有个这 () 结构时错误的
#define MAX(a, b) ({\
  __typeof(a) __a = (a);\
  __typeof(b) __b = (b);\
  __a > __b ? __a : __b;\
})

#define MIN(a, b) {\
  a > b ? b : a\
}

// #func 中的 # 将 func 的内容转换成字符串进行输出
#define p(macro) {\
  printf("%s = %d\n", #macro, macro);\
}

int main() {
  int a = 7;
  // printf("MAX(2, 3) = %d\n", MAX(2, 3));
  // printf("5 + MAX(2, 3) = %d\n", 5 + MAX(2, 3));
  // printf("MAX(2, MAX(3, 4)) = %d\n", MAX(2, MAX(3, 4)));
  // printf("MAX(2, 3 > 4 ? 3 : 4) = %d\n", MAX(2, 3 > 4 ? 3 : 4));
  // printf("MAX(a++, 6) = %d\n", MAX(a++, 6));
  // printf("a = %d\n", a);
  p(MAX(2, 3));
  p(5 + MAX(2, 3));
  p(MAX(2, MAX(3, 4)));
  p(MAX(2, 3 > 4 ? 3 : 4));
  p(MAX(a++, 6));
  p(a);
  return 0;
}

// -E 展开预编译阶段的代码
// g++ -E 18.define.cpp

// #define MAX(a, b) a > b ? a : b
// { printf("%s = %d\n", "MAX(2, 3)", 2 > 3 ? 2 : 3);};
// { printf("%s = %d\n", "5 + MAX(2, 3)", 5 + 2 > 3 ? 2 : 3);};
// { printf("%s = %d\n", "MAX(2, MAX(3, 4))", 2 > 3 > 4 ? 3 : 4 ? 2 : 3 > 4 ? 3 : 4);};
// { printf("%s = %d\n", "MAX(2, 3 > 4 ? 3 : 4)", 2 > 3 > 4 ? 3 : 4 ? 2 : 3 > 4 ? 3 : 4);};
// { printf("%s = %d\n", "MAX(a++, 6)", a++ > 6 ? a++ : 6);};
// { printf("%s = %d\n", "a", a);};
