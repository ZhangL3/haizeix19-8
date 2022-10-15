#include <stdio.h>
using namespace std;

int main() {
	// int n;
	// char a, b;
	// scanf("%d", &n);
	// scanf("%c%c", &a, &b);
	// printf("a = %d, b = %\n", a, b);
	/* 
	13
	97
	a = 10, b = 57
	// \n 是 10, 0 是 48, 9 是 57
	// %c 会读入每一个字符，空格和回车也是一个字符
	*/

	char form[10];
	double m, n;
	scanf("%s%lf%lf", form, &m, &n);

	printf("%.2lf\n", (form[0] == 'r' ? m * n : m * n / 2.0));

	return 0;
}