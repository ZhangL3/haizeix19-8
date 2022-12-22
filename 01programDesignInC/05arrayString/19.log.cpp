#include <stdio.h>

// 执行时加入参数
// g++ -D DEBUG 19.log.cpp
// 或者在文件中定义
#define DEBUG
#ifdef DEBUG

// #: 将后面的变量展开成字符串
// ##: 连接两个宏展开的形式，就是把前后两个宏替代的代码连接到一起，两个变量就变成一个了，支持了参数列表为空的情况
// printf(frm, ##arg) 相当于输出 frm##arg
// frm: 格式字符控制
#define log(frm, arg...) {\
  printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
  printf(frm, ##arg);\
  printf("\n");\
}

#else
#define log(frm, arg...)
#endif

#define contact(a, b) a##b
// #define contact(a, b) ab 把宏替换成立 "ab" 字符，并没有展开 a 和 b

int main() {
  int a = 123;
  int abcdef = 15;
  contact(abc, def) = 23;
  // abcdef = 23
  printf("[%s : %s : %d] %d\n", __FILE__, __func__, __LINE__, a);
  log("%d", a);
  log("hello world");
  log("%d", abcdef);
  return 0;
}
