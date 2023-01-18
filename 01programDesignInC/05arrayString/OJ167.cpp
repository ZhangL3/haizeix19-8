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

int main() {
	char A[20000], B[10000];
	int N;

	scanf("%s", A);
	scanf("%d", &N);
	scanf("%s", B);

	printf("%lu\n", strlen(A));

	for (int i = 0, j = 1; i < strlen(A); i++, j++) {
		if (A[i] == 'a') {
			printf("%d\n", j);
			break;
		}
	}

	insertStr(A, N, B);
	printf("%s\n", A);

	return 0;
}