#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "one" << endl;
		break;
	case 2:
		cout << "two" << endl;
		break;
	case 3:
		cout << "three" << endl;
		break;
	default:
		cout << "error" << endl;
		break;
	}

	return 0;
}