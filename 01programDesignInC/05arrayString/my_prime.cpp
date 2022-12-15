#include <iostream>
using namespace std;

int main() {
  int t[121] = {0};
  
  for (int i = 2; i < sizeof(t) / sizeof(int); i++) {
    if (!t[i]) {
      /*for (int j = 2; j < (sizeof(t) / sizeof(int)) / 2; j++) {
        if (i * j < sizeof(t) / sizeof(int) && t[i * j] == 0) {
          t[i * j] = 1;
        }
      }*/
      // 这里是可以优化的，j 可以用来表示 i 的倍数，而不是 i 的几倍
      // 所以每个循环结束是 j += i
      // 因为 i * 2 已经被 2 标记，可以不需要再来一遍了，所以 j 的初始值可以是 i * i
      for (int j = i * i; j < sizeof(t) / sizeof(int); j += i) {
        t[j] = 1;
      }
    }
  }

  for (int i = 2; i < sizeof(t) / sizeof(int) ; i++) {
    !t[i] && cout << i << endl;
  }

  return 0;
}
