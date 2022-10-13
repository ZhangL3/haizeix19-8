#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	// int a, b;
	// scanf("%d%d", &a, &b);

	// while (a - b >= 0) {
	// 	if (a - b == 0) {
	// 		printf("YES\n");
	// 		return 0;
	// 	} else {
	// 		a -= b;
	// 	}
	// }

	// printf("NO\n");

	// if (a % b) {
	// 	printf("YES\n");
	// } else {
	// 	printf("NO\n");
	// }

	int c, d;
	cin >> c >> d;
	cout << (c % d ? "NO" : "YES") << endl;

	return 0;
}