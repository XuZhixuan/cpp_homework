#include <iostream>

using namespace std;

int sum(int*, int);

int main()
{
	int length;

	cin >> length;

	length += 1;

	int *feb = new int[length];

	feb[0] = 0;
	feb[1] = 1;

	for (int i = 2; i < length; i++)
	{
		feb[i] = feb[i - 1] + feb[i - 2];
	}

	cout << feb[length - 1] << endl;
	cout << sum(feb, length) << endl;

	delete[] feb;

	return 0;
}

int sum(int* arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum;
}
