#include <iostream>
using namespace std;

int main() {
	int degree, rank, age, work;
	cin >> degree >> rank >> age >> work;

	if (
		(rank <= 50 || degree >= 1)
		&& (age <= 25 || work >= 5)
	) {
		cout << "ok" << endl;
		return 0;
	}
	cout << "pass" << endl;

	return 0;
}