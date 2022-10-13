#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;

	// while (a >= 9) {
	// 	if (a % 10 == 9) {
	// 		cout << "YES" << endl;
	// 		return 0;
	// 	}
	// 	a /= 10;
	// }
	// cout << "NO" << endl;

	// 只有三位数字
	if (a % 10 == 9 || a % 100 / 10 == 9 || a % 100 == 9) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}