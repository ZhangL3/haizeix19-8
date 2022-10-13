#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	double n;
	cin >> n;
	// cout << (n < 0 ? -n : n) << endl;
	cout << fabs(n) << endl;

/* 	double m;
	scanf("%lf", &m);
	if (m < 0) {
		// printf("%lf\n", -m);
		// 23.000000
		printf("%g\n", -m);
		// 23
	} else {
		// printf("%lf\n", m);
		printf("%g\n", m);
	} */

	return 0;
}