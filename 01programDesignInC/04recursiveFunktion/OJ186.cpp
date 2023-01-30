#include <stdio.h>

void sprint(int pSize, const int *p, int pInd, int *cnt) {
	// printf("pSize = %d, pInd = %d, cnt = %d\n", pSize, pInd, *cnt);
	// 进来了就要先跳，如果不出去，在计算其他值
	pSize = pSize - p[pInd];
	if (pSize <= 0) return ;
	*cnt += 1;
	pInd = pInd + p[pInd];
	sprint(pSize, p, pInd, cnt);


}

int main() {
	int n, cnt = 1;
	int p[100005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	sprint(n, p, 0, &cnt);
	printf("%d\n", cnt);
}