#include <stdio.h>

union IP {
	unsigned int num;
	struct {
		unsigned char a1;
		unsigned char a2;
		unsigned char a3;
		unsigned char a4;
	} ip;
};

int main() {
	union IP p;
	char str[25];
	unsigned int arr[4];

	while (~scanf("%s", str)) {
		sscanf(str, "%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
		// p.ip.a1 = arr[0];
		// p.ip.a2 = arr[1];
		// p.ip.a3 = arr[2];
		// p.ip.a4 = arr[3];
		/* 
		192.168.0.1
		16820416
		192.168.0.2
		33597632
		193.168.0.1
		16820417
		 */

		p.ip.a1 = arr[3];
		p.ip.a2 = arr[2];
		p.ip.a3 = arr[1];
		p.ip.a4 = arr[0];
		/* 
		192.168.0.1
		3232235521
		192.168.0.2
		3232235522
		193.168.0.1
		3249012737
		*/
		printf("%u\n", p.num);
		// a1, a2, a3, a4 和 num 是公用内存，所以读 num 的时候，就是 读 a 的那 4 个 Bytes
		/*
		大端机：低位 -> 高地址
		小端机：低位 -> 低地址
		*/
	}
	return 0;
}