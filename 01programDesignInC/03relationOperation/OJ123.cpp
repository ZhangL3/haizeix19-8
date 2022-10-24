#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	if (
		(a <= c && b >= d)
		|| (c <= a && d >= b)
	) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;

	return 0;
}