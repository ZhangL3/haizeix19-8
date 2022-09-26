#include <stdio.h>

// int main() {
// 	int a = 2, b = 3;

// 	int c = ++a;
// 	/* 可以编译
// 	对一行进行操作，操作完，过了这一行还可以操作，叫做左值，不能的叫右值
// 	*/

// 	int d = ++(2 + 3);
// 	/* error: increment of read-only location ‘(2 + 3)’
// 	属于中间变量的就是右值，不能进行 ++ 操作*/

// 	// int c = a + b;
// 	printf("d = %d, c = %d\n", d, c);

// 	return 0;
// }

int main() {
	/* int a = 6, b = 3, d = 4;
	int *p = &a; */
	// *p--;
	// printf("%d\n", a);
	/* output: 6
	p 取 a 的值，做 --，但是 a 值并没有变
	取值 * 和 -- 都是 2 级，2 级内优先级是右到左, 所以 -- 的对象是 p 的地址，不是值
	*/
	/* --*p;
	(*p)--;
	printf("%d\n", a); */
	/* output: 4 */

	/* int n;
	scanf("%d", &n); */
	// mod 运算最慢
	/* if (n % 2 == 0) {
		printf("even\n");
	} else {
		printf("odd\n");
	} */

	/* 按位与 &，有 0 则 0，同 1 为 1
		3 = 1 1 	2 = 1 0
		1 = 0 1		1 = 0 1
	=>	1 = 0 1		0 = 0 0
	*/
	/* if (n & 1) {
		printf("odd\n");
	} else {
		printf("even\n");
	} */

	int t, k;
	/* 交换 t, k 的值
	异或操作 ^: 同为 0，不同为 1
		a = 1 1 0
		b = 1 0 1
	a ^ b = 0 1 1
	已知任意两个就能得到第三个
	*/
	scanf("%d%d", &t, &k);
	printf("t = %d, k = %d\n", t, k);
	t ^= k; // t = t ^ k; t = 1 1 1
	k ^= t; // k = k ^ t; 
	t ^= k; // t = t ^ k;
	printf("t = %d, k = %d\n", t, k);
	return 0;
}