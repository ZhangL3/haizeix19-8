#include <stdio.h>
#include <string.h>

void pushStr(char *str, int strSize, int offset) {
	char strCp[30];
	char doubleStr[60];
	strcpy(doubleStr, str);
	strcat(doubleStr + strSize, str);
	// printf("%s\n", doubleStr);
	for (int i = 0; i < strSize; i++) {
		str[i] = doubleStr[strSize - offset + i];
	}
	str[strSize] = '\0';
	return ;
}

int main() {
	int strSize, a = 0;
	char str[30];
	scanf("%s", str);
	strSize = strlen(str);
	// for (int i = 0; i < strSize; i++) {
	// 	printf("%s\n", str);
	// 	pushStr(str, strSize, 2);
	// }

	for (int i = 0; i < strSize; i++) {
		for (int j = 0; j < strSize; j++) {
			printf("%c", str[a]);
			a++;
			a %= strSize;
		}
		printf("\n");
		a += strSize - 2;
		a %= strSize;
	}
}