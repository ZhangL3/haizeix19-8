#include <iostream>
#include<algorithm>
#define MAX_N 100000
using namespace std;

int a[MAX_N + 5];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  // sort(第一个元素，终止后以为)
  // a 是数组的起始位置，a[1] 是数组的第一个元素，也可以用 a + 1 表示
  sort(a + 1, a + n + 1);
  int p = a[(n + 1) / 2], ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i] - p);
  }
  cout << ans << endl;
  return 0;
}