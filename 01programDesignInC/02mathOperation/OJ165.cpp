#include <stdio.h>
#include <math.h>

// a, b, c < pow(10, 6) > Max_int
int main() {
	long long c, cnt = 0;
	double b;
	scanf("%d", &c);

	for (long long a = 1; a * a < c * c - a * a; a++) {
		b = sqrt(c * c - a * a);
		if (b - (int)b == 0) cnt++;
	}

	// for (long long a = 1; a < c; a++) {
	// 	b = sqrt(c * c - a * a);
	// 	if (b - (int)b == 0) cnt++;
	// }

	printf("%d\n", cnt);

	return 0;
}