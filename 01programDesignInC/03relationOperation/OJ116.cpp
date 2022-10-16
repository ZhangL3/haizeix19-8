#include <iostream>
using namespace std;

int main() {
	int a, b, c, f;
	cin >> a >> b >> c;

	// sort a < b < c
	if (a > b) {
		// swap a, b
		a = a - b;
		b = a + b;
		a = b - a;
	}

	if (b > c) {
		b = b - c;
		c = b + c;
		b = c - b;
	}

	if (a > b) {
		// swap a, b
		a = a - b;
		b = a + b;
		a = b - a;
	}

	f = a * a + b * b - c * c;

	if (a + b <= c) {
		cout << "illegal triangle" << endl;
		return 0;
	}

	if (f > 0) {
		cout << "acute triangle" << endl;
	} else if (f == 0) {
		cout << "right triangle" << endl;
	} else {
		cout << "obtuse triangle" << endl;
	}

	return 0;
}