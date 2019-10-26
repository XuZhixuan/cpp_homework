#include <iostream>
#include <cmath>

double fun(double);

int main()
{
	using namespace std;
	float lower, upper;

	cin >> lower;
	cin >> upper;

	double step = (upper - lower) / 200;

	double sum = 0;
	double temp = 0;

	for (int i = 0; i < 200; i++)
	{
		temp = fun(lower);
		lower += step;
		temp += fun(lower);
		temp *= step / 2;

		sum += temp;
	}

	cout << sum << endl;
	return 0;
}

double fun(double x)
{
	using namespace std;

	return sin(x) + exp(x);
}
