#include <iostream>

using namespace std;

class Counter
{
protected:
	int n_;

public:
	Counter();
	Counter(int);
	int getCount();
	Counter operator++ ();
	Counter operator++ (int);
};

int main()
{
	int key;

	cin >> key;

	Counter c(key);
	c++;

	cout << c.getCount() << endl;

	++c;

	cout << c.getCount() << endl;

	return 0;
}

Counter::Counter()
{
	n_ = 0;
}

Counter::Counter(int init)
{
	n_ = init;
}

Counter Counter::operator ++()
{
	n_++;

	return Counter(n_);
}

Counter Counter::operator++ (int)
{
	n_++;
	return Counter(n_);
}


int Counter::getCount()
{
	return n_;
}
