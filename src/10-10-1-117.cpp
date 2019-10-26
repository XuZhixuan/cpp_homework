#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	cout << "dec oct hex char" << endl;

	for (a; a <= b; a++)
	{
		cout << dec << a << ' ';
		cout << oct << a << ' ';
		cout << hex << a << ' ';
		cout << (char)a;
		cout << endl;
	}

	return 0;
}