#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	double n, sum = 0, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
	}

	printf("%.2lf\n", sum / n);
	return 0;
}