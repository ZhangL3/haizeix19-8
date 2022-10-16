#include <iostream>
using namespace std;

int day[13] = {0,
	31, 28, 31,
	30, 31, 30,
	31, 31, 30,
	31, 30, 31
};

int main() {
	int y, m;
	cin >> y >> m;
	/* switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << 31 << endl;
			break;
		case 2:
			cout << (!(y % 400) || (!(y % 4) && (y % 100)) ? 29 : 28) << endl;
			break;
		default:
			cout << 30 << endl;
			break;
	} */
	cout << (day[m] + (m == 2 && (!(y % 400) || (!(y % 4) && (y % 100))) ? 1 : 0)) << endl;

	return 0;
}