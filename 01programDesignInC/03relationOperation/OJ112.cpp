#include <iostream>
using namespace std;

int main() {
	char x;
	cin >> x;
	switch (x)
	{
	case 'a':
		cout << "It is good" << endl;
		break;
	case 'b':
		cout << "OMG" << endl;
		break;
	case 'c':
		cout << "Yes!" << endl;
		break;
	default:
		break;
	}

	return 0;
}