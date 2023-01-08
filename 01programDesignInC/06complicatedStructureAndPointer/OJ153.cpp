#include <stdio.h>

void calculateMonth(int *y, int *m) {
	// 多行必须得加 {}，不然只有第一个表达式算在 if 里
	// if (*m == 1) {*m = 13; *y = *y - 1;} return;
	// if (*m == 2) {*m = 14; *y = *y - 1;} return;
	if (*m <= 2) {
		*m += 12;
		// 指针不能用 ++ --
		*y -= 1;
	}
}

int main() {
	int y, m, d, j, k, h;

	scanf("%d %d %d", &y, &m, &d);
	// printf("%d %d %d\n", y, m, d);
	calculateMonth(&y, &m);
	// printf("%d %d %d\n", y, m, d);

	j = y / 100;
	k = y % 100;
	h = (d + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;

	switch (h)
	{
	case 0:
		printf("%d\n", 6);
		break;
	case 1:
		printf("%d\n", 7);
		break;
	case 2:
		printf("%d\n", 1);
		break;
	case 3:
		printf("%d\n", 2);
		break;
	case 4:
		printf("%d\n", 3);
		break;
	case 5:
		printf("%d\n", 4);
		break;
	case 6:
		printf("%d\n", 5);
		break;
	
	default:
		break;
	}

	return 0;
}