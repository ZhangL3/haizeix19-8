#include <stdio.h>

int calculateDate(int n) {
	if ((n + 3) <= 7) return n + 3;
	else return n + 3 - 7;
}

void printDate(int n) {
	switch (n)
	{
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
		break;
	case 7:
		printf("Sunday");
		break;
	default:
		break;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printDate(calculateDate(n));
	printf("\n");
	return 0;
}