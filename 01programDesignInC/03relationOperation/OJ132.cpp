#include <iostream>
using namespace std;

int main() {
	int n, x;
	long long result = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		result *= x;
	}

	cout << result << endl;

	return 0;
}