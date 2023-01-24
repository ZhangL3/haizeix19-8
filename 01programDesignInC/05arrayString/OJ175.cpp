#include <stdio.h>

int main() {
	int n, tmp, You = 0, Liang = 0, Zhong = 0, Cha = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp <= 100 && tmp >= 90) You++;
		else if (tmp <= 89 && tmp >= 80) Liang++;
		else if (tmp <= 79 && tmp >= 60) Zhong++;
		else Cha++;
	}
	printf("You %d\n", You);
	printf("Liang %d\n", Liang);
	printf("Zhong %d\n", Zhong);
	printf("Cha %d\n", Cha);

	return 0;
}