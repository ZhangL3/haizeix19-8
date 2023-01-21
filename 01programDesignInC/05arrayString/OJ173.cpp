#include <stdio.h>
#include <string.h>

int main() {
	char str[1005];
	int alphabet = 0, number = 0, space = 0, others = 0, ind = 0;
	char tmp;
	scanf("%[^\n]s", str);
	// printf("%s\n", str);
	
	for (int i = 0; i < strlen(str); i++) {
		// printf("%d: %c(%d)\n ", i, str[i], str[i]);
		if(
			str[i] >= 48 && str[i] <= 57
		) number++;
		else if (
			(str[i] >= 65 && str[i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122)
		) alphabet++;
		else if (
			str[i] == 32
		) space++;
		else others++;
	}

	printf("%d %d %d %d\n", alphabet, number, space, others);

	return 0;
}