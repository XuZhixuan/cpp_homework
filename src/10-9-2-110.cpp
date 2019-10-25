#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Vector
{
protected:
	int dimension_;
	int* arr_;

public:
	Vector();
	~Vector();
	Vector(int, int*);
	int getContent(int) const;
	void printVector();
	Vector operator+ (const Vector&);
};

int main()
{
	int dimension;

	cin >> dimension;

	int* temp_1 = new int[dimension];
	int* temp_2 = new int[dimension];

	for (int i = 0; i < dimension; i++)
	{
		cin >> temp_1[i];
	}

	for (int i = 0; i < dimension; i++)
	{
		cin >> temp_2[i];
	}

	Vector v1(dimension, temp_1);
	Vector v2(dimension, temp_2);

	Vector v = v1 + v2;

	v.printVector();

	return 0;
}

Vector::Vector()
{
	dimension_ = 0;
	arr_ = NULL;
}

Vector::Vector(int dimension, int* content)
{
	dimension_ = dimension;
	arr_ = content;
}

Vector::~Vector()
{
	delete[] arr_;
}

int Vector::getContent(int x) const
{
	if (x > dimension_ - 1)
	{
		return 0;
	}

	return arr_[x];
}

void Vector::printVector()
{
	for (int i = 0; i < dimension_; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(8) << arr_[i];
	}
	cout << endl;
}

Vector Vector::operator+ (const Vector& vector)
{
	int dimension = max(dimension_, vector.dimension_);
	int* content = new int[dimension];

	for (int i = 0; i < dimension; i++)
	{
		content[i] = getContent(i) + vector.getContent(i);
	}

 	return Vector(dimension, content);
}
