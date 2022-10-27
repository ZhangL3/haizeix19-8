#include <iostream>
#include <stdio.h>
using namespace std;

void printChar(int maxLen, int charCnt, int startCharCode) {
	int spaceCnt = (maxLen - charCnt) / 2;
	int charCode = startCharCode;
	for (int i = 0; i < spaceCnt; i++) {
		cout << " ";
	}
	for (int j = 0; j < charCnt; j++) {
		if (j < charCnt / 2) {
			printf("%c", charCode++);
		} else {
			printf("%c", charCode--);
		}
	}
	cout << endl;
}

int main() {
	int n, j, cCnt;
	cin >> n;

	int MAX_LEN = 2 * n + 1;

	for (int i = 0, j = n - 1, charCode = 65; i < 2 * n + 1; i++) {
		if (i <= n) {
			cCnt = 2 * (n - i) + 1;
			printChar(MAX_LEN, cCnt, charCode);
		} else {
			cCnt = 2 * (n - j) + 1;
			printChar(MAX_LEN, cCnt, charCode);
			j--;
		}

		i < n ? charCode++ : charCode--;
	}
}