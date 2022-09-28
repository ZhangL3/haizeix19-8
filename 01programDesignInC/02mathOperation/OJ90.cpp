#include <iostream>
#include <string>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << a / 100 << endl;
	// cout << (a - ((a / 100) * 100)) / 10 << endl;
	cout << (a % 100) / 10 << endl;
	cout << a % 10 << endl;

	return 0;
}