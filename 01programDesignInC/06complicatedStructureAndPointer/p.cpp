#include <stdio.h>

int main() {
	int num2 = 0x61626364;
	printf("test: \n");
    printf("%s\n", (char *)(&num2 + 1));
}