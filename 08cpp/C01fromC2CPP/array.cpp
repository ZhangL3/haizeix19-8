#include <iostream>
#include <vector>
using namespace std;

// 关键字 struct 完全是为了兼容 C 语言，但运行方式和 C 语言不同
// C++ 为了支持 C 的原生指针类型，也做了一些妥协。在 2.0 标准中，肯能去掉支持原生指针类型

template<typename T>
class Array {
public :
  Array() {
    // 初始化时，连续区域为 10 个 T 的大小
    this->__size = 10;
    this->__cnt = 0;
    // data 占的空间为 10 个 T 的大小
    this->data = new T[this->__size];
  }

  Array(int n) {
    this->__size = 2 * n;
    this->__cnt = n;
    this->data = new T[this->__size];
  }

  void push_back(const T &a) {
    // 这行代码有 bug，关于复制 a 的问题
    this->data[(this->__cnt)++] = a;
  }

  int size() {
    return this->__cnt;
  }

  // &operator[] 重载了 [] 运算符, 使得 Array 对象可以像数组一样使用, 例如 arr[0] = 123;
  T &operator[](int index) {
    return this->data[index];
  }

private:
  // 顺序表中那片连续的存储区域
  T *data;
  // 连续存储区的真实大小，到底存储了多少个元素
  int __size, __cnt;
};

int main() {
  vector<int> arr(10);
  Array<int> arr2(10);
  // Array<double> arr3(10);
  // Array<Node> arr4(10);

  cout << arr.size() << endl;
  arr.push_back(123);
  cout << arr[0] << endl;
  cout << arr.size() << endl;

  cout << arr2.size() << endl;
  arr2.push_back(123);
  cout << arr2[0] << endl;
  cout << arr2.size() << endl;
  return 0;
}
