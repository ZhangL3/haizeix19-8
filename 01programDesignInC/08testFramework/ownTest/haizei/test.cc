#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <haizei/test.h>
#include <haizei/linklist.h>

int func_cnt = 0;
struct Function func_head, *func_tail = &func_head;
struct FunctionInfo haizei_test_info;
// 链表节点的头指针
struct LinkNode *head = NULL;

int RUN_ALL_TESTS() {
  for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
    struct Function *func = Head(p, struct Function, p);
    // \033[32m...\033[0m 显示绿色
    printf(GREEN("[====Run====]") RED_HL(" %s\n"), func->str);
    haizei_test_info.total = haizei_test_info.success = 0;
    func->run();
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
  struct Function *temp = (struct Function *)calloc(1, sizeof(struct Function));
  temp->run = func;
  // strdup 拷贝字符串
  temp->str = strdup(str);
  // 添加 temp 节点到链表的尾部
  func_tail->p.next = &(temp->p);
  func_tail = temp;
  return ;
}
