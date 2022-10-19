#include <iostream>
#include <stdio.h>
using namespace std;

// V1 传值
void swap_t_v1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	printf("swap_t_v1 : a = %d, b = %d\n", a, b);
}

// V2 传指针
void swap_t_v2(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap_t_v2 : a = %d, b = %d\n", *a, *b);
}

// V3 传引用
void swap_t_v3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
	printf("swap_t_v3 : a = %d, b = %d\n", a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	// a 和 b 在 swap_t 的作用域里交换了
	swap_t_v1(a, b);
	// 这里的 a 和 b 并没有被交换
	cout << "v1: " << a << " " << b << endl;
	// 传地址，加取地址符 &
	swap_t_v2(&a, &b);
	cout << "v2: " << a << " " << b << endl;
	// 传引用
	swap_t_v3(a, b);
	cout << "v3: " << a << " " << b << endl;
}