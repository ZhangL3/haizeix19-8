#include <cstdarg>
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int reverse_num(int num ,int *temp) {
  // 123 => 321, 但 1000 => 0001 => 1
  // 如果用 while，x 是 0 的时候无法进入，所以用 do while
  int digit = 0;
  do {
    *temp = *temp * 10 + num % 10;
    num /= 10;
    digit += 1;
  } while(num);
  return digit;
}

int output_num(int temp, int digit) {
  int cnt = 0;
  while (digit--) {
    putchar(temp % 10 + '0');
    temp /= 10;
    cnt += 1;
  }
  return cnt;
}

// 返回在标准输出的字符的个数
// const 可以接收字符串的字面量
int my_printf(const char *frm, ...) {
  int cnt = 0;
  // 定义语句的宏
  #define PUTC(a) putchar(a), ++cnt
  va_list arg;
  va_start(arg, frm);
  // 字符串结尾标识符 \0, ASCII 码就是 0
  // strlen 就是循环字符串到 \0
  for (int i = 0; frm[i]; i++) {
    switch (frm[i]) {
      case '%': {
        switch (frm[++i]) {
          case 'd': {
            // INT32_MAX = 2147483647 INT32_MIN = -2147483648
            // 用 int 处理负数取反时会超界，所以用 uint32_t
            int xx = va_arg(arg, int), temp = 0, digit = 0;
            uint32_t x;
            // 处理负数
            if (xx < 0) PUTC('-'), x = -xx;
            x = xx;
            // 输出 INT32_MAX (2147483647) 时，反转数字是可能会超过这个数字，就超界了，所以分两段处理
            // 这里没有考虑如 1000010，这种中间有 0 的情况
            int num1 = x / 100000, num2 = x % 100000;
            int temp1 = 0, temp2 = 0;
            // 因为输出时从后往前输出数字字符，所以先颠倒一下
            int digit1 = reverse_num(num1, &temp1);
            int digit2 = reverse_num(num2, &temp2);
            if (num1) digit2 = 5;
            else digit1 = 0;
            cnt += output_num(temp1, digit1);
            cnt += output_num(temp2, digit2);
          } break;
          case '%': {
            PUTC(frm[i]);
          } break;
          case 's': {
            const char *str = va_arg(arg, const char *);
            for (int i = 0; str[i]; i++) {
              PUTC(str[i]);
            }
          } break;
        }
      } break;
      default: PUTC(frm[i]); break;
    }
  }
  va_end(arg);
  #undef PUTC
	return cnt;
}

int main() {
  // int a = 123;
  // int a = 1000;
  // int a = 0;
  int a = -123;
	printf("hello world\n");
	my_printf("hello world\n");
  // printf("int (a) = %%\n");
  // my_printf("int (a) = %%\n", a);
  printf("int (a) = %d\n", a);
  my_printf("int (a) = %d\n", a);
  printf("INT32_MAX = %d\n", INT32_MAX);
  my_printf("INT32_MAX = %d\n", INT32_MAX);
  printf("INT32_MIN = %d\n", INT32_MIN);
  my_printf("INT32_MIN = %d\n", INT32_MIN);
  char str[100] = "I love Beijing !";
  printf("%s\n", str);
  my_printf("%s\n", str);
	return 0;
}
