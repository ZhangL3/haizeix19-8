#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
#define NAME_SIZE 100
#define NAME_ARRAY_SIZE 100

using namespace std;

int compareStr(const char *a, const char *b) {
	int la = strlen(a), lb = strlen(b);
	int l = min(strlen(a), strlen(b));
	bool cmp;
	for (int i = 0; i < l; i++) {
		if (a[i] == b[i]) continue;
		cmp = a[i] < b[i];
		return cmp ? -1 : 1;
	}
	if (la == lb) return 0;
	return la < lb ? -1 : 1;
}

void swapPointer(char **arrStr, int a, int b) {
	char *tmpPtr = arrStr[b];
	arrStr[b] = arrStr[a];
	arrStr[a] = tmpPtr;
}

void swapData(char **arrStr, int a, int b) {
	char tmp[100];
	strcpy(tmp, arrStr[b]);
	strcpy(arrStr[b], arrStr[a]);
	strcpy(arrStr[a], tmp);
}

// test compareStr
/* int main() {
	char a[100];
	char b[100];
	scanf("%s %s", a, b);
	printf("%s : %s = ", a, b);
	printf("%d\n", compareStr(a, b));
} */


int main() {
	int N;
	char name[NAME_SIZE];
	char names[NAME_ARRAY_SIZE][NAME_SIZE];
	char *ptrNames[NAME_ARRAY_SIZE];

	scanf("%d", &N);

	// link the pointer array to data array
	for (int i = 0; i < NAME_ARRAY_SIZE; i++) {
		ptrNames[i] = names[i];
	}

	for (int i = 0, k = 0, c = 0; i < N; i++, k = i) {
		scanf("%s", name);
		// convert name and store it into array
		names[i][0] = (char)toupper(name[0]);
		for (int j = 1; j < strlen(name); j++) {
			names[i][j] = (char)tolower(name[j]);
		}
		if (k > 0) {
			// compare string, if smaller, swap the pointer
			c = compareStr(ptrNames[k], ptrNames[k - 1]);
			while (k > 0 && c < 0) {
				swapPointer(ptrNames, k, k - 1);
				k--;
				if (k == 0) break;
				c = compareStr(ptrNames[k], ptrNames[k - 1]);
			}
		}
	}


	for (int i = 0; i < N; i++) {
		printf("%s\n", ptrNames[i]);
	}

	// test swapPointer & swapData
	// swapPointer(ptrNames, 1, 2);
	// printf("============================\n");

	// for (int i = 0; i < N; i++) {
	// 	printf("%s, %s\n", names[i], ptrNames[i]);
	// }

	// swapData(ptrNames, 1, 2);
	// printf("============================\n");

	// for (int i = 0; i < N; i++) {
	// 	printf("%s, %s\n", names[i], ptrNames[i]);
	// }

	return 0;
}