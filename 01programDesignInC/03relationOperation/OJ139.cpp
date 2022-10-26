#include <iostream>
using namespace std;

void printA(int spaceCnt, int aCnt) {
	for (int i = 0; i < spaceCnt; i++) {
		cout << " ";
	}
	for (int j = 0; j < aCnt; j++) {
		cout << "A";
	}
	cout << endl;
}

int main() {
	int n, j;
	cin >> n;

	int MAX_LEN = n * 2;

	for (int i = 1, j = n - 1; i <= 2 * n - 1; i++) {
		if (i <= n) {
			printA((MAX_LEN - 2 * i) / 2, 2 * i);
		} else {
			printA((MAX_LEN - 2 * j) / 2, 2 * j);
			j--;
		}
	}
}