#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	float a, b;
	cin >> a >> b;
	printf("%.2lf\n",  (a + b) * 2.0);
	printf("%.2lf\n", a * b);
	
	return 0;
}