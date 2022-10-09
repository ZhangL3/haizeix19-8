#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string ret;
	cin >> n;
	// if (n == 0) {
	if (!n) {
		ret = "FOOLISH";
	} else if (n < 60) {
		ret = "FALL";
	} else if (n < 75) {
		ret = "MEDIUM";
	} else if (n <= 100) {
		ret = "GOOD";
	}
	cout << ret << endl;

	return 0;
}