#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

// int main() {
//   // 类似数组，但是没有边界
//   // map<int, int> arr;
//   unordered_map<int, int> arr;
//   arr[-100] = 36;
//   arr[-90] = 50;
//   arr[105] = 37;
//   arr[79] = 65;
//   for (auto iter = arr.begin(); iter != arr.end(); iter++) {
//     // first 相当与 key 值
//     cout << iter->first << endl;
//     // map 是按从小到大输出
//     // unordered_map 不是按顺序输出
//   }

//   return 0;
// }

// // 依次输入年龄和名字，按年龄顺序输出名字
// int main() {
//   // 类似数组，但是没有边界
//   // map<int, int> arr;
//   map<int, string> arr;
//   string name;
//   int n, age;

//   cin >> n;
//   for (int i = 0; i < n; i++) {
//     cin >> age >> name;
//     arr[age] = name;
//   }

//   for (auto iter = arr.begin(); iter != arr.end(); iter++) {
//     // second 相当与 value 值
//     cout << iter->second << endl;
//   }

//   return 0;
// }

int main() {
  // set 底层也是红黑树，但不是 key，value 对，会去重
  set<int> s;
  s.insert(3);
  s.insert(5);
  s.insert(2);
  // 因为重复，没有被插入
  s.insert(3);

  // s.begin() 永远是最小的元素，就可以看作是小顶堆, s.begin() 就是堆底元素
  cout << *s.begin() << endl;

  s.erase(*s.begin());
  for (auto iter = s.begin(); iter != s.end(); iter++) {
    // iter 迭代器是个指针 *iter 代表的是值
    cout << *iter << " ";
  }
  cout << endl;
  
  return 0;
}