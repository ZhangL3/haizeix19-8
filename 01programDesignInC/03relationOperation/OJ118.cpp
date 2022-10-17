#include <iostream>
using namespace std;

int main() {
	int year;
	cin >> year;

	char animals[][10] = {
		"rat", "ox", "tiger",
		"rabbit", "dragon", "snake",
		"horse", "sheep", "monkey",
		"rooster", "dog", "pig"
	};

	if (year >= 1900) {
		cout << animals[(year - 1900) % 12] << endl;
	} else {
		cout << animals[12 - ((1900 - year) % 12)] << endl;
	}
	// cout << animals[((year - 1900) % 12 + 12) % 12] << endl;

	return 0;
}