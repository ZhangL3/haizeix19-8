#include <iostream>
using namespace std;

int main() {
	int n, A = 65;
	cin >> n;

	for (int i = 0, m = 0; i < n; i++, m++) {
		for (int j = 0; j < n - m; j++, A++) {
			printf("%c", A);
		}
		printf("\n");
	}
	return 0;
}