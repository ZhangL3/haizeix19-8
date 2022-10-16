#include <iostream>
using namespace std;

int main() {
	int x, y, sameDigits = 0;
	cin >> x >> y;
	if (x == y) {
		cout << 100 << endl;
		return 0;
	}

	if ((y % 10 == y / 10) && (y / 10 == x % 10 || y / 10 == x / 10)) {
		cout << 2 << endl;
		return 0;
	}

	sameDigits += (y % 10 == x / 10 || y % 10 == x % 10);
	sameDigits += (y / 10 == x / 10 || y / 10 == x % 10);
	
	if (sameDigits == 2) {
		cout << 20 << endl;
	} else if (sameDigits == 1) {
		cout << 2 << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}