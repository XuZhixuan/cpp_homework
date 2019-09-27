#include <iostream>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	float a, b, c, d;

	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	float sum = a + b + c + d;

	cout << sum << endl;
	cout << (int)(sum + 0.5) << endl;

	return 0;
}
