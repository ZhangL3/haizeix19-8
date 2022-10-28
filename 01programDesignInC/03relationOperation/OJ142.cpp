#include <iostream>
using namespace std;

int isPalindromic(int n) {
	int m = 0, temp = n;
	while (temp) {
		m *= 10;
		m += temp % 10;
		temp /= 10;
	}
	return m == n;
}

int main() {
	int a , b, spaceFlag = 1;
	cin >> a >> b;
	/* 素数筛算法 */
	int *prime = new int[b + 1];
	// prime[i] 如果等于 0，说明 i 是素数, 如果 i 不是 0，i 不是素数
	// 先标记所有数为素数
	for (int i = 0; i < b; i++) prime[i] = 0;
	for (int i = 2; i * i < b; i++) {
		// 如果 i 不是素数，跳过这轮
		if (prime[i]) continue;
		// 标记多有素数的倍数
		// j 遍历所有 i 的倍数: j += i
		for (int j = 2 * i; j <= b; j += i) {
			prime[j] = 1;
		}
	}

	for (int i = a; i <= b; i++) {
		if (prime[i] == 0 && isPalindromic(i)) {
			cout << (spaceFlag ? "" : " ") << i;
			spaceFlag = 0;
		}
	}
	cout << endl;
}