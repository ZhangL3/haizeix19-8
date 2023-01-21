#include <stdio.h>
#include <string.h>
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

int main() {
	int N = 10;
	char name[NAME_SIZE];
	char names[NAME_ARRAY_SIZE][NAME_SIZE];
	char *ptrNames[NAME_ARRAY_SIZE];

	// link the pointer array to data array
	for (int i = 0; i < NAME_ARRAY_SIZE; i++) {
		ptrNames[i] = names[i];
	}

	for (int i = 0, k = 0, c = 0; i < N; i++, k = i) {
		scanf("%s", name);
		// store name into array
		for (int j = 0; j < strlen(name); j++) {
			names[i][j] = (char)name[j];
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