#include <iostream>
using namespace std;


int main() {
	char x;
	cin >> x;
	switch (x)
	{
	case 'h':
		cout << "He" << endl;
		break;
	case 'l':
		cout << "Li" << endl;
		break;
	case 'c':
		cout << "Cao" << endl;
		break;
	case 'd':
		cout << "Duan" << endl;
		break;
	case 'w':
		cout << "Wang" << endl;
		break;
	default:
		cout << "Not Here" << endl;
		break;
	}

	return 0;
}