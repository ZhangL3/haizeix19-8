#include <iostream>
using namespace std;

int main() {
	int a, b, AB, CD, cnt,
		temp, Ones, Tens, Hundreds, Thousands, flag;
	cin >> a >> b;
	int *prime = new int[b + 1];
	int *perfectSquare = new int[b + 1];

	// 0: 素数, 非完全平方根
	for (int i = 0; i < b; i++) {
		prime[i] = 0;
		perfectSquare[i] = 0;
	}
	// 求素数集
	for (int i = 2; i * i < b; i++) {
		if (prime[i]) continue;
		for (int j = 2 * i; j <= b; j += i) {
			prime[j] = 1;
		}
	}
	// 求完全平方数集合
	for (int i = 0; i * i <= b; i++) {
		perfectSquare[i * i] = 1;
	}

	cnt = 0;
	flag = 1;
	for (int i = a; i <= b; i++) {
		 if (i % 6 == 0) {
			temp = i;
			AB = CD = 0;
			Ones = Tens = Hundreds = Thousands = 0;

			Ones = temp % 10;
			temp /= 10;
			Tens = temp % 10;
			temp /= 10;
			Hundreds = temp % 10;
			temp /= 10;
			Thousands = temp % 10;

			AB = Thousands * 10 + Hundreds;
			CD = Tens * 10 + Ones;

			if (prime[AB] == 0 && perfectSquare[CD] == 1) {
				cnt += 1;
				cout << (flag ? "" : " ") << i;
				flag = 0;
			} else {
				continue;
			}
		 } else {
			continue;
		 }
	}
	cout << endl << cnt << endl;
	cout << endl;


	return 0;
}