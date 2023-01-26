#include <stdio.h>
#include <string.h>
#define CHAR_A 65

void calcValue(int *v, int middleVal, int startInd, int endInd) {
	if (startInd == endInd) return ;
	int middleInd = (startInd + endInd + 1) / 2;
	v[middleInd] = middleVal;
	calcValue(v, middleVal - 1, startInd, middleInd - 1);
	calcValue(v, middleVal - 1, middleInd + 1, endInd);
}

int main() {
	// const int l20 = 1048575;
	int n;
	scanf("%d", &n);
	// int v[(l20 + 5) / 2] = {0};
	// int l = 1;
	// for (int j = 1; j < n; j++) {
	// 	l = 2 * l + 1;
	// }
	// // printf("l = %d\n", l);
	// calcValue(v, n - 1, 0, l - 1);
	// for (int k = 0; k < l; k++) {
	// 	printf("%C", (CHAR_A + v[k]));

	// }
	// printf("\n");

	/* 思路
	l = 3
	ABACABA
	0 = 6
	1 = 5
	2 = 4
	=> 2 * l - i
	*/
	char s[5000000] = {'A'};
	for (int i = 1; i < n; i++) {
		int l = strlen(s);
		for (int j = 0; j < l; j++) {
			s[2 * l - j] = s[j];
		}
		s[l] = 'A' + i;
		printf("%d: %s\n", i, s);
	}
	printf("%s\n", s);


	return 0;
}