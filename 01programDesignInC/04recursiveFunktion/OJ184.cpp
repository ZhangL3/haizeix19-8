#include <stdio.h>

void eatPeach(int *n, int *cnt) {
	printf("n = %d, cnt = %d\n", *n, *cnt);
	*n -= 1;
	if (*n == 0) return ;
	*cnt = 2 * (*cnt + 1);
	eatPeach(n, cnt);
}

int main() {
	int n, cnt = 1;
	scanf("%d", &n);
	eatPeach(&n, &cnt);
	printf("%d\n", cnt);
	
	return 0;
}