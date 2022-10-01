#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	// x 为第二段时间
	double a, b, c, t, x;
	cin >> a >> b >> c >> t;
	x = (1 - (( 1/a + 1/b) * t)) / (1/a + 1/b - 1/c);
	printf("%.2lf", x + t);

	return 0;
}