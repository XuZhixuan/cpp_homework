#include <iostream>

void sort(int*, int);

int main()
{
	using namespace std;

	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	sort(arr, 10);

	int sum = 0;
	for (int i = 1; i < 9; i++)
	{
		sum += arr[i];
	}

	cout << sum / 8 << endl;

	return 0;
}

void sort(int* arr, int size)
{
	int buff;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				buff = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}
