#include <stdio.h>

int main() {
	char ch;
	int cnt;
	while (scanf("%c", &ch)) {
		if ((int)ch == 32) {
			cnt = 0;
		} else if ((int)ch == 10) {
			break;
		} else {
			cnt ++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}