#include <iostream>
using namespace std;

int monthDays[13] = {0,
	31, 28, 31,
	30, 31, 30,
	31, 31, 30,
	31, 30, 31
};

int isLeapYear(int year) {
	return !(year % 400) || (!(year % 4) && (year % 100));
}

int getMonthDays(int month, int year) {
	if (month >= 1 && month <= 12) {
		if (month == 2) {
			return monthDays[month] + isLeapYear(year);

		} else {
			return monthDays[month];
		}
	} else {
		return -1;
	}
}

int validDate(int y, int m, int d) {
	int monthDays = getMonthDays(m, y);
	if (monthDays == -1) return 0;
	if (d >= 1 && d <= monthDays) return 1;
	return 0;
}

int main() {
	int y, m, d;
	cin >> y >> m >> d;
	cout << (validDate(y, m, d) ? "YES" : "NO") << endl;


	return 0;
}