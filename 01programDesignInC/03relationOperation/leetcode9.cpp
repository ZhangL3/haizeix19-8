#include <iostream>
using namespace std;

bool isPalindrome(int x) {
	// 负数不可能是回文
	if (__builtin_expect(!!(x < 0), 0)) return false;
	long long y = 0;
	int z = x;
	while (x) {
		// y 向左移动一位
		y = y * 10;
		// 补上新的 x 的末位的值
		y += x % 10;
		// 消掉 x 的末位的值
		x /= 10;
	}

	return z==y;
}

int main() {
	int n;
	cin >> n;
	cout << isPalindrome(n) << endl;
	
	return 0;
}