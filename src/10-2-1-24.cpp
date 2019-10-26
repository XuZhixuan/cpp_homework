#include <iostream>
#include <cmath>

bool triangle(float*, int, int);
float squre(float*, int, int);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	float length[3];
	   
	for (int i = 0; i < 3; i++)
	{
		cin >> length[i];
	}

	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		sum += length[i];
	}

	if (triangle(length, 3, sum))
	{
		cout << squre(length, 3, sum) << endl;
	}
	else
	{
		cout << "Error Data!" << endl;
	}

	return 0;
}

bool triangle(float* length, int size, int sum)
{	
	for (int i = 0; i < size; i++)
	{
		if (2 * length[i] > sum)
		{
			return false;
		}
	}
	return true;
}

float squre(float* length, int size, int sum)
{
	using std::sqrt;

	sum /= 2.0;
	float result = sum;

	for (int i = 0; i < size; i++)
	{
		result *= (sum - length[i]);
	}

	return sqrt(result);
}
