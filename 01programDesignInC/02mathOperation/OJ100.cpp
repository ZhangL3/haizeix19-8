#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double n, res = 0;
	cin >> n;
	for (int8_t i = 0; i < 6; i++)
	{
		res = (n + res) * (1 + 0.00417);
	}
	printf("$%.2lf\n", res);
	
	return 0;
}