#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 2 * i; j++) {
			printf("%c", 65);
		}
		printf("\n");
	}
}