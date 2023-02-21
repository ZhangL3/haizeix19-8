#include <string.h>
#include <stdio.h>
#include <math.h>
#include <haizei/test.h>

int func_cnt = 0;
Function func_arr[100];
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS() {
  for (int i = 0; i < func_cnt; i++) {
    // \033[32m...\033[0m 显示绿色
    printf(GREEN("[====Run====]") RED_HL(" %s\n"), func_arr[i].str);
    haizei_test_info.total = haizei_test_info.success = 0;
    func_arr[i].func();
    double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
    // 总共 6 位，小数点儿后2 位
    printf(GREEN("[  "));
    // if (haizei_test_info.success == haizei_test_info.total) {
    // 浮点数没法完全判等，只能是小于一个极小值时就算是相等
    if (fabs(rate - 100.0) < 1e-6) {
      printf(BLUE_HL("%6.2lf%%"), rate);
    } else {
      printf(RED_HL("%6.2lf%%"), rate);
    }
    printf(
      GREEN("  ]") " total : %d  success : %d\n",
      haizei_test_info.total,
      haizei_test_info.success
    );
  }
  return 0;
}

void add_function(TestFuncT func, const char *str) {
  func_arr[func_cnt].func = func;
  // strdup 拷贝字符串
  func_arr[func_cnt].str = strdup(str);
  func_cnt++;
  return ;
}
