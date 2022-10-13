#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << ( n & 1 && !(n % 7) ? "YES" : "NO") << endl;
	return 0;
}