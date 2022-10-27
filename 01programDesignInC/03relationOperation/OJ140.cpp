#include <iostream>
#include <stdio.h>
using namespace std;

void printChar(int spaceCnt, int charCnt, int charCode) {
	for (int i = 0; i < spaceCnt; i++) {
		cout << " ";
	}
	for (int j = 0; j < charCnt; j++) {
		printf("%c", charCode);
	}
	cout << endl;
}

int main() {
	int n, j, cCnt;
	cin >> n;

	int MAX_LEN = 1 + ((n - 1) * 2);

	for (int i = 1, j = n - 1, charCode = 65; i <= 2 * n - 1; i++) {
		if (i <= n) {
			cCnt = 1 + ((i - 1) * 2);
			printChar((MAX_LEN - cCnt) / 2, cCnt, charCode);
		} else {
			cCnt = 1 + ((j - 1) * 2);
			printChar((MAX_LEN - cCnt) / 2, cCnt, charCode);
			j--;
		}

		i < n ? charCode++ : charCode--;
	}
}