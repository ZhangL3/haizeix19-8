#include <iostream>
#include <stdarg.h>
using namespace std;

int main() {
	double v, a;
	cin >> v >> a;
	printf("%.2lf\n", (v * v) / (2 * a));

	return 0;
}