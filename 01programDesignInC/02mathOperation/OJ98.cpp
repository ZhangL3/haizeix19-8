#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double r, h;
	cin >> r >> h;
	printf("%.2f\n", r * r * 3.14);
	printf("%.2f\n", r * r * 3.14 * h);
	
	return 0;
}