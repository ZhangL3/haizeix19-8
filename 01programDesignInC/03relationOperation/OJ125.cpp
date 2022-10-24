#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int h, m, s, t,
		stopH, stopM, stopS, dayTime,
		startT, stopT;
	double percentage;
	cin >> h >> m >> s >> t;
	percentage = t / 86400.0 * 100;
	startT = h * 3600 + m * 60 + s;
	stopT = startT + t;
	stopH = stopT / 3600;
	stopM = stopT % 3600 / 60;
	stopS = stopT % 60;

	if (stopM == 0 && stopS == 0 && stopH == 24) {
		stopH = 12;
		dayTime = 0;
	} else if (stopM == 0 && stopS == 0 && stopH == 12) {
		dayTime = 1;
	} else {
		if (stopH >= 24) stopH -= 24;
		if (stopH >= 12) {
			stopH -= 12;
			dayTime = 1;
		} else {
			dayTime = 0;
		}
	}

	printf(
		"%d:%d:%d%s\n",
		stopH,
		stopM,
		stopS,
		dayTime == 0 ? "am" : "pm"
	);
	printf("%.2lf%%\n", percentage);

	return 0;
}