#include <iostream>
using namespace std;

int main() {
	int a, b = 0, temp;
	cin >> a;
	if (a < 0) {
		cout << "NO" << endl;
		return 0;
	}
	temp = a;
	while(a) {
		b *= 10;
		b += a % 10;
		a /= 10;
	}
	cout << (temp - b ? "NO" : "YES") << endl;

	return 0;
}