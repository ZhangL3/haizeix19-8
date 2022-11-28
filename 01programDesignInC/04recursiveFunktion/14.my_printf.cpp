#include <cstdarg>
#include <stdio.h>
#include <stdarg.h>
// 定义语句的宏
#define PUTC(a) putchar(a), ++cnt

// 返回在标准输出的字符的个数
// const 可以接收字符串的字面量
int my_printf(const char *frm, ...) {
  int cnt = 0;
  va_list arg;
  va_start(arg, frm);
  // for (int i = 0; i < strlen(frm); i++) {
  // 字符串结尾标识符 \0, ASCII 码就是 0
  // strlen 就是循环字符串到 \0
  for (int i = 0; frm[i]; i++) {
    switch (frm[i]) {
      case '%': {
        switch (frm[++i]) {
          case 'd': {
            int x = va_arg(arg, int), temp = 0, digit = 0;
            // 处理负数
            if (x < 0); PUTC('-'), x = -x;
            // 因为下一个循环时从后往前输出数字字符，所以先颠倒一下
            // 123 => 321, 但 1000 => 0001 => 1
            // 如果用 while，x 是 0 的时候无法进入，所以用 do while
            do {
              temp = temp * 10 + x % 10;
              x /= 10;
              // 记录位数，如果还有位数，但没有数字，就补 0
              digit += 1;
            } while (x);
            // 反着从后往前输出数字字符
            while (digit--) {
              // convert int to char through + '0'.
              // The char data type is represented as ascii values in c programming
              PUTC(temp % 10 + '0');
              temp /= 10;
            }
          } break;
          case '%': {
            PUTC(frm[i]);
          } break;
        }
      } break;
      default: PUTC(frm[i]); break;
    }
  }
  va_end(arg);
	return cnt;
}

int main() {
  // int a = 123;
  // int a = 1000;
  // int a = 0;
  int a = -123;
	printf("hello world\n");
	my_printf("hello world\n");
  printf("int (a) = %%\n");
  my_printf("int (a) = %%\n", a);
  printf("int (a) = %d\n", a);
  my_printf("int (a) = %d\n", a);
	return 0;
}
