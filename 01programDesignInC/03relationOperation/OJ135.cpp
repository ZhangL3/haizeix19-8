#include <iostream>
using namespace std;

bool isLeapYear(int year) {
	return !(year % 400) || (!(year % 4) && (year % 100));
}

int day[13] = {0,
	31, 28, 31, 30,
	31, 30, 31, 31,
	30, 31, 30, 31,
};

int Days(int y, int m) {
	return day[m] + (m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)));
}

void next_day(int &y, int &m, int &d) {
	d += 1;
	if (d >Days(y, m)) {
		m += 1, d = 1;
		if (m > 12) {
			y += 1, m = 1;
		}
	}

	return ;
}

int main() {
	int x, y, m, d;
	cin >> x >> y >> m >> d;

	for(int i = 0; i < x; i++) {
		next_day(y, m, d);
	}

	cout << y << " " << m << " " << d << endl;

	return 0;
}