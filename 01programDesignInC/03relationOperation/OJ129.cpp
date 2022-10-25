#include <iostream>
#include <cinttypes>
using namespace std;

int main() {
	int32_t n, ans = INT32_MAX, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ans = min(ans, temp);
	}

	cout << ans << endl;
	return 0;
}