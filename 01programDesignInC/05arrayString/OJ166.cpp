#include <stdio.h>
#include <string.h>

void cpStr(char a[], char b[]) {
	int i = 0;
	while(a[i]) {
		b[i] = a[i];
		i++;
	}
	return ;
}

void insertStr(char a[], int p, char b[]) {
	char c[10000];
	int la = strlen(a), lb = strlen(b);
	int P = p - 1;

	cpStr(a, c);
	for (int i = 0; i < lb; i++) {
		a[P + i] = b[i];
	}
	for (int i = 0; i < la - P; i++) {
		a[P + lb + i] = c[P + i];
	}
}

/* char* insertStr2(char a[], int p, char b[]) {
	char c[10000], d[10000];
	int la = strlen(a), lb = strlen(b);
	int P = p - 1;

	cpStr(a, c);
	cpStr(a, d);
	for (int i = 0; i < lb; i++) {
		d[P + i] = b[i];
	}
	for (int i = 0; i < la - P - lb; i++) {
		d[P + lb + i] = c[P + i];
	}
	printf("d = %s\n", d);
	// 不能返回 function 内自己的地址，因为执行完了会被回收
	return d;
} */

int main() {
	int N, L;
	char A[20000], B[20000], C[20000];

	scanf("%s", A);
	scanf("%d", &N);
	scanf("%s", B);
	// printf("%s, %d, %s\n", A, N, B);

	L = strlen(A);
	printf("%d\n", L > 100 ? 100 : L);

	insertStr(A, N, B);
	printf("%s\n", A);
	// 为什么这个不对？
	// printf("%lu\n", strlen(A) - (N - 1) - strlen(B) + 1);
	for (int i = strlen(A) - 1, cnt = 1; i > 0; i--, cnt++) {
		if (A[i] == 'x') {
			printf("%d\n", cnt);
			break;
		}
	}

	return 0;
}