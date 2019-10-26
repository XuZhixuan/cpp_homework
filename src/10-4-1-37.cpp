#include <iostream>

using namespace std;

int main()
{
	int loop;

	cin >> loop;

	float a = 2;
	float b = 1;
	float t;

	double sum = 0;

	for (int i = 0; i < loop; i++)
	{
		sum += a / b;
		t = a;
		a += b;
		b = t;
	}

	cout << sum;

	return 0;
}
