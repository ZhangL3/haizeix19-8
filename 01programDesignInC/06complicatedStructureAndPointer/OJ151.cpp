#include <stdio.h>

int win(const char m, const char n) {
	if (m == n) return 0;
	if (
		(m == 'Y' && n == 'H')
		|| (m == 'O' && n == 'Y')
		|| (m == 'H' && n == 'O')
	) return 1;
	return -1;
}

int winMing() {
	printf("MING\n");
	return 0;
}

int winLi() {
	printf("LIHUA\n");
	return 0;
}

int tie() {
	printf("TIE\n");
	return 0;
}

int main() {
	char ML, MR, LL, LR;
	scanf("%s %s", &ML, &MR);
	scanf("%s %s", &LL, &LR);
	// printf("%c %c\n%c %c\n", ML, MR, LL, LR);
	// printf("%d\n", win(ML, LL));
	if (win(ML, LL) > 0) {
		if (win(ML, LR) >= 0) return winMing();
		if (win(ML, LR) < 0) {
			if (win(MR, LR) > 0) return winMing();
			else return winLi();
		}
	};
	if (win(ML, LL) == 0) {
		if (win(MR, LR) > 0) return winMing();
		if (win(MR, LR) < 0) return winLi();
		if (win(MR, LR) == 0) return tie();
	}
	if (win(ML, LL) < 0) {
		if (win(MR, LL) <= 0) return winLi();
		else {
			if (win(MR, LL)) {
				if (win(MR, LR) >= 0) return winMing();
				else winLi();
			}
		}
	}

	return 0;
}