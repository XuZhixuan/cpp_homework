#include <iostream>
#include <cmath>

using namespace std;

double low, up, m;

double f(double);
bool hasSameSymbol(double, double);
bool secant();

int main()
{
	cin >> low;
	cin >> up;

	while (!secant())
	{
		//
	}

	cout << m << endl;

	return 0;
}

bool secant()
{
	m = low - (low - up) / (f(low) - f(up)) * f(low);
	double result = f(m);

	if (hasSameSymbol(result, f(low)))
	{
		low = m;
	}
	else {
		up = m;
	}

	return abs(result) < 1.0e-9 ;
}

double f(double x)
{
	return x * x - 2 * x;
}

bool hasSameSymbol(double a, double b)
{
	return (a >= 0 && b >= 0) || (a < 0 && b < 0);
}
