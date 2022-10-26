#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = n / 7;

	for (int i = 7; i <= cnt * 7; i += 7) {
		cout << i << endl;
	}

	return 0;
}