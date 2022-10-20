#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char str[][10] = {"am", "pm", "midnoon"};

int main() {
	int t, h, m, s, flag = 0;
	cin >> t;
	h = t / 3600;
	m = t % 3600 / 60;
	s = t % 60;
	// 当经历了这行，标记 flag
	if (h > 12) h -= 12, flag = 1;
	printf("%02d:%02d:%02d ", h, m, s);

	flag += 2 * (h == 12);
	printf("%s\n", str[flag]);

	// printf("%02d:%02d:%02d", h, m, s);
	// if (h == 12) {
	// 	printf(" midnoon\n");
	// } else if (flag) {
	// 	printf(" pm\n");
	// } else {
	// 	printf(" am\n");
	// }
	
	return 0;
}