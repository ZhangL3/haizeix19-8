#include <iostream>
using namespace std;

int main() {
	int number = 88;
	int * p1 = &number;

	int * p2;
	cout << "before: " << p2 << endl;
	p2 = new int;

	cout << "before assignment: " << p2 << endl;
	*p2 = 99;
	cout << "after assignment: " << p2 << endl;
	cout << *p2 << endl;
	delete p2;
	cout << "after delete: " << p2 << endl;

	return 0;
}