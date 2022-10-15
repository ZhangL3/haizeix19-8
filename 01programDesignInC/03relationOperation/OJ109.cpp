#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n) {
		if (!((n % 10) & 1)) {
			cout << "YES" << endl;
			return 0;
		}
		n /= 10;
	}
	cout << "NO" << endl;

	return 0;
}