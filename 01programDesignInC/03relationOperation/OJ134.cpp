#include <iostream>
using namespace std;

int main() {
	int a, b, flag = 0;
	cin >> a >> b;
	// for (int i = a; i <= b; i++) {
	// 	i % 11 == 0 && cout << (flag++ ? " " : "") <<  i;
	// }
	// cout << endl;

	// while (a <= b) {
	// 	if (flag == 0) {
	// 		if (a % 11 == 0) {
	// 			cout << a;
	// 			flag++;
	// 			a += 11;
	// 		} else {
	// 			a++;
	// 		}
	// 	} else {
	// 		cout << " " << a;
	// 		a += 11;
	// 	}
	// }
	// cout << endl;

	for (int i = ((a - 1) / 11 + 1) * 11, j = 0; i <= b; i += 11, j++) {
		j && cout << " ";
		cout << i;
	}
	cout << endl;
	return 0;
}