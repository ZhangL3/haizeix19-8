#include <iostream>
using namespace std;

bool isLeapYear(int year) {
	return !(year % 400) || (!(year % 4) && (year % 100));
}

int main() {
	int y, m, d,
		preY, preM, preD,
		nextY, nextM, nextD;
	int bigMonth[] = {1, 3, 5, 7, 8, 10, 12};
	cin >> y >> m >> d;

	// 计算年
	if (m == 1 && d == 1) {
		preY = y - 1;
		nextY = y;
	} else if (m == 12 && d == 31) {
		preY = y;
		nextY = y + 1;
	} else {
		preY = nextY = y;
	}

	// 计算月, 特殊情况（d 为 28，29，30）在计算日的过程中被计算
	if (m == 1 && d == 1) {
		preM = 12;
		nextM = 1;
	} else if (m == 12 && d == 31) {
		preM = 12;
		nextM = 1;
	} else if (d == 1) {
		preM = m - 1;
		nextM = m;
	} else if (d == 31) {
		preM = m;
		nextM = m + 1;
	} else {
		preM = m;
		nextM = m;
	}

	// 计算日
	if (d >= 2 && d <= 27) {
		preD = d - 1;
		nextD = d + 1;
	} else if (d == 1) {
		nextD = 2;
		if (m - 1 == 2) {
			preD = isLeapYear(y) ? 29 : 28;
		} else {
			for (int i = 0; i < sizeof(bigMonth); i++) {
				if (m - 1 == bigMonth[i]) {
					preD = 31;
					break;
				}
			}
			if (!(preD)) {
				preD = 30;
			}
		}
	} else if (d == 30) {
		preD = 29;
		for (int i = 0; i < sizeof(bigMonth); i++) {
			if (m == bigMonth[i]) {
				nextD = 31;
				break;
			}
		}
		if (!nextD) {
			nextD = 1;
			nextM = m + 1;
		}
	} else if (d == 31) {
		preD = 30;
		nextD = 1;
	} else if (d == 28 && m == 2) {
		preD = 27;
		nextD = (isLeapYear(y)) ? 29 : 1;
		nextM = (isLeapYear(y)) ? 2 : 3;
	} else if (d == 29 && m == 2) {
		preD = 28;
		preM = 2;
		nextD = 1;
		nextM = 3;
	}

	cout << preY << " " << preM << " " << preD << endl;
	cout << nextY << " " << nextM << " " << nextD << endl;
}