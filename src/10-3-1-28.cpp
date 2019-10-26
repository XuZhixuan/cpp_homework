#include <iostream>

long factorial(int);

int main()
{
	using namespace std;

	int in;
	cin >> in;

	long sum = 0;

	for (int i = 1; i <= in; i++)
	{
		sum += factorial(i);
	}

	cout << sum << endl;
	return 0;
}

long factorial(int x)
{
	long fact = 1;

	for (int i = 1; i <= x; i++)
	{
		fact *= i;
	}

	return fact;
}
