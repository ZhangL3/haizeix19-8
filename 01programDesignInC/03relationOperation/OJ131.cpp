#include <iostream>
using namespace std;

int main() {
	int32_t n, x, minV = INT32_MAX, maxV = INT32_MIN;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		minV = min(minV, x);
		maxV = max(maxV, x);
	}
	cout << (maxV - minV) << endl;
	
	return 0;
}