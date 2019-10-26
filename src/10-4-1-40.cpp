#include <iostream>
#include <vector>

using namespace std;

void dec2bin(int);

int main()
{
	int input;

	cin >> input;

	dec2bin(input);

	return 0;
}

void dec2bin(int val)
{
	vector<int> ivec;

	while (val != 0)
	{
		ivec.push_back(val % 2);
		val /= 2;
	}

	vector<int>::size_type size = ivec.size();
	vector<int> vec;

	for (vector<int>::size_type i = 1; i <= size; i++)
	{
		vec.push_back(ivec[size - i]);
	}

	for (vector<int>::size_type i = 0; i < size; i++)
	{
		cout << vec[i];
	}
}
