#include <iostream>
#include<algorithm>
#define MAX_N 100000
using namespace std;

int a[MAX_N + 5];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  // 方法 1： sort
  // sort(第一个元素，最后一个元素后一位)
  // a 是数组的起始位置，a[1] 是数组的第一个元素，也可以用 a + 1 表示
  // sort(a + 1, a + n + 1);

  // 方法 2： nth_element
  // nth_element(第一个元素，a + k ,最后一个元素后一位) K: 要找的 k 位置的值放在 k 位置
  nth_element(a + 1, a + (n + 1) / 2, a + n + 1);
  // nth_element 不排序
  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  int p = a[(n + 1) / 2], ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i] - p);
  }
  cout << ans << endl;
  return 0;
}