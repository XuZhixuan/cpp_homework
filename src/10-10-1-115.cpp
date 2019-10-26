#include <iostream>
#include <iomanip>

using namespace std;

double toCelsius(int);

int main()
{
	int a, b;

	cin >> a >> b;

	int length, precision;

	cin >> length >> precision;

	cout << setiosflags(ios::fixed) << setiosflags(ios::right) << setprecision(precision);

	cout << setw(length) << "Fahrenheit";
	cout << setw(length) << "Celsius" << endl;

	for (a; a <= b; a++)
	{
		cout << setw(length) << a;
		cout << setw(length) << toCelsius(a) << endl;
	}

	return 0;
}

double toCelsius(int Fahrenheit)
{
	return 5.0 / 9.0 * (Fahrenheit - 32);
}