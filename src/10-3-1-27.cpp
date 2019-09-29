#include <iostream>

double eval(double, char, double);

int main()
{
	using namespace std;
	float x, y;
	char operation;

	cin >> x;
	cin >> operation;
	cin >> y;

	cout << eval(x, operation, y) << endl;
	return 0;
}

double eval(double x, char operation, double y)
{
	double result = 0;
	switch (operation)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '/':
		result = x / y;
		break;
	case '*':
		result = x * y;
		break;
	default:
		break;
	}
	return result;
}
