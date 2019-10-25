#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Complex
{
protected:
	int real_;
	int virtual_;

public:
	Complex();
	Complex(int, int);
	void printComplex();
	Complex operator- (Complex&);
};

int main()
{
	int a, b;

	cin >> a >> b;
	Complex comp1(a, b);

	cin >> a >> b;
	Complex comp2(a, b);

	comp1.printComplex();
	comp2.printComplex();

	Complex comp = comp1 - comp2;
	comp.printComplex();

	return 0;
}

Complex::Complex()
{
	real_ = 0;
	virtual_ = 0;
}

Complex::Complex(int real, int virt)
{
	real_ = real;
	virtual_ = virt;
}

void Complex::printComplex()
{
	cout << real_ << "+j" << virtual_ << endl;
}

Complex Complex::operator- (Complex& com)
{
	int real = real_ - com.real_;
	int virt = virtual_ - com.virtual_;

	return Complex(real, virt);
}
