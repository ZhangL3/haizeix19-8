#include <stdio.h>
using namespace std;

int main() {
	char str[10];
	scanf("%[^\n]s", str);
	if (str[0] == str[2]) {
		printf("%s\n", "TIE");
		return 0;
	}

	if (
		str[0] == 'O' && str[2] == 'Y'
		|| str[0] == 'Y' && str[2] == 'H'
		|| str[0] == 'H' && str[2] == 'O'
	) {
		printf("%s\n", "MING");
	} else {
		printf("%s\n", "LI");
	}

	return 0;
}